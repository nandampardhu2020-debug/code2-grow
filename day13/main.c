
#include <stdio.h>
int main() {
    int numPassengers, i, age;
    float distance, fare, totalFare = 0;
    char timeOfTravel;

    printf("=== SRM Smart Bus Fare Calculator ===\n");
    
    printf("Enter number of passengers: ");
    scanf("%d", &numPassengers);

    for(i = 1; i <= numPassengers; i++) {
        printf("\n--- Passenger %d Details ---\n", i);

        printf("Enter Distance in KM: ");
        scanf("%f", &distance);

        printf("Enter Age: ");
        scanf("%d", &age);

        printf("Enter Time of Travel (P for Peak / N for Non-Peak): ");
        scanf(" %c", &timeOfTravel);

        float ratePerKm;
        
        if (timeOfTravel == 'P' || timeOfTravel == 'p') {
            ratePerKm = 5.0;  // Peak hours
        } else {
            ratePerKm = 3.5;  // Non-peak hours
        }

        fare = distance * ratePerKm;

        if (age < 12) {
            fare *= 0.50;  // 50% discount
        } else if (age >= 60) {
            fare *= 0.70;  // 30% discount for senior citizens
        } else if (age >= 18 && age <= 25) {
            fare *= 0.80;  // 20% discount for university students
        }

        printf("Calculated Fare for Passenger %d: Rs %.2f\n", i, fare);
        totalFare += fare;
    }

    printf("\n========== SUMMARY REPORT ==========\n");
    printf("Total Passengers: %d\n", numPassengers);
    printf("Total Fare to be Collected: Rs %.2f\n", totalFare);
    printf("===================================\n");

    return 0;
}
