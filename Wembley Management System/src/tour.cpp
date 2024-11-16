#include "tour.hpp"  // Include the header file for the StadiumTour class

// Default constructor for the StadiumTour class
StadiumTour::StadiumTour() {}

// Parameterized constructor for the StadiumTour class
StadiumTour::StadiumTour(std::string ticketHolderName, std::string date)
    : ticketHolderName(ticketHolderName), date(date) {}

// Getter method for retrieving the ticket holder's name
std::string StadiumTour::getTicketHolderName() const
{
    return ticketHolderName;
}

// Setter method for setting the ticket holder's name
void StadiumTour::setTicketHolderName(const std::string &ticketHolderName)
{
    this->ticketHolderName = ticketHolderName;
}

// Getter method for retrieving the date of the stadium tour
std::string StadiumTour::getDate() const
{
    return date;
}

// Setter method for setting the date of the stadium tour
void StadiumTour::setDate(const std::string &date)
{
    this->date = date;
}

// Getter method for retrieving the total cost of the stadium tour
double StadiumTour::getTotalCost() const
{
    return TICKET_PRICE; // Fixed ticket price for stadium tour
}
