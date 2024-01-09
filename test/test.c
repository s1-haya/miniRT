#include <stdio.h>

typedef struct {
    double x;
    double y;
    double z;
} Vector3D;

Vector3D convert_2D_to_3D(int x_screen, int y_screen, int screen_width, int screen_height) {
    double x_normalized = 2 * (double)x_screen / screen_width - 1.0;
    double y_normalized = -2 * (double)y_screen / screen_height + 1.0;

    // 任意の三次元座標系の範囲にマッピング
    double x_3d = x_normalized;
    double y_3d = y_normalized;
    double z_3d = 0;

    Vector3D result = { x_3d, y_3d, z_3d };
    return result;
}

int main() {
    int screen_width = 512; // スクリーンの幅
    int screen_height = 512; // スクリーンの高さ
    int x_screen = 511; // スクリーン X 座標
    int y_screen = 511; // スクリーン Y 座標

    Vector3D coordinates_3D = convert_2D_to_3D(x_screen, y_screen, screen_width - 1, screen_height - 1);

    printf("2D coordinates (%d, %d) converted to 3D coordinates: (%.2f, %.2f, %.2f)\n",
        x_screen, y_screen, coordinates_3D.x, coordinates_3D.y, coordinates_3D.z);

    return 0;
}
