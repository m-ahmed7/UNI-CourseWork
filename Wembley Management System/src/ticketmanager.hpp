#ifndef TICKET_MANAGER_H
#define TICKET_MANAGER_H

#include "ticket.hpp"  // Include the header file for the Ticket class
#include <vector>      // Include necessary header file for vector container

// Declaration of the TicketManager class
class TicketManager
{
private:
    std::vector<Ticket> tickets;  // Vector to store Ticket objects

public:
    // Constructor
    TicketManager();

    // Method to add a ticket to the manager
    void addTicket(const Ticket &ticket);
};

#endif // TICKET_MANAGER_H
