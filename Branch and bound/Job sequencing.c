#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b) {
    return (*(int*)b) - (*(int*)a);
}

int findMaxDeadline(int arr[], int n) {
    int maxDeadline = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] > maxDeadline) {
            maxDeadline = arr[i];
        }
    }
    return maxDeadline;
}

void jobSequencing(int deadlines[], int profits[], int n) {
    qsort(profits, n, sizeof(int), compare);

    int maxDeadline = findMaxDeadline(deadlines, n);
    int timeSlots[maxDeadline];
    int jobSequence[maxDeadline];

    for (int i = 0; i < maxDeadline; i++) {
        timeSlots[i] = -1;
    }

    for (int i = 0; i < n; i++) {
        for (int j = deadlines[i] - 1; j >= 0; j--) {
            if (timeSlots[j] == -1) {
                timeSlots[j] = i + 1;
                jobSequence[j] = profits[i];
                break;
            }
        }
    }

    int totalProfit = 0;
    printf("Job Sequence: ");
    for (int i = 0; i < maxDeadline; i++) {
        if (timeSlots[i] != -1) {
            printf("%d ", timeSlots[i]);
            totalProfit += jobSequence[i];
        }
    }

    printf("\nTotal Profit: %d\n", totalProfit);
}

int main() {
    int n;
    printf("Enter the number of jobs: ");
    scanf("%d", &n);

    int deadlines[n];
    int profits[n];
    for (int i = 0; i < n; i++) {
        printf("Enter the deadline and profit for Job %d: ", i + 1);
        scanf("%d %d", &deadlines[i], &profits[i]);
    }

    jobSequencing(deadlines, profits, n);

    return 0;
}

