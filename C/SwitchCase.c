// Printing days of the week using loop and whenever there is wrong choice, prompt the user to enter again a day from 0 to 6
#include <stdio.h>
int main() {
    int day;
    while (1) {  
        printf("Enter any day b/w 0 to 6: ");
        scanf("%d", &day);
        switch (day) {
            case 0: printf("Sunday\n"); 
                break;
            case 1: printf("Monday\n"); 
                break;
            case 2: printf("Tuesday\n"); 
                break;
            case 3: printf("Wednesday\n"); 
                break;
            case 4: printf("Thursday\n"); 
                break;
            case 5: printf("Friday\n"); 
                break;
            case 6: printf("Saturday\n"); 
                break;
            default:
                printf("Invalid choice. Please enter a number between 0 and 6.\n\n");
                continue;
        }
        break;
    }
    return 0;
}