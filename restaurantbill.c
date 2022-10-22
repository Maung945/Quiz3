/*
 * Myo Aung, CS26000 - System Programming
 * 
 * Implentation of pointers and pointer functions learned class.
 * Create a Menu table using struct
 * ptr - points to the table and iterate through it to search the target
 * Create methods/functions that calculate Tax and Tip
 * printGrandTotal() will call calulateTax() and calculateTip()
 */
#include <stdlib.h>
#include <stdio.h>

#define TAX 0.095                                                       // Macro for Tax Percentage
 
typedef struct                                                          // Struct
{
    int item;
    char *itemName;
    double price;
} Menu, *PtrToMenu;

typedef const Menu *PtrtoItems;

Menu MenuTable[] = {
    {1, "Salad", 9.95}, {2, "Soup", 4.55}, {3, "Sandwich", 13.25}, {4, "Pizza", 22.35}};

const int MenuTableEntries = sizeof(MenuTable) / sizeof(MenuTable[0]);  // Size of the array

PtrToMenu display(PtrtoItems ptr, int tableSize)                        // Pointer return funcion 
{
    const PtrtoItems endPtr = ptr + tableSize;                          // End-Pointer is set for the loop to stop
    for (; ptr < endPtr; ptr++)
    {
        printf("%d) %s: $%1.2f\n", ptr->item, ptr->itemName, ptr->price);
    }
}

PtrToMenu searchItem(PtrtoItems ptr, int tableSize, int target)         // Pointer return function for search item
{
    const PtrtoItems endPtr = ptr + tableSize;
    for (; ptr < endPtr; ptr++)
    {
        if (ptr->item == target)                                        // If ptr pointer points at target
            return (PtrToMenu)ptr;                                      // Return that ptr pointer
    }
    return NULL;
}

double calculateOneItems(PtrToMenu ptr1)                                // Calculte for One Item
{
    return (ptr1->price);
}

double calculateTwoItems(PtrToMenu ptr1, PtrToMenu ptr2)                // Calculte for One Item
{
    return (ptr1->price + ptr2->price);
}

double calculateThreeItems(PtrToMenu ptr1, PtrToMenu ptr2, PtrToMenu ptr3)
{
    return (ptr1->price + ptr2->price + ptr3->price);                   // Calculte for One Item
}

double calculateFourItems(PtrToMenu ptr1, PtrToMenu ptr2, PtrToMenu ptr3, PtrToMenu ptr4)
{
    return (ptr1->price + ptr2->price + ptr3->price + ptr4->price);     // Calculte for One Item
}

double calculateTip(double total, int tipPercentage)                    // Calculate Tips
{
    return (total * (tipPercentage * 0.01));
}

double calculateTax(double total)                                       // Calculate Tax
{
    return (total * TAX);
}

void printGrandTotal(double total)                                      // Void function for display
{
    double tip;
    double grandTotal;
    printf("Enter Tip %%\t\t    : ");
    scanf("%lf", &tip);
    printf("Total Tip\t\t    : $%1.2f\n", calculateTip(total, tip));
    printf("Tax 9.5%%\t\t    : $%1.2f\n", calculateTax(total));
    printf("-------------------------------------\n");
    grandTotal = total + calculateTip(total, tip) + calculateTax(total);
    printf("Your Grand Total\t    : $%1.2f\n", grandTotal);
    printf("-------------------------------------\n\n");
}

int main(void)                                                          // Main function
{
    
    int itemOne, itemTwo, itemThree, itemFour;
    int itemCount;
    printf("\n\n     -------------\n");

    printf("     Today's Menu\n");
    printf("     -------------\n");

    PtrToMenu display(const Menu table[], int tableSize);

    display(MenuTable, MenuTableEntries);
    printf("--------------------------\n");
    printf("How many items selecting: ");
    scanf("%d", &itemCount);
    printf("--------------------------\n");

    PtrToMenu searchItem(const Menu table[], int tableSize, int target);
    
    double total;
    
    switch (itemCount)
    {
    case 1:
        int randomNumber1 = rand() % 3 + 1; 
        itemOne = randomNumber1;
        printf("Randomly Selected Item Number: %d\n", itemOne);
        PtrToMenu matchPtr;
        matchPtr = searchItem(MenuTable, MenuTableEntries, itemOne);
        printf("Item Selected: %s is $%1.2f\n", matchPtr->itemName, matchPtr->price);
        printf("--------------------------\n");
        total = calculateOneItems(matchPtr);

        printf("Sub-Total for ONE item is   : $%1.2f\n", total);
        printGrandTotal(total);
        break;

    case 2:
        int randomNumber2 = rand() % 3 + 1; 
        int randomNumber3 = rand() % 1 + 1;
        itemOne = randomNumber2;
        itemTwo = randomNumber3;
        printf("Randomly Selected Item Number: %d\n", itemOne);
        printf("Randomly Selected Item Number: %d\n", itemTwo);
        
        PtrToMenu matchPtr1;
        matchPtr1 = searchItem(MenuTable, MenuTableEntries, itemOne);
        printf("Item 1: %s is $%1.2f\n", matchPtr1->itemName, matchPtr1->price);

        PtrToMenu matchPtr2;
        matchPtr2 = searchItem(MenuTable, MenuTableEntries, itemTwo);
        printf("Item 2: %s is $%1.2f\n", matchPtr2->itemName, matchPtr2->price);
        printf("--------------------------\n");
        total = calculateTwoItems(matchPtr1, matchPtr2);
        printf("Sub-Total for TWO items is  : $%1.2f\n", total);
        printGrandTotal(total);
        break;
    case 3:
        int randomNumber5 = rand() % 3 + 1; 
        int randomNumber6 = rand() % 1 + 1;
        int randomNumber7 = rand() % 2 + 1; 
        itemOne = randomNumber5;
        itemTwo = randomNumber6;
        itemThree = randomNumber7;
        printf("Randomly Selected Item Number: %d\n", itemOne);
        printf("Randomly Selected Item Number: %d\n", itemTwo);
        printf("Randomly Selected Item Number: %d\n", itemThree);

        PtrToMenu matchPtrOne;
        matchPtrOne = searchItem(MenuTable, MenuTableEntries, itemOne);
        printf("Item 1: %s is $%1.2f\n", matchPtrOne->itemName, matchPtrOne->price);

        PtrToMenu matchPtrTwo;
        matchPtrTwo = searchItem(MenuTable, MenuTableEntries, itemTwo);
        printf("Item 2: %s is $%1.2f\n", matchPtrTwo->itemName, matchPtrTwo->price);

        PtrToMenu matchPtrThree;
        matchPtrThree = searchItem(MenuTable, MenuTableEntries, itemThree);
        printf("Item 3: %s is $%1.2f\n", matchPtrThree->itemName, matchPtrThree->price);
        printf("--------------------------\n");
        total = calculateThreeItems(matchPtrOne, matchPtrTwo, matchPtrThree);
        printf("Sub-Total for THREE items is: $%1.2f\n", total);

        printGrandTotal(total);
        break;

    case 4:
        int randomNumber8 = rand() % 3 + 1; 
        int randomNumber9 = rand() % 1 + 1;
        int randomNumber10 = rand() % 3 + 1; 
        int randomNumber11= rand() % 2 + 1;
        itemOne = randomNumber8;
        itemTwo = randomNumber9;
        itemThree = randomNumber10;
        itemFour = randomNumber11;
        printf("Randomly Selected Item Number: %d\n", itemOne);
        printf("Randomly Selected Item Number: %d\n", itemTwo);
        printf("Randomly Selected Item Number: %d\n", itemThree);
        printf("Randomly Selected Item Number: %d\n", itemFour);
        PtrToMenu ptrOne;
        ptrOne = searchItem(MenuTable, MenuTableEntries, itemOne);
        printf("Item 1: %s is $%1.2f\n", ptrOne->itemName, ptrOne->price);

        PtrToMenu ptrTwo;
        ptrTwo = searchItem(MenuTable, MenuTableEntries, itemTwo);
        printf("Item 2: %s is $%1.2f\n", ptrTwo->itemName, ptrTwo->price);

        PtrToMenu ptrThree;
        ptrThree = searchItem(MenuTable, MenuTableEntries, itemThree);
        printf("Item 3: %s is $%1.2f\n", ptrThree->itemName, ptrThree->price);

        PtrToMenu ptrFour;
        ptrFour = searchItem(MenuTable, MenuTableEntries, itemFour);
        printf("Item 4: %s is $%1.2f\n", ptrFour->itemName, ptrFour->price);

        printf("--------------------------\n");
        total = calculateFourItems(ptrOne, ptrTwo, ptrThree, ptrFour);
        printf("Sub-Total for FOUR items is : $%1.2f\n", total);

        printGrandTotal(total);
        break;

    default:
        printf("Enter a valid number\n");
    }

    return EXIT_SUCCESS;
}
