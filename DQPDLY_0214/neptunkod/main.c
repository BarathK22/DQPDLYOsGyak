#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *F = fopen("barath.txt","w");
    fprintf(F,"Nev: Barath Kristof \nSzak: Mernokinformatikus \nNeptunkod: DQPDLY");
    fclose(F);
    return 0;
}
