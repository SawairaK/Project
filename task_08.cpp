#include <stdio.h>
#include <stdbool.h>

#define NUM_BOATS 10
#define OPEN_HOUR 10
#define CLOSE_HOUR 17
#define HOURLY_RATE 20
#define HALF_HOUR_RATE 12

typedef struct {
    int boatNumber;
    float totalHours;
    float moneyTaken;
    int returnTime;
} Boat;

void initializeBoats(Boat boats[]) {
    for (int i = 0; i < NUM_BOATS; ++i) {
        boats[i].boatNumber = i + 1;
        boats[i].totalHours = 0.0;
        boats[i].moneyTaken = 0.0;
        boats[i].returnTime = OPEN_HOUR;
    }
}

void hireBoat(Boat *boat, float duration) {
    boat->totalHours += duration;
    boat->moneyTaken += (duration >= 1.0) ? duration * HOURLY_RATE : duration * HALF_HOUR_RATE;
    boat->returnTime += duration;
}

void displayDailyStats(Boat boats[]) {
    float totalMoney = 0.0, totalHours = 0.0;
    int boatsNotUsed = 0, maxUsedBoat = 0;

    for (int i = 0; i < NUM_BOATS; ++i) {
        totalMoney += boats[i].moneyTaken;
        totalHours += boats[i].totalHours;

        if (boats[i].totalHours == 0) {
            boatsNotUsed++;
        }

        if (boats[i].totalHours > boats[maxUsedBoat].totalHours) {
            maxUsedBoat = i;
        }
    }

    printf("\nSummary of the day:\n");
    printf("Total money taken today: $%.2f\n", totalMoney);
    printf("Total hours hired today: %.2f\n", totalHours);
    printf("Boats not used today: %d\n", boatsNotUsed);
    printf("Boat used the most today: %d (Total hours: %.2f)\n", boats[maxUsedBoat].boatNumber, boats[maxUsedBoat].totalHours);
}

void printAvailableBoats(Boat boats[], int currentTime) {
    int availableBoats = 0;

    printf("\nAvailable boats at %d: ", currentTime);
    for (int i = 0; i < NUM_BOATS; ++i) {
        if (boats[i].returnTime <= currentTime) {
            printf("%d ", boats[i].boatNumber);
            availableBoats++;
        }
    }

    if (availableBoats == 0) {
        int earliestReturn = CLOSE_HOUR;
        for (int i = 0; i < NUM_BOATS; ++i) {
            if (boats[i].returnTime < earliestReturn) {
                earliestReturn = boats[i].returnTime;
            }
        }
        printf("\nNo boats available. Earliest available time: %d\n", earliestReturn);
    }
}

void performTask1(Boat boats[]) {
    printf("\nTASK 1 - Calculate the money taken for one boat:\n");
    int boatNum;
    float duration;

    printf("Enter boat number (1-10): ");
    scanf("%d", &boatNum);

    if (boatNum < 1 || boatNum > NUM_BOATS) {
        printf("Invalid boat number! Please enter a number between 1 and %d.\n", NUM_BOATS);
        return;
    }

    printf("Enter duration in hours: ");
    scanf("%f", &duration);

    if (duration <= 0) {
        printf("Invalid duration! Please enter a positive value.\n");
        return;
    }

    Boat *selectedBoat = &boats[boatNum - 1];
    hireBoat(selectedBoat, duration);
    printf("Money taken for boat %d today: $%.2f\n", selectedBoat->boatNumber, selectedBoat->moneyTaken);
    printf("Total hours hired for boat %d today: %.2f\n", selectedBoat->boatNumber, selectedBoat->totalHours);
}

void performTask2(Boat boats[]) {
    printf("\nTASK 2 - Find the next available boat:\n");
    int currentTime;

    printf("Enter current time (in 24-hour format): ");
    scanf("%d", &currentTime);

    if (currentTime < OPEN_HOUR || currentTime >= CLOSE_HOUR) {
        printf("Boat hire not available at this time!\n");
        return;
    }

    printAvailableBoats(boats, currentTime);
}

int main() {
    Boat boats[NUM_BOATS];
    initializeBoats(boats);

    performTask1(boats);
    performTask2(boats);

    displayDailyStats(boats);

    return 0;
}

