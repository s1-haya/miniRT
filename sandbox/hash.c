#include <stdio.h>

typedef struct s_hashmap {
    const char          *key;
    const char          **value;
    struct s_hashmap    *next;
}   t_hashmap;

void print_hashmap(t_hashmap *hashmap) {
    if (hashmap != NULL) {
        while (hashmap->next != NULL) {
            printf("key: %s\n", hashmap->key);
            hashmap = hashmap->next;
        }
		printf("key: %s\n", hashmap->key);
    }
}

void start(t_hashmap map) {
    print_hashmap(&map);
}

int main() {
    t_hashmap map;

    // mapの初期化
    map.key = "1 key";
    map.value = NULL; // この例では値は設定していません
    map.next = NULL; // 次の要素はありません
    t_hashmap map2;

    // mapの初期化
    map2.key = "2 key";
    map2.value = NULL; // この例では値は設定していません
    map2.next = NULL; // 次の要素はありません

	map.next = &(map2);
    start(map); // mapをstart関数に渡す

    return 0;
}
