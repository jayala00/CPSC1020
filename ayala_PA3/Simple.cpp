/*
  Jonathan Ayala
  CPSC 1020-002, Sp18
  ayala
*/
#include "Simple.h"

Simple::Simple() :
  Filter() {}

Simple::Simple(string name) :
  Filter(name) {}

Simple::Simple(const Simple& obj) :
  Filter(obj.name) {}

Simple::~Simple() {}
