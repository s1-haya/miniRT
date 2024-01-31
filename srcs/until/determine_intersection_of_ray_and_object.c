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
void my_mlx_pixel_put(t_mlx_data *img_data, int x, int y, int color);
double get_value_in_range(double v, double v_min, double v_max);

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
	// printf("numerator:   %f\n",-dot_product(ray.point, plane->normal));
	// printf("denominator: %f\n",dot_product(ray.direction, plane->normal));
	// printf("anser:       %f\n", (-dot_product(ray.point, plane->normal)) / (dot_product(ray.direction, plane->normal)));
	return ((-dot_product(ray.point, plane->normal)) + dot_product(plane->point, plane->normal) / (dot_product(ray.direction, plane->normal)));
}

double	determine_intersection_ray_and_sphere(t_sphere *sphere, t_ray ray)
{
	t_vector intersection_vector;
	double a;
	double b;
	double c;
	double d;
	double t;

	intersection_vector = subtract_vectors(ray.point, sphere->origin);
	a = pow(vector_length(ray.direction), 2.0);
	b = 2 * dot_product(ray.direction, intersection_vector);
	c = pow(vector_length(intersection_vector), 2.0) - pow(sphere->radius, 2.0);
	d = pow(b, 2.0) - 4 * a * c;
	t = -1;
	if (d == 0)
		t = -b / (2 * a);
	else if (d > 0)
	{
		double t1 = (-b + sqrt(d)) / (2 * a);
		double t2 = (-b - sqrt(d)) / (2 * a);
		if (t1 > 0)
			t = t1;
		if (t2 > 0 && t1 > t2)
			t = t2;
	}
	return (t);
}

double determine_intersection_ray_and_cylinder(t_cylinder *cylinder, t_ray ray)
{
	t_vector intersection_vector;
	double a;
	double b;
	double c;
	double d;
	double t;
	double t1;
	double t2;

	intersection_vector = subtract_vectors(ray.point, cylinder->origin);
	a = ray.direction.x * ray.direction.x + ray.direction.z * ray.direction.z;
	b = 2 * (ray.direction.x * intersection_vector.x + ray.direction.z * intersection_vector.z);
	c = intersection_vector.x * intersection_vector.x + intersection_vector.z * intersection_vector.z - cylinder->radius * cylinder->radius;
	d = b * b - 4 * a * c;
	t = -1;
	if (d >= 0)
	{
		t1 = (-b + sqrt(d)) / (2 * a);
		t2 = (-b - sqrt(d)) / (2 * a);
		if (t1 >= 0 && (t1 < t || t < 0))
			t = t1;
		if (t2 >= 0 && (t2 < t || t < 0))
			t = t2;
	}
	double t_min_y = min(((cylinder->height / 2 - ray.point.y) / ray.direction.y), ((-(cylinder->height / 2) - ray.point.y) / ray.direction.y));
	double t_max_y = max(((cylinder->height / 2 - ray.point.y) / ray.direction.y), ((-(cylinder->height / 2) - ray.point.y) / ray.direction.y));
	if (t_min_y > t || t > t_max_y)
		return (-1);
	return (t);
}



double	get_intersection_ray_and_object(t_shape *shape, t_ray ray)
{
	if (shape->object == PLANE)
		return (determine_intersection_ray_and_plane(shape->plane, ray));
	else if (shape->object == SPHERE)
		return (determine_intersection_ray_and_sphere(shape->sphere, ray));
	return (determine_intersection_ray_and_cylinder(shape->cylinder, ray));
}

t_shape	*determine_intersection_ray_and_object(t_shape **shape, t_ray ray, double light_source_distance, bool exit)
{
	size_t	z;
	double	t;
	t_shape	*nearest_shape;
	t_intersection	*tmp;

	z = 0;
	nearest_shape = NULL;
	while (z < SIZE)
	{
		t = get_intersection_ray_and_object(shape[z], ray);
		tmp = new_intersection(ray, t);
		if (tmp != NULL && light_source_distance > tmp->distance)
		{
			// printf("shape[%d]: distance %f\n", z, tmp->distance);
			if (nearest_shape == NULL || nearest_shape->intersection->distance > tmp->distance)
			{
				shape[z]->intersection = tmp;
				nearest_shape = shape[z];
				if (exit)
					return (nearest_shape);
				// printf("shape[%d]: nearest_distance %f\n",z , nearest_shape->intersection->distance);
			}
			// printf("distance[%d]: %f\n",z, ->intersection->distance);
		}
		z++;
	}
	if (nearest_shape != NULL)
		return (nearest_shape);
	return (NULL);
}
