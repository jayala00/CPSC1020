/*
  Jonathan Ayala
  CPSC 1020-002, Sp18
  ayala
*/
#include "Filter.h"

Filter::Filter() :
  name("") {}

Filter::Filter(string name) :
  name(name) {}

Filter::Filter(const Filter& f) :
  name(f.name)  {}

Filter::~Filter() {}

/*
  Inputs: 3 integers:
          lo - lowest possible pixel value, 0
          hi - highest possible pixel value, 255
          x - the value of the selected pixel.
  Output: an integer value
  Purpose: checks to see if selected pixel value is the range of
    0-255.
*/
int Filter::clamp (int lo, int hi, int x) {
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
double Filter::clamp (double lo, double hi, double x) {
  return std::max(lo, std::min(x, hi));
}
