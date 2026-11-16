#include "rle.h"

#define MAX_LEN 256
int ft_rle_decompress(const char *src, char dest[MAX_LEN])
{
    int i = 0;
    int j = 0;

    while (src[i] != '\0')
    {
        int count = 0;

        if (!ft_is_digit(src[i]))
        {
            dest[0] = '\0';
            return -1;
        }

        while (ft_is_digit(src[i]))
        {
            int digit = src[i] - '0';

            if (count > (MAX_LEN - 1 - digit) / 10)
            {
                dest[0] = '\0';
                return -1;
            }

            count = count * 10 + digit;
            i++;
        }

        if (count == 0 || src[i] == '\0')
        {
            dest[0] = '\0';
            return -1;
        }

        char c = src[i];
        i++;

        if (j + count >= MAX_LEN)
        {
            dest[0] = '\0';
            return -1;
        }

        while (count > 0)
        {
            dest[j] = c;
            j++;
            count--;
        }
    }

    dest[j] = '\0';

    return j;
}
