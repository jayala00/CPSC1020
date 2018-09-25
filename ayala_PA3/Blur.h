/*
  Jonathan Ayala
  CPSC 1020-002, Sp18
  ayala
*/
#ifndef BLUR_H
#define BLUR_H

#include <string>
#include <algorithm>
#include "Kernel.h"
#include "Image.h"

using namespace std;

class Blur : public Kernel {
  protected:
    // this is here because this class utilizes a matrix for the apply
    // function
    static const Matrix k3;
  public:
    //constructors for the class
    Blur();
    Blur(string);
    Blur(const Blur&);

    // the apply function that will be implemented
    virtual void apply(Image&) const;

};

#endif
