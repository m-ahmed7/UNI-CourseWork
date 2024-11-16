#include "eventmanager.hpp" // Include the header file for the EventManager class
#include <iostream>         // Include necessary header file for input/output operations
#include <fstream>          // Include necessary header file for file input/output operations

// Constructor for the EventManager class
EventManager::EventManager() {}

// Method to add an event to the event list and write its details to the 'events.txt' file
void EventManager::addEvent(const EventItem &event) {
    events.push_back(event);  // Add the event to the existing list

    // Open the 'events.txt' file in append mode to add new events without deleting old ones
    std::ofstream file("events.txt", std::ios::app);

    // Check if the file is successfully opened
    if (file.is_open()) {
        // Write the event details to the file
        file << "Event Type: " << event.getType() << ", Date: " << event.getDate() << std::endl;
        file.close();  // Close the file after writing to free system resources
    } else {
        std::cerr << "Failed to open events.txt" << std::endl;  // Error message if file opening fails
    }
}

// Method to remove an event from the event list based on type and date
void EventManager::removeEvent(const std::string &type, const std::string &date) {
    for (auto it = events.begin(); it != events.end(); ++it) {
        if (it->getType() == type && it->getDate() == date) {
            events.erase(it);  // Remove the event from the list
            break;
        }
    }
}

// Method to list all events in the event list
void EventManager::listEvents() const {
    std::cout << "List of events:" << std::endl;
    for (const auto &event: events) {
        std::cout << "Type: " << event.getType() << ", Date: " << event.getDate() << std::endl;
    }
}
