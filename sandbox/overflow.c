// #include <errno.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

// https://learn.microsoft.com/ja-jp/cpp/c-runtime-libft/errno-doserrno-sys-errlist-and-sys-nerr?view=msvc-170

int main() {
    char *end;
    // char *str = "1e400"; // 大きすぎる値
    char *str = "-1e400"; // 大きすぎる値

    double value = strtod(str, &end);
	// double value = strtod("1", &end);

	//erronoは更新されない。ERANGE（34）のままだけどvalueは出力されてる
	value = strtod("1", &end);

    if (value == HUGE_VAL || value == -HUGE_VAL) {
        // オーバーフローが発生
		perror("Overflow occurred");
    } else {
        // 正常に変換された
        printf("Value = %f\n", value);
    }

    return 0;
}
// int main() {
//     char *end;
//     char *str = "1e400"; // 大きすぎる値
//     errno = 0;

//     double value = strtod(str, &end);
// 	printf("errono: %d\n", errno);
// 	// double value = strtod("1", &end);

// 	//erronoは更新されない。ERANGE（34）のままだけどvalueは出力されてる
// 	value = strtod("1", &end);

// 	printf("errono: %d\n", errno);
//     if (errno == ERANGE && (value == HUGE_VAL || value == -HUGE_VAL)) {
//         // オーバーフローが発生
//         printf("Overflow occurred\n");
//     } else {
//         // 正常に変換された
//         printf("Value = %f\n", value);
//     }

//     return 0;
// }
