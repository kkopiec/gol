#include "world.h"

int main(int argc, char *argv[]){
  World *w = new World(10,10);
  w->flipOver(4,4);
  w->flipOver(5,4);
  w->flipOver(6,4);
  w->flipOver(5,5);
  for (int i =0 ;i < 11; i++){
    w->evaluate();
    std::cout << *w;
  }
  delete(w);
  return 0;
}
