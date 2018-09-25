/*
  Jonathan Ayala
  CPSC 1020-002, Sp18
  ayala
*/
#ifndef HFLIP_H
#define HFLIP_H

#include "Image.h"
#include "Simple.h"
#include <string>
#include <algorithm>

using namespace std;

class Hflip : public Simple {
  public:
    //constructors
    Hflip();
    Hflip(string);
    Hflip(const Hflip&);

    // the apply function that will be implemented in the .cpp
    virtual void apply(Image&) const;
};
#endif
