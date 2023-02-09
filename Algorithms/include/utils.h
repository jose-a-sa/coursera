#ifndef UTILS_H_
#define UTILS_H_

#include <stdlib.h>
#include <stdbool.h>

#define LEN(a) (size_t)(sizeof(a) / sizeof(a[0]))
#define MAX(a, b) ({ __typeof__ (a) _a = (a); __typeof__ (b) _b = (b); _a > _b ? _a : _b; })
#define MIN(a, b) ({ __typeof__ (a) _a = (a); __typeof__ (b) _b = (b); _a < _b ? _a : _b; })
#define FRAC(a, b) ({ __typeof__ (a) _a = (a); __typeof__ (b) _b = (b); ((1.0L * _a)/(1.0L * _b)); })

void error(const char *);
int mod(const int, const int);
char *abs_path(char *);

typedef uint32_t bitblock_t;
typedef struct bits_t
{
    size_t n;
    size_t stride;
    size_t blocks;
    bitblock_t *bits;
} bits_t;
bits_t *bitarray_init(size_t n);
void bitarray_set(bits_t *a, size_t k, bool bit);
bool bitarray_get(bits_t *a, size_t k);
void bitblock_print(bitblock_t);

void print_array_int(const int *, const size_t, const char *);
int *sub_array_int(const int *, const size_t, const size_t);
int *array_int_copy(const int *, const size_t);
char *substring(const char *, const size_t, const size_t);
char *padleft(const char *, const char, const size_t);
char *padright(const char *, const char, const size_t);

#endif /* UTILS_H_ */