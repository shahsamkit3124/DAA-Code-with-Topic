#include<stdio.h>
#include<conio.h>  

void knapsack(int num, float weight[], float profit[], float capacity)
{
    float x[20], tp = 0;
    int i, j, u;
    u = capacity;

    for (i = 0; i < num; i++)
        {
            x [i] = 0;
        }

    for (i = 0; i < num; i++)
        {
            if (weight[i] > u)
            break;
            else
            {
                x[i] = 1;
                tp = tp + profit[i];
                u = u - weight[i];
            }
        }
    if (i < num)
    x[i] = u / weight[i];
    tp = tp + (x[i] * profit[i]);
    printf("\nThe result vector is:- ");
    for (i = 0; i < num; i++)
    printf("%f\t", x[i]);
    printf("\nMaximum profit is:- %f", tp);
}

void main()
{
    int n;
    printf("Enter the number of items:");
    scanf("%d",&n);
    int profit[n],weight[n];
    float ppw[n],temp;
    printf("Enter the profits:");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&profit[i]);
    }
    printf("Enter the weights:");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&weight[i]);
    }    
    for(int i=0;i<n;i++)
    {
        ppw[i]=profit[i]/weight[i];
    }
    printf("Item No\t\t Profit\t\t Weight\t\t Profit per Weight\n");
    for(int i=0;i<n;i++)
    {
        printf("%d\t\t %d\t\t %d\t\t %f\n",i+1,profit[i],weight[i],ppw[i]);
    }
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(ppw[i]<ppw[j])
            {
                temp = ppw[j];
                ppw[j] = ppw[i];
                ppw[i] = temp;
                temp = profit[j];
                profit[j] = profit[i];
                profit[i] = temp;
                temp = weight[j];
                weight[j] = weight[i];
                weight[i] = temp;
            }
        }
    }
    printf("Item No\t\t Profit\t\t Weight\t\t Profit per Weight\n");
    for(int i=0;i<n;i++)
    {
        printf("%d\t\t %d\t\t %d\t\t %f\n",i+1,profit[i],weight[i],ppw[i]);
    }

    knapsack(n, weight, profit, capacity);
    getch();
}
