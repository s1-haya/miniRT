
//調査　constの定義された値はポインタを使って値を変更することができるのか？
//結果　値を変更することができた。

#include <stdio.h>
int main() {
    int x = 42;
    const int *ptr1 = &x;  // const修飾されたint型へのポインタ
    int *ptr2 = (int *)ptr1;  // const修飾されていないint型へのポインタに変換

    // ptr1とptr2に格納された値は等しく比較されるべき
	printf("ptr1: %d\n", *ptr1);
	printf("ptr2: %d\n", *ptr2);
	*ptr2 = 3;
	printf("ptr1: %d\n", *ptr1);
	printf("ptr2: %d\n", *ptr2);
    if (ptr1 == ptr2) {
        printf("ポインタは等しいです\n");
    } else {
        printf("ポインタは等しくありません\n");
    }

// voidポインタから任意の型への変換は未定義動作
	int intValue = 42;
    
    // 整数をポインタに変換
    void *ptr = (void *)intValue;

    // ポインタを逆参照（実際の型が不明なため注意が必要）
    printf("変換されたポインタが指す値: %d\n", *(int *)ptr);

    return 0;
}
