#ifndef PIECE_H
#define PIECE_H

#include <string>
#include <iostream>
#include <sstream>

#include "Coordinate.h"

using std::string;
using std::stringstream;
using std::ostream;

class Player;
class Piece {
    //friend ostream& operator<<(ostream& out, const Piece& piece);
    
    protected:
      // Protected Data
      int type;

    public:
      // Constructors
      Piece();
      Piece(Player* owner);
      Piece(Player* owner, int type);
      
      // Public functions
      int getType();
      bool setType(int type);
      virtual string print();
      
      // Public Data
      Player* owner;
};

#endif
