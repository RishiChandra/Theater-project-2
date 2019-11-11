// Name: Rishi Chandra
// NetID: rxc170008
// List of libraries to include
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>      // to use std::setprecision when displaying the report
#include <limits>
// List of classes
#include "base.h"
#include "theaterSeat.h"
#include "auditorium.h"

using namespace std;

int main()
{
    string name; // Var to store the next line form the text file
    int num_rows; // Var to store number of rows since the memory of the 2d array is not dynamically allocated
    int num_cols; // Var to store number of cols
    ifstream input("A1.txt"); // Var to read the text file

    // Validate files
    if (input.good()){
        // Loop over the file to find the size of the array
        while(!input.eof()){
            getline(input, name);
            num_rows++; // Increment the number of rows for each line in the theater file
            //cout << num_rows;
        }

        num_cols = name.size(); // Get the number of cols based on the number of characters in the line
        input.seekg(0); // Reset the flag for reading the file

        // Create the auditorium object
        auditorium theater(input, num_rows, num_cols);


        input.close(); // Close the file so there wont be stream errors later

        int cont; // Initialize variable to check if the user wants to continue

        // Initialize vars to check if input is valid
        string test;
        bool valid;

        cout << "1. Reserve Seats" << endl << "2. Exit" << endl; // Prompt the user
        cin >> cont;

        // Check if input is valid
        if (cin.fail() || !(cont == 1 || cont == 2)){
            valid = true;
            // If not valid clear cin
            getline(cin, test);
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else {
            valid = false;
            getline(cin, test);
        }
        // Make sure input is valid and there is nothing inputed after
        while (valid || test.size() > 0){
            // Prompt and accept user input
            cout << "Please enter valid input" << endl;
            cin >> cont;
            if (cin.fail() || !(cont == 1 || cont == 2)){
                valid = true;
                // If not valid clear
                getline(cin, test);
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            else {
                valid = false;
                getline(cin, test);
            }
        }

        // Continue as long as the user wants to
        while(cont == 1){

            // Call method to display the theater
            theater.display();
            // Initialize vars to store the users desired seat info
            int row;
            char seat_letter;
            int seat;
            int adult;
            int child;
            int senior;
            int total;

            // Prompt the user and store responses
            cout << "What row number would you like?" << endl;
            cin >> row;

            // Essentially recreate the logic from above to ensure the input for row is valid
            if ((cin.fail()) || row - 1> num_rows - 1 || row <= 0){
                valid = true;
                // If not valid clear cin
                getline(cin, test);
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            else {
                valid = false;
                getline(cin, test);
            }
            // Make sure input is valid
            while (valid || test.size() > 0){
                // Prompt and accept user input
                cout << "Please enter valid input" << endl;
                cin >> row;
                if ((cin.fail()) || row - 1> num_rows - 1 || row <= 0){
                    valid = true;
                    // If not valid clear
                    getline(cin, test);
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                else {
                    valid = false;
                    getline(cin, test);
                }
            }
            row--;

            cout << "What seat would you like?" << endl;
            cin >> seat_letter;
            // Essentially recreate the logic from above to ensure the input for row is valid
            if ((cin.fail()) || toupper(seat_letter) - '@' > num_cols || toupper(seat_letter) - '@' <= 0 ){
                valid = true;
                // If not valid clear cin
                getline(cin, test);
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            else {
                valid = false;
                getline(cin, test);
            }
            // Make sure input is valid
            while (valid || test.size() > 0){
                // Prompt and accept user input
                cout << "Please enter valid input" << endl;
                cin >> seat_letter;
                if ((cin.fail()) || toupper(seat_letter) - '@' > num_cols || toupper(seat_letter) - '@' <= 0 ){
                    valid = true;
                    // If not valid clear
                    getline(cin, test);
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                else {
                    valid = false;
                    getline(cin, test);
                }
            }
            seat = toupper(seat_letter) - '@' - 1;

            cout << "How many adult tickets would you like?" << endl;
            cin >> adult;
            // Essentially recreate the logic from above to ensure the input for row is valid
            if (cin.fail() || adult < 0){
                valid = true;
                // If not valid clear cin
                getline(cin, test);
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            else {
                valid = false;
                getline(cin, test);
            }
            // Make sure input is valid
            while (valid || test.size() > 0){
                // Prompt and accept user input
                cout << "Please enter valid input" << endl;
                cin >> adult;
                if (cin.fail() || adult < 0){
                    valid = true;
                    // If not valid clear
                    getline(cin, test);
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                else {
                    valid = false;
                    getline(cin, test);
                }
            }


            cout << "How many child tickets would you like?" << endl;
            cin >> child;
            // Essentially recreate the logic from above to ensure the input for row is valid
            if (cin.fail() || child < 0){
                valid = true;
                // If not valid clear cin
                getline(cin, test);
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            else {
                valid = false;
                getline(cin, test);
            }
            // Make sure input is valid
            while (valid || test.size() > 0){
                // Prompt and accept user input
                cout << "Please enter valid input" << endl;
                cin >> child;
                if (cin.fail() || child < 0){
                    valid = true;
                    // If not valid clear
                    getline(cin, test);
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                else {
                    valid = false;
                    getline(cin, test);
                }
            }

            cout << "How many senior tickets would you like?" << endl;
            cin >> senior;
            // Essentially recreate the logic from above to ensure the input for row is valid
            if (cin.fail() || senior < 0){
                valid = true;
                // If not valid clear cin
                getline(cin, test);
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            else {
                valid = false;
                getline(cin, test);
            }
            // Make sure input is valid
            while (valid || test.size() > 0){
                // Prompt and accept user input
                cout << "Please enter valid input" << endl;
                cin >> senior;
                if (cin.fail() || senior < 0){
                    valid = true;
                    // If not valid clear
                    getline(cin, test);
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                else {
                    valid = false;
                    getline(cin, test);
                }
            }

            total = adult + child + senior; // Find total number of desired seats
            // Check if desired seats are available
            if (theater.isAvail(seat, row, adult, child, senior)){
                cout << "Your seats have been reserved" << endl;
                theater.reserve(seat, row, adult, child, senior); // Reserve them if they are

            }
            // Find and display best available seats
            else{
                theaterSeat* best = theater.bestAvail(adult, child, senior); // Find the best available seat
                if (best != nullptr){ // If there are available seats
                    cout << "Those seats are unavailable...the next best seats are at ";
                    cout << "row " << best->getRow() + 1 << " seat " << best->getSeat() << endl;
                    cout << "Enter Y if you want to reserve these seats or N if you do not" << endl;

                    char accept;
                    cin >> accept;
                    // Essentially recreate the logic from above to ensure the input for row is valid
                    if ((cin.fail()) || !(accept == 'Y' || accept == 'y' || accept == 'N' || accept == 'n')){
                        valid = true;
                        // If not valid clear cin
                        getline(cin, test);
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }
                    else {
                        valid = false;
                        getline(cin, test);
                    }
                    // Make sure input is valid
                    while (valid || test.size() > 0){
                        // Prompt and accept user input
                        cout << "Please enter valid input" << endl;
                        cin >> accept;
                        if ((cin.fail()) || !(accept == 'Y' || accept == 'y' || accept == 'N' || accept == 'n')){
                            valid = true;
                            // If not valid clear
                            getline(cin, test);
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        }
                        else {
                            valid = false;
                            getline(cin, test);
                        }
                    }
                    // Reserve the seats if accepted
                    if (accept == 'Y' || accept == 'y'){
                        theater.reserve(best->getSeat() - '@' - 1, best->getRow(), adult, child, senior);
                    }
                }
                else{
                    cout << "There are no available seats" << endl;
                }

            }

            // Same as above, prompt the user to continue or not and validate
            cout << "1. Reserve Seats" << endl << "2. Exit" << endl; // Prompt the user
            cin >> cont;

            // Check if input is valid
            if (cin.fail() || !(cont == 1 || cont == 2)){
                valid = true;
                // If not valid clear cin
                getline(cin, test);
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            else {
                valid = false;
                getline(cin, test);
            }
            // Make sure input is valid and there is nothing inputed after
            while (valid || test.size() > 0){
                // Prompt and accept user input
                cout << "Please enter valid input" << endl;
                cin >> cont;
                if (cin.fail() || !(cont == 1 || cont == 2)){
                    valid = true;
                    // If not valid clear
                    getline(cin, test);
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                else {
                    valid = false;
                    getline(cin, test);
                }
            }
        }

        // When done reserving seats, display the final report
        theater.report();

        // Write the final auditorium back to file
        // Create temp pointer to navigate the linked list
        theaterSeat* row = theater.getHead();
        theaterSeat* curr = row;

        ofstream out("A1.txt"); //Open the file for writing
        for (int i = 0; i < num_rows; i++){ // Loop through the rows
            string in = "";
            for (int j = 0; j < num_cols; j++){ // Loop through the cols
                in += curr->getType(); // Write the data of the seat to file
                curr = curr->getRight(); // Move the pointer to the next seat
            }
            row = row->getDown(); // Move the pointer to the head of the next row
            curr = row;

            // Write the row to file
            out << in;
            if (i != num_rows - 1){ //add a new line unless it is the last row
                out << endl;
            }
        }
        out.close(); //Close the file
    }
    // If the file is invalid
    else{
        cout << "Missing file or invalid filename" << endl;
    }
    return 0;
}
