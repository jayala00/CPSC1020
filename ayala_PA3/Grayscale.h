/*
  Jonathan Ayala
  CPSC 1020-002, Sp18
  ayala
*/
#ifndef GRAYSCALE_H
#define GRAYSCALE_H

#include "PixelF.h"
#include "Image.h"
#include <string>
#include <algorithm>

using namespace std;

class Grayscale : public PixelF {
  public:
    //constructors
    Grayscale();
    Grayscale(string);
    Grayscale(const Grayscale&);
    ~Grayscale();

    // the apply_transform function that will be implemented in the .cpp
    virtual Pixel apply_transform(const Pixel&) const;
};

#endif
