/* Program simulates a user ordering from a menu 
and keeps track of the current inventory of snacks
as well as the cost of the order */
#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;
// Function prints out the menu for the user to read
void print_menu(string cust, string snacks[], float prices[])
{
   cout << "Hello " << cust << "!";
   cout << " Snacks for sale: " << endl;
   for (int i = 0; i < 10; i++)
   {
      cout << i+1 << ". " << snacks[i] << " $" << prices[i] << endl;
   }
}
// Function lets the user choose a snack and amount
void choose_snack(string cust, string snacks[], int inven[], float prices[])
{
   string snackName; 
   float totalCost; //Keeps track of the cost of the order
   int numOfSnack = 0;
   bool isSnack = false; // Determines whether an inputted snack is on the menu
   bool isValidNum = false; // Determines whether an inputted amount is valid
   while (snackName != "pay") 
   {
      isValidNum = false;
      while (isSnack == false && snackName != "pay")
      { 
         cout << "Enter the name of the snack you want or \"pay\" to exit: " << endl;
         cin >> snackName;
         for (int i = 0; i < 10; i++)
         {
            if (snackName == snacks[i]) // Checks if the inputted snack is in the snacks array
               isSnack = true;
         }
         if (isSnack == false && snackName != "pay")
            cout << "Snack not included on menu." << endl;
      }
      while (snackName != "pay" && isValidNum == false)
      {
         cout << "How many do you want?" << endl;
         cin >> numOfSnack;
         for (int i = 0; i < 10; i++)
         {
            if (snacks[i] == snackName && inven[i]-numOfSnack >=0 && numOfSnack >=0) /* Executes when the inputted number is not negative 
                                                                                        and there is enough snacks available in the inventory */
            {
               isValidNum = true;
               inven[i] -= numOfSnack;
               totalCost += (prices[i]*numOfSnack);
            }
            else if (snacks[i] == snackName)
                cout << "Invalid number of items." << endl;
         }
      }
      isSnack = false;
   }
   cout << cust << ", the cost of your order is:  $" << totalCost << endl; 
}
// Function prints out the current inventory 
void print_inventory(string snacks[], int inven[])
{
   for (int i = 0; i < 10; i++)
   {
      cout << snacks[i] << " " << inven[i] << endl;
   }
}
int main()
{
   string customerName;
   string snackNames[10] = {"Coke", "Pepsi", "Lemonade", "Donut", "Popcorn", "Doritos", "Churro", "Kitkat", "Hotdog", "Salad"};
   int inventory[10];
   float snackPrices[10] = {1.75, 1.75, 2.00, 3.00, 1.50, 1.00, 2.50, 0.50, 2.50, 3.00};
   for (int i = 0; i < 10; i++)
   {
      inventory[i] = (rand()%91)+10; /* Assigns to each element of inventory
                                        a random number from 10-100 */
   }
   print_inventory(snackNames, inventory);
   while (customerName != "exit")
   {
      cout << "Enter your name (or \"exit\"): " << endl;
      cin >> customerName;
      if (customerName != "exit")
      {
         print_menu(customerName, snackNames, snackPrices);
         choose_snack(customerName, snackNames, inventory, snackPrices);
      }
   }
   print_inventory(snackNames, inventory);
   return 0;
}
