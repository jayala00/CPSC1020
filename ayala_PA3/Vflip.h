/*
  Jonathan Ayala
  CPSC 1020-002, Sp18
  ayala
*/
#ifndef VFLIP_H
#define VFLIP_H

#include "Image.h"
#include "Simple.h"
#include <string>
#include <algorithm>
#include <vector>

using namespace std;


class Vflip : public Simple {
  public:
    //constructors
    Vflip();
    Vflip(string);
    Vflip(const Vflip&);

    // the apply function that will be implemented in the .cpp
    virtual void apply(Image&) const;
};

#endif
