#include "gameManager.h"
using namespace std;
gameManager::gameManager()
{
start = false;
gameOver = false;
run();
}
gameManager::~gameManager()
{

}
void gameManager::run()
{
playerMenu();
if(start == true)
{
   gameLoop();
}
}
void gameManager::playerMenu()
{
  while(start != true)
    {
      int tempShips = 5;
      cout << "===WELCOME TO BATTLESHIP!====\n========Select Number and Hit Enter to Choose Option===========\n1.) Start Game\n 2.)Rules\n3.)Close Game\n===============================================\n";
      cin >> playerChoice;
      if(playerChoice == 1)
        {
          cout<<"Game Starting!\n";
          Player p1(tempShips);
          Player p2(tempShips);
           start = true;
        }
     else if(PlayerChoice == 2)
       {
          cout<<"Current Ruleset: Number of ships = "<<tempShips<<"\nPlease input new number of ships to play (must be between 1 and 5): ";
          cin>>tempShips;
          if (tempShips < 1)
          {
            tempShips = 1;
          }
          else if (tempShips > 5)
          {
            tempShips = 5;
          }
          cout<<"New Ruleset: "<<tempShips<<" ships per game.";
       }
    else if(playerChoice == 3)
       {
         cout<<"Thanks for playing!";
         break;
       }
    else
      {
        cout << "Invalid Menu Choice! Please Choose Again.\n";
      }
    }
  gameLoop();
}
void gameManager::gameLoop()
{
  string s = "";
  while(!p1.isDead() && !p2.isDead())
  {
    cout<< "=======================\nPlayer One: it's your turn!\n=======================";
    playerTurn(p1);
    if (p2.isDead())
    {
      gameOver(p1);
      break;
    }
    cout << "Press any key(AND ENTER) to begin Player 2's turn: \n"; //dont know how to make accept just keypress.
    cin >> s;
    cout<< "=======================\nPlayer Two: it's your turn!\n=======================";
    playerTurn(p2);
    if (p1.isDead())
    {
      gameOver(p2);
      break;
    }
    cout << "Press any key(AND ENTER) to begin Player 1's turn: \n"; //same as comment above. (WIP)
    cin >> s;
  }
  playerMenu();
}
void gameManager::playerTurn(Player p)
{
cout << '\n';
cout<<"YOUR BOARD: \n";
p.getBoard('o').printBoard(); //'o' represents "own board"
cout<<"\nTARGET BOARD: \n";
p.getBoard('e').printBoard(); //'e' represents "enemy board"
cout << '\n';
do
{
bool validX = true;
bool validY = true;
int xVal =0;
int yVal =0;
char xTemp = ' ';
string playerShot = "";
cout << "Enter space to fire at: ";
cin >> playerShot;
xTemp = playerShot.at(0);
yVal = playerShot.at(1);

    switch (xTemp)
	{
           case 'a':
		xVal = 0;
		break;
	         case 'b':
		xVal = 1;
		break;
           case 'c':
		xVal = 2;			//switch block transforms first char in input string from the player into integer value.
		break;
	         case 'd':
		xVal = 3;
		break;
           case 'e':
		xVal = 4;
		break;
	         case 'f':
		xVal = 5;
		break;
           case 'g':
		xVal = 6;
		break;
	         case 'h':
		xVal = 7;
		break;
	         default:
		cout <<"X Position Out of Bounds!\n";
    validX = false;
		break;
  }
    switch (yVal)
	{
           case '1':
		yVal = 0;
		break;
	         case '2':
		yVal = 1;
		break;
           case '3':
		yVal = 2;			//switch block transforms second char into integer value for grid.
		break;
	         case '4':
		yVal = 3;
		break;
           case '5':
		yVal = 4;
		break;
	         case '6':
		yVal = 5;
		break;
           case '7':
		yVal = 6;
		break;
	         case '8':
		yVal = 7;
		break;
	         default:
		cout <<"Y Position Out of Bounds!\n";
    validY = false;
		break;
	}
}
while (!validX || !validY);
p.fireShot(xVal,yVal);
cout<<"TARGET BOARD: \n";
p.getBoard('e').printBoard();


}

void gameManager::gameOver(Player winner)
{
  cout<<"============\nGAME OVER\n============\n";
  switch (winner)
  {
    case (p1)
    cout<<"Player 1 Wins!\n";
    break;

    case (p2)
    cout<<"Player 2 Wins!\n";
    break;

    default
    cout<<"Whoops!  Something's not right here.\n";
  }
}
