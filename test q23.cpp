#include <stdio.h>
#include <stdlib.h>

#define MAX_TRACKS 200
void sortRequests(int tracks[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (tracks[j] > tracks[j + 1]) {
                int temp = tracks[j];
                tracks[j] = tracks[j + 1];
                tracks[j + 1] = temp;
            }
        }
    }
}

void scan(int tracks[], int n, int start) {
    sortRequests(tracks, n);

    int headMovement = 0;
    int direction = 1; 
    int currentPosition = start;

    for (int i = 0; i < n; i++) {
        while (direction == 1 && tracks[i] < currentPosition) {
            printf("Move from track %d to track %d\n", currentPosition, currentPosition - 1);
            currentPosition--;
            headMovement++;
        }
        while (direction == -1 && tracks[i] > currentPosition) {
            printf("Move from track %d to track %d\n", currentPosition, currentPosition + 1);
            currentPosition++;
            headMovement++;
        }

        // If we reach the end, reverse direction
        if (direction == 1 && currentPosition == MAX_TRACKS - 1) {
            direction = -1;
        } else if (direction == -1 && currentPosition == 0) {
            direction = 1;
        }

        printf("Move from track %d to track %d\n", currentPosition, tracks[i]);
        headMovement += abs(tracks[i] - currentPosition);
        currentPosition = tracks[i];
    }

    printf("Total head movement = %d\n", headMovement);
}

int main() {
    int n, start;
    printf("Enter the number of track requests: ");
    scanf("%d", &n);

    if (n < 1) {
        printf("Invalid number of requests.\n");
        return 1;
    }

    printf("Enter the starting track number: ");
    scanf("%d", &start);

    if (start < 0 || start >= MAX_TRACKS) {
        printf("Invalid starting track number.\n");
        return 1;
    }

    int tracks[n];
    printf("Enter the track requests: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &tracks[i]);
        if (tracks[i] < 0 || tracks[i] >= MAX_TRACKS) {
            printf("Invalid track request.\n");
            return 1;
        }
    }

    scan(tracks, n, start);

    return 0;
}
