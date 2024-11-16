#ifndef TOUR_MANAGER_H
#define TOUR_MANAGER_H

#include "tour.hpp"
#include <vector>
#include <fstream>

// Modify the struct name to Tour
struct Tour
{
    std::string ticketHolderName;
    std::string tourDate;
    int numberOfTickets;
    double totalCost;

    // Constructor for initializing Tour struct members
    Tour(std::string name, std::string date, int numTickets, double cost)
        : ticketHolderName(name), tourDate(date), numberOfTickets(numTickets), totalCost(cost) {}
};

class TourManager
{
private:
    std::vector<StadiumTour> tours;
    std::vector<Tour> tickets; // New vector to store booked tours

public:
    TourManager();

    // Methods
    void addTour(const StadiumTour &tour);
    void removeTour(const std::string &date, const std::string &time);
    void listAvailableTours() const;
    void bookTickets();
    double calculateTotalCost(int numberOfTickets);
    void saveBookingDetails(const Tour &tour);
};

#endif // TOUR_MANAGER_H
