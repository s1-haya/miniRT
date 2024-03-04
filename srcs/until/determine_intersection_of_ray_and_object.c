#include <mlx.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include "minirt.h"
#include "vector.h"
#include "shape.h"
#include "libft.h"

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

t_intersection	determine_intersection_ray_and_plane(t_plane *plane, t_ray ray)
{
	double			t;
	t_intersection	intersection;

	t = -dot_product(ray.point, plane->normal) / dot_product(ray.direction, plane->normal);
	intersection = new_intersection(ray, t);
	if (intersection.is_success)
		intersection.normal = plane->normal;
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

t_intersection	determine_intersection_ray_and_sphere(t_sphere *sphere, t_ray ray)
{
	t_vector		intersection_vector;
	double			a;
	double			b;
	double			c;
	t_intersection	intersection;

	intersection_vector = subtract_vectors(ray.point, sphere->origin);
	a = pow(vector_length(ray.direction), 2.0);
	b = 2 * dot_product(ray.direction, intersection_vector);
	c = pow(vector_length(intersection_vector), 2.0) - pow(sphere->radius, 2.0);
	intersection = new_intersection(ray, min_solution(a, b, c));
	if (intersection.is_success)
		intersection.normal = subtract_vectors(intersection.point, sphere->origin);
	return (intersection);
}

static bool	cylinder_form_bottom(t_cylinder *cylinder, t_ray ray, double t)
{
	double	temp;
	t_vector	intersection_point;

	intersection_point = add_vectors(ray.point, scalar_multiply(ray.direction, t));
	temp = dot_product(subtract_vectors(intersection_point, cylinder->origin), cylinder->axis);
	return (0 <= temp && temp <= cylinder->height);
}

t_vector	cylinder_normal(t_intersection intersection, t_cylinder *cylinder)
{
	t_vector	normal;

	normal = subtract_vectors(subtract_vectors(\
		intersection.point, cylinder->origin), scalar_multiply(cylinder->axis, \
	dot_product(subtract_vectors(intersection.point, cylinder->origin), cylinder->axis)));
	normalize_vector(&normal);
	return (normal);
}

t_intersection get_intersection_ray_and_cylinder(t_cylinder *cylinder, t_ray ray, double t1, double t2)
{
	t_intersection	intersection;

	intersection.is_success = false;
	if (cylinder_form_bottom(cylinder, ray, t1))
	{
		intersection = new_intersection(ray, t1);
		if (intersection.is_success)
			intersection.normal = cylinder_normal(intersection, cylinder);
	}
	else if (cylinder_form_bottom(cylinder, ray, t2))
	{
		intersection = new_intersection(ray, t2);
		if (intersection.is_success)
			intersection.normal = \
				get_inverse_vector(cylinder_normal(intersection, cylinder));
	}
	return (intersection);
}

t_intersection	determine_intersection_ray_and_cylinder(t_cylinder *cylinder, t_ray ray)
{
	t_intersection	intersection;
	double			a;
	double			b;
	double			c;
	double			d;

	intersection.is_success = false;
	a = pow(vector_length(cross_product(ray.direction, cylinder->axis)), 2.0);
	b = 2 * dot_product(cross_product(ray.direction, cylinder->axis), \
		cross_product(subtract_vectors(ray.point, cylinder->origin), cylinder->axis));
	c = pow(vector_length(cross_product(subtract_vectors(ray.point, \
		cylinder->origin), cylinder->axis)), 2.0) - pow(cylinder->radius, 2.0);
	if (a == 0)
		return (intersection);
	d = discriminant(a, b, c);
	if (d < 0)
		return (intersection);
	return (get_intersection_ray_and_cylinder(cylinder, ray, \
			(-b - sqrt(d)) / (2 * a), (-b + sqrt(d)) / (2 * a)));
}

t_intersection	get_intersection_ray_and_object(t_shape *shape, t_ray ray)
{
	t_intersection	intersection;

	if (shape->object == PLANE)
		intersection = determine_intersection_ray_and_plane(shape->substance, ray);
	else if (shape->object == SPHERE)
		intersection = determine_intersection_ray_and_sphere(shape->substance, ray);
	else if (shape->object == CYLINDER)
		intersection = determine_intersection_ray_and_cylinder(shape->substance, ray);
	else
		intersection.is_success = false;
	return (intersection);
}

t_shape	*determine_intersection_ray_and_object(t_list *shape_list, t_ray ray, double light_source_distance)
{
	t_list			*iterator;
	t_shape			*nearest_shape;
	t_intersection	intersection;

	iterator = shape_list;
	nearest_shape = NULL;
	while (iterator != NULL)
	{
		intersection = get_intersection_ray_and_object(iterator->content, ray);
		if (intersection.is_success && light_source_distance > vector_length(subtract_vectors(intersection.point, ray.point)))
		{
			((t_shape *)iterator->content)->intersection = intersection;
			nearest_shape = iterator->content;
			light_source_distance = vector_length(subtract_vectors(intersection.point, ray.point));
		}
		iterator = iterator->next;
	}
	return (nearest_shape);
}
