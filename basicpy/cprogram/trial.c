#include <stdio.h>

// Define an enumerated type for days of the week
enum Weekday {
    SUNDAY,
    MONDAY,
    TUESDAY,
    WEDNESDAY,
    THURSDAY,
    FRIDAY,
    SATURDAY
};

int main() 
    // Declare a variable of ty
    enum Weekday today;
    int day;


    printf("Enter a number (0-6) for the day of the week (0 for Sunday, 1 for Monday, etc.): ");
    scanf("%d", &day);

    // Assign the user input to the enum variable
    today = day;

    // Use an if statement to check the value of the variable
    if (today == WEDNESDAY) {
        printf("It's Wednesday! Halfway through the week.\n");
    } else if (today == MONDAY) {
        printf("It's Monday! Start of the week.\n");
    } else if (today == FRIDAY) {
        printf("It's Friday! Almost the weekend.\n");
    } else {
        printf("It's some other day.\n");
    }

    return 0;


