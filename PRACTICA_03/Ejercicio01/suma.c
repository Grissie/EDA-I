#include <stdio.h>

void suma(int *v, int a, int b)
{
    int i;
    for(i=0; i<a; i++)
    {
        v[i] = v[i] + b;
    }
}
