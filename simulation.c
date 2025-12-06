#include <stdio.h>
#include <string.h>

#define MAX_ITEMS 50

struct Food {
    char name[50];
    int calories;
};

int main() {
    char name[50], gender;
    int age, i, n;
    float height, weight, bmr, dailyLimit;
    struct Food items[MAX_ITEMS];
    int totalCalories = 0;

    printf("======= CALORIE COUNTER SYSTEM =======\n");

    // Taking personal information
    printf("Enter your name: ");
    scanf("%s", name);
    printf("Enter gender (M/F): ");
    scanf(" %c", &gender);
    printf("Enter age: ");
    scanf("%d", &age);
    printf("Enter height in cm: ");
    scanf("%f", &height);
    printf("Enter weight in kg: ");
    scanf("%f", &weight);

    // Asking user choice
    int choice;
    printf("\nDo you want calorie limit to be:\n1. Automatically calculated\n2. Enter manually\nEnter choice: ");
    scanf("%d", &choice);

    if (choice == 1) {
        // Harris–Benedict Formula
        if (gender == 'M' || gender == 'm') {
            bmr = 66 + (13.7 * weight) + (5 * height) - (6.8 * age);
        } else {
            bmr = 655 + (9.6 * weight) + (1.8 * height) - (4.7 * age);
        }

        // Moderate activity factor
        dailyLimit = bmr * 1.55;
        printf("\nYour calculated daily calorie limit is: %.2f calories\n", dailyLimit);

    } else {
        printf("Enter your daily calorie limit: ");
        scanf("%f", &dailyLimit);
    }

    // Taking food items
    printf("\nHow many food items did you eat today? ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("\nEnter food item %d name: ", i + 1);
        scanf("%s", items[i].name);
        printf("Enter calories for %s: ", items[i].name);
        scanf("%d", &items[i].calories);

        totalCalories += items[i].calories;
    }

    // Final report
    printf("\n============ DAILY CALORIE REPORT ============\n");
    printf("Name: %s\n", name);
    printf("Daily Calorie Limit: %.2f\n", dailyLimit);
    printf("Total Calories Consumed: %d\n", totalCalories);

    if (totalCalories > dailyLimit) {
        printf("\n⚠ You exceeded your calorie limit by %.2f calories!\n", 
               totalCalories - dailyLimit);
    } else {
        printf("\n You can still eat %.2f calories.\n",
               dailyLimit - totalCalories);
    }

    printf("==============================================\n");

    return 0;
}