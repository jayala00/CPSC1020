/*
  Jonathan Ayala
  CPSC 1020-002, Sp18
  ayala
*/
#ifndef KERNEL_H
#define KERNEL_H

#include <string>
#include <algorithm>
#include "Filter.h"
#include "Image.h"

using namespace std;
using Matrix = vector<vector<double>>;

class Kernel : public Filter {
  protected:
    // following constructors are protected because kernel is abstract
    Kernel();
    Kernel(string);
    Kernel(const Kernel&);
    // these are given from the write up
    virtual void apply(Image&, const Matrix&) const;
    virtual Pixel apply_kernel(Image&, int x, int y, const Matrix&) const;
  public:
    virtual ~Kernel() = 0;
    static int clamp(int lo, int hi, int x);
    static double clamp(double lo, double hi, double x);
    virtual void apply(Image&) const = 0;
};

#endif
