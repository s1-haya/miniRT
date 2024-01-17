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
void my_mlx_pixel_put(t_data *img_data, int x, int y, int color);
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

double determine_intersection_ray_and_object(t_shape *shape, t_ray ray)
{
	t_vector intersection_vector;
	double a;
	double b;
	double c;
	double d;
	double t;

	intersection_vector = subtract_vectors(ray.viewpoint, shape->sphere->origin);
	a = pow(vector_length(ray.direction), 2.0);
	b = 2 * dot_product(ray.direction, intersection_vector);
	c = pow(vector_length(intersection_vector), 2.0) - pow(RADIUS, 2.0);
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
