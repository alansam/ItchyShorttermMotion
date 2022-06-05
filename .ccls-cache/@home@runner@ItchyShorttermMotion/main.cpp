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
