#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_SIGNALS 4
#define MAX_CYCLES 5

void displaySignals(int congestion[], int greenIndex) {
    printf("\nSignal Status:\n");
    for (int i = 0; i < NUM_SIGNALS; i++) {
        if (i == greenIndex) {
            printf("Signal %d : GREEN (Congestion = %d)\n", i + 1, congestion[i]);
        } else {
            printf("Signal %d : RED   (Congestion = %d)\n", i + 1, congestion[i]);
        }
    }
}

int findMaxCongestion(int congestion[]) {
    int maxIndex = 0;
    for (int i = 1; i < NUM_SIGNALS; i++) {
        if (congestion[i] > congestion[maxIndex]) {
            maxIndex = i;
        }
    }
    return maxIndex;
}

int main() {
    int congestion[NUM_SIGNALS];
    srand(time(NULL));

    printf("SMART CITY TRAFFIC SIGNAL SYNCHRONIZATION\n");
    printf("=======================================\n");

    for (int cycle = 1; cycle <= MAX_CYCLES; cycle++) {

        printf("\nCycle %d\n", cycle);
        printf("-----------------------------\n");

        for (int i = 0; i < NUM_SIGNALS; i++) {
            congestion[i] = rand() % 100;
        }

        int greenSignal = findMaxCongestion(congestion);
        displaySignals(congestion, greenSignal);

        printf("Green signal allocated to Signal %d\n", greenSignal + 1);
    }

    printf("\nSimulation Finished Successfully.\n");
    return 0;
}
