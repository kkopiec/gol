#include "world.h"

World::World(int w, int h){
  boardsize = w*h;
  bw = w;
  bh = h;
  turns = 0;
  board = new Cell*[boardsize];
  for (int i = 0; i<boardsize ;i++){
    Cell* c = new Cell();

    if (i < w) {				// first row
      if(i>0)					// very first element (do nothing)
      c->addNeighbour(board[i-1]);

    } else {					// last row
      if ((i % w) == 0){		        // first column
	Cell *c1 = board[i-w];			// 1 2 3
	Cell *c2 = board[i-w+1];		// 4 5 6
	c->addNeighbour(c1);
	c->addNeighbour(c2);
      } else if ((i+1) % w == 0) { 		// last column
	Cell *c1 = board[i-1];
	Cell *c2 = board[i-w-1];
	Cell *c3 = board[i-w];
	c->addNeighbour(c1);
	c->addNeighbour(c2);
	c->addNeighbour(c3);
      } else {					// any other column
	Cell *c1 = board[i-1];
	Cell *c2 = board[i-w-1];
	Cell *c3 = board[i-w];
	Cell *c4 = board[i-w+1];
	c->addNeighbour(c1);
	c->addNeighbour(c2);
	c->addNeighbour(c3);
	c->addNeighbour(c4);
      }
    }
    board[i] = c;
  }
}
World::~World(){


  for (int i = 0 ;i < boardsize; i++){
    delete(board[i]);
  }

  delete[](board);
}
void World::clear(){
  for (int i = 0 ;i < boardsize; i++){
    board[i]->setAlive(false);
    board[i]->setFlipped(false);
  }
}
void World::evaluate(){
  //Setup position
  for (int i = 0 ;i < boardsize; i++){
    board[i]->flip();
  }
  //Calculate next position
  for (int i = 0 ;i < boardsize; i++){
    board[i]->markFlip();
  }
}
void World::flipOver(int w, int h){
  int pos = h*bw + w;
  board[pos]->setAlive(!board[pos]->getAlive());
}
std::ostream & operator<<(std::ostream &os, const World &w){
  for (int i = 0 ;i < w.boardsize; i++){
    if (i % w.bw == 0) os << std::endl;
    os << *w.board[i];
  }
  os << std::endl;
  return os;
}
