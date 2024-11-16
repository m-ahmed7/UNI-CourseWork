#ifndef EVENT_H
#define EVENT_H

#include <string>

// Declaration of the EventItem class
class EventItem
{
private:
    std::string type;        // Type of the event
    std::string date;        // Date of the event
    double ticketPrice;      // Price of the event's ticket

public:
    // Constructors
    EventItem();                                       // Default constructor
    EventItem(std::string type, std::string date, double ticketPrice); // Parameterized constructor with ticket price
    EventItem(std::string type, std::string date);    // Parameterized constructor without ticket price

    // Getter and setter methods for the event type
    std::string getType() const;
    void setType(const std::string &type);

    // Getter and setter methods for the event date
    std::string getDate() const;
    void setDate(const std::string &date);

    // Getter and setter methods for the event ticket price
    double getTicketPrice() const;
    void setTicketPrice(double ticketPrice);
};

#endif // EVENT_H
