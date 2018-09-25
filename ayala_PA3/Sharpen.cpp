/*
  Jonathan Ayala
  CPSC 1020-002, Sp18
  ayala
*/
#include "Sharpen.h"

Sharpen::Sharpen() : Kernel("") {}

Sharpen::Sharpen(string name) : Kernel(name) {}

Sharpen::Sharpen(const Sharpen& obj) : Kernel(obj.name) {}

// matrix that will sharpen the image wanted
const Matrix Sharpen::k3 =
{{ 0,-1, 0},
 {-1, 5,-1},
 { 0,-1, 0}};

 /*
   Inputs: an Image object
   Outpus: N/A because it is a void function
   Purpose: calls the Kernel's apply function to sharpen each pixel in the
    Image
 */
void Sharpen::apply(Image& img) const {
  Kernel::apply(img, k3);
}
