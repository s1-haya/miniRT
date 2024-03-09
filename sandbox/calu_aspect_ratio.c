#include <stdio.h>
#include <stdlib.h>

typedef struct s_view_port {
	size_t height;
	size_t width;
}	t_view_port;

size_t get_greatest_common_divisor(size_t a, size_t b)
{
	if (b == 0) 
		return (a);
	return (get_greatest_common_divisor(b, a % b));
}

t_view_port get_current_view_port_size(size_t height, size_t width, size_t aspect_ratio)
{
	t_view_port size;
	size.height = width / (aspect_ratio);
	size.width = height * (aspect_ratio);
	return (size);
}

t_view_port get_adjusted_view_port_size(size_t original_height, size_t original_width) {
	t_view_port size;
	size_t gcd = get_greatest_common_divisor(original_height, original_width);
	size_t aspect_height = original_height / gcd;
	size_t aspect_width = original_width / gcd;
	size.width = original_width; // Keep original width
	size.height = (original_width * aspect_height) / aspect_width; // Adjust height based on original width and aspect ratio
	return size;
}

int main(void)
{
	size_t height = 1000;
	size_t width = 1080;
	size_t gcd = get_greatest_common_divisor(height, width);
	size_t aspect_height = height / gcd;
	size_t aspect_width = width / gcd;
	printf("aspect ratio\nheight:width %zu:%zu\n", aspect_height, aspect_width);
	t_view_port view_port = get_current_view_port_size(height, width, (aspect_height / aspect_width));
	printf("view port size\nheight:width %zu:%zu\n", view_port.height, view_port.width);
	t_view_port adjusted_view_port = get_adjusted_view_port_size(height, width);
	printf("adjusted view port size\nheight:width %zu:%zu\n", adjusted_view_port.height, adjusted_view_port.width);
	return (0);
}
