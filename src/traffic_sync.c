#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h;
#include <sys/sem.h>
#include <sys/wait.h>
#include <time.h>

#define NUM_SIGNALS 3

void sem_lock(int semid) {
    struct sembuf sb = {0, -1, 0};
    semop(semid, &sb, 1);
}

void sem_unlock(int semid) {
    struct sembuf sb = {0, 1, 0};
    semop(semid, &sb, 1);
}

int main() {
    srand(time(NULL));

    int shmid = shmget(IPC_PRIVATE, NUM_SIGNALS * sizeof(int), IPC_CREAT | 0666);
    int *congestion = (int *) shmat(shmid, NULL, 0);

    int semid = semget(IPC_PRIVATE, 1, IPC_CREAT | 0666);
    semctl(semid, 0, SETVAL, 1);

    printf("\nSMART CITY TRAFFIC SIGNAL SYNCHRONIZATION SIMULATION\n\n");

    for (int i = 0; i < NUM_SIGNALS; i++) {
        pid_t pid = fork();

        if (pid == 0) {
            for (int t = 0; t < 5; t++) {

                sem_lock(semid);

                congestion[i] = rand() % 101;

                printf("Signal %d updated congestion → %d\n", i + 1, congestion[i]);

                int max = congestion[0];
                int maxIndex = 0;

                for (int j = 1; j < NUM_SIGNALS; j++) {
                    if (congestion[j] > max) {
                        max = congestion[j];
                        maxIndex = j;
                    }
                }

                if (i == maxIndex) {
                    printf(">>> Signal %d: GREEN (highest congestion: %d)\n\n", i + 1, congestion[i]);
                } else {
                    printf("Signal %d: RED (congestion: %d)\n\n", i + 1, congestion[i]);
                }

                sem_unlock(semid);

                sleep(1);
            }
            exit(0);
        }
    }

    for (int i = 0; i < NUM_SIGNALS; i++) {
        wait(NULL);
    }

    shmdt(congestion);
    shmctl(shmid, IPC_RMID, NULL);
    semctl(semid, 0, IPC_RMID);

    printf("Simulation Completed Successfully.\n");

    return 0;
}
