/* Maintains a parts database (array version) */
#include "readline.h"
#include <stdio.h>
#include <stdlib.h>

#define NAME_LEN 25

struct part {
    int number;
    char name[NAME_LEN + 1];
    int on_hand;
    double price;
};

int find_part(int number, int num_parts, struct part* inventory);
void insert(int* num_parts, struct part** inventory, int* max_parts);
void search(int num_parts, struct part* inventory);
void update(int num_parts, struct part* inventory);
void adjust(int num_parts, struct part* inventory);
void print(int num_parts, struct part* inventory);
int cmp_part(const void* a, const void* b);

/*************************************************************
 * main: Prompts the user to enter an operation code,        *
 *       then calls a function to perform the requested      *
 *       action. Repeats until the user enters the           *
 *       command ’q’. Prints an error message if the user    *
 *       enters an illegal code.                             *
 *************************************************************/
int main(void)
{
    char code;
    int num_parts = 0;
    int max_parts = 10;

    struct part* inventory = malloc(max_parts * sizeof(struct part));
    if (inventory == NULL) {
        printf("Memory allocation failed. Exiting.\n");
        return 1;
    }
    printf("Inventory set to %d slots.\n", max_parts);

    for (;;) {
        printf("Enter operation code: ");
        scanf(" %c", &code);
        while (getchar() != '\n') /* skips to end of line */
            ;
        switch (code) {
        case 'i':
            insert(&num_parts, &inventory, &max_parts);
            break;
        case 's':
            search(num_parts, inventory);
            break;
        case 'u':
            update(num_parts, inventory);
            break;
        case 'a':
            adjust(num_parts, inventory);
            break;
        case 'p':
            print(num_parts, inventory);
            break;
        case 'q':
            free(inventory);
            return 0;
        default:
            printf("Illegal code\n");
        };
        printf("\n");
    }
}

/************************************************************
 * find_part: Looks up a part number in the inventory       *
 *            array. Returns the array index if the part    *
 *            number is found; otherwise, returns -1.       *
 ************************************************************/
int find_part(int number, int num_parts, struct part* inventory)
{
    for (int i = 0; i < num_parts; i++)
        if (inventory[i].number == number)
            return i;
    return -1;
}
/************************************************************
 * insert: Prompts the user for information about a new     *
 *         part and then inserts the part into the          *
 *         database. Prints an error message and returns    *
 *         prematurely if the part already exists or the    *
 *         database is full.                                *
 ************************************************************/
void insert(int* num_parts, struct part** inventory, int* max_parts)
{
    int part_number;

    // Reallocate if the array is full
    if (*num_parts == *max_parts) {
        int new_max = *max_parts * 2;
        struct part* temp = realloc(*inventory, new_max * sizeof(struct part));
        if (temp == NULL) {
            printf("Failed to expand inventory. Insertion aborted.\n");
            return;
        }
        *inventory = temp;
        *max_parts = new_max;
        printf("Inventory expanded to %d slots.\n", new_max);
    }

    // Get part number
    printf("Enter part number: ");
    scanf("%d", &part_number);
    if (find_part(part_number, *num_parts, *inventory) >= 0) {
        printf("Part already exists.\n");
        return;
    }

    (*inventory)[*num_parts].number = part_number;

    printf("Enter part name: ");
    read_line((*inventory)[*num_parts].name, NAME_LEN);

    printf("Enter quantity on hand: ");
    scanf("%d", &(*inventory)[*num_parts].on_hand);

    printf("Enter part price: ");
    scanf("%lf", &(*inventory)[*num_parts].price);

    (*num_parts)++;
}

/************************************************************
 * search: Prompts the user to enter a part number, then    *
 *         looks up the part in the database. If the part   *
 *         exists, prints the name and quantity on hand;    *
 *         if not, prints an error message.                 *
 ************************************************************/
void search(int num_parts, struct part* inventory)
{
    int i, number;

    printf("Enter part number: ");
    scanf("%d", &number);
    i = find_part(number, num_parts, inventory);
    if (i >= 0) {
        printf("Part name: %s\n", inventory[i].name);
        printf("Quantity on hand: %d\n", inventory[i].on_hand);
        printf("Part price: %.2lf\n", inventory[i].price);
    } else
        printf("Part not found.\n");
}

/********************************************************
 * update: Prompts the user to enter a part number.     *
 *         Prints an error message if the part doesn't  *
 *         exist; otherwise, prompts the user to enter  *
 *         change in quantity on hand and updates the   *
 *         database.                                    *
 ********************************************************/
void update(int num_parts, struct part* inventory)
{
    int i, number, change;

    printf("Enter part number: ");
    scanf("%d", &number);
    i = find_part(number, num_parts, inventory);
    if (i >= 0) {
        printf("Enter change in quantity on hand: ");
        scanf("%d", &change);
        inventory[i].on_hand += change;
    } else
        printf("Part not found.\n");
}

/********************************************************
 * adjust: Prompts the user to enter a part number.     *
 *         Prints an error message if the part doesn't  *
 *         exist; otherwise, prompts the user to enter  *
 *         a new price and updates the                  *
 *         database.                                    *
 ********************************************************/
void adjust(int num_parts, struct part* inventory)
{
    int i, number;
    double new_price;

    printf("Enter part number: ");
    scanf("%d", &number);
    i = find_part(number, num_parts, inventory);
    if (i >= 0) {
        printf("Enter new price: ");
        scanf("%lf", &new_price);
        inventory[i].price = new_price;
    } else {
        printf("Part not found.\n");
    }
}

int cmp_part(const void* a, const void* b)
{
    const struct part* a1 = a;
    const struct part* b1 = b;

    if (a1->number < b1->number) {
        return -1;
    } else if (a1->number > b1->number) {
        return 1;
    } else {
        return 0;
    }
}

/************************************************************
 * print: Prints a listing of all parts in the database,    *
 *        showing the part number, part name, and           *
 *        quantity on hand. Parts are printed in the        *
 *        order in which they were entered into the         *
 *        database.                                         *
 ************************************************************/
void print(int num_parts, struct part* inventory)
{
    int i;

    qsort(inventory, num_parts, sizeof(struct part), cmp_part);

    printf("Part Number   Part Name        "
           "Quantity on Hand        Price\n");
    for (i = 0; i < num_parts; i++)
        printf("%7d       %-25s%-16d%.2lf\n", inventory[i].number,
            inventory[i].name, inventory[i].on_hand, inventory[i].price);
}
