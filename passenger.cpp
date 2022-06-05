
#include "passenger.hpp"

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
