SMART CITY TRAFFIC SYNCHRONIZATION – FULL PROJECT REPORT

1.	PROJECT OVERVIEW

Modern smart cities rely on intelligent and interconnected systems to efficiently manage transportation and reduce congestion. One critical component is the traffic signal network, which must operate in a synchronized manner to ensure smooth vehicle movement. Traditional standalone traffic controllers cause inefficiency, delays, and increased congestion. This project focuses on designing a distributed process synchronization model for coordinating multiple traffic controllers using semaphores or mutual exclusion principles.

The project simulates a smart city traffic network where multiple signal controllers communicate and adjust their timings based on live congestion data. The major concern addressed is race conditions – situations where multiple controllers try to update timing data simultaneously, leading to inconsistent or unsafe traffic light behavior. The solution is to implement a robust synchronization mechanism ensuring only one controller updates shared traffic data at a time.

Expected outcomes:
•	A working C simulation of multiple processes controlling traffic signals.
•	Semaphore-based locking to prevent race conditions.
•	Modular architecture demonstrating smart city traffic synchronization.
•	Documentation, diagrams, and version-controlled GitHub repository with 7+ revisions.

Scope:
•	Distributed systems concepts – processes, synchronization, semaphores.
•	Simulation of traffic intersections.
•	Synchronization algorithm design.
•	Output visualization on terminal.
(not included: hardware implementation, real sensor integration)

---

2.	MODULE-WISE BREAKDOWN

Module 1: Traffic Data Simulation Purpose:
Simulates traffic flow at multiple intersections. Generates vehicle count or congestion levels.
 
Responsibilities:
•	Generate random or fixed congestion data.
•	Provide input to the synchronization module.
•	Represent each traffic signal controller as a process/thread.

Module 2: Synchronization Engine Purpose:
Prevent race conditions and ensure consistent timing updates.

Responsibilities:
•	Use semaphores or mutex locks to control access.
•	Allow only one controller to update global timing values.
•	Manage critical section for safe updates.

Module 3: Monitoring and Output Purpose:
Display updated signal states and timing logic.

Responsibilities:
•	Print final signal configuration for each intersection.
•	Show which process is currently in the critical section.
•	Provide logs or summary of synchronized operations.

---

3.	FUNCTIONALITIES

Module 1 Functionalities:
•	Generate traffic density values (0–100).
•	Assign initial timing to each signal.
•	Start multiple controller processes.
 
Module 2 Functionalities:
•	Implement semaphore initialization.
•	Lock/unlock critical section during updates.
•	Adjust green/red times based on congestion.

Module 3 Functionalities:
•	Display updated traffic logic to user.
•	Show controller activity sequence.
•	Print logs for debugging/race verification.

---

4.	TECHNOLOGY USED

Programming Language:
•	C

Libraries and Tools:
•	pthreads for multithreading
•	semaphores for synchronization
•	stdio.h, stdlib.h

Other Tools:
•	GitHub for version control
•	Git for workflow
•	ReportLab for PDF generation (documentation)
•	VS Code / GCC compiler

---

5.	FLOW DIAGRAM

Flow (described textually):
 
Traffic Inputs  Start Controllers  Lock Critical Section  Update Timings  Unlock  Next Controller  Final Output

---

6.	REVISION TRACKING ON GITHUB

Repository Name: smart-city-traffic-synchronization GitHub Link: (Insert Link)
Sample Revision Log:
1.	Initial project structure uploaded.
2.	Added base C simulation file.
3.	Implemented semaphore-based synchronization.
4.	Added documentation folder and README.
5.	Added full report and appendix files.
6.	Code optimization and cleanup.
7.	Final commit with diagram and formatting fixes.

Branches used:
•	main
•	feature/sync-module
•	feature/report-update

Pull Requests:
•	Merged synchronization branch into main.

---

7.	CONCLUSION AND FUTURE SCOPE

This project successfully demonstrates how distributed process synchronization can eliminate race conditions and ensure consistent traffic management in smart city environments. Using
semaphore-based mutual exclusion, multiple controllers operated safely without creating conflicting signal updates.
 
Future scope:
•	Integrate real-time IoT sensors.
•	Implement AI-based adaptive timing.
•	Build GUI for real-time traffic visualization.
•	Extend simulation to multiple city zones.

---

8.	REFERENCES

•	Silberschatz, Galvin – Operating System Concepts
•	Tanenbaum – Distributed Systems Principles
•	IEEE Smart City Traffic Management Papers
•	GCC and Linux Man Pages

---

APPENDIX A – AI GENERATED BREAKDOWN
1. Project Overview
The system simulates traffic signal synchronization at multiple intersections.
Its main goal is to minimize congestion and waiting time by dynamically adjusting signal timings based on real-time traffic data.
Key Points:
•	Modular design ensures scalability.
•	Uses C programming for simulation.
•	Simulates real-world traffic scenarios using loops and conditional logic.
________________________________________
2. Modules Breakdown
a) Signal Controller Module
•	Controls the timing cycles of traffic lights (Red, Yellow, Green).
•	Each signal has configurable time durations.
•	Handles the switching of signals in sequence for smooth flow.
Example Functionality:
•	Initialize signal durations
•	Switch signal after timer expires
•	Reset cycle after completion
________________________________________
b) Sensor Input Module
•	Simulates detection of vehicle density at intersections.
•	Inputs can be predefined or randomized for testing purposes.
•	Provides data for the Synchronization Engine to adjust timings.
Example Data Points:
•	Number of vehicles waiting
•	Arrival rate per lane
•	Traffic density thresholds
________________________________________
c) Synchronization Engine
•	Core logic that adjusts signal timings dynamically.
•	Ensures multiple intersections are synchronized to prevent traffic jams.
•	Uses traffic density data from Sensor Input Module.
Key Steps:
1.	Read traffic density from sensors
2.	Calculate optimal signal duration
3.	Adjust current signal cycle accordingly
4.	Maintain synchronization across intersections
________________________________________
d) Display Module
•	Outputs the current status of traffic signals in real time.
•	Can be displayed as console output or simple text-based interface.
•	Helps visualize how synchronization affects traffic flow.
Display Example:
Intersection 1: Green | Intersection 2: Red | Intersection 3: Green
________________________________________
3. Workflow / Logic Flow
1.	Start system and initialize all modules
2.	Read sensor inputs for traffic density
3.	Process data in Synchronization Engine
4.	Adjust signals for optimal flow
5.	Display signal status
6.	Repeat continuously
Flow Summary:
START → Read Sensors → Process Data → Adjust Signals → Display → LOOP
________________________________________
4. Benefits of AI-Generated Approach
•	Provides a clear understanding of each module and its role
•	Highlights dependencies between modules
•	Allows quick reference for debugging or extending the project
________________________________________
5. Notes for Implementation
•	Modular design allows adding more intersections easily
•	Can be extended to integrate hardware sensors instead of simulated data
•	Timer-based control ensures smooth and predictable signal switching

APPENDIX B – PROBLEM STATEMENT
“Distributed Process Synchronization for a Smart City Traffic Network – Traffic signals must synchronize with each other based on congestion. Multiple controllers create race conditions and inconsistent timings.”

APPENDIX C – SOLUTION / CODE
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
