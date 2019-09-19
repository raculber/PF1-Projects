//------------------------------------------------------------
// Purpose: To implement an online "Man vs. Wild: Mountain Special"
//          game.  Mountain locations are described by separate functions.
//          The user playing the game finds "food" and "water" as 
//          they do different activities.
//
// Author:  Rachel Culbertson
//------------------------------------------------------------
#include <cstdlib>
#include <iostream>
using namespace std;

// Function prototypes
int FindWater(int max_water);
int FindFood(int max_food, int & food_gained);
char GetDirection();

//Functions for locations
void Exit(int &water, int &food);
void Mountain1(int &water, int &food);
void Mountain2(int &water, int &food);
void Mountain3(int &water, int &food);
void Mountain4(int &water, int &food);
void Mountain5(int &water, int &food);
void Mountain6(int &water, int &food);
void Mountain7(int &water, int &food);
void Mountain8(int &water, int &food);
//------------------------------------------------------------
// Purpose: To calculate how much water user has.
// Input:   Maximum water (int -100..100).     
// Output:  Actual water (int -100..100).
//------------------------------------------------------------
int FindWater(int max_water)
{
   // Range checking of parameters
   if (max_water < -100) max_water = -100;
   if (max_water >  100) max_water =  100;

   cout << "Do you want to pick this bottled water up? (yes/no)" << endl; 
   string answer;
   cin >> answer;

   // Handle yes answer
   int water = 0;
   if (answer == "yes")
   {
      float fraction = (1.0 + random() % 100) / 100.0;
      water = fraction * max_water;
      if (water > 0)
         cout << "You found " << water << " L water " << endl;
      else
         cout << "You fell down and lost " << water << " L water" << endl;
   } 

   // Handle no answer
   else if (answer == "no")
   { 
      if (max_water > 0)
         cout << "Too bad, you need around 4-5 liters of water at altitude to feel great" << endl;
      else      
         cout << "Good thing you didn't get it, it is empty" << endl;
   }

   // Handle wrong answer
   else 
   { 
      cout << "A simple 'yes' or 'no' would be nice..." << endl;
      cout << "Better luck next time you see an item" << endl;
   }
   return water;
}


//------------------------------------------------------------
// Purpose: To calculate how much food user has.
// Input:   Maximum food (int 1..100).
// Output:  Actual food gained (int 1..100).
//------------------------------------------------------------
void GainFood(int max_food, int & food_gained)
{
   // Range checking of parameters
   if (max_food < 1)  max_food = 1;
   if (max_food > 100) max_food = 100;

   cout << "Do you want to pick this airdropping package up? (yes/no)" << endl; 
   string answer;
   cin >> answer;

   // Handle help answer
   if (answer == "Yes")
   {
      food_gained = 1 + random() % max_food;
      cout << "Congratulations, you gained " << food_gained << " food points" << endl;
   } 

   // Handle other answers
   else 
   { 
      food_gained = -(1 + random() % max_food);
      if (random() % 2 == 0)
         cout << "Illusion! Thats not a real package" << endl;
      else
         cout << "You lost " << food_gained << " food points" << endl;
   }
}

//------------------------------------------------------------
// Purpose: To get direction from user
// Input:   None
// Output:  Character code for N,S,E,W direction
//------------------------------------------------------------
char GetDirection()
{
   cout << "\nWhat direction would you like to go (N,S,E,W): ";
   char direction;
   cin >> direction;
   direction = toupper(direction);
   while ((direction != 'N') && (direction != 'S') &&
          (direction != 'E') && (direction != 'W'))
   {
      cout << "Sorry, You can not go that way...\n";
      cout << "What direction would you like to go (N,S,E,W): ";
      cin >> direction;
      direction = toupper(direction);
   }
   return direction;
}

//------------------------------------------------------------
// Purpose: The ending Mountain for the game
// Input:   The water and food variables 
// Output:  None
//------------------------------------------------------------
void Exit(int &water, int &food)
{
   cout << "\n------------------------------------------------------------\n";
   cout << "\nYou have already finished the summits challenge\n";
   cout << "I hope you enjoyed this trip\n";
   cout << "You got \n";
   cout << "\nWater: " << water << " Food: " << food << endl;
   
   // Give prizes
   if (water <= 0) 
   {
      cout << "\nYou feel thirsty and give up climbing other highest point in the world\n";
   }
   else if (food <= 0)
   {
      cout << "\nYou feel hungry and give up climbing other highest point in the world\n";
   }
   else if ((water > 100) && (food > 100))
   {
      cout << "\nThe four summits challenge is the ultimate lifetime achievement for those looking for adventure\n";

   }
   else if ((water > 10) && (food > 10))
   {
      cout << "\nGreat job.  You get a ticket to the Vinson Massif Mountain(Locatied in Antarctica)\n";
   }
   else 
   {
      cout << "\nYou got juicy and tasty steak\n";
   }

   // Leave program
   exit(0);
}

//------------------------------------------------------------
// Purpose: To climb Mountain 
// Input:   The water and food variables
// Output:  None
//------------------------------------------------------------
void Mountain1(int &water, int &food)
{
   cout << "\n------------------------------------------------------------\n";
   cout << "\nYou just summitted the Kosciuszko Mountain(Highest point in Australia) \n";
   cout << "\nYou found it is harder to spell Mt kosciuszko than it is to climb it) \n";


   // ADD CODE HERE
   int foodGained; // Keeps track of the food gained
   GainFood(10, foodGained); // Changes in the function
   food += foodGained; // Added to the total food 
   cout << "\nHealth: " << food << " water: " << water << endl;
}

//------------------------------------------------------------
// Purpose: To climb Mountain
// Input:   The water and food variables
// Output:  None
//------------------------------------------------------------
void Mountain2(int &water, int &food)
{
   cout << "\n------------------------------------------------------------\n";
   cout << "\nYou just summitted the Denali Mountain(North American) \n";
   cout << "\nIt's unbelievably cold and is used as a training ground for the Himalayas) \n";

   // ADD CODE HERE
   water += FindWater(5);
   cout << "\nHealth: " << food << " water: " << water << endl;
}

//------------------------------------------------------------
// Purpose: To climb Mountain
// Input:   The water and food variables
// Output:  None
//------------------------------------------------------------
void Mountain3(int &water, int &food)
{
   cout << "\n------------------------------------------------------------\n";
   cout << "\nYou just summitted the Aconcagua Mountain(Highest Mountain outside of the Himalayas) \n";
   cout << "\nThe peak rises almost 7000m into the air \n";

   // ADD CODE HERE
   int foodGained;
   GainFood(3, foodGained);
   food += foodGained;
   cout << "\nHealth: " << food << " water: " << water << endl;
}

//------------------------------------------------------------
// Purpose: To climb Mountain
// Input:   The water and food variables
// Output:  None
//------------------------------------------------------------
void Mountain4(int &water, int &food)
{
   cout << "\n------------------------------------------------------------\n";
   cout << "\nYou just summitted the Everest Mountain(Highest Mountain in the world) \n";
   cout << "\nNo other mountain is so instantly recognizably or has such a history surrounding it) \n";

   // ADD CODE HERE
   water += FindWater(6);
   cout << "\nHealth: " << food << " water: " << water << endl;
}

// ADD MORE ROOM FUNCTIONS HERE
// More Mountain Functions
void Mountain5(int &water, int &food)
{
    cout << "\n------------------------------------------------------------\n";
    cout << "\nYou just summitted the Salcantay Mountain(Andes, Peru)\n";
    cout << "\nThe name comes from the Quechua word sallqa, meaning \"wild\". \n";
    water += FindWater(8);
    cout << "\nHealth: " << food << " water: " << water << endl;
}
void Mountain6(int &water, int &food)
{
    cout << "\n------------------------------------------------------------\n";
    cout << "\nYou just summitted Mount St. Helens(United States)\n";
    cout << "\nThis mountain is most famous for its 1980 eruption that killed 57 people.\n";
    int foodGained;
    GainFood(5, foodGained);
    food += foodGained;
    water += FindWater(5);
    cout << "\nHealth: " << food << " water: " << water << endl;
}
void Mountain7(int &water, int &food)
{
    cout << "\n------------------------------------------------------------\n";
    cout << "\nYou just summitted the Yushan Mountain(Taiwan)\n";
    cout << "\nThe name means \"Jade Mountain\" and is the highest mountain in Taiwan.\n";
    int foodGained;
    GainFood(4, foodGained);
    food += foodGained;
    cout << "\nHealth: " << food << " water: " << water << endl;
}
void Mountain8(int &water, int &food)
{
    cout << "\n------------------------------------------------------------\n";
    cout << "\nYou just summitted Mount Taranaki(New Zealand)\n";
    cout << "In 2017, this mountain became the third geographic feature in New Zealand to be granted a legal personality.\n";
    GainFood(10, food);
    water += FindWater(5); 
    cout << "\nHealth: " << food << " water: " << water << endl;
}
//------------------------------------------------------------
// Purpose: The main program
// Input:   None
// Output:  None
//------------------------------------------------------------
int main()
{
   // Initialize game
   int water = 50;
   int food = 50;
   char direction;
   int mountainNum = 1; // Starting Mountain
   bool inExit; // Tests to see if user has found the exist
   srandom(time(NULL));

   // Test the mountain functions   
   while (!inExit) // Executes until the user finds the exit
   {
      if (mountainNum == 1)
      {
         Mountain1(water, food); //Calls mountain function
         direction = GetDirection();
         if (direction == 'E')
            mountainNum = 2;
         else if (direction == 'S')
            mountainNum = 3;
         else
         {
             cout << "You can't go that way." << endl; 
             direction = GetDirection(); // Gets direction until user types in a direction that leads to a mountain
         }
      }
      else if (mountainNum == 2)
      {
         Mountain2(water, food);
         direction = GetDirection();
         if (direction == 'S')
         {
            mountainNum = 4;
         }
         else 
         {
             cout << "You can't go that way." << endl; 
             direction = GetDirection();
         }
      }
      else if (mountainNum == 3)
      {
         Mountain3(water, food);
         direction = GetDirection();
         if (direction == 'S')
            mountainNum = 8;
         else if (direction == 'N')
            mountainNum = 1;
         else if (direction == 'E')
            mountainNum = 4;
         else
	 {
	     cout << "You can't go that way." << endl; 
             direction = GetDirection();
         }
      }
      else if (mountainNum == 4)
      {
         Mountain4(water, food);
         direction = GetDirection();
         if (direction == 'N')
           mountainNum = 2;
         else if (direction == 'W')
           mountainNum = 3;
         else if (direction == 'E')
           mountainNum = 5;
         else if (direction == 'S')
           mountainNum = 7;
         else
             direction = GetDirection();
      }
      else if (mountainNum == 5)
      {
         Mountain5(water, food);
         direction = GetDirection();
         if (direction == 'S')
            mountainNum = 6;
         else if (direction == 'W')
            mountainNum = 4;
         else
         {
             cout << "You can't go that way." << endl; 
             direction = GetDirection();
         }
      }
      else if (mountainNum == 6)
      {
         Mountain6(water, food);
         direction = GetDirection();
         if (direction == 'W')
           mountainNum = 7;
         else
         {
             cout << "You can't go that way." << endl; 
             direction = GetDirection();
         }
      }
      else if (mountainNum == 7)
      {
         Mountain7(water, food);
         direction = GetDirection();
         if (direction == 'N')
            mountainNum = 4;
         else if (direction == 'W')
            mountainNum = 8;
         else if (direction == 'E')
            mountainNum = 6;
         else if (direction == 'S')
            inExit = true; // Location of exit 
      }
      else if (mountainNum == 8)
      {
         Mountain8(water, food);
         direction = GetDirection();
         if (direction == 'N')
            mountainNum = 3;
         else if (direction == 'E')
            mountainNum = 7;
         else
         {
             cout << "You can't go that way." << endl;
             direction = GetDirection();
         }
      }
   }
   Exit(water, food); // Excutes when while loop is exited (inExit is set to true)

   return 0;
}
