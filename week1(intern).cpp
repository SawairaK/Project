#include <stdio.h>
#include <stdlib.h>

#define MAX_ITEMS 3  // Maximum number of items to choose (1 case, 1 RAM, 1 HDD)

// Function to display the menu and get user's choice
int displayMenu(char category[], char itemCode[][3], char description[][50], float price[], int categorySize) {
    printf("\n%s:\n", category);
    for (int i = 0; i < categorySize; i++) {
        printf("%d: %s - %s ($%.2f)\n", i + 1, itemCode[i], description[i], price[i]);
    }

    int choice;
    do {
        printf("\nEnter the number of your choice (1-%d) or 0 to skip: ", categorySize);
        scanf("%d", &choice);

        // Check if the choice is within a valid range
        if (choice < 0 || choice > categorySize) {
            printf("Invalid choice. Please enter a number between 0 and %d.\n", categorySize);
        }
    } while (choice < 0 || choice > categorySize);

    // Return the index of the chosen item in the arrays
    return choice - 1;
}

// Function to update the price of the computer and display additional items, new total price, and discounts
void updateComputer(int chosenCase, int chosenRam, int chosenHDD, float* totalPrice) {
    // Arrays to store item information for additional categories
    char ssdItemCode[][3] = {"D1", "D2"};
    char ssdDescription[][50] = {"240 GB SSD", "480 GB SSD"};
    float ssdPrice[] = {59.99, 119.99};

    char secondHDDItemCode[][3] = {"E1", "E2", "E3"};
    char secondHDDDescription[][50] = {"1 TB HDD", "2 TB HDD", "4 TB HDD"};
    float secondHDDPrice[] = {49.99, 89.99, 129.99};

    char opticalItemCode[][3] = {"F1", "F2"};
    char opticalDescription[][50] = {"DVD/Blu-Ray Player", "DVD/Blu-Ray Re-writer"};
    float opticalPrice[] = {50.00, 100.00};

    char osItemCode[][3] = {"G1", "G2"};
    char osDescription[][50] = {"Standard Version", "Professional Version"};
    float osPrice[] = {100.00, 175.00};

    // Additional items and new total price
    int additionalItems[MAX_ITEMS];
    float additionalPrice = 0.0;

    // Ask the user if they want to purchase additional items
    printf("\nDo you want to purchase additional items? (1 for Yes, 0 for No): ");
    int purchaseAdditional;
    scanf("%d", &purchaseAdditional);

    if (purchaseAdditional == 1) {
        // Allow the customer to choose additional items
        for (int i = 0; i < MAX_ITEMS; i++) {
            if (i == 0) {
                additionalItems[i] = displayMenu("SSD", ssdItemCode, ssdDescription, ssdPrice, sizeof(ssdItemCode) / sizeof(ssdItemCode[0]));
            } else if (i == 1) {
                additionalItems[i] = displayMenu("Second Hard Disk Drive", secondHDDItemCode, secondHDDDescription, secondHDDPrice, sizeof(secondHDDItemCode) / sizeof(secondHDDItemCode[0]));
            } else if (i == 2) {
                additionalItems[i] = displayMenu("Optical Drive", opticalItemCode, opticalDescription, opticalPrice, sizeof(opticalItemCode) / sizeof(opticalItemCode[0]));
            } else {
                additionalItems[i] = displayMenu("Operating System", osItemCode, osDescription, osPrice, sizeof(osItemCode) / sizeof(osItemCode[0]));
            }

            // Update the additional price
            switch (i) {
                case 0:
                    additionalPrice += ssdPrice[additionalItems[i]];
                    break;
                case 1:
                    additionalPrice += secondHDDPrice[additionalItems[i]];
                    break;
                case 2:
                    additionalPrice += opticalPrice[additionalItems[i]];
                    break;
                case 3:
                    additionalPrice += osPrice[additionalItems[i]];
                    break;
                default:
                    break;
            }
        }

        // Update the total price
        *totalPrice += additionalPrice;

        // Display the additional items and new total price
        printf("\nAdditional items:\n");
        for (int i = 0; i < MAX_ITEMS; i++) {
            printf("Additional Item %d: %s - %s ($%.2f)\n", i + 1,
                   (i == 0) ? ssdItemCode[additionalItems[i]] :
                   (i == 1) ? secondHDDItemCode[additionalItems[i]] :
                   (i == 2) ? opticalItemCode[additionalItems[i]] : osItemCode[additionalItems[i]],
                   (i == 0) ? ssdDescription[additionalItems[i]] :
                   (i == 1) ? secondHDDDescription[additionalItems[i]] :
                   (i == 2) ? opticalDescription[additionalItems[i]] : osDescription[additionalItems[i]],
                   (i == 0) ? ssdPrice[additionalItems[i]] :
                   (i == 1) ? secondHDDPrice[additionalItems[i]] :
                   (i == 2) ? opticalPrice[additionalItems[i]] : osPrice[additionalItems[i]]);
        }

        // Calculate discount based on the number of additional items
        float discount = 0.0;
        if (MAX_ITEMS == 1) {
            discount = 0.05;  // 5% discount for one additional item
        } else if (MAX_ITEMS > 1) {
            discount = 0.10;  // 10% discount for two or more additional items
        }

        // Apply discount to the total price
        float discountAmount = *totalPrice * discount;
        *totalPrice -= discountAmount;

        // Display the discount and new total price
        printf("\nDiscount Applied: %.2f%%\n", discount * 100);
        printf("Amount of Money Saved: $%.2f\n", discountAmount);
        printf("New Total Price of the Computer: $%.2f\n", *totalPrice);
    }
}

int main() {
    // Arrays to store item information
    char caseItemCode[][3] = {"A1", "A2"};
    char caseDescription[][50] = {"A1 Compact", "Tower"};
    float casePrice[] = {75.00, 150.00};

    char ramItemCode[][3] = {"B1", "B2", "B3"};
    char ramDescription[][50] = {"8 GB", "16 GB", "32 GB"};
    float ramPrice[] = {79.99, 149.99, 299.99};

    char hddItemCode[][3] = {"C1", "C2", "C3"};
    char hddDescription[][50] = {"1 TB HDD", "2 TB HDD", "4 TB HDD"};
    float hddPrice[] = {49.99, 89.99, 129.99};

    // Variables to store user's choices
    int chosenCase, chosenRam, chosenHDD;

    // Display and get user's choice for each category
    chosenCase = displayMenu("Case", caseItemCode, caseDescription, casePrice, sizeof(caseItemCode) / sizeof(caseItemCode[0]));
    chosenRam = displayMenu("RAM", ramItemCode, ramDescription, ramPrice, sizeof(ramItemCode) / sizeof(ramItemCode[0]));
    chosenHDD = displayMenu("Main Hard Disk Drive", hddItemCode, hddDescription, hddPrice, sizeof(hddItemCode) / sizeof(hddItemCode[0]));

    // Calculate the total price
    float totalPrice = casePrice[chosenCase] + ramPrice[chosenRam] + hddPrice[chosenHDD];

    // Display the chosen items and total price
    printf("\nChosen items:\n");
    printf("Case: %s - %s ($%.2f)\n", caseItemCode[chosenCase], caseDescription[chosenCase], casePrice[chosenCase]);
    printf("RAM: %s - %s ($%.2f)\n", ramItemCode[chosenRam], ramDescription[chosenRam], ramPrice[chosenRam]);
    printf("Main Hard Disk Drive: %s - %s ($%.2f)\n", hddItemCode[chosenHDD], hddDescription[chosenHDD], hddPrice[chosenHDD]);

    printf("\nTotal Price of the Computer: $%.2f\n", totalPrice);

    // Update the computer and display additional items, new total price, and discounts
    updateComputer(chosenCase, chosenRam, chosenHDD, &totalPrice);

    // Display the final total price
    printf("\nFinal Total Price of the Computer: $%.2f\n", totalPrice);

    return 0;
}

