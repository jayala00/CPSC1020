/*
  Jonathan Ayala
  CPSC 1020-002, Sp18
  ayala
*/
#include "Hflip.h"

Hflip::Hflip() :
  Simple() {}

Hflip::Hflip(string name) :
  Simple(name) {}

Hflip::Hflip(const Hflip& obj) :
  Simple(obj.name) {}

/*
  Inputs: Image object
  Output: N/A because it is a void function
  Purpose: rearrange the pixels so that they are flipped from right to left.
*/
void Hflip::apply(Image& img) const {
  int row = img.header().height();
  int col = img.header().width();

  for (int i = 0; i < row; i++){
    for (int j = 0; j < (col/2); j++){
      swap(img(j,i), img(col-j-1,i));
    }
  }
}
