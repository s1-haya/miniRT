#include <mlx.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include "minirt.h"
#include "vector.h"
#include "shape.h"

t_vector new_vector(double x, double y, double z);
t_vector add_vectors(t_vector v1, t_vector v2);
t_vector subtract_vectors(t_vector v1, t_vector v2);
double dot_product(t_vector v1, t_vector v2);
t_vector cross_product(t_vector v1, t_vector v2);
double vector_length(t_vector v);
void normalize_vector(t_vector *v);
t_vector scalar_multiply(t_vector vector, double scalar);
void my_mlx_pixel_put(t_img *img_data, int x, int y, int color);
double clamp(double v, double v_min, double v_max);

double	min(double n1, double n2)
{
	if (n1 < n2)
		return (n1);
	return (n2);
}

double	max(double n1, double n2)
{
	if (n1 < n2)
		return (n2);
	return (n1);
}

double	determine_intersection_ray_and_plane(t_plane *plane, t_ray ray)
{
	return (-dot_product(ray.point, plane->normal) + dot_product(plane->point, plane->normal) / dot_product(ray.direction, plane->normal));
}

static double	discriminant(double a, double b, double c)
{
	return (pow(b, 2.0) - 4 * a * c);
}

static double	min_solution(double a, double b, double c)
{
	double	d;
	double	t1;
	double	t2;

	d = discriminant(a, b, c);
	if (d < 0)
		return (-1);
	t1 = (-b + sqrt(d)) / (2 * a);
	t2 = (-b - sqrt(d)) / (2 * a);
	if (t1 > 0 && t2 > 0)
		return (min(t1, t2));
	else if (t2 > 0)
		return (t2);
	else if (t1 > 0)
		return (t1);
	return (-1);
}

double	determine_intersection_ray_and_sphere(t_sphere *sphere, t_ray ray)
{
	t_vector	intersection_vector;
	double		a;
	double		b;
	double		c;

	intersection_vector = subtract_vectors(ray.point, sphere->origin);
	a = pow(vector_length(ray.direction), 2.0);
	b = 2 * dot_product(ray.direction, intersection_vector);
	c = pow(vector_length(intersection_vector), 2.0) - pow(sphere->radius, 2.0);
	return (min_solution(a, b, c));
}

double vector_length2_xz(t_vector v)
{
	double	length;

	length = v.x * v.x + v.z * v.z;
	return (length);
}

double dot_product_xz(t_vector v1, t_vector v2)
{
	return (v1.x * v2.x + v1.z * v2.z);
}

static double	check_height_cylinder(t_cylinder *cylinder, t_ray ray, double t)
{
	t_vector		intersection_vector;
	double			t_min_y;
	double			t_max_y;
	const double	height = cylinder->height / 2;

	intersection_vector = subtract_vectors(ray.point, cylinder->origin);
	t_min_y = min((height - intersection_vector.y) / ray.direction.y, \
				(-height - intersection_vector.y) / ray.direction.y);
	t_max_y = max((height - intersection_vector.y) / ray.direction.y, \
				(-height - intersection_vector.y) / ray.direction.y);
	if (t_min_y > t || t > t_max_y)
		return (-1);
	return (t);
}

double determine_intersection_ray_and_cylinder(t_cylinder *cylinder, t_ray ray)
{
	t_vector	intersection_vector;
	double		a;
	double		b;
	double		c;
	double		t;

	intersection_vector = subtract_vectors(ray.point, cylinder->origin);
	a = vector_length2_xz(ray.direction);
	b = 2 * dot_product_xz(intersection_vector, ray.direction);
	c = vector_length2_xz(intersection_vector) - pow(cylinder->radius, 2.0);
	t = min_solution(a, b, c);
	return (check_height_cylinder(cylinder, ray, t));
}

double	get_intersection_ray_and_object(t_shape *shape, t_ray ray)
{
	if (shape->object == PLANE)
		return (determine_intersection_ray_and_plane(shape->plane, ray));
	else if (shape->object == SPHERE)
		return (determine_intersection_ray_and_sphere(shape->sphere, ray));
	else if (shape->object == CYLINDER)
		return (determine_intersection_ray_and_cylinder(shape->cylinder, ray));
	else
		return (-1); // err
}

t_shape	*determine_intersection_ray_and_object(t_shape **shape, t_ray ray, double light_source_distance, bool exit)
{
	size_t			z;
	double			t;
	t_shape			*nearest_shape;
	t_intersection	*tmp;

	z = 0;
	nearest_shape = NULL;
	while (z < SIZE)
	{
		t = get_intersection_ray_and_object(shape[z], ray);
		tmp = new_intersection(ray, t);
		if (tmp != NULL && light_source_distance > tmp->distance)
		{
			if (nearest_shape == NULL || nearest_shape->intersection->distance > tmp->distance)
			{
				shape[z]->intersection = tmp;
				nearest_shape = shape[z];
				if (exit)
					return (nearest_shape);
			}
		}
		z++;
	}
	return (nearest_shape);
}
