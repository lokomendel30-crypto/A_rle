#include "rle.h"

#define MAX_LEN 256
int ft_rle_compress(const char *src, char dest[MAX_LEN])
{
    char temp[MAX_LEN];
    char digits[10];
    int i = 0;
    int j = 0;

    while (src[i] != '\0')
    {
        int count = 1;

        while (src[i] == src[i + 1])

        {
            count++;
            i++;
        }

        int n = count;
        int k = 0;

        do
        {
            digits[k] = '0' + (n % 10);
            k++;
            n = n/10;

        } while (n>0);

        if (j+k>= MAX_LEN)
        {
            dest[0] = '0';
            return -1;
        }

        while (k>0)
        {
            k--;
            temp[j] = digits[k];
            j++;
        }

        temp[j] = src[i];
        j++;
        i++;
    }

    temp[j] = '\0';

    i = 0;
    while (i <= j)
    {
        dest[i] = temp[i];
        i++;
    }

    return j;
}
