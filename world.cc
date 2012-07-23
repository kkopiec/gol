#include"world.h"

World::World(int w, int h){
  boardsize = w*h;
  turns = 0;
  board = new Cell[boardsize];
}
World::~World(){
  //TODO: Implement destructor
}
void World::clear(){
  //TODO: Implement clear the board
}
void World::evaluate(){
  //TODO: Implement evaluation - look for test.cc for prototype
}
void World::flipOver(int w, int h){
  //TODO: Implement setting cells alive/dead
}
friend std::ostream & operator<<(std::ostream &os, const World &w){
  //TODO: Implement Debbuging graphical indication of the world state
  return os;
}
