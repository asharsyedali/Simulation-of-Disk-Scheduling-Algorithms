/* Disk Scheduling Algorithm Simulation */
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_REQUESTS 100
#define DISK_SIZE 200 // Default disk size from 0 to 199

void fcfs(int requests[], int n, int head);
void sstf(int requests[], int n, int head);
void scan(int requests[], int n, int head, int direction);
void look(int requests[], int n, int head, int direction);
void get_requests(int requests[], int *n, int *head);
void print_table(int total_movements, char *algorithm);

int main() {
    int requests[MAX_REQUESTS], n, head;
    int choice, direction;

    get_requests(requests, &n, &head);

    printf("Choose Disk Scheduling Algorithm:\n");
    printf("1. FCFS\n2. SSTF\n3. SCAN\n4. LOOK\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    if (choice == 3 || choice == 4) {
        printf("Enter direction (0 for left, 1 for right): ");
        scanf("%d", &direction);
    }

    switch (choice) {
        case 1: fcfs(requests, n, head); break;
        case 2: sstf(requests, n, head); break;
        case 3: scan(requests, n, head, direction); break;
        case 4: look(requests, n, head, direction); break;
        default: printf("Invalid choice!\n");
    }

    return 0;
}

void fcfs(int requests[], int n, int head) {
    int total_movements = 0;
    printf("FCFS Order: ");
    for (int i = 0; i < n; i++) {
        total_movements += abs(requests[i] - head);
        head = requests[i];
        printf("%d ", head);
    }
    printf("\n");
    print_table(total_movements, "FCFS");
}

void sstf(int requests[], int n, int head) {
    int total_movements = 0, done[MAX_REQUESTS] = {0};
    printf("SSTF Order: ");
    for (int i = 0; i < n; i++) {
        int min_dist = INT_MAX, idx = -1;
        for (int j = 0; j < n; j++) {
            if (!done[j] && abs(requests[j] - head) < min_dist) {
                min_dist = abs(requests[j] - head);
                idx = j;
            }
        }
        done[idx] = 1;
        total_movements += min_dist;
        head = requests[idx];
        printf("%d ", head);
    }
    printf("\n");
    print_table(total_movements, "SSTF");
}

void scan(int requests[], int n, int head, int direction) {
    int total_movements = 0, sorted[MAX_REQUESTS + 1], i, j;
    requests[n++] = head;
    for (i = 0; i < n; i++) sorted[i] = requests[i];
    for (i = 0; i < n - 1; i++)
        for (j = i + 1; j < n; j++)
            if (sorted[i] > sorted[j]) {
                int temp = sorted[i];
                sorted[i] = sorted[j];
                sorted[j] = temp;
            }

    int start = 0;
    while (sorted[start] < head) start++;

    printf("SCAN Order: ");
    if (direction == 1) {
        for (i = start; i < n; i++) {
            total_movements += abs(sorted[i] - head);
            head = sorted[i];
            printf("%d ", head);
        }
        total_movements += abs(DISK_SIZE - 1 - head);
        head = DISK_SIZE - 1;
        for (i = start - 1; i >= 0; i--) {
            total_movements += abs(sorted[i] - head);
            head = sorted[i];
            printf("%d ", head);
        }
    } else {
        for (i = start - 1; i >= 0; i--) {
            total_movements += abs(sorted[i] - head);
            head = sorted[i];
            printf("%d ", head);
        }
        total_movements += abs(head - 0);
        head = 0;
        for (i = start; i < n; i++) {
            total_movements += abs(sorted[i] - head);
            head = sorted[i];
            printf("%d ", head);
        }
    }
    printf("\n");
    print_table(total_movements, "SCAN");
}

void look(int requests[], int n, int head, int direction) {
    int total_movements = 0, sorted[MAX_REQUESTS], i, j;
    for (i = 0; i < n; i++) sorted[i] = requests[i];
    for (i = 0; i < n - 1; i++)
        for (j = i + 1; j < n; j++)
            if (sorted[i] > sorted[j]) {
                int temp = sorted[i];
                sorted[i] = sorted[j];
                sorted[j] = temp;
            }

    int start = 0;
    while (sorted[start] < head) start++;

    printf("LOOK Order: ");
    if (direction == 1) {
        for (i = start; i < n; i++) {
            total_movements += abs(sorted[i] - head);
            head = sorted[i];
            printf("%d ", head);
        }
        for (i = start - 1; i >= 0; i--) {
            total_movements += abs(sorted[i] - head);
            head = sorted[i];
            printf("%d ", head);
        }
    } else {
        for (i = start - 1; i >= 0; i--) {
            total_movements += abs(sorted[i] - head);
            head = sorted[i];
            printf("%d ", head);
        }
        for (i = start; i < n; i++) {
            total_movements += abs(sorted[i] - head);
            head = sorted[i];
            printf("%d ", head);
        }
    }
    printf("\n");
    print_table(total_movements, "LOOK");
}

void print_table(int total_movements, char *algorithm) {
    printf("Algorithm: %s, Total Head Movement: %d\n", algorithm, total_movements);
}

void get_requests(int requests[], int *n, int *head) {
    printf("Enter number of requests: ");
    scanf("%d", n);
    printf("Enter request sequence: ");
    for (int i = 0; i < *n; i++)
        scanf("%d", &requests[i]);
    printf("Enter initial head position: ");
    scanf("%d", head);
}
