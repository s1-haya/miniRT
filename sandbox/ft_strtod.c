#include <stdio.h>
#include <ctype.h>

#include <stdio.h>
#include <ctype.h>
#include <math.h>

double processIntegerPart(const char **str) {
    double result = 0.0;
    while (isdigit(**str)) {
        result = (result * 10.0) + (**str - '0');
        (*str)++;
    }
    return result;
}

double processFractionPart(const char **str) {
    double fraction = 0.1;
    double result = 0.0;
    if (**str == '.') {
        (*str)++;
        while (isdigit(**str)) {
            result += (**str - '0') * fraction;
            fraction *= 0.1;
            (*str)++;
        }
    }
    return result;
}

int processExponentPart(const char **str, double *expSign) {
    int exponent = 0;
    if (**str == 'e' || **str == 'E') {
        (*str)++;
        if (**str == '-') {
            *expSign = -1.0;
            (*str)++;
        } else if (**str == '+') {
            (*str)++;
        }
        while (isdigit(**str)) {
            exponent = (exponent * 10) + (**str - '0');
            (*str)++;
        }
    }
    return exponent;
}

double	ft_strtod(const char *str, char **endptr)
{
	double	result;
	double	sign; 
	double	expSign;
	int exponent;

	result = 0.0;
	sign = 1.0;
	expSign = 1.0;
	while (isspace(*str))
		str++;
	if (*str == '-') { sign = -1.0; str++; } else if (*str == '+') { str++; }

	result = processIntegerPart(&str);
	result += processFractionPart(&str);
	exponent = processExponentPart(&str, &expSign);

	if (endptr != NULL) *endptr = (char *)str;
	return (result * sign * pow(10.0, exponent * expSign));
}

int main() {
    // const char *str = " -123.456e-2";
    const char *str = " -0.34141";
    char *endptr;

    double value = ft_strtod(str, &endptr);

    printf("Converted value: %f\n", value);
    printf("Remaining string: %s\n", endptr);

    return 0;
}
