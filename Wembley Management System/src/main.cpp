#include <iostream>
#include <fstream>
#include <sstream>
#include <limits>
#include "admin.hpp"
#include "adminmanager.hpp"
#include "event.hpp"
#include "eventmanager.hpp"
#include "user.hpp"
#include "usermanager.hpp"
#include "ticket.hpp"
#include "ticketmanager.hpp"
#include "tour.hpp"
#include "tourmanager.hpp"

std::vector<EventItem> loadEvents(const std::string &filename)
{
    std::vector<EventItem> events;
    std::ifstream file(filename);
    std::string line;

    while (getline(file, line))
    {
        std::stringstream ss(line);
        std::string type, date;
        getline(ss, type, ',');                 // Read until the comma
        type = type.substr(type.find(":") + 2); // Skip "Event Type: "
        getline(ss, date);
        date = date.substr(date.find(":") + 2); // Skip "Date: "
        events.push_back(EventItem(type, date));
    }

    return events;
}

int InputOptions(int lower, int upper) // input option validation
{
    int choice = 0;
    while (!(std::cin >> choice) || choice < lower || choice > upper) // while input is outside of option bounds
    {

        std::cin.clear();

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // only accept integers

        std::cout << "This field accepts numbers between " << lower << " and " << upper << ": ";
    }
    return choice;
}
// Function to write ticket purchase details to tickets.txt

double readTicketPriceFromEvents(const std::string &eventName, const std::string &eventDate)
{
    std::ifstream inFile("events.txt");
    if (inFile.is_open())
    {
        std::string line;
        while (std::getline(inFile, line))
        {
            // Assuming the format in events.txt is "Event Name: eventName, Event Date: eventDate, Ticket Price: ticketPrice"
            if (line.find("Event Name: " + eventName) != std::string::npos && line.find("Event Date: " + eventDate) != std::string::npos)
            {
                size_t pos = line.find("Ticket Price: ");
                if (pos != std::string::npos)
                {
                    std::istringstream iss(line.substr(pos + 14));
                    double ticketPrice;
                    iss >> ticketPrice;
                    std::cout << "Found ticket price: " << ticketPrice << std::endl;
                    return ticketPrice;
                }
            }
        }
        inFile.close();
    }
    std::cerr << "Ticket price not found for event: " << eventName << " on date: " << eventDate << std::endl;
    return 0.0;
}
void writeTicketPurchase(const std::string &username, const std::string &eventType, const std::string &eventDate, int numTickets, double ticketPrice)
{
    std::ofstream outFile("tickets.txt", std::ios::app); // Append mode
    if (outFile.is_open())
    {
        // Write ticket purchase details to file, including ticket price
        outFile << "Username: " << username << ", Event Type: " << eventType << ", Event Date: " << eventDate << ", Number of Tickets: " << numTickets << ", Ticket Price: " << ticketPrice << std::endl;
        outFile.close();
    }
    else
    {
        std::cerr << "Error: Unable to open tickets.txt for writing." << std::endl;
    }
}

void writeEvent(const std::string &eventName, const std::string &eventDate, double ticketPrice)
{
    std::ofstream outFile("events.txt", std::ios::app); // Open file in append mode
    if (outFile.is_open())
    {
        // Write event details to the file
        outFile << "Event Name: " << eventName << ", Event Date: " << eventDate << ", Ticket Price: " << ticketPrice << std::endl;
        outFile.close(); // Close the file
    }
    else
    {
        std::cerr << "Error: Unable to open events.txt for writing." << std::endl;
    }
}

int main()
{
    std::string filename = "events.txt"; // The path to events file
    auto events = loadEvents(filename);

    AdminManager adminManager;
    EventManager eventManager;
    UserManager userManager;

    // start menu options
    enum Options
    {
        startMenu,
        adminLogin,
        userLogin,
        exit
    };
    Options option = startMenu;

    // admin options
    enum AdminOptions
    {
        adminMenu,
        addAdmin,
        addEvent,
        viewTickets,
        addAnotherUser,
        adminLogOut,
        adminExit
    };
    AdminOptions adminOption = adminMenu;

    // user options
    enum UserOptions
    {
        userMenu,
        buyTickets,
        BookTour,
        viewEvents,
        userLogOut,
        userExit
    };
    UserOptions userOption = userMenu;

    // Create admin manager and add default admin
    Admin defaultAdmin("admin", "admin123");
    adminManager.addAdmin(defaultAdmin);
    // Create user manager and add users
    User user1("user1", "password1");
    userManager.addUser(user1);
    User user2("user2", "password2");
    userManager.addUser(user2);

    while (option != exit)
    {

        if (option == startMenu)
        {

            adminOption = adminMenu;
            userOption = userMenu;

            std::cout << "Welcome to the Stadium Management System!" << std::endl;
            std::cout << "Please select an option:" << std::endl;
            std::cout << "1. Admin Login" << std::endl;
            std::cout << "2. User Login" << std::endl;
            std::cout << "3. Exit" << std::endl;
            std::cout << "Enter your choice: ";

            option = static_cast<Options>(InputOptions(1, 3)); // input
        }

        else if (option == adminLogin) // admin login
        {
            std::string adminUsername, adminPassword;
            std::cout << "Enter admin username: ";
            std::cin >> adminUsername;
            std::cout << "Enter admin password: ";
            std::cin >> adminPassword;

            if (adminManager.validateAdmin(adminUsername, adminPassword)) // checks if admin login details are correct
            {

                std::cout << "Admin login successful." << std::endl;

                while (option == adminLogin) // while the admin is logged in, access the admin menu
                {

                    switch (adminOption)
                    {

                    case (adminMenu):
                    {
                        std::cout << "\nAdmin Menu:" << std::endl;
                        std::cout << "1. Add Another Admin" << std::endl;
                        std::cout << "2. Add Event" << std::endl;
                        std::cout << "3. View Tickets" << std::endl;     // New option for viewing tickets
                        std::cout << "4. Add Another User" << std::endl; // New option for adding another user
                        std::cout << "5. Log Out" << std::endl;
                        std::cout << "6. Exit" << std::endl;
                        std::cout << "Enter your choice: ";

                        adminOption = static_cast<AdminOptions>(InputOptions(1, 6)); // input
                        break;
                    }
                    case (addAdmin): // add new admin
                    {
                        std::string newAdminUsername, newAdminPassword;
                        std::cout << "Enter new admin username: ";
                        std::cin >> newAdminUsername;
                        std::cout << "Enter new admin password: ";
                        std::cin >> newAdminPassword;
                        Admin newAdmin(newAdminUsername, newAdminPassword);
                        adminManager.addAdmin(newAdmin);
                        std::cout << "New admin added successfully." << std::endl;
                        adminOption = adminMenu;
                        break;
                    }

                    case (addEvent): // add new event
                    {
                        int eventType;
                        std::cout << "Enter event type (1 for Sport, 2 for Concert): ";
                        eventType = InputOptions(1, 2);

                        if (eventType == 1 || eventType == 2)
                        {
                            std::string eventName, year, month, day, date;
                            double ticketPrice; // Added ticket price variable

                            std::cout << "Enter event name: ";
                            std::cin >> eventName;
                            std::cout << "Enter ticket price: "; // Prompt for ticket price
                            std::cin >> ticketPrice;

                            std::cout << "Enter date (YYYY-MM-DD): "; // set the date the event will take place
                            std::cout << "Enter Year: ";
                            year = std::to_string(InputOptions(2024, 2050)); // set year
                            std::cout << "Enter Month: ";
                            month = std::to_string(InputOptions(1, 12)); // set month
                            std::cout << "Enter Day: ";
                            day = std::to_string(InputOptions(1, 30)); // set day

                            if (month.size() == 1) // if the month is single digit put a zero at the start
                            {
                                month = "0" + month;
                            }
                            if (day.size() == 1) // if the day is single digit put a zero at the start
                            {
                                day = "0" + day;
                            }
                            date = year + "-" + month + "-" + day; // create date string

                            // Write event details to events.txt
                            writeEvent(eventName, date, ticketPrice);

                            std::cout << "Event added successfully." << std::endl;
                        }
                        else
                        {
                            std::cout << "Invalid event type. Please enter 1 or 2." << std::endl;
                        }

                        std::cout << "\nPress Enter to continue...";
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        std::cin.get(); // Wait for Enter key
                        adminOption = adminMenu;
                        break;
                    }

                    case (viewTickets): // view tickets
                    {
                        // Open tickets.txt for reading
                        std::ifstream ticketsFile("tickets.txt");
                        if (ticketsFile.is_open())
                        {
                            std::string ticketInfo;
                            std::cout << "Tickets sold:" << std::endl;
                            // Read and display each line from tickets.txt
                            while (getline(ticketsFile, ticketInfo))
                            {
                                std::cout << ticketInfo << std::endl;
                            }
                            ticketsFile.close();
                        }
                        else
                        {
                            std::cerr << "Error opening tickets.txt for reading." << std::endl;
                        }
                        std::cout << "\nPress Enter to continue...";
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        std::cin.get();                        // Wait for Enter key
                        adminOption = AdminOptions::adminMenu; // Assuming adminMenu is the option to return to the admin menu
                        break;
                    }

                    case AdminOptions::addAnotherUser:
                    {
                        std::string newUserUsername, newUserPassword;
                        std::cout << "Enter new user username: ";
                        std::cin >> newUserUsername;
                        std::cout << "Enter new user password: ";
                        std::cin >> newUserPassword;
                        User newUser(newUserUsername, newUserPassword);
                        userManager.addUser(newUser);
                        std::cout << "New user added successfully." << std::endl;
                        adminOption = AdminOptions::adminMenu;
                        break;
                    }

                    case (adminLogOut): // log out to the start menu
                    {
                        std::cout << "Logging out." << std::endl;
                        option = startMenu;
                        break;
                    }

                    case (adminExit): // exit program
                    {
                        std::cout << "Exiting program." << std::endl;
                        option = startMenu;
                        return 0;
                    }
                    }
                }
            }

            else // admin login invalid
            {
                std::cout << "Invalid Login." << std::endl;
                std::cout << "1. Return To Menu" << std::endl;
                std::cout << "2. Try Again" << std::endl;

                option = static_cast<Options>(InputOptions(1, 2) - 1);
            }
        }

        else if (option == userLogin) // user login
        {
            std::string username, password;
            std::cout << "Enter username: ";
            std::cin >> username;
            std::cout << "Enter password: ";
            std::cin >> password;

            if (userManager.validateUser(username, password))
            {
                std::cout << "User login successful." << std::endl;

                while (option == userLogin) // while the user is logged in, they can access the user menu
                {

                    switch (userOption) // user options
                    {

                    case (userMenu):
                    {
                        std::cout << "\nUser Menu:" << std::endl;
                        std::cout << "1. Buy Tickets" << std::endl;
                        std::cout << "2. Book Tour" << std::endl; // New option
                        std::cout << "3. View Events" << std::endl;
                        std::cout << "4. Log Out" << std::endl;
                        std::cout << "5. Exit" << std::endl; // Updated numbering
                        std::cout << "Enter your choice: ";

                        userOption = static_cast<UserOptions>(InputOptions(1, 5)); // Updated range for input
                        break;
                    }

                    case (buyTickets):
                    {
                        std::cout << "Available Events:" << std::endl;
                        // Display available events
                        for (size_t i = 0; i < events.size(); ++i)
                        {
                            std::cout << "Event " << i << " - Event Type: " << events[i].getType() << ", Date: " << events[i].getDate() << std::endl;
                        }
                        // Prompt user to select an event
                        std::cout << "Enter the index of the event you want to buy tickets for: ";
                        int eventIndex = InputOptions(0, events.size() - 1);

                        // Prompt user for the number of tickets
                        std::cout << "Enter the number of tickets you want to buy: ";
                        int numTickets = InputOptions(1, std::numeric_limits<int>::max());

                        // Read ticket price from events.txt
                        double ticketPrice = readTicketPriceFromEvents(events[eventIndex].getType(), events[eventIndex].getDate());

                        if (ticketPrice > 0)
                        {
                            // Calculate total cost
                            double totalCost = ticketPrice * numTickets;
                            std::cout << "Total Cost: $" << totalCost << std::endl;

                            // Store ticket purchase details in tickets.txt
                            std::ofstream outFile("tickets.txt", std::ios::app);
                            if (outFile.is_open())
                            {
                                outFile << "Username: " << username << ", Event Type: " << events[eventIndex].getType() << ", Event Date: " << events[eventIndex].getDate()
                                        << ", Number of Tickets: " << numTickets << ", Ticket Price: " << ticketPrice << ", Total Cost: " << totalCost << std::endl;
                                outFile.close();
                                std::cout << "Tickets have been purchased." << std::endl;
                            }
                            else
                            {
                                std::cerr << "Error: Unable to open tickets.txt for writing." << std::endl;
                            }
                        }
                        else
                        {
                            std::cout << "Ticket price not found for the selected event." << std::endl;
                        }

                        std::cout << "\nPress Enter to continue...";
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        std::cin.get(); // Wait for Enter key
                        userOption = userMenu;
                        break;
                    }

                    case (BookTour):
                    {
                        std::cout << "\nBooking a Tour:" << std::endl;

                        // Prompt the user for the ticket holder's name, tour date, and number of tickets
                        std::string ticketHolderName, date, year, month, day;
                        std::cout << "Enter your name: ";
                        std::cin >> ticketHolderName;
                        std::cout << "Enter tour date (YYYY-MM-DD): ";
                        std::cout << "Enter Year: ";
                        year = std::to_string(InputOptions(2024, 2050)); // set year
                        std::cout << "Enter Month: ";
                        month = std::to_string(InputOptions(1, 12)); // set month
                        std::cout << "Enter Day: ";
                        day = std::to_string(InputOptions(1, 30)); // set day

                        if (month.size() == 1) // if the month is single digit put a zero at the start
                        {
                             month = "0" + month;
                        }
                        if (day.size() == 1) // if the day is single digit put a zero at the start
                        {
                            day = "0" + day;
                        }
                        date = year + "-" + month + "-" + day; // create date string
                        
                        std::cout << "Enter number of tickets: ";
                        int numTickets;
                        std::cin >> numTickets;

                        // Calculate the total cost based on the fixed ticket price (£20 per ticket)
                        double totalCost = numTickets * 20.0;

                        // Open tickets.txt file to append booking details
                        std::ofstream outFile("tickets.txt", std::ios_base::app);
                        if (outFile.is_open())
                        {
                            outFile << "Ticket Holder: " << ticketHolderName << ", Tour Date: " << date
                                    << ", Number of Tickets: " << numTickets << ", Total Cost: £" << totalCost << std::endl;
                            outFile.close();
                        }
                        else
                        {
                            std::cerr << "Error opening tickets file for writing." << std::endl;
                        }

                        // Display the booking details
                        std::cout << "Tour booked successfully!" << std::endl;
                        std::cout << "Ticket Holder: " << ticketHolderName << std::endl;
                        std::cout << "Tour Date: " << date << std::endl;
                        std::cout << "Number of Tickets: " << numTickets << std::endl;
                        std::cout << "Total Cost: £" << totalCost << std::endl;

                        // Optionally, you can wait for the user to press Enter to continue
                        std::cout << "\nPress Enter to continue...";
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        std::cin.get(); // Wait for Enter key

                        userOption = userMenu; // Go back to the user menu
                        break;
                    }

                    case (viewEvents):
                    {
                        std::cout << "Available Events:" << std::endl;
                        // Display available events
                        for (size_t i = 0; i < events.size(); ++i)
                        {
                            std::cout << "Event " << i + 1 << " - Event Type: " << events[i].getType() << ", Date: " << events[i].getDate() << std::endl;
                        }
                        std::cout << "\nPress Enter to continue...";
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        std::cin.get(); // Wait for Enter key
                        userOption = userMenu;
                        break;
                    }

                    case (userLogOut):
                    {
                        std::cout << "Logging out." << std::endl;
                        option = startMenu;
                        break;
                    }

                    case (userExit):
                    {
                        std::cout << "Exiting program." << std::endl;
                        option = startMenu;
                        return 0;
                        break;
                    }
                    }
                }
            }

            else // user login invalid
            {
                std::cout << "Invalid Login." << std::endl;
                std::cout << "1. Return To Menu" << std::endl;
                std::cout << "2. Try Again" << std::endl;

                if (InputOptions(1, 2) == 1) // return to menu
                {
                    option = startMenu;
                }
            }
        }

        else if (option == exit)
        {
            std::cout << "Exiting program." << std::endl;
            return 0;
        }
    }
}