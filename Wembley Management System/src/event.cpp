#include "event.hpp" // Include the header file for the EventItem class

// Default constructor
EventItem::EventItem() {}

// Parameterized constructor with type, date, and ticketPrice
EventItem::EventItem(std::string type, std::string date, double ticketPrice)
    : type(type), date(date), ticketPrice(ticketPrice) {}

// Parameterized constructor with type and date (without ticketPrice)
EventItem::EventItem(std::string type, std::string date)
    : type(type), date(date) {}

// Getter method for retrieving the type of the event
std::string EventItem::getType() const
{
    return type;
}

// Setter method for updating the type of the event
void EventItem::setType(const std::string &type)
{
    this->type = type;
}

// Getter method for retrieving the date of the event
std::string EventItem::getDate() const
{
    return date;
}

// Setter method for updating the date of the event
void EventItem::setDate(const std::string &date)
{
    this->date = date;
}

// Getter method for retrieving the ticket price of the event
double EventItem::getTicketPrice() const
{
    return ticketPrice;
}

// Setter method for updating the ticket price of the event
void EventItem::setTicketPrice(double ticketPrice)
{
    this->ticketPrice = ticketPrice;
}
