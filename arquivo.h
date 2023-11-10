#include <go32.h>
#include <stdio.h>
#include <sys/farptr.h>
#include <stdio.h>
void printCharAt(char ch, int x, int y, char attributes);
void printStringAt(char *str, int x, int y, char attributes);
void printIntAt(int numero, int x, int y, char attributes);
void drawFrame(char *title, char attributes, int x, int y, int largura, int altura);