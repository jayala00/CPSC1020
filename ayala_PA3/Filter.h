/*
  Jonathan Ayala
  CPSC 1020-002, Sp18
  ayala
*/
#ifndef FILTER_H
#define FILTER_H

#include <string>
#include <algorithm>
#include "Image.h"

using namespace std;

class Filter {
  protected:
    // Data - Shows that abstract classes can still contain data
    string name;

    // Derived classes need these visible
    Filter();
    Filter(string);
    Filter(const Filter&);

  public:
    // Pure virtual destructor - Still needs definition!
    // This will be in the .cpp file even though it is pure virtual,
    // becuase it is a destructor
    virtual ~Filter () = 0;

    // Static helpers - should be a template
    static int clamp (int lo, int hi, int x);
    static double clamp (double lo, double hi, double x);

    // Public Interface - every derived class must implement
    //                  - or be abstract itself
    // Since this is a pure virtual and not a destructor, this wont be
    // in the .cpp file
    virtual void apply (Image&) const = 0;
};

#endif
