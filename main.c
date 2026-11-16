#include "rle.h"


int comparer_chaines(const char *s1, const char *s2)
{
        int i = 0;
        while(s1[i] == s2[i] && s1[i] != '\0'){
            i++;
        }
        return(s1[i] == s2[i]);
}

int main(int argc, char *argv[])
{
    char resultat[MAX_LEN];
    int longueur;
    // vérification des arguments
    if(argc != 3)
    {
        write(2, "Erreur: nombre d'argument invalide\n", sizeof("Erreur: nombre d'argument invalide\n") - 1);
        return(1);
    }

    if(comparer_chaines(argv[1], "compress"))
    {
        longueur = ft_rle_compress(argv[2], resultat);

        if (longueur == -1)
        {
            write(2, "Erreur de compression\n", sizeof("Erreur de compression\n") - 1);
            return(1);
        }
        write(1, resultat, longueur);
        write(1, "\n", 1);
    }
    else if (comparer_chaines(argv[1], "decompress"))
    {
        longueur = ft_rle_decompress(argv[2], resultat);
        if(longueur == -1)
        {
            write(2, "Erreur de décompression\n", sizeof("Erreur de décompression\n") - 1 );
            return(1);
        }
        write(1, resultat, longueur);
        write(1, "\n", 1);
    }
    else{
        write(2, "Erreur: operation invalide\n", 27);
        return (1);
    }

    return(0);
}
