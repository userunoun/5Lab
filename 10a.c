#include <stdio.h>
#include <conio.h>
int main()
{
    int i, j, k, n, f, pf = 0, c = 0, rs[25], m[10];
    
    printf("\n Enter the length of reference string -- ");
    scanf("%d", &n);
    printf("\n Enter the reference string -- ");
    for (i = 0; i < n; i++){
        scanf("%d", &rs[i]);
    }
    printf("\n Enter no. of frames -- ");
    scanf("%d", &f);
    for (i = 0; i < f; i++){
        m[i] = -1;
    }
    printf("\n The Page Replacement Process is -- \n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < f; j++)
        {
            if (m[j] == rs[i])
                break;
        }
        if (j == f)
        {
            m[c++] = rs[i];
            pf++;
        }
        for (k = 0; k < f; k++){
            printf("\t%d", m[k]);
        }
        if (j == f){
            printf("\tPF No. %d", pf);
        }
        printf("\n");
        if (c == f){
            c = 0;
        }
    }
    printf("\n The number of Page Faults using FIFO are %d", pf);
}