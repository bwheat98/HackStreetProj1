#include "Board.h"
#include "Player.h"
#include "Ship.h"
#include <iostream>
#include "gameManager.h"
#include <graphics.h>
#include <conio.h>
using namespace std;

int main()
  {
    gameManager g1();
    cout << "Test compile" << endl;
    int gd=DETECT,gm,points[]={320,150,420,300,250,300,320,150};

initgraph(&gd, &gm, "C:\\TC\\BGI");

drawpoly(4, points);

getch();
closegraph();
return 0;
  }
