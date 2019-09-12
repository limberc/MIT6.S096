#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>

#define ABSOLUTE_WIDTH 31
#define MANTISSA_WIDTH 23
#define EXPONENT_WIDTH 8
#define EXPONENT_MASK 0xffu
#define MANTISSA_MASK 0x007fffffu
#define EXPONENT_BIAS 127

union float_bits {
    float f;
    uint32_t bits;
};

void print_float(FILE *output, float f)
{
    union float_bits t;
    t.f = f;

    uint32_t sign_bit = (t.bits >> ABSOLUTE_WIDTH);
    uint32_t exponent = (t.bits >> MANTISSA_WIDTH) & EXPONENT_MASK;
    uint32_t mantissa = (t.bits & MANTISSA_MASK);

    if (sign_bit != 0)
    {
        fprintf(output, "-");
    }

    if (exponent > 2 * EXPONENT_BIAS)
    {
        fprintf(output, "Inf\n"); /* Infinity */
        return;
    }
    else if (exponent == 0)
    {
        fprintf(output, "0."); /* Zero or Denormal */
        exponent = (mantissa != 0) ? exponent + 1 : exponent;
    }
    else
    {
        fprintf(output, "1."); /* Usual */
    }

    for (int k = MANTISSA_WIDTH - 1; k >= 0; --k)
    {
        fprintf(output, "%d", (mantissa >> k) & 1);
    }

    if (exponent != 0 || mantissa != 0)
    {
        fprintf(output, " * 2^%d\n", (int)(exponent - EXPONENT_BIAS));
    }
}

int main()
{
    FILE *input = fopen("floating.in", "r"),
         *output = fopen("floating.out", "w");

    size_t N;
    float f;
    fscanf(input, "%zu", &N);
    for (size_t i = 0; i < N; ++i)
    {
        fscanf(input, "%f", &f);
        print_float(output, f);
    }

    fclose(input);
    fclose(output);
    return 0;
}