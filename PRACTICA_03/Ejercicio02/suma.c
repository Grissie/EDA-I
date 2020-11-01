#include <stdio.h>

void suma(int w,float *a,float *b,float *c)
{
    int i;
    for(i=0; i<w; i++)
    {
        c[i] = a[i] + b[i];
    }
}
