#pragma once

#include <iostream>
#include <iomanip>
#include <string>

#include "part.hpp"

using namespace std::literals::string_literals;

// syntax class constructor
class passenger {
private:
    std::string name;
    bool hve_ticket;
    std::string ticketname;
    part working;

public:
  // default consructor
  passenger(std::string const s_name = "--NO NAME--"s,
            std::string const s_ticket = "NONE"s,
            part const n_work = KP::NO_TICK);

  // copy constructor
  passenger(passenger const & depart);

  // move constructor - defaulted for now
  passenger(passenger && depart) = default;

  //  destructor
  ~passenger() = default;

  //  Aaaignment - defaulted for now
  passenger & operator=(passenger const & that) = default;
  passenger & operator=(passenger && that) = default;

  //  getters/setters
  std::string get_name(void) { return name; }
  std::string set_name(std::string const nm) { return (name = nm); }
  std::string get_ticketname(void) { return ticketname; }
  std::string set_ticketname(std::string const tn) { return (ticketname = tn); }
  bool has_ticket(void) { return hve_ticket; }
  bool has_ticket(bool const ht) { return (hve_ticket = ht); }
  part & get_working(void) { return working; }
  part & set_working(part const & wk) { return (working = wk); }

  // format object for output
  friend
  std::ostream & operator<<(std::ostream & os, passenger const & that) {
    os << that.name << ", "s
       << std::boolalpha
       << that.hve_ticket << ", "s
       << that.ticketname << ", "s
       << that.working;
    return os;
  }
};
