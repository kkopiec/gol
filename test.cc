#include "cell.h"
#include<iostream>
int main(int argc, char* argv[]){

  Cell *c = new Cell();
  Cell *d = new Cell();
  Cell *e = new Cell();
  Cell *f = new Cell();
  c->setAlive(true);
  d->setAlive(true);
  e->setAlive(true);
  f->setAlive(true);
  c->addNeighbour(d);
  c->addNeighbour(e);
  c->addNeighbour(f);
  d->addNeighbour(e);
  d->addNeighbour(f);
  e->addNeighbour(f);

  std::cout << "Before Flip\n";
  std::cout << "Cell created:\n" << *c << std::endl;
  for (int i = 0; i < 10; i++) {
    std::cout << "After flip turn " << i << std::endl;
    c->flip();
    d->flip();
    e->flip();
    f->flip();
    std::cout << "C :" << *c << std::endl;
    std::cout << "D :" << *d << std::endl;
    std::cout << "E :" << *e << std::endl;
    std::cout << "F :" << *f << std::endl;
    std::cout <<"====================================================" << std::endl;
  }
  return 0;
}
