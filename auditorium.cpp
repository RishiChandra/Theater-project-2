// List of headers and libraries to include
#include "auditorium.h"
#include "base.h"
#include "theaterSeat.h"
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>      // to use std::setprecision when displaying the report
#include <limits>
#include <math.h>

// Constructor using input file
auditorium::auditorium(std::ifstream& input, int num_rows, int num_cols){
    std::string name;
    theaterSeat* headptr; // Create pointer to head
    theaterSeat* headrowptr; // Create pointer to head of the row
    for(int i = 0; i < num_rows; i++){ // Loop over the number of rows
        theaterSeat* prevptr; // Create pointer to the previous pointer
        theaterSeat* currptr; // Create pointer to the current pointer
        std::getline(input, name); // Get the line in the row and store it in name via pass by reference
        for(int j = 0; j < num_cols; j++){ // Loop over the number of cols
            // Create head ptr
            if (i == 0 && j == 0){
                bool res = false;
                if (name.at(j) != '.'){
                    res = true;
                }
                headptr = new theaterSeat(i, static_cast<char>('A' + j), res, name.at(j));
                prevptr = headptr;
                headrowptr = headptr;
            }
            // Create pointer to head of the row
            else if (j == 0){
                bool res = false;
                if (name.at(j) != '.'){
                    res = true;
                }
                theaterSeat* temp = new theaterSeat(i, static_cast<char>('A' + j), res, name.at(j));
                // Link the nodes
                headrowptr->setDown(temp);
                headrowptr = temp;
                prevptr = temp;
            }
            // Create the rest of the pointers
            else{
                bool res = false;
                if (name.at(j) != '.'){
                    res = true;
                }
                currptr = new theaterSeat(i, static_cast<char>('A' + j), res, name.at(j));
                // Link the nodes
                currptr->setLeft(prevptr);
                prevptr->setRight(currptr);
                prevptr = currptr;
            }
        }
    }
    // Set vals for the object members
    head = headptr;
    rows = num_rows;
    cols = num_cols;


}

// Method to display the auditorium
void auditorium::display(){
    // Create the line for how many seats there are
    std::cout << "  ";
    for (int i = 0; i < cols; i++){
        std::cout << static_cast<char>('A' + i);
    }
    std::cout << std::endl;

    // Create pointers to help navigate the grid
    theaterSeat* curr = head;
    theaterSeat* row = head;
    for(int i = 0; i < rows; i++){ // Loop through rows
        std::cout << i+1 << " "; // Display col number
        for (int j = 0; j < cols; j++){ // Loop through the seat
            // Display whether the seat is taken or not
            if (curr->getType() == '.'){
                std::cout << '.';
            }
            else {
                std::cout << '#';
            }
            curr = curr->getRight(); // Get the seat to the right
        }
        std::cout << std::endl;
        // Navigate to the next row
        curr = row->getDown();
        row = curr;
    }

}

// Method to display the final report
void auditorium::report(){
    // Initialize the vars to store the theater stats
    int seats = 0;
    int sold = 0;
    int adult = 0;
    int child = 0;
    int senior = 0;

    // Create pointers to help navigate the grid
    theaterSeat* curr = head;
    theaterSeat* row = head;
    for(int i = 0; i < rows; i++){ // Loop through the rows
        for (int j = 0; j < cols; j++){ // Loop through the cols
            // Calculate the totals
            if (curr->getType() != '.'){
                sold++;
                if (curr->getType() == 'A'){
                    adult++;
                }
                else if (curr->getType() == 'C'){
                    child++;
                }
                else if(curr->getType() == 'S'){
                    senior++;
                }
            }
            curr = curr->getRight(); // Go to the next seat
        }
        // Go to the next row
        curr = row->getDown();
        row = curr;
    }

    // Display the formatted report
    std::cout << std::endl << "Final Report:" << std::endl;
    std::cout << "------------------------------------------------" << std::endl;
    std::cout << "|Total seats: \t\t\t|" << seats << "\t\t|" << std::endl;
    std::cout << "|Total seats sold: \t\t|" << sold << "\t\t|" << std::endl;
    std::cout << "|Total adult seats sold: \t|" << adult << "\t\t|" << std::endl;
    std::cout << "|Total child seats sold: \t|" << child << "\t\t|" << std::endl;
    std::cout << "|Total senior seats sold: \t|" << senior << "\t\t|" << std::endl;
    double sales = 10 * adult + 5 * child + 7.5 * senior; // Calculate the total sales using the given ticket prices
    std::cout << "|Total ticket sales: \t\t|$" << std::fixed << std::setprecision(2) << sales << "\t|" << std::endl; // Format the sales
    std::cout << "-------------------------------------------------" << std::endl;


}

// Method to check if the requested seats are available
bool auditorium::isAvail(int seat, int row, int adult, int child, int senior){

    int total = adult + child + senior; // Get total seats requested

    theaterSeat* rowhead = head; // Pointer to head of desired row
    // Navigate to the desired row
    for (int i = 0; i < row; i++){
        rowhead = rowhead->getDown();
    }

    theaterSeat* curr = rowhead; // Pointer to desired seat
    // Navigate to the desired seat
    for (int i = 0; i < seat; i++){
        curr = curr->getRight();
    }
    // Loop through all the seats requested starting at the seat
    for (int i = 0; i < total; i++){
        if (curr->getRight() == nullptr){ // If at the end of the row
            return false;
        }
        else if (curr->getType() != '.'){ // If the seat is taken
            return false;
        }
        curr = curr->getRight(); // Move to the next seat
    }
    return true;
}

// Method to reserve seats
void auditorium::reserve(int seat, int row, int adult, int child, int senior){

    int total = adult + child + senior; // Get the total number of seats desired

    theaterSeat* rowhead = head; // pointer to head of desired row
    // Go to desired row
    for (int i = 0; i < row; i++){
        rowhead = rowhead->getDown();
    }

    theaterSeat* curr = rowhead; // Pointer to desired starting seat
    for (int i = 0; i < seat; i++){ // Go to desired seat
        curr = curr->getRight();
    }

    // Reserve the seats based on how many of each ticket was ordered
    for (int i = 0; i < adult; i++){
        curr->setRes(true);
        curr->setType('A');
        curr = curr->getRight();
    }
    for (int i = 0; i < child; i++){
        curr->setRes(true);
        curr->setType('C');
        curr = curr->getRight();
    }
    for (int i = 0; i < senior; i++){
        curr->setRes(true);
        curr->setType('S');
        curr = curr->getRight();
    }
}

// Method to find the best seats available
theaterSeat* auditorium::bestAvail(int adult, int child, int senior){
    // Create pointers to navigate grid
    theaterSeat* curr = head;
    theaterSeat* row = head;
    double dist = 10000; // Initialise the var to store the smallest distance
    theaterSeat* best = head; // Start with the best seat being the head
    for(int i = 0; i < rows; i++){
        curr = row;
        // Calculate how much in a row to skip at the end to not go out of bounds
        int add = adult + child + senior - 1;
        if (adult +  child + senior == 0){
            add = 0;
        }
        for (int j = 0; j < cols - add; j++){
            if (isAvail(j, i, adult, child, senior)){ // Check if the seats are available
                // Initialize middle vars to use when calculating distance
                double mid_row = (rows - 1) / 2.0;
                double mid_col = (cols -1)  / 2.0;
                double mid_seat = ((j + j + adult + child + senior) - 1)/2.0;
                // Find distance by using basic distance formula
                double d = sqrt(pow(mid_row-i,2)+pow(mid_col-mid_seat,2));
                // In case of tie for distance
                if (d == dist){
                    // Chose seat closest to middle
                    if (pow(curr->getRow() - mid_row, 2) < pow(best->getRow() - mid_row, 2)){
                        best = curr;
                    }
                }
                // If the distance is less
                else if (d < dist){
                    // Set the seat as new best seat
                    dist = d;
                    best = curr;
                }
            }
            curr = curr->getRight(); // Go to the next seat
        }
        // Navigate to the next row
        curr = row->getDown();
        row = curr;

    }
    // If there is no best seat return a null ptr
    if (!(dist < 10000)){
        best = nullptr;
    }

    return best;

}

//  Very simple destructor
// Due to the theater seat destructor, the deletion of the head
// Will trigger the deletion of the rest
auditorium::~auditorium()
{
    delete head;
}
