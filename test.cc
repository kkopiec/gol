#include "cell.h"
#include<iostream>
int main(int argc, char* argv[]){

  Cell *c = new Cell();                     // c d e
  Cell *d = new Cell();			    // f g h
  Cell *e = new Cell();			    // i j k
  Cell *f = new Cell();
  Cell *g = new Cell();
  Cell *h = new Cell();
  Cell *i = new Cell();
  Cell *j = new Cell();
  Cell *k = new Cell();
  
  f->setAlive(true);			    // blinker
  g->setAlive(true);			    // 
  h->setAlive(true);			    // 
  d->addNeighbour(c);
  e->addNeighbour(d);
  f->addNeighbour(c);
  f->addNeighbour(d);
  g->addNeighbour(f);
  g->addNeighbour(c);
  g->addNeighbour(d);
  g->addNeighbour(e);
  h->addNeighbour(g);
  h->addNeighbour(d);
  h->addNeighbour(e);
  i->addNeighbour(f);
  i->addNeighbour(g);
  j->addNeighbour(i);
  j->addNeighbour(f);
  j->addNeighbour(g);
  j->addNeighbour(h);
  k->addNeighbour(j);
  k->addNeighbour(g);
  k->addNeighbour(h);
  std::cout << "Before Flip\n";
  std::cout << "Cell created:\n" << *c << std::endl;
  for (int ii = 0; ii < 10; ii++) {
    std::cout << "After flip turn " << i << std::endl;
    c->flip();
    d->flip();
    e->flip();
    f->flip();
    g->flip();
    h->flip();
    i->flip();
    j->flip();
    k->flip();

    c->markFlip();
    d->markFlip();
    e->markFlip();
    f->markFlip();
    g->markFlip();
    h->markFlip();
    i->markFlip();
    j->markFlip();
    k->markFlip();
    std::cout << "\tc d e" << std::endl;
    std::cout << "\tf g h" << std::endl;
    std::cout << "\ti j k" << std::endl;
    std::cout << "C :" << *c << std::endl;
    std::cout << "D :" << *d << std::endl;
    std::cout << "E :" << *e << std::endl;
    std::cout << "F :" << *f << std::endl;
    std::cout << "G :" << *g << std::endl;
    std::cout << "H :" << *h << std::endl;
    std::cout << "I :" << *i << std::endl;
    std::cout << "J :" << *j << std::endl;
    std::cout << "K :" << *k << std::endl;
    std::cout <<"====================================================" << std::endl;
  }
  return 0;
}
