#include <stdio.h>

void optimal_storage(int tape_size, int n, int sizes[]) {
    int tape_count = 1;
    int tape_used = sizes[0];

    printf("Tape %d: %d", tape_count, sizes[0]);

    for (int i = 1; i < n; i++) {
        if (tape_used + sizes[i] <= tape_size) {
            tape_used += sizes[i];
            printf(" %d", sizes[i]);
        } else {
            tape_count++;
            tape_used = sizes[i];
            printf("\nTape %d: %d", tape_count, sizes[i]);
        }
    }
    printf("\n");
}

int main() {
    int tape_size = 50;
    int n = 8;
    int sizes[] = {10, 20, 30, 40, 25, 15, 35, 5};

    optimal_storage(tape_size, n, sizes);

    return 0;
}
