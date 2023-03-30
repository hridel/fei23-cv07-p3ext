#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *f;
    int numElements;
    int num;

    f = fopen("hdata.bin", "rb");
    if (f == NULL)
    {
        printf("Soubor se nepodařilo otevřít.\n");
        exit(1);
    }

    fseek(f, 0, SEEK_END);
    numElements = ftell(f) / sizeof(int);
    printf("Počet čísel v souboru: %d\n", numElements);

    fseek(f, 0, SEEK_SET);
    fread(&num, sizeof(int), 1, f);
    printf("První prvek: %d\n", num);

    fseek(f, 9 * sizeof(int), SEEK_SET);
    fread(&num, sizeof(int), 1, f);
    printf("Desátý prvek: %d\n", num);

    fseek(f, 99 * sizeof(int), SEEK_SET);
    fread(&num, sizeof(int), 1, f);
    printf("Stý prvek: %d\n", num);

    fseek(f, 999 * sizeof(int), SEEK_SET);
    fread(&num, sizeof(int), 1, f);
    printf("Tisící prvek: %d\n", num);

    int evenCount[100] = {0};
    fseek(f, 0L, SEEK_SET);
    for (int i = 0; i < numElements; i++)
    {
        fread(&num, sizeof(int), 1, f);
        if (num % 2 == 0)
        {
            evenCount[num / 2]++;
        }
    }
    for (int i = 0; i < 100; i++)
    {
        if (evenCount[i] > 0)
        {
            printf("Frequency of %d: %dx\n", i * 2, evenCount[i]);
        }
    }
    fclose(f);

    return 0;
}
