#include "Player.h"
#include "Piece.h"

Player::Player() {}

Player::Player(int amountOfTypes, std::vector<std::string> types, int maxPieces) {
  this->types = types;
  this->amountOfPieces = 0;
  this->amountOfTypes = amountOfTypes;
  this->maxPieces = maxPieces;
  this->pieces.resize(maxPieces);
}


std::string Player::getCharacter(int type) {
  return types[type];
}

bool Player::hasType(int type) {
  if(type<amountOfTypes) {
    return true;
  } else {
    return false;
  }
}

Piece* Player::addPiece() {
  Piece* piece = 0;
  if(amountOfPieces < maxPieces) {
    pieces[amountOfPieces] = new Piece(this);
    piece = pieces[amountOfPieces];
    amountOfPieces++;
  }
  return piece;
}

// Only used by snakes and ladders
Piece* Player::addPiece(Piece* insert) {
  Piece* piece = 0;
  if(amountOfPieces < maxPieces) {
    pieces[amountOfPieces] = insert;
    piece = pieces[amountOfPieces];
    amountOfPieces++;
  }
  return piece;
}

bool Player::removePiece() {
  if(amountOfPieces > 0) {
    amountOfPieces--;
    return true;
  } else {
    return false;
  }
}

int Player::getAmountOfPieces() {
  return amountOfPieces;
}

Piece* Player::getPiece(int index) {
  Piece* piece = 0;
  if(index >= 0 && index < maxPieces) {
    piece = pieces[index];
  }
  return piece;
}