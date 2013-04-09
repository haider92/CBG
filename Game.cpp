#include "Game.h"

using std::cout;
using std::ostream;

Game::Game(const int amountOfPlayers, const int columns, const int rows)
           : amountOfPlayers(amountOfPlayers), columns(columns), rows(rows) {
  this->currentPlayer = 0;
  this->state = 0;
  this->players = new Player[amountOfPlayers];
  this->grid = new Square*[rows];
  for(int i=0; i<rows; i++) {
    this->grid[i] = new Square[columns];
  }
}

Game::~Game() {
  for(int i=0; i<rows; i++) {
    delete [] grid[i];
  }
  delete [] grid;
  delete [] players;
}

void Game::start() {
  drawScreen();
  while(state==0) {
    if(getMove()) {
      drawScreen();
    } else {
      cout << "Invalid Move, try again.\n";
    }
  }

  cout << "Game ended with state: " << state << "\n";
}

void Game::clearScreen() {
  cout << "\033[2J\033[;H";
}

ostream& operator<<(ostream& out, const Square& square) {
  for(int i=0; i<square.amountOfPlayers; i++) {
    if(square.pieces[i] != 0) {
      out << square.pieces[i]->print();
      return out;
    }
  }
  out << " ";
  return out;
}
/*
ostream& operator<<(ostream& out, const Piece& piece) {
  out << piece.print();
  return out;
}*/