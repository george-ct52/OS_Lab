#include <stdio.h>

// Function to read a matrix
void readmatrix(int n, int m, int matrix[20][20]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
}

// Function to print a matrix
void printmatrix(int n, int m, int matrix[20][20]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to read an array
void readarray(int n, int array[20]) {
    for (int i = 0; i < n; i++) {
        scanf("%d", &array[i]);
    }
}

// Function to calculate the Need matrix
void NeedMatrix(int n, int m, int alloc[20][20], int max[20][20], int need[20][20]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }
}

// Function to check if the system is in a safe state
int issafe(int n, int m, int alloc[20][20], int avail[20], int need[20][20], int safeseq[20]) {
    int finish[n]; // to store the completion status of processes
    int work[m];   // to store the available resources temporarily

    // Initialize finish array to false and copy available resources to work
    for (int i = 0; i < n; i++) {
        finish[i] = 0;
    }
    for (int i = 0; i < m; i++) {
        work[i] = avail[i];
    }

    int count = 0; // to keep track of the number of processes in the safe sequence

    // Main loop to find a safe sequence
    while (count < n) {
        int found = 0;
        for (int i = 0; i < n; i++) {
            if (finish[i] == 0) {
                int flag = 1;
                for (int j = 0; j < m; j++) {
                    if (need[i][j] > work[j]) {
                        flag = 0;
                        break;
                    }
                }
                if (flag == 1) {
                    for (int k = 0; k < m; k++) {
                        work[k] += alloc[i][k];
                    }
                    safeseq[count++] = i;
                    finish[i] = 1;
                    found = 1;
                }
            }
        }
        if (found == 0) {
            return 0; // Not safe
        }
    }
    return 1; // Safe
}

int main() {
    int n, m;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("Enter the number of resources: ");
    scanf("%d", &m);

    int alloc[20][20], max[20][20], avail[20], need[20][20], safeseq[20];

    printf("Enter the Allocation matrix: \n");
    readmatrix(n, m, alloc);

    printf("Enter the Max matrix: \n");
    readmatrix(n, m, max);

    printf("Enter the Available matrix: \n");
    readarray(m, avail);

    // Calculate the Need matrix
    NeedMatrix(n, m, alloc, max, need);

    // Display the Need matrix
    printf("The Need matrix is: \n");
    printmatrix(n, m, need);

    // Check if the system is in a safe state and print the safe sequence if it is
    if (issafe(n, m, alloc, avail, need, safeseq)) {
        printf("The system is in a safe state.\nSafe sequence is: ");
        for (int i = 0; i < n; i++) {
            printf("P%d ", safeseq[i]);
        }
        printf("\n");
    } else {
        printf("The system is not in a safe state.\n");
    }

    return 0;
}
