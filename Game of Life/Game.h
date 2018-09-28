#include <iostream>
#include <fstream>

using namespace std;

class Game {
private:
  char** board;
  char** nextGeneration;
  int board_rows;
  int board_cols;

  int mode; //0 classic, 1 donut, 2 mirror

public:
  //Constructor
  Game();

  //Destructor
  ~Game();

  //Functions
  void startGame(); //calls random or file grid
  void initializeBoard(); //initialize memory & fill wtih blanks
  void generateRandomGrid(); //random life
  void generateFileGrid(); //life from file

  void printBoard(); //display function
  void NextGen(); // go to the next generator

  void gameSettings(); //switching between generations
  void gameMode(); //chose which mode
  void classicMode(); 
  void donutMode();
  void mirrorMode();

};
