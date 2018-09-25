/*
  Jonathan Ayala
  CPSC 1020-002, Sp18
  ayala
*/
#ifndef BINARY_H
#define BINARY_H

#include "PixelF.h"
#include "Image.h"
#include <string>
#include <algorithm>
#include <iostream>
#include "Pixel.h"


using namespace std;

class Binary : public PixelF {
  // 2 Pixel variables are created in order to have the colors wanted for this
  // filter.
  protected:
    Pixel col1;
    Pixel col2;
  public:
    // Constructors needed for this class
    Binary();
    Binary(const Binary&);
    ~Binary();
    //The apply_transform that will be implemented in this class
    virtual Pixel apply_transform(const Pixel&) const;
};

#endif
