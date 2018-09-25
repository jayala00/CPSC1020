/*
  Jonathan Ayala
  CPSC 1020-002, Sp18
  ayala
*/
#include "Sepia.h"

Sepia::Sepia() :
  PixelF() {}

Sepia::Sepia(string name) :
  PixelF(name) {}

Sepia::Sepia(const Sepia& obj) :
  PixelF(obj.name) {}

Sepia::~Sepia() {}

/*
  Inputs: pix - constant pixel object
  Outputs: pixel object that is being transformed
  Purpose: change the rgb pixels to sRGB. then switched to lRGB using
    gamma_expansion. After, I checked if their value was greater than one then
    once, i reverted the pixel values back to their base "255" value.
*/
Pixel Sepia::apply_transform(const Pixel& pix) const {
  //to sRGB
  double sR, sG, sB;
  sR = (double) pix.r() / 255.0;
  sG = (double) pix.g() / 255.0;
  sB = (double) pix.b() / 255.0;
  //to lRGB
  double lR, lG, lB;
  lR = Pixel::gamma_expansion(sR);
  lG = Pixel::gamma_expansion(sG);
  lB = Pixel::gamma_expansion(sB);
  // sepia forumula
  sR = (lR * .393) + (lG *.769) + (lB * .189);
	sG = (lR * .349) + (lG *.686) + (lB * .168);
	sB = (lR * .272) + (lG *.534) + (lB * .131);

  double newR, newG, newB;

  if (sR > 1.0){
    newR = Pixel::inverse_gamma(1.0);
  }
  else{
    newR = Pixel::inverse_gamma(sR);
  }
  if (sG > 1.0){
    newG = Pixel::inverse_gamma(1.0);
  }
  else{
    newG = Pixel::inverse_gamma(sG);
  }
  if (sB > 1.0){
    newB = Pixel::inverse_gamma(1.0);
  }
  else{
    newB = Pixel::inverse_gamma(sB);
  }
  // reverts the pixel values back to its original "255" scale
  newR = newR * 255.0;
  newG = newG * 255.0;
  newB = newB * 255.0;
  Pixel newpix((uint8_t)(newR),(uint8_t)(newG),(uint8_t)(newB));
  return newpix;
}
