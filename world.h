#ifndef WORLD_H
#define WORLD_H
#include"cell.h"
#include<iostream>

class World {
public:
  World(int, int);
  ~World();
  void clear();
  void evaluate();
  void flipOver(int,int);
  friend std::ostream & operator<<(std::ostream &os, const World &w);
protected:
  int boardSize;
  long long turns;
  Cell* board;
}

#endif
