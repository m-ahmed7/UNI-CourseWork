#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "../src/event.hpp"
#include "../src/eventmanager.hpp"
#include "../src/tourmanager.hpp"
#include <fstream>
#include <sstream>
#include <string>

// TESTS FOR EventItem, EventManager, and TourManager

TEST_CASE("EventItem Constructors", "[EventItem]") {
    SECTION("Default Constructor") {
        EventItem event;
        REQUIRE(event.getType().empty());
        REQUIRE(event.getDate().empty());
    }

    SECTION("Parameterized Constructor with Type, Date, and Ticket Price") {
        EventItem event("Concert", "2024-04-20", 150.0);
        REQUIRE(event.getType() == "Concert");
        REQUIRE(event.getDate() == "2024-04-20");
        REQUIRE(event.getTicketPrice() == Approx(150.0).epsilon(0.001));
    }

    SECTION("Parameterized Constructor with Type and Date") {
        EventItem event("Sports", "2024-05-15");
        REQUIRE(event.getType() == "Sports");
        REQUIRE(event.getDate() == "2024-05-15");
    }
}

TEST_CASE("EventItem Setters and Getters", "[EventItem]") {
    EventItem event;

    SECTION("Set and Get Type") {
        event.setType("Exhibition");
        REQUIRE(event.getType() == "Exhibition");
    }

    SECTION("Set and Get Date") {
        event.setDate("2024-06-01");
        REQUIRE(event.getDate() == "2024-06-01");
    }

    SECTION("Set and Get Ticket Price") {
        event.setTicketPrice(99.99);
        REQUIRE(event.getTicketPrice() == Approx(99.99).epsilon(0.001));
    }
}

TEST_CASE("EventManager Operations", "[EventManager]") {
    EventManager manager;
    EventItem event1("Concert", "2024-04-20", 120.0);
    EventItem event2("Sports", "2024-05-15", 60.0);

    SECTION("Add Event") {
        manager.addEvent(event1);
        std::ifstream file("events.txt");
        std::string content((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
        REQUIRE(content.find("Concert") != std::string::npos);
        file.close();
    }

    SECTION("Remove Event") {
        manager.addEvent(event1);
        manager.addEvent(event2);
        manager.removeEvent("Concert", "2024-04-20");
        REQUIRE(true);
    }
}

TEST_CASE("TourManager Operations", "[TourManager]") {
    TourManager manager;

    SECTION("Calculate Total Cost") {
        int numberOfTickets = 3;
        double expectedCost = 60.0;
        REQUIRE(manager.calculateTotalCost(numberOfTickets) == Approx(expectedCost).epsilon(0.001));
    }

    SECTION("Save Booking Details") {
        Tour tour("John Doe", "2024-07-20", 3, 60.0);
        manager.saveBookingDetails(tour);
        std::ifstream file("tickets.txt");
        std::string content((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
        file.close();
        REQUIRE(content.find("John Doe") != std::string::npos);
        REQUIRE(content.find("2024-07-20") != std::string::npos);
        REQUIRE(content.find("3") != std::string::npos);
    }
}
