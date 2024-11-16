#include "ticketmanager.hpp"  // Include the header file for TicketManager class

// Constructor for the TicketManager class
TicketManager::TicketManager() {}

// Method to add a ticket to the TicketManager
void TicketManager::addTicket(const Ticket &ticket)
{
    tickets.push_back(ticket);  // Add the ticket to the internal vector
}
