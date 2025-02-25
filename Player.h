/** @brief Player class that acts as a storage device for the two players in the gameManager class. holds the ships and boards of each player and fires shots.
    @author Brandon Wheat,William Burdick,Hunter Cobb, Zackariah Khazraeinazmpour, Justin Khounsombath
    @date September 22, 2019
    */
#include "Board.h"
#ifndef PLAYER_H
#define PLAYER_H

using namespace std;

class Player
  {
  public:
    ~Player();
    /**Default constructor that sets ships and boards to default as well.
        */
    Player();
    /**main constructor that sets number of ships and creates an array of myShips
        @param shipNums - Numbers of ships to be included in the player.
        */
    Player(int shipNums);
    /**sets the positions of the ships on the board.
        */
    void placeShips();
    /**function to allow players to fire shots at enemy board.
        @param xPos - x position of shot
        @param yPos - y position of shot
        @param target - player that is to be fired upon.
        */
    bool fireShot(int xPos, int yPos, Player target);
    /**Checks whether a player is still alive
      @return whether or not a players ships have all been sunk
        */
    bool isDead();
    /**gets a players board.
        @param choice - char to decide whether the target board or their own board is to be chosen.
        @return the board specifed
        */
    Board getBoard(char choice);
    /**takes the enemy player's hit and applies it to the ship that was hit on the opponents board.
      @param xPos - the x position that has been hit
      @param yPos - the y position that has been hit
        */
    void receiveHit(int xPos, int yPos); 


  private:
    Board ownBoard; /**Board containing the player's own ships.*/
    Board enemyBoard; /**Board that contains hits and missses for the player*/
    int numShips;/**number of ships assigned to each player*/
    Ship* ownShips; /**Points toward array of ships owned by the player*/

  };
#endif
