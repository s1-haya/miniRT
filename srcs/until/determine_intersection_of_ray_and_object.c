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

t_intersection	*determine_intersection_ray_and_plane(t_plane *plane, t_ray ray)
{
	double	t;
	t_intersection	*intersection;

	t = -dot_product(ray.point, plane->normal) / dot_product(ray.direction, plane->normal);
	intersection = new_intersection(ray, t);
	if (intersection)
		intersection->normal = plane->normal;
	return (intersection);
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
	if (t1 >= 0 && t2 >= 0)
		return (min(t1, t2));
	else if (t2 >= 0)
		return (t2);
	else if (t1 >= 0)
		return (t1);
	return (-1);
}

t_intersection	*determine_intersection_ray_and_sphere(t_sphere *sphere, t_ray ray)
{
	t_vector	intersection_vector;
	double		a;
	double		b;
	double		c;
	t_intersection	*intersection;

	intersection_vector = subtract_vectors(ray.point, sphere->origin);
	a = pow(vector_length(ray.direction), 2.0);
	b = 2 * dot_product(ray.direction, intersection_vector);
	c = pow(vector_length(intersection_vector), 2.0) - pow(sphere->radius, 2.0);
	intersection = new_intersection(ray, min_solution(a, b, c));
	if (intersection)
		intersection->normal = subtract_vectors(intersection->point, sphere->origin);
	return (intersection);
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

static bool	cylinder_form_bottom(t_cylinder *cylinder, t_ray ray, double t)
{
	double	temp;
	const t_vector	n = new_vector(0, 1, 0);
	t_vector	intersection_point;

	intersection_point = add_vectors(ray.point, scalar_multiply(ray.direction, t));
	temp = dot_product(subtract_vectors(intersection_point, cylinder->origin), n);
	return (0 <= temp && temp <= cylinder->height);
}

t_intersection *determine_intersection_ray_and_cylinder(t_cylinder *cylinder, t_ray ray)
{
	double		a;
	double		b;
	double		c;
	const t_vector	n = new_vector(0, 1, 0);
	t_intersection	*intersection = NULL;

	a = pow(vector_length(cross_product(ray.direction, n)), 2.0);
	b = 2 * dot_product(cross_product(ray.direction, n), cross_product(subtract_vectors(ray.point, cylinder->origin), n));
	c = pow(vector_length(cross_product(subtract_vectors(ray.point, cylinder->origin), n)), 2.0) - pow(cylinder->radius, 2.0);
	if (a == 0)
		return (NULL);
	double d = discriminant(a, b, c);
	if (d < 0)
		return (NULL);
	double t1 = (-b - sqrt(d)) / (2 * a);
	double t2 = (-b + sqrt(d)) / (2 * a);
	if (cylinder_form_bottom(cylinder, ray, t1))
	{
		intersection = new_intersection(ray, t1);
		if (intersection)
		{
			intersection->normal = subtract_vectors(subtract_vectors(intersection->point, cylinder->origin), scalar_multiply(n, dot_product(subtract_vectors(intersection->point, cylinder->origin), n)));
			normalize_vector(&intersection->normal);
		}
	}
	else if (cylinder_form_bottom(cylinder, ray, t2))
	{
		intersection = new_intersection(ray, t2);
		if (intersection)
		{
			intersection->normal = subtract_vectors(scalar_multiply(n, dot_product(subtract_vectors(intersection->point, cylinder->origin), n)), subtract_vectors(intersection->point, cylinder->origin));
			normalize_vector(&intersection->normal);
		}
	}
	return (intersection);
}

t_intersection	*get_intersection_ray_and_object(t_shape *shape, t_ray ray)
{
	t_intersection	*intersection;

	if (shape->object == PLANE)
		intersection = determine_intersection_ray_and_plane(shape->plane, ray);
	else if (shape->object == SPHERE)
		intersection = determine_intersection_ray_and_sphere(shape->sphere, ray);
	else if (shape->object == CYLINDER)
		intersection = determine_intersection_ray_and_cylinder(shape->cylinder, ray);
	else
		intersection = NULL;
	return (intersection);
}

// static bool	cylinder_form_bottom(t_cylinder *cylinder, t_ray ray)
// {
// 	t_vector	intersection_vector;
// 	double		a;
// 	double		b;
// 	double		c;
// 	double		d;
// 	double		t1;
// 	double		t2;
// 	double		t_min_y;
// 	double		t_max_y;

// 	intersection_vector = subtract_vectors(ray.point, cylinder->origin);
// 	a = vector_length2_xz(ray.direction);
// 	b = 2 * dot_product_xz(intersection_vector, ray.direction);
// 	c = vector_length2_xz(intersection_vector) - pow(cylinder->radius, 2.0);
// 	t_min_y = min((cylinder->height / 2 - intersection_vector.y) / ray.direction.y, (-cylinder->height / 2 - intersection_vector.y) / ray.direction.y);
// 	t_max_y = max((cylinder->height / 2 - intersection_vector.y) / ray.direction.y, (-cylinder->height / 2 - intersection_vector.y) / ray.direction.y);
// 	d = discriminant(a, b, c);
// 	if (d < 0)
// 		return (false);
// 	t1 = (-b - sqrt(d)) / (2 * a);
// 	t2 = (-b + sqrt(d)) / (2 * a);
// 	return (t_min_y >= t1);
// 	// return (t_max_y <= t2);
// }

t_intersection	*intersection_normal_vec(t_shape *shape, t_ray ray)
{
	t_intersection	*res;
	// double			t;
	// static double	distance = 0;
	// const t_vector	n = new_vector(0, 1, 0);

	// res = new_intersection(ray, t);
	res = get_intersection_ray_and_object(shape, ray);
	// if (!res)
		// return (NULL);
	// distance = res->distance;
	return (res);
}

t_shape	*determine_intersection_ray_and_object(t_shape **shape, t_ray ray, double light_source_distance, bool is_exit)
{
	size_t			z;
	double			t = 100000;
	t_shape			*nearest_shape;
	t_intersection	*intersection;

	z = 0;
	nearest_shape = NULL;
	while (z < SIZE)
	{
		intersection = intersection_normal_vec(shape[z], ray);
		if (intersection != NULL && light_source_distance > intersection->distance)
		{
			if (nearest_shape == NULL || vector_length(subtract_vectors(intersection->point, ray.point)) < t)
			{
				shape[z]->intersection = intersection;
				nearest_shape = shape[z];
				if (is_exit)
					return (nearest_shape);
				// printf("%d\n", nearest_shape->object);
			}
			t = vector_length(subtract_vectors(intersection->point, ray.point));
		}
		z++;
	}
	return (nearest_shape);
}
