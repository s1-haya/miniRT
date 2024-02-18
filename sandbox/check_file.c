#include <stdio.h>
#include <string.h>

// ファイル名の拡張子が .rt であるかどうかをチェックする関数
int checkExtension(const char *filename) {
    const char *dot = strrchr(filename, '.'); // ファイル名から最後のドットを検索
    if (!dot || dot == filename) {
        // ドットが見つからない、またはファイル名の最初にある場合は、拡張子なし
        return 0;
    }
    return strcmp(dot, ".rt") == 0; // 拡張子が .rt であるかをチェック
}

int main() {
    char filename[256];

    // ユーザーにファイル名を入力させる
    printf("Enter the filename to process: ");
    scanf("%255s", filename);

    // 拡張子のチェック
    if (checkExtension(filename)) {
        printf("Processing file: %s\n", filename);
        // ファイル処理のロジックをここに追加
    } else {
        printf("Error: Only .rt files are supported.\n");
    }

    return 0;
}
