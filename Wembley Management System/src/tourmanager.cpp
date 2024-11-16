#include "tourmanager.hpp"
#include <iostream>

// Default constructor for TourManager
TourManager::TourManager() {}

// Method to book tickets for a tour
void TourManager::bookTickets()
{
    // Prompt user for booking details
    std::cout << "\nBooking Tickets:" << std::endl;
    std::cout << "Enter your name: ";
    std::string name;
    std::cin >> name;
    std::cout << "Enter tour date: ";
    std::string date;
    std::cin >> date;
    std::cout << "Enter number of tickets: ";
    int numTickets;
    std::cin >> numTickets;

    // Calculate total cost based on number of tickets
    double totalCost = calculateTotalCost(numTickets);

    // Create new tour object with booking details
    Tour newTour(name, date, numTickets, totalCost);
    
    // Add the new tour to the list of booked tickets
    tickets.push_back(newTour);

    // Save booking details to file
    saveBookingDetails(newTour);

    std::cout << "Tickets booked successfully!" << std::endl;
}

// Method to calculate the total cost based on number of tickets
double TourManager::calculateTotalCost(int numberOfTickets)
{
    // Assuming ticket price is £20 per ticket
    double ticketPrice = 20.0;
    return numberOfTickets * ticketPrice;
}

// Method to save booking details to a file
void TourManager::saveBookingDetails(const Tour &tour)
{
    // Open file for appending
    std::ofstream outFile("tickets.txt", std::ios_base::app);
    if (outFile.is_open())
    {
        // Write booking details to file
        outFile << "Ticket Holder: " << tour.ticketHolderName << ", Tour Date: " << tour.tourDate
                << ", Number of Tickets: " << tour.numberOfTickets << ", Total Cost: £" << tour.totalCost << std::endl;
        outFile.close(); // Close the file
    }
    else
    {
        // Display error message if file opening fails
        std::cerr << "Error opening tickets file for writing." << std::endl;
    }
}
