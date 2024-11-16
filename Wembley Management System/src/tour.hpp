#ifndef STADIUM_TOUR_H
#define STADIUM_TOUR_H

#include <string>

class StadiumTour
{
private:
    std::string ticketHolderName; // Name of the ticket holder
    std::string date;             // Date of the stadium tour
    static constexpr double TICKET_PRICE = 20.0; // Fixed ticket price

public:
    // Default constructor
    StadiumTour();

    // Parameterized constructor
    StadiumTour(std::string ticketHolderName, std::string date);

    // Getter and setter methods for ticket holder name
    std::string getTicketHolderName() const;
    void setTicketHolderName(const std::string &ticketHolderName);

    // Getter and setter methods for tour date
    std::string getDate() const;
    void setDate(const std::string &date);

    // Method to retrieve the total cost of the tour
    double getTotalCost() const;
};

#endif // STADIUM_TOUR_H
