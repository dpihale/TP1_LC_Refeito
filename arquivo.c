#include "arquivo.h"
#include <go32.h>
#include <stdio.h>
#include <sys/farptr.h>
#include <string.h>
#include <stdio.h>
void printCharAt(char ch, int x, int y, char attributes)
{
    unsigned long base = 0xB8000;
    unsigned long offset = 2 * (80 * x) + y * 2;
    if (x >= 0 && x < 80 && y >= 0 && y < 25)
    {
        _farpokeb(_dos_ds, base + offset, ch);
        _farpokeb(_dos_ds, base + offset + 1, attributes);
    }
     scanf("");
}

void printStringAt(char *str, int x, int y, char attributes)
{
    unsigned long base = 0xB8000;
    unsigned long offset = 2 * (80 * x) + y * 2;
    if (x >= 0 && x < 80 && y >= 0 && y < 25)
    {
        int i = 0;
        while (str[i])
        {
            printCharAt(str[i++], x, y++, attributes);
            offset += 2;
        }
    }
}

// void printIntAt(int numero, int x, int y, char attributes)
// {
//     char buffer[12];
//     snprintf(buffer, sizeof(buffer), "%d", numero);
//     printStringAt(buffer, x, y, attributes);
// }

void drawFrame(char *title, char attributes, int x, int y, int largura, int altura)
{
    if (x >= 0 && x < largura && y >= 0 && y < altura && largura > 0 && altura > 0)
    {
        int i;
        printCharAt('+', x, y, attributes);
        int titleLength = strlen(title);
        int titleX = x + (largura - titleLength) / 2;
        printStringAt(title, titleX, y, attributes);

        for (i = 1; i < largura - 1; i++)
        {
            printCharAt('-', x + i, y, attributes);
        }

        printCharAt('+', x + largura - 1, y, attributes);

        for (i = 1; i < altura - 1; i++)
        {
            printCharAt('|', x, y + i, attributes);
            printCharAt('|', x + largura - 1, y + i, attributes);
        }

        for (i = 1; i < largura - 1; i++)
        {
            printCharAt('-', x + i, y + altura - 1, attributes);
        }

        printCharAt('+', x, y + altura - 1, attributes);

        printCharAt('+', x + largura - 1, y + altura - 1, attributes);
    }
}
