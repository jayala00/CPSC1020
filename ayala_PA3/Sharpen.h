/*
  Jonathan Ayala
  CPSC 1020-002, Sp18
  ayala
*/
#ifndef SHARPEN_H
#define SHARPEN_H

#include <string>
#include <algorithm>
#include "Kernel.h"
#include "Image.h"

using namespace std;

class Sharpen : public Kernel {
  protected:
    static const Matrix k3;
  public:
    //constructors are public because this class isnt abstract
    Sharpen();
    Sharpen(string);
    Sharpen(const Sharpen&);
    // the apply function that will be implemented 
    virtual void apply(Image&) const;

};

#endif
