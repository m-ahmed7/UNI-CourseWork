#ifndef TICKET_H
#define TICKET_H

#include <string>  // Include necessary header file for string manipulation

// Declaration of the Ticket class
class Ticket
{
private:
    std::string event;  // Name of the event associated with the ticket
    double price;       // Price of the ticket

public:
    // Constructors
    Ticket();                              // Default constructor
    Ticket(std::string event, double price); // Parameterized constructor

    // Getter and setter methods for the event name
    std::string getEvent() const;
    void setEvent(const std::string &event);

    // Getter and setter methods for the ticket price
    double getPrice() const;
    void setPrice(double price);
};

#endif // TICKET_H
