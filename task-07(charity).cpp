#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_CHARITIES 3

struct Charity 
{
    char name[50];
    float totalDonation;
};

// Function prototypes
void setupCharities(struct Charity charities[]);
void recordDonation(struct Charity charities[], float donation, int choice);
void showTotals(struct Charity charities[]);

int main()
 {
    struct Charity charities[NUM_CHARITIES];
    float shoppingBill;
    int choice;

    // Initialize charities and totals
    setupCharities(charities);

    while (1) 
	{
        printf("\nEnter charity choice (1, 2, 3) or -1 to show totals: ");
        scanf("%d", &choice);

        if (choice == -1) 
		{
            // Show totals and exit loop
            showTotals(charities);
            break;
        } else if (choice < 1 || choice > NUM_CHARITIES) 
		{
            printf("Invalid choice. Please choose 1, 2, 3 or -1 to show totals.\n");
            continue;
        }

        printf("Enter the value of the customer's shopping bill: ");
        scanf("%f", &shoppingBill);

        // Record donation for the chosen charity
        recordDonation(charities, shoppingBill * 0.01, choice);
    }

    return 0;
}

// Set up the donation system
void setupCharities(struct Charity charities[]) 
{
    printf("Enter names for three charities:\n");
    for (int i = 0; i < NUM_CHARITIES; ++i) 
	{
        printf("Charity %d: ", i + 1);
        scanf("%s", charities[i].name);
        charities[i].totalDonation = 0.0;
    }

    printf("\nCharities:\n");
    for (int i = 0; i < NUM_CHARITIES; ++i) 
	{
        printf("%d. %s\n", i + 1, charities[i].name);
    }
}

// Record and total each donation
void recordDonation(struct Charity charities[], float donation, int choice) 
{
    choice--; // Adjusting choice to match array index
    charities[choice].totalDonation += donation;
    printf("Donation of $%.2f recorded for %s\n", donation, charities[choice].name);
}

// Show the totals so far
void showTotals(struct Charity charities[]) 
{
    printf("\nTotals Donated:\n");
    
    // Sort charities by total donation (simple bubble sort)
    for (int i = 0; i < NUM_CHARITIES - 1; ++i) 
	{
        for (int j = 0; j < NUM_CHARITIES - i - 1; ++j) 
		{
            if (charities[j].totalDonation < charities[j + 1].totalDonation) 
			{
                struct Charity temp = charities[j];
                charities[j] = charities[j + 1];
                charities[j + 1] = temp;
            }
        }
    }

    // Display totals in descending order
    for (int i = 0; i < NUM_CHARITIES; ++i) 
	{
        printf("%s: $%.2f\n", charities[i].name, charities[i].totalDonation);
    }

    // Calculate grand total
    float grandTotal = 0;
    for (int i = 0; i < NUM_CHARITIES; ++i)
	 {
        grandTotal += charities[i].totalDonation;
    }

    printf("\nGRAND TOTAL DONATED TO CHARITY: $%.2f\n", grandTotal);
}

