/* Prints a one-month reminder list */
/*
2. Improve the remind.c program of Section 13.5 in the following ways:
(a) Have the program print an error message and ignore a reminder if the corresponding
day is negative or larger than 31. Hint: Use the continue statement.
(b) Allow the user to enter a day, a 24-hour time, and a reminder. The printed reminder list
should be sorted first by day, then by time. (The original program allows the user to
enter a time, but it's treated as part of the reminder.)
(c) Have the program print a one-year reminder list. Require the user to enter days in the
form month/day.
*/
#include <stdio.h>
#include <string.h>

#define MAX_REMIND 50 /* maximum number of reminders */
#define MSG_LEN 60 /* max length of reminder message */

int read_line(char str[], int n);

int main(void)
{
    char reminders[MAX_REMIND][MSG_LEN + 3];
    char month_str[3], day_str[4], hour_str[4], min_str[4], msg_str[MSG_LEN + 1];
    int month, day, hour, min, i, j, num_remind = 0;

    for (;;) {
        if (num_remind == MAX_REMIND) {
            printf("No space left --\n");
            break;
        }

        printf("Enter a day (month/day), 24-hour time, and a reminder: ");
        scanf("%2d/%2d", &month, &day);
        if (month == 0)
            break;
        if (month < 0 || month > 12) {
            printf("Error: invalid month\nReminder ignored.\n");
            read_line(msg_str, MSG_LEN); // Clear input buffer
            continue;
        }
        if (day < 0 || day > 31) {
            printf("Error: invalid day\nReminder ignored.\n");
            read_line(msg_str, MSG_LEN); // Clear input buffer
            continue;
        }
        sprintf(month_str, "%02d", month);
        sprintf(day_str, "%02d", day);

        scanf("%2d:%2d", &hour, &min);
        sprintf(hour_str, "%02d", hour);
        sprintf(min_str, "%02d", min);

        read_line(msg_str, MSG_LEN);

        char new_key[9];
        char old_key[9];
        sprintf(new_key, "%02d%02d%02d%02d", month, day, hour, min);
        // Determine where "mm/dd and time" belongs
        for (i = 0; i < num_remind; i++) {
            strncpy(old_key, reminders[i], 8);
            old_key[8] = '\0';

            if (strcmp(new_key, old_key) < 0) {
                break;
            }
        }

        // Move all reminders below "mm/dd and time" down 1 position
        for (j = num_remind; j > i; j--)
            strcpy(reminders[j], reminders[j - 1]);

        strcpy(reminders[i], new_key);
        strcat(reminders[i], msg_str);

        num_remind++;
    }

    printf("\nMonth\tDay\tTime\tReminder\n");

    // Print out all reminders
    for (i = 0; i < num_remind; i++) {
        char day_str[3];
        char hour_str[3];
        char min_str[3];

        strncpy(month_str, reminders[i], 2);
        month_str[2] = '\0';
        strncpy(day_str, reminders[i] + 2, 2);
        day_str[2] = '\0';
        strncpy(hour_str, reminders[i] + 4, 2);
        hour_str[2] = '\0';
        strncpy(min_str, reminders[i] + 6, 2);
        min_str[2] = '\0';

        printf("%s\t%s\t%s:%s\t%s\n",
            month_str,
            day_str,
            hour_str,
            min_str,
            reminders[i] + 8);
    }

    return 0;
}

int read_line(char str[], int n)
{
    getchar();
    int ch, i = 0;
    while ((ch = getchar()) != '\n')
        if (i < n)
            str[i++] = ch;
    str[i] = '\0';
    return i;
}
