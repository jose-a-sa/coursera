#include <stdio.h>
#include <string.h>
#include "utils.h"

int mod(const int x, const int m)
{
    return (x % m + m) % m;
}

void error(const char * msg)
{
    fprintf(stderr, "ERROR: %s", msg);
    exit(EXIT_FAILURE);
}

char *abs_path(char *rel)
{
    char *pwd = getenv("PWD");
    size_t n_pwd = strlen(pwd);
    size_t n_rel = strlen(rel);

    char *res;
    if ((res = (char *)malloc((n_pwd + n_rel + 2) * sizeof(char))) == NULL)
        error("failed to malloc char pointer in abs_filepath");

    strcat(res, pwd);
    strcat(res, "/");
    strcat(res, rel);
    res[n_pwd + n_rel + 1] = '\0';

    return res;
}

bits_t *bitarray_init(size_t n)
{
    bits_t *a;
    if ((a = (bits_t *)malloc(sizeof(bits_t))) == NULL)
        error("failed to malloc bits_t pointer in bitarray_init");

    a->stride = 8 * sizeof(bitblock_t);
    a->blocks = n / (a->stride) + (n % (a->stride) > 0);

    if ((a->bits = (bitblock_t *)calloc(a->blocks, a->stride / 8)) == NULL)
        error("failed to malloc bitblock_t pointer in bitarray_init");

    for (size_t i = 0; i < a->blocks; i++)
        a->bits[i] = (bitblock_t)0;

    return a;
}

void bitarray_set(bits_t *a, size_t k, bool bit)
{
    bitblock_t mask = 1 << (k % (a->stride));
    if (bit)
        a->bits[k / a->stride] |= mask;
    else
        a->bits[k / a->stride] &= ~(mask);
}

bool bitarray_get(bits_t *a, size_t k)
{
    bitblock_t mask = 1 << (k % a->stride);
    bool res = (a->bits[k / a->stride] & mask) != 0;
    return res;
}

void bitblock_print(bitblock_t x)
{
    bitblock_t num = x;
    size_t size = 8 * sizeof(bitblock_t);
    bitblock_t mask = 1 << (size - 1);
    for (size_t i = 0; i < size; i++)
    {
        printf("%u", num & mask ? 1 : 0);
        num = num << 1;
    }
}

void print_array_int(const int * a, const size_t n, const char * eol)
{
    printf("{");

    if (n == 0)
    {
        printf("}%s", eol);
        return;
    }

    int i;
    for (i = 0; i < n - 1; i++)
        printf("%d, ", a[i]);
    printf("%d}%s", a[i], eol);
}

int *sub_array_int(const int * a, const size_t l, const size_t r)
{
    if (l > r)
        error("left pointer is greater than right pointer");

    size_t n = r - l;

    int *copy;
    if ((copy = (int *)calloc(n, sizeof(int))) == NULL)
        error("failed to alloc arrayIntSubCopy");

    memcpy(copy, &a[l], n * sizeof(int));

    return copy;
}

int *array_int_copy(const int * a, const size_t n)
{
    return sub_array_int(a, 0, n);
}

char *padright(const char * x, const char p, const size_t m)
{
    const size_t nx = strlen(x);
    char *z;
    if ((z = (char *)calloc(nx + m + 1, sizeof(char))) == NULL)
        error("failed alloc of char pointer in padright");

    memcpy(z, &x[0], nx * sizeof(char));
    memset(&z[nx], p, m);
    z[nx + m] = '\0';

    return z;
}

char *padleft(const char * x, const char p, const size_t m)
{
    const size_t nx = strlen(x);
    char *z;
    if ((z = (char *)calloc(nx + m + 1, sizeof(char))) == NULL)
        error("failed alloc of char pointer in padleft");

    memset(z, p, m);
    memcpy(&z[m], x, nx * sizeof(char));
    z[nx + m] = '\0';

    return z;
}

char *substring(const char * x, const size_t l, const size_t r)
{
    if (l > r)
        error("left pointer is greater than right pointer");

    const size_t n = r - l;
    char *z;
    if ((z = (char *)calloc(n + 1, sizeof(char))) == NULL)
        error("failed alloc of char pointer in substring");

    memcpy(z, &x[l], n * sizeof(char));
    z[n] = '\0';

    return z;
}
