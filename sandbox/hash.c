#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// 連想配列の要素を表す構造体
typedef struct s_hashmap {
	const char			*key;
	const char			**value;
	struct s_hashmap	*next;
}	t_hashmap;

// // 連想配列を初期化する関数
// void initAssocArray(AssocArray *array, const char *key, char **values, int size) {
//     array->key = strdup(key);
//     array->values = (char **)malloc(size * sizeof(char *));
//     for (int i = 0; i < size; i++) {
//         array->values[i] = strdup(values[i]);
//     }
//     array->size = size;
// }

// // 連想配列の内容を表示する関数
// void printAssocArray(AssocArray *array) {
//     printf("{%s: [", array->key);
//     for (int i = 0; i < array->size; i++) {
//         printf("%s", array->values[i]);
//         if (i < array->size - 1) printf(", ");
//     }
//     printf("]}\n");
// }

// // メモリを解放する関数
// void freeAssocArray(AssocArray *array) {
//     free(array->key);
//     for (int i = 0; i < array->size; i++) {
//         free(array->values[i]);
//     }
//     free(array->values);
// }

t_hashmap	init_hashmap()
{
	t_hashmap	hashmap;

	hashmap.key = NULL;
	hashmap.value = NULL;
	hashmap.next = NULL;
	return (hashmap);
}

#include <stdio.h>
void	print_hashmap(t_hashmap *hashmap)
{
	if (hashmap != NULL)
	{
		while (hashmap->key != NULL)
		{
			printf("key:   %s\n", hashmap->key);
			// printf("value: %s\n", hashmap->value);
			hashmap = hashmap->next;
		}
		// printf("key:   %s\n", hashmap->key);
	}
}

int main() {
    // サンプルのキーと値
    t_hashmap hash1;
    t_hashmap hash2;

	hash1 = init_hashmap();
	hash1.key = "1 key";
	// hash1.value = "1 value";
	hash2 = init_hashmap();
	hash2.key = "2 key";
	// hash2.value = "2 value";
	hash1.next = &hash2;
	print_hashmap(&hash1);
    return 0;
}
