#ifndef CELL_H
#define CELL_H
#include<vector>
#include<iostream>
class Cell {
protected:
  bool alive;
  bool flipped;
  bool knowsAbout (const Cell*) const;
  std::vector<const Cell*> neighbours;
public:
  void setAlive(bool);
  bool getAlive() const;
  void setFlipped(bool);
  bool getFlipped() const;
  void addNeighbour(Cell*);
  void flip();
  friend std::ostream &  operator<<(std::ostream &os, const Cell &c);
  Cell();
  ~Cell();
};
#endif
