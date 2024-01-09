#include <mlx.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include "vector.h"

// 𝐩𝐞−→視点位置
// 𝐩𝐜−→球の中心位置
// 球の半径
// 𝐩𝐰−→スクリーン上の点の位置．𝐩𝐰−→=(𝑥𝑤,𝑦𝑤,0)．

//視点ベクトル方向　スクリーン上の位置ベクトル - 視点の位置ベクトル
//交差判定　スクリーン上の位置ベクトル - 球の中心位置ベクトル
//交点計算のため二次方程式𝐴𝑡2+𝐵𝑡+𝐶=0
bool	determine_intersection_ray_and_object(double lx, double ly)
{
	double	a;
	double	b;
	double	c;
	double	d;
	t_vector	viewpoint;
	t_vector	screen_point;
	t_vector	origin_of_the_sphere;
	t_vector	line_of_sight_vector;
	t_vector	intersection_vector;

	screen_point = new_vector(lx, ly, 0.0);
	viewpoint = new_vector(0, 0, -5);
	origin_of_the_sphere = new_vector(0, 0, 5);
	line_of_sight_vector = subtract_vectors(screen_point, viewpoint);
	intersection_vector= subtract_vectors(viewpoint, origin_of_the_sphere);
	a = pow(vector_length(line_of_sight_vector), 2.0);
	b = 2 * dot_product(line_of_sight_vector, intersection_vector);
	c = pow(vector_length(intersection_vector), 2.0) - pow(1.0, 2.0);
	d = pow(b, 2.0) - 4 * a * c;
	return (d >= 0);
}
