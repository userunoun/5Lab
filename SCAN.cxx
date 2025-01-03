#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, t[100], head, k = 0, atr[100], sum = 0, p = 0;

    printf("\n Enter the number of tracks : ");
    scanf("%d", &n);

    printf("\n Enter the head position :");
    scanf("%d", &head);

    printf("\n Enter the Queue requests :");
    for (int i = 0; i < n; i++)
        scanf("%d", &t[i]);

    if (head != 0) t[n++] = 0;
    if (head != 199) t[n++] = head;

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (t[i] > t[j])
            {
                int temp = t[i];
                t[i] = t[j];
                t[j] = temp;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (t[i] == head)
        {
            k = i;
            break;
        }
    }

    for (int i = k; i >= 0; i--)
    {
        atr[p] = t[i];
        p++;
    }

    for (int i = k + 1; i < n; i++)
    {
        atr[p++] = t[i];
    }

    for (int i = 0; i < n - 1; i++)
    {
        sum += abs(atr[i + 1] - atr[i]);
    }

    printf("\n Traversed Disks are : \n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", atr[i]);
    }

    printf("\nHead movements : %d\n", sum);

    return 0;
}