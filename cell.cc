#include "cell.h"
#include<algorithm>
Cell::Cell(){
  alive=false;
  flipped=false;
}

Cell::~Cell(){
  delete(&neighbours);
}
void Cell::setAlive(bool t){
  alive = t;
}
bool Cell::getAlive() const {
  return alive;
}
void Cell::setFlipped(bool t){
  flipped = true;
}
bool Cell::getFlipped() const{
  return flipped;
}
void Cell::addNeighbour(Cell *c){
  if (!this->knowsAbout(c)){
    neighbours.push_back(c);
    c->addNeighbour(this);
  }
}
void Cell::flip() {
  std::vector<const Cell*>::iterator it;
  int alives = 0;
  if (flipped){
    alive =!alive;
    flipped = false;
  }
  for(it = neighbours.begin(); it < neighbours.end(); it++){
    if ((*it)->getAlive()) alives++;
  }
  switch(alives){
  case 2:
    break;
  case 3:
    if(!alive)
      flipped = true;
    break;
  default:
    if(alive)
      flipped = true;
  }
}
bool Cell::knowsAbout(const Cell *c) const {
  bool found = false;
  if (std::find(neighbours.begin(), neighbours.end(), c) != neighbours.end()) found = true;
  return found;
}

std::ostream &  operator<<(std::ostream &os, const Cell &c){
  os << "Alive: " << c.alive << "\tFlipped: " << c.flipped 
     << "\tNeighbours: " << c.neighbours.size();
  return os;
}
