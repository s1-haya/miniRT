#include <stdbool.h> // 真偽値のために必要
#include <string.h> // strrchr, strncmp, strlen のために必要

bool is_target_file_extension(const char *filename, const char *extension) {
    const char *dot;

    if (!filename || !extension)
        return (false);
    
    dot = ft_strrchr(filename, '.'); // '.' の最後の出現を探す
    if (!dot || dot == filename) // ファイル名の先頭が '.' か、'.' がない場合は false
        return (false);
    
    // dot と extension を比較し、完全に一致する場合にのみ true を返す
    // ここで、extension の長さと比較することで、正確な一致を確認
    return (ft_strncmp(dot, extension, ft_strlen(extension) + 1) == 0); // +1 はヌル終端を含めるため
}
