/*
  Jonathan Ayala
  CPSC 1020-002, Sp18
  ayala
*/
#ifndef PIXELF_H
#define PIXELF_H

#include <string>
#include <algorithm>
#include "Filter.h"
#include "Image.h"

using namespace std;

class PixelF : public Filter {
  protected:
    // constructors
    PixelF();
    PixelF(string);
    PixelF(const PixelF&);
  public:
    // destructor 
    virtual ~PixelF() = 0;
    static int clamp(int lo, int hi, int x);
    static double clamp(double lo, double hi, double x);
    //the following are given from the write up
    virtual void apply(Image&) const;
    virtual Pixel apply_transform(const Pixel&) const = 0;
};

#endif
