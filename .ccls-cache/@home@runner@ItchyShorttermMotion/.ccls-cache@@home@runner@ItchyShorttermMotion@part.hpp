#pragma once

#include <iostream>
#include <iomanip>

class part {
public:
  //  default constructor
  part(int num = 0) : num_ { num } {}
  //  copy and move ctors - default for now
  part(part const & that) = default;
  part(part && that) = default;

  //  dtor - default for now
  ~part() = default;

  //  copy assignment
  part & operator=(part const & that) {
    this->num_ = that.num_;
    return *this;
  }
  //  move assignment
  part & operator=(part && that) = default;

  //  getters/setters
  int num(void) const { return num_; }
  int num(int nr) { return (num_ = nr); }

  // format object for output
  friend
  std::ostream & operator<<(std::ostream & os, part const & that) {
    os << "part no:"s
       << std::setw(5)
       << that.num();
    return os;
  }

private:
  int num_;
};
