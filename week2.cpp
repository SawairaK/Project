#include <stdio.h>

// Constants
#define NUM_JOURNEYS 4
#define NUM_COACHES 6
#define SEATS_PER_COACH 80
#define TICKET_PRICE 25

// Function prototypes
void initializeData(int passengers[][NUM_JOURNEYS], int earnings[]);
void displayScreen(int passengers[][NUM_JOURNEYS], int earnings[]);
void purchaseTickets(int passengers[][NUM_JOURNEYS], int earnings[]);
void endOfDaySummary(int passengers[][NUM_JOURNEYS], int earnings[]);

int main() {
    // Data structures to store passenger count and earnings for each journey
    int passengers[NUM_COACHES][NUM_JOURNEYS] = {0};  // 2D array for passengers
    int earnings[NUM_JOURNEYS] = {0};  // Array for earnings

    // Task 1: Start of the day
    initializeData(passengers, earnings);

    // Continue booking until all tickets are sold
    while (1) {
        // Task 2: Purchasing tickets
        purchaseTickets(passengers, earnings);

        // Check if all tickets are sold
        int allTicketsSold = 1;
        for (int j = 0; j < NUM_JOURNEYS; ++j) {
            if (passengers[0][j] < NUM_COACHES * SEATS_PER_COACH) {
                allTicketsSold = 0;
                break;
            }
        }

        if (allTicketsSold) {
            printf("\nAll tickets are sold. Ending the booking.\n");
            break;
        }
    }

    // Task 3: End of the day
    endOfDaySummary(passengers, earnings);

    return 0;
}

// Function to initialize data at the start of the day
void initializeData(int passengers[][NUM_JOURNEYS], int earnings[]) {
    // Initialize passenger count and earnings arrays to zero
    for (int i = 0; i < NUM_COACHES; ++i) {
        for (int j = 0; j < NUM_JOURNEYS; ++j) {
            passengers[i][j] = 0;
        }
    }

    for (int i = 0; i < NUM_JOURNEYS; ++i) {
        earnings[i] = 0;
    }
}

// Function to display the screen with available tickets and earnings
void displayScreen(int passengers[][NUM_JOURNEYS], int earnings[]) {
    // Display train times, available tickets, and earnings
    printf("Train Times\tAvailable Tickets\tEarnings\n");
    for (int j = 0; j < NUM_JOURNEYS; ++j) {
        printf("%02d:00 - %02d:00\t", 9 + j * 2, 10 + j * 2);
        if (passengers[0][j] < NUM_COACHES * SEATS_PER_COACH) {
            printf("%d\t\t\t", NUM_COACHES * SEATS_PER_COACH - passengers[0][j]);
        } else {
            printf("Closed\t\t\t");
        }
        printf("$%d\n", earnings[j]);
    }
}

// Function to purchase tickets
void purchaseTickets(int passengers[][NUM_JOURNEYS], int earnings[]) {
    int numPassengers;
    int totalEarnings = 0;

    // Get user input for the number of passengers
    printf("Enter the number of passengers: ");
    scanf("%d", &numPassengers);

    // Calculate total earnings
    totalEarnings = numPassengers * TICKET_PRICE;

    // Display available trains and ask for the train choice
    displayScreen(passengers, earnings);
    printf("Enter the train number (1-4): ");
    int trainChoice;
    scanf("%d", &trainChoice);

    // Update passenger count and earnings
    passengers[0][trainChoice - 1] += numPassengers;
    earnings[trainChoice - 1] += totalEarnings;

    // Display updated screen
    displayScreen(passengers, earnings);

    printf("Tickets purchased successfully!\n");
}

// Function for end-of-day summary
void endOfDaySummary(int passengers[][NUM_JOURNEYS], int earnings[]) {
    // Display end-of-day summary
    printf("\nEnd of Day Summary\n");
    printf("Train Times\tTotal Passengers\tEarnings\n");

    int totalPassengers = 0;
    int totalEarnings = 0;
    int maxPassengers = 0;
    int maxPassengersIndex = 0;

    for (int j = 0; j < NUM_JOURNEYS; ++j) {
        printf("%02d:00 - %02d:00\t%d\t\t\t$%d\n", 9 + j * 2, 10 + j * 2, passengers[0][j], earnings[j]);

        // Calculate total passengers and earnings
        totalPassengers += passengers[0][j];
        totalEarnings += earnings[j];

        // Find the journey with the most passengers
        if (passengers[0][j] > maxPassengers) {
            maxPassengers = passengers[0][j];
            maxPassengersIndex = j;
        }
    }

    printf("\nTotal Passengers for the day: %d\n", totalPassengers);
    printf("Total Earnings for the day: $%d\n", totalEarnings);
    printf("Journey with the most passengers: %02d:00 - %02d:00\n", 9 + maxPassengersIndex * 2, 10 + maxPassengersIndex * 2);
}

