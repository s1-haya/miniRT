#include <mlx.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include "minirt.h"
#include "vector.h"

// 𝐩𝐞−→視点位置
// 𝐩𝐜−→球の中心位置
// 球の半径
// 𝐩𝐰−→スクリーン上の点の位置．𝐩𝐰−→=(𝑥𝑤,𝑦𝑤,0)．

// 視点ベクトル方向　スクリーン上の位置ベクトル - 視点の位置ベクトル
// 交差判定　スクリーン上の位置ベクトル - 球の中心位置ベクトル
// 交点計算のため二次方程式𝐴𝑡2+𝐵𝑡+𝐶=0

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

double determine_intersection_ray_and_object(int x, int y, double lx, double ly, t_vector_data *vector, t_data *img_data)
{
	double a;
	double b;
	double c;
	double d;
	double t;

	vector->screen_point = new_vector(lx, ly, 0.0);
	vector->viewpoint = VIEWPOINT;
	vector->origin_of_the_sphere = ORIGIN_OF_THE_SPHERE;
	vector->line_of_sight_vector = subtract_vectors(vector->screen_point, vector->viewpoint);
	vector->intersection_vector = subtract_vectors(vector->viewpoint, vector->origin_of_the_sphere);
	a = pow(vector_length(vector->line_of_sight_vector), 2.0);
	b = 2 * dot_product(vector->line_of_sight_vector, vector->intersection_vector);
	c = pow(vector_length(vector->intersection_vector), 2.0) - pow(RADIUS, 2.0);
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
	(void)x;
	(void)y;
	(void)img_data;
	// if (t > 0)
	// {
	// 	scalar_multiply(&vector->line_of_sight_vector, t);
	// 	t_vector point_of_intersection = add_vectors(vector->intersection_vector, vector->line_of_sight_vector);
	// 	t_vector incident_vector = subtract_vectors(LIGHT_SOURCE, point_of_intersection);
	// 	normalize_vector(&incident_vector);
	// 	t_vector normal_vector = subtract_vectors(point_of_intersection, img_data->vector->origin_of_the_sphere);
	// 	normalize_vector(&normal_vector);
	// 	double nldot = get_value_in_range(dot_product(normal_vector, incident_vector), 0.0, 1.0);
	// 	printf("nldot %f\n", nldot);
	// 	int gray = (int)(255 * nldot);
	// 	int color = (gray << 16) | (gray << 8) | gray;
	// 	my_mlx_pixel_put(img_data, x, y, color);
	// }
	// else
	// 	my_mlx_pixel_put(img_data, x, y, 0x000000FF);
	return (t);
}
