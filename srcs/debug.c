#include "minirt.h"
#include "vector.h"

void print_vector(t_vector vector, char *name) {
    printf("%s: (%f, %f, %f)\n",name, vector.x, vector.y, vector.z);
}
