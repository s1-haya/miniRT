//  方向ベクトルが0, 0, 0の時動く
// parserの段階で弾く。方向ベクトルをチェックし、エラーメッセージ出力する関数用意する

#include "vector.h"
#include <stdbool.h>
#include <unistd.h>

#define ERROR_DIRECTION_VECTOR_EQUQL_ZERO "Error: Direction vector is zero.\
Please check direction vector in rt file you have enterd."

void	check_direction_vector(t_vector vector, bool *result)
{
	if (*result && (!vector.x && !vector.y && !vector.z))
	{
		write(STDERR_FILENO, ERROR_DIRECTION_VECTOR_EQUQL_ZERO,
				sizeof(ERROR_DIRECTION_VECTOR_EQUQL_ZERO) - 1);
		*result = false;
	}
}
