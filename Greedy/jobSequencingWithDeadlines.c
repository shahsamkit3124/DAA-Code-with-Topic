#include<stdio.h>
#include<conio.h>
void main()
{
    int n;
    printf("Enter the number of jobs:");
    scanf("%d",&n);
    int deadline[n],profit[n],id[n],x[n],temp;
    printf("Enter the deadlines of the jobs:");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&deadline[i]);
    }
    printf("Enter the profits of the jobs:");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&profit[i]);
    }
    for(int i=0;i<n;i++)
    {
        id[i]=i+1;
    }

    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(profit[j]>profit[i])
            {
                temp=profit[j];
                profit[j]=profit[i];
                profit[i]=temp;

                temp=id[j];
                id[j]=id[i];
                id[i]=temp;

                temp=deadline[j];
                deadline[j]=deadline[i];
                deadline[i]=temp;
            }
        }
    }
    printf("No.\t Deadline\t Profit\n");
    for(int i=0;i<n;i++)
    {
        printf("%d\t %d\t\t %d\n",id[i],deadline[i],profit[i]);
    }
    int max=deadline[0];
    for(int i=0;i<n;i++)
    {
        if(max<deadline[i])
        {
            max=deadline[i];
        }
    }
    for(int i=0;i<max;i++)
    {
        x[i]=0;
    }
    for(int i=max-1;i>=0;i--)
    {
        for(int j=0;j<n;j++)
        {
            if(deadline[j]==i+1)
            {
                x[j]=id[j];
            }
        }
    }
    printf("The solution is:");
    for(int i=0;i<max;i++)
    {
        printf("%d\t",x[i]);
    }
}
