#ifndef RLE_H
#define RLE_H

#include <unistd.h>
#include <stddef.h>

#define MAX_LEN 256

size_t ft_strlen(const char *s);
int ft_is_digit(char c);
int ft_rle_compress(const char *src, char dest[MAX_LEN]);
int ft_rle_decompress(const char *src,char dest [MAX_LEN]);

#endif
