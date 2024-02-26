#include <stdio.h>

// 自作の strcmp 関数
int my_strcmp(const char *s1, const char *s2) {
    while (*s1 && (*s1 == *s2)) {
        s1++;
        s2++;
    }
    return *(const unsigned char *)s1 - *(const unsigned char *)s2;
}

#include <string.h>
int main() {
    const char *str1 = "Hello";
    const char *str2 = "Hello";
    const char *str3 = "World";

    printf("str1 vs str2: %d\n", my_strcmp(str1, str2)); // 結果は 0 （等しい）
    printf("str1 vs str3: %d\n", my_strcmp(str1, str3)); // 結果は負の整数 （str1 < str3）
    printf("str3 vs str1: %d\n", my_strcmp(str3, str1)); // 結果は正の整数 （str3 > str1）

    // printf("strcmp: %d\n", strcmp(str1, NULL)); // NULL
    // printf("origin: %d\n", my_strcmp(str1, NULL)); // NULL
    // printf("strcmp: %d\n", strcmp(NULL, NULL)); // NULL
    // printf("origin: %d\n", my_strcmp(NULL, NULL)); // 結果は負の整数 （str1 < str3）
    printf("strcmp: %d\n", strcmp(NULL, str1)); // NULL
    printf("origin: %d\n", my_strcmp(NULL, str1)); // 結果は正の整数 （str3 > str1）

    return 0;
}