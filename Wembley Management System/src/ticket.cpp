#include "ticket.hpp"  // Include the header file for the Ticket class

// Default constructor for the Ticket class
Ticket::Ticket() {}

// Parameterized constructor for the Ticket class
Ticket::Ticket(std::string event, double price)
    : event(event), price(price) {}

// Getter method to retrieve the event name
std::string Ticket::getEvent() const
{
    return event;
}

// Setter method to set the event name
void Ticket::setEvent(const std::string &event)
{
    this->event = event;
}

// Getter method to retrieve the ticket price
double Ticket::getPrice() const
{
    return price;
}

// Setter method to set the ticket price
void Ticket::setPrice(double price)
{
    this->price = price;
}
