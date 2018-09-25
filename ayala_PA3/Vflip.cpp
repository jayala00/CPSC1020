/*
  Jonathan Ayala
  CPSC 1020-002, Sp18
  ayala
*/
#include "Vflip.h"

Vflip::Vflip() :
  Simple() {}

Vflip::Vflip(string name) :
  Simple(name) {}

Vflip::Vflip(const Vflip& obj) :
  Simple(obj.name) {}

  /*
    Inputs: Image object
    Output: N/A because it is a void function
    Purpose: rearrange the pixels so that they are flipped from top to bottom
  */
void Vflip::apply(Image& img) const {
  int row = img.header().height();
  int col = img.header().width();

  for (int i = 0; i < (row/2); i++){
    for (int j = 0; j < col; j++){
      swap(img(j,i), img(j,row -i-1));
    }

  }
}
