/*
hello my freind let ask some question about constructur
i dont understand full function of constructor 
initialize as given member value
#include "passenger.h"
*/

#include <iostream>
#include <iomanip>
#include <string>

#include "passenger.hpp"

using namespace std::literals::string_literals;

//  MARK: - Class passenger Implementation
// copy constructor
passenger::passenger(const passenger & pass) {
    name = pass.name;
    hve_ticket = pass.hve_ticket;
    ticketname = pass.ticketname;
    working = pass.working;
}

// default constructor
// constructor given member values
passenger::passenger(std::string const s_name,
            std::string const s_ticket,
            part const n_work)
  : name { s_name },
    ticketname { s_ticket },
    working { n_work },
    hve_ticket { (s_ticket != "NONE"s) } {}

//  MARK: - Driver
/*
 *  MARK: main()
 */
int main(int argc, char const * argv[]) {
  passenger p1("Who Diss"s, "There & Back Again"s, KP::HAS_TICK);
  passenger p2("Who Dat"s, "NONE"s, KP::NO_TICK);
  passenger p3(p1);
  p3.set_working(
    p3.get_working().num(
      p3.get_working().num() + 10
    )
  );
  passenger p4 = p2;
  passenger p5;
  std::cout << "Testing...\n";
  std::cout << p1 << std::endl;
  std::cout << p2 << std::endl;
  std::cout << p3 << std::endl;
  std::cout << p4 << std::endl;
  std::cout << p5 << std::endl;
  std::cout << "Done!\n";

  return 0;
}
