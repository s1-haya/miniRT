#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// 連想配列の要素を表す構造体
typedef struct {
    char *key;       // キーとなる文字列
    char **values;   // 値となる文字列の配列
    int size;        // 配列のサイズ
} AssocArray;

// 連想配列を初期化する関数
void initAssocArray(AssocArray *array, const char *key, char **values, int size) {
    array->key = strdup(key);
    array->values = (char **)malloc(size * sizeof(char *));
    for (int i = 0; i < size; i++) {
        array->values[i] = strdup(values[i]);
    }
    array->size = size;
}

// 連想配列の内容を表示する関数
void printAssocArray(AssocArray *array) {
    printf("{%s: [", array->key);
    for (int i = 0; i < array->size; i++) {
        printf("%s", array->values[i]);
        if (i < array->size - 1) printf(", ");
    }
    printf("]}\n");
}

// メモリを解放する関数
void freeAssocArray(AssocArray *array) {
    free(array->key);
    for (int i = 0; i < array->size; i++) {
        free(array->values[i]);
    }
    free(array->values);
}

int main() {
    // サンプルのキーと値
    char *key = "Az";
    char *values[] = {"d", "89", "90", "20"};
    int size = sizeof(values) / sizeof(values[0]);

    AssocArray array;

    // 連想配列の初期化と表示
    initAssocArray(&array, key, values, size);
    printAssocArray(&array);

    // メモリの解放
    freeAssocArray(&array);

    return 0;
}
