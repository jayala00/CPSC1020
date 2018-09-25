/*
  Jonathan Ayala
  CPSC 1020-002, Sp18
  ayala
*/
#include "Blur.h"

Blur::Blur() : Kernel("") {}

Blur::Blur(string name) : Kernel(name) {}

Blur::Blur(const Blur& obj) : Kernel(obj.name) {}

//This matrix function is the only thing different compared to Shapen's .cpp
const Matrix Blur::k3 =
{{0.0625,0.125 ,0.0625},
 {0.125 ,0.25  ,0.125 },
 {0.0625,0.125 ,0.0625}};

/*
  Inputs: an Image object
  Outpus: N/A because it is a void function
  Purpose: calls the Kernel's apply function to blur each pixel in the Image
*/
void Blur::apply(Image& img) const {
  Kernel::apply(img, k3);
}
