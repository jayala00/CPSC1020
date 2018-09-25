/*
  Jonathan Ayala
  CPSC 1020-002, Sp18
  ayala
*/
#include "Binary.h"

Binary::Binary() :
  PixelF(" "), col1(46,40,219), col2(0,0,0) {}


Binary::Binary(const Binary& obj) :
  PixelF(obj.name), col1(obj.col1), col2(obj.col2) {}


Binary::~Binary() {}

/*
  Inputs: constant Pixel object
  Output: another Pixel object
  What this function does: Based on the 2 colors chosen in the constructor,
    you use the luminance function on the inputed Pixel object and if the
    luminance value is greater than half of the greates pixel value, the Pixel
    object would equal one color, else it equals the next color.
*/
Pixel Binary::apply_transform(const Pixel& pix) const {

  if (pix.luminance() > col1.r()) {
    return col2;
  }
  else {
    return col1;
  }
}
