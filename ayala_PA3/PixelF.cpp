/*
  Jonathan Ayala
  CPSC 1020-002, Sp18
  ayala
*/
#include "PixelF.h"

PixelF::PixelF() :
  Filter() {}

PixelF::PixelF(string name) :
  Filter(name) {}

PixelF::PixelF(const PixelF& obj) :
  Filter(obj.name) {}

PixelF::~PixelF() {}

/*
  Inputs: 3 integers:
          lo - lowest possible pixel value, 0
          hi - highest possible pixel value, 255
          x - the value of the selected pixel.
  Output: an integer value
  Purpose: checks to see if selected pixel value is the range of
    0-255.
*/
int PixelF::clamp(int lo, int hi, int x){
  return std::max(lo, std::min(x, hi));
}

/*
  Inputs: 3 double:
          lo - lowest possible pixel value, 0
          hi - highest possible pixel value, 255
          x - the value of the selected pixel.
  Output: an double value
  Purpose: checks to see if selected pixel value is the range of
    0-255.
*/
double PixelF::clamp(double lo, double hi, double x){
  return std::max(lo, std::min(x, hi));
}

/*
  Inputs: img - Image object
  Outputs: N/A because it is a void function
  Purpose: loops through each pixel and calls the apply_transform
    function to the specified pixel.
*/
void PixelF::apply(Image& img) const {
  int row = img.header().height();
  int col = img.header().width();



  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col ; j++) {
      Pixel& pix = img(j,i);
      img(j,i) = this->apply_transform(pix);
    }
  }
}
