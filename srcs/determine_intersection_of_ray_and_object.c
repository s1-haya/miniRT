#include "mlx.h"
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>


static bool	determine_intersection_ray_and_plane
{

}
// 𝐩𝐞−→視点位置
// 𝐩𝐜−→球の中心位置
// 球の半径
// 𝐩𝐰−→スクリーン上の点の位置．𝐩𝐰−→=(𝑥𝑤,𝑦𝑤,0)．

//視点ベクトル方向　スクリーン上の位置ベクトル - 視点の位置ベクトル
//交差判定　スクリーン上の位置ベクトル - 球の中心位置ベクトル
//交点計算のため二次方程式𝐴𝑡2+𝐵𝑡+𝐶=0
bool	determine_intersection_ray_and_object(long lx, long ly)
{
	long	A;
	long	B;
	long	C;
	long	D;
	return 
}
