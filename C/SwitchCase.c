// Printing days of the week with input validation

#include <stdio.h>

int main() {
    int day;

    while (1) {  
        printf("Enter any day b/w 0 to 6: ");
        scanf("%d", &day);
        switch (day) {
            case 0: printf("Sunday\n"); return 0;
            case 1: printf("Monday\n"); return 0;
            case 2: printf("Tuesday\n"); return 0;
            case 3: printf("Wednesday\n"); return 0;
            case 4: printf("Thursday\n"); return 0;
            case 5: printf("Friday\n"); return 0;
            case 6: printf("Saturday\n"); return 0;
            case 7: printf("Sunday\n"); return 0;
            default:
                printf("Invalid choice. Please enter a number between 1 and 7.\n\n");
        }
    }

    return 0;
}