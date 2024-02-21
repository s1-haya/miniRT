#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

char	**ft_split(char const *str, char c);

typedef struct s_minirt_list {
    char                *identifier;
    char                **value;
    struct s_minirt_list *next;
}   t_minirt_list;

t_minirt_list *one_line_to_minirt_list(const char *input, bool *result) {
	// ft_isspaceだと改行も含まれるためスペースのみにした
	while (*input == ' ')
		input++;
    char *first_space = strchr(input, ' ');
    if (!first_space) {
        *result = false;
        return NULL;
    }

    t_minirt_list *new_element = malloc(sizeof(t_minirt_list));
    if (!new_element) {
        *result = false;
        return NULL;
    }

    *result = true;
	printf("first space: %s\n", first_space);
    new_element->identifier = strndup(input, first_space - input);
	printf("identifer: %s\n", new_element->identifier);
	// printf("space %ss\n", first_space + 1);
    new_element->value = ft_split(first_space + 1, ' ');
    if (new_element->value[0] == NULL) {
        *result = false;
		free(new_element->identifier);
		free(new_element->value);
		free(new_element);
        return NULL;
    }
    new_element->next = NULL;
    return new_element;
}

#include <libc.h>
int main() {
    const char *input = "a          d  ";
    bool result;

    t_minirt_list *parsed = one_line_to_minirt_list(input, &result);
    if (result) {
        printf("identifier = \"%s\"\n", parsed->identifier);
        printf("value = [");
        for (int i = 0; parsed->value[i]; i++) {
            if (i > 0) printf(" ");
            printf("\"%s\"", parsed->value[i]);
        }
        printf("]\n");
    } else {
        printf("Failed to parse the string.\n");
    }

    // Cleanup
    if (parsed) {
        free(parsed->identifier);
        for (int i = 0; parsed->value[i]; i++) {
            free(parsed->value[i]);
        }
        free(parsed->value);
        free(parsed);
    }
	system("leaks -q a.out");
    return 0;
}
