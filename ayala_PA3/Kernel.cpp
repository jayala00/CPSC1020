/*
  Jonathan Ayala
  CPSC 1020-002, Sp18
  ayala
*/
#include "Kernel.h"

Kernel::Kernel() :
  Filter() {}

Kernel::Kernel(string name) :
  Filter(name) {}

Kernel::Kernel(const Kernel& f) :
  Filter(f.name) {}

Kernel::~Kernel() {}

/*
  Inputs: 3 integers:
          lo - lowest possible pixel value, 0
          hi - highest possible pixel value, 255
          x - the value of the selected pixel.
  Output: an integer value
  Purpose: checks to see if selected pixel value is the range of
    0-255.
*/
int Kernel::clamp(int lo, int hi, int x){
  return std::max(lo, std::min(x, hi));
}

/*
  Inputs: 3 doubles:
          lo - lowest possible pixel value, 0
          hi - highest possible pixel value, 255
          x - the value of the selected pixel.
  Output: an double value
  Purpose: checks to see if selected pixel value is the range of
    0-255.
*/
double Kernel::clamp(double lo, double hi, double x){
  return std::max(lo, std::min(x, hi));
}

/*
  Inputs: an Image obj.
          a constant Matrix object k
  Outputs: N/A because it is a void function.
  Purpose: The functions iterates through every pixel, except the edges, and
    applies the apply_kernel function to each pixel.
*/
void Kernel::apply(Image& img, const Matrix& k) const {
  Image clean(img);
  int mid = k.size()/2;
  int row = img.header().height();
  int col = img.header().width();

  for(int i = mid; i < (row - mid); i++){
    for(int j = mid; j < (col - mid); j++){
      img(j,i) = this->apply_kernel(clean,j,i,k);
    }
  }
}

/*
  Inputs: img - Image object
          x - the row of the Pixel
          y - the column of the pixel
          k - the k3 Matrix
  Outputs: a Pixel object
  Purpose: Takes in the surrounding pixels from the inputed pixel
    and makes a calculation from the matrix k.
*/
Pixel Kernel::apply_kernel(Image& img, int x, int y, const Matrix& k) const {
  int k_center = k.size()/2;
  int r, g, b;
  r = g = b = 0;

  // The kernel is centered at k_center (1 for a 3x3 kernel)
  // This loop takes values -1, 0, 1 which we can use as offsets
  // Nice because we can use as offsets for kernel and image pixel at x,y
  for (int j = -k_center; j <= k_center; j++) {
    for (int i = -k_center; i <= k_center; i++) {
      Pixel& p = img(x+i,y+i);
      double modifier = k[k_center+i][k_center+j];
      r += (int)(p.r() * modifier);
      g += (int)(p.g() * modifier);
      b += (int)(p.b() * modifier);
    }
  }

  // Make sure within RBG range of pixel
  r = clamp(0,255,r);
  g = clamp(0,255,g);
  b = clamp(0,255,b);

  return Pixel(r,g,b);
}
