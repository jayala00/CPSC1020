/*
  Jonathan Ayala
  CPSC 1020-002, Sp18
  ayala
*/
#include "Grayscale.h"

Grayscale::Grayscale() :
  PixelF() {}

Grayscale::Grayscale(string name) :
  PixelF(name) {}

Grayscale::Grayscale(const Grayscale& obj) :
  PixelF(obj.name) {}

Grayscale::~Grayscale() {}

/*
  Inputs: constant Pixel object
  Ouptut: a new modified Pixel object
  Purpose: go through each pixel and add all the rgb values then
    divide it by 3. Then ensure that the new value is within the 0-255 range
    and put the new values into a new Pixel object and return it out.
*/
Pixel Grayscale::apply_transform(const Pixel& pix) const{
  int sumRGB = (pix.r() + pix.g() + pix.b()) /  3;

  sumRGB = PixelF::clamp(0,255,sumRGB);

  Pixel newpix(sumRGB, sumRGB, sumRGB);
return newpix;
}
