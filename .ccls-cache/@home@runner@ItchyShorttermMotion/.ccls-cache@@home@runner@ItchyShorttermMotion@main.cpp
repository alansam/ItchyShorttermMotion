/*
hello my freind let ask some question about constructur
i dont understand full function of constructor 
initialize as given member value
#include "passenger.h"
*/

#include <iostream>
#include <iomanip>
#include <string>

#include "part.hpp"

using namespace std::literals::string_literals;


//  useful constants
part const NO_TICK(0);
part const HAS_TICK(1);

// syntax class constructor
class passenger {
private:
    std::string name;
    bool hve_ticket;
    std::string ticketname;
    part working;

public:
  // default consructor
  passenger();

  passenger(std::string const & name,
            part namepart,
            std::string const & tickname = "NONE");

  passenger(std::string const s_name,
            std::string const s_ticket = "NONE",
            part const n_work = NO_TICK);

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

// default constructor
passenger::passenger() {
    name = "--NO NAME--";
    working = NO_TICK;
    hve_ticket = false;
    ticketname = "NONE";
}

// constructor given member values
passenger::passenger(std::string const & namet,
                     part namepart,
                     std::string const & ticketname_2) {
    name = namet;
    working = namepart;
    hve_ticket = (ticketname_2 != "NONE"s);   //true only if ticketnamrt_2 given
    ticketname = ticketname_2; 
}

// copy constructor
passenger::passenger(const passenger & pass) {
    name = pass.name;
    hve_ticket = pass.hve_ticket;
    ticketname = pass.ticketname;
    working = pass.working;
}

passenger::passenger(std::string const s_name,
            std::string const s_ticket,
            part const n_work)
  : name(s_name),
    ticketname(s_ticket),
    working(n_work) {
    hve_ticket = (s_ticket != "NONE");
  }

int main(int argc, char const * argv[]) {
  passenger p1("Who Diss"s, "There & Back Again"s, HAS_TICK);
  passenger p2("Who Dat"s, NO_TICK, "NONE"s);
  passenger p3(p1);
  p3.set_working(
    p3.get_working().num(
      p3.get_working().num() + 10
    )
  );
  passenger p4 = p2;
  std::cout << "Testing...\n";
  std::cout << p1 << std::endl;
  std::cout << p2 << std::endl;
  std::cout << p3 << std::endl;
  std::cout << p4 << std::endl;
  std::cout << "Done!\n";

  return 0;
}
