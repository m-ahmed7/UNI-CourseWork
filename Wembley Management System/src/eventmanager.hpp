#ifndef EVENT_MANAGER_H
#define EVENT_MANAGER_H

#include "event.hpp"  // Include the header file for the EventItem class
#include <vector>     // Include necessary header file for vector container

// Declaration of the EventManager class
class EventManager
{
private:
    std::vector<EventItem> events;  // Vector to store EventItem objects

public:
    // Constructor
    EventManager();

    // Methods
    void addEvent(const EventItem &event);                 // Method to add an event
    void removeEvent(const std::string &type, const std::string &date); // Method to remove an event
    void listEvents() const;                               // Method to list all events
};

#endif // EVENT_MANAGER_H
