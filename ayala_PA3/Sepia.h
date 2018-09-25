/*
  Jonathan Ayala
  CPSC 1020-002, Sp18
  ayala
*/
#ifndef SEPIA_H
#define SEPIA_H

#include "PixelF.h"
#include "Image.h"
#include <string>
#include <algorithm>

using namespace std;

class Sepia : public PixelF {
  public:
    //constructors
    Sepia();
    Sepia(string);
    Sepia(const Sepia&);
    ~Sepia();

    // apply_transform that will be implemented 
    virtual Pixel apply_transform(const Pixel&) const;
};

#endif
