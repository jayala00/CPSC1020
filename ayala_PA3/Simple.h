/*
  Jonathan Ayala
  CPSC 1020-002, Sp18
  ayala
*/
#ifndef SIMPLE_H
#define SIMPLE_H

#include <string>
#include <algorithm>
#include "Filter.h"
#include "Image.h"

using namespace std;
//using Matrix = vector<vector<double>>;

class Simple : public Filter {
  protected:
    // following constructors are protected because kernel is abstract
    Simple();
    Simple(string);
    Simple(const Simple&);
  public:
    // these are pure virtual void because they wont be implemented,
    // except for the destructor, which is always implemented.
    virtual ~Simple() = 0;
    virtual void apply(Image&) const = 0;
};

#endif
