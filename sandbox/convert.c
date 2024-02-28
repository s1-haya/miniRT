#include <stdio.h>

// 値を一定範囲に制限する関数
double constrain(double v, double v_min, double v_max)
{
	if (v < v_min)
	{
		return v_min;
	}
	else if (v > v_max)
	{
		return v_max;
	}
	return v;
}

// 値の範囲を変換する関数 (map)
double map(double v, double v_min, double v_max, double t_min, double t_max)
{
	// constrain関数を用いてvを[v_min, v_max]の範囲に制限
	double constrained_value = constrain(v, v_min, v_max);

	// t_minからt_maxの範囲に値を変換
	double mapped_value = t_min + ((t_max - t_min) * (constrained_value - v_min)) / (v_max - v_min);
	return mapped_value;
}

int main()
{
	// constrainの使用例
	double constrained_value = constrain(40, -1, 1);
	printf("Constrained value: %f\n", constrained_value); // 出力は0になります

	// mapの使用例
	double mapped_value = map(6, 0, 10, -1.0, 1.0);
	printf("Mapped value: %f\n", mapped_value); // 出力は50になります
	mapped_value = map(6, 0, 512, 1.0, -1.0);
	printf("Mapped value: %f\n", mapped_value); // 出力は50になります
	mapped_value = map(6, 0, 512, -1.0, 1.0);
	printf("Mapped value: %f\n", mapped_value); // 出力は50になります

	return 0;
}
