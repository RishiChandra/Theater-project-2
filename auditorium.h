#ifndef AUDITORIUM_H
#define AUDITORIUM_H
#include <iostream>
#include "base.h"
#include "theaterSeat.h"

class auditorium
{
    public:
        auditorium(){};
        // Overloaded constructor
        auditorium(std::ifstream&, int, int);

        void display(); // Display the auditorium
        void report(); // Display the final report
        bool isAvail(int, int, int, int, int); // Check if those seats are available
        void reserve(int, int, int, int, int); // Reserve the seats
        theaterSeat* getHead() {return head;} // Accessor method to get the start of the list
        theaterSeat* bestAvail(int, int, int); // Find the best available seats given the quantity
        virtual ~auditorium(); // Destructor

    protected:

    private:
        // Members
        int rows;
        int cols;
        theaterSeat* head;
};

#endif // AUDITORIUM_H
