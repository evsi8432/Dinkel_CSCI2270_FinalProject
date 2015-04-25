//Jack Dinkel
//CSCI 2270 - Hoenigman
//Final Project

//Driver file

//Builds a hashtable to store movie information using user input
//Uses class: HashTable
//Takes no command line input

#include <iostream>
#include "HashTable.h"

using namespace std;

void displayMenu();
string askInput();

int main(){
	HashTable h(10); //initialize the table

	bool quit = false;
	int input;
    int MovieCounter = 0;

	while(quit != true){ //to run until the user says quit
        displayMenu();
        cin >> input;

        //clear out cin
        cin.clear();
        cin.ignore(10000,'\n');

        switch (input){
            case 1: //insert movie
            {
            	Movie *newMovie = new Movie;
            	string title;
            	int year;
                int ranking;

            	//ask user for input
            	cout << "Enter title: ";
            	title = askInput();
            	cout << "Enter year: ";
            	cin >> year;
                cout << "Enter your ranking (1-10): ";
                cin >> ranking;
                while (ranking > 11 || ranking < 1){ //if ranking invalid
                    cout << "Invalid ranking! Please enter an integer between 1 and 10: ";
                    cin >> ranking;
                }

            	//build the new Movie object
            	newMovie->title = title;
            	newMovie->year = year;
                newMovie->ranking = ranking;
                newMovie->next = NULL;
                newMovie->alphaLeft = NULL;
                newMovie->alphaRight = NULL;
                newMovie->numLeft = NULL;
                newMovie->numRight = NULL;

                // Root successfully created and stored
                if (MovieCounter == 0){
                    h.root = newMovie;
                    MovieCounter++;
                }

            	h.insertMovie(newMovie); //insert the movie into the hashtable

                break;
            }

            case 2: //delete movie
            {
            	Movie *movieToFind = new Movie;
            	string title;

            	//ask user for input
            	cout << "Enter title: " << endl;
            	title = askInput();

            	h.deleteMovie(title); //delete the movie from the hashtable

                break;
            }

            case 3: //find movie
            {
            	Movie *movieToFind = new Movie;
            	string title;

            	//ask user for input
            	cout << "Enter title: " << endl;
            	title = askInput();

            	movieToFind = h.findMovie(title); //search the hashtable for the movie

            	if (movieToFind == NULL){ //if NULL is returned, print "not found"
                    h.movieMatch(title);
            	}
            	else{ //print statement
            		cout << "Movie found in position: " << h.hashFunction(title) << endl;
                    cout << "\tTitle: " << movieToFind->title << endl;
                    cout << "\tYear: " << movieToFind->year << endl;
                    cout << "\tRanking: " << movieToFind->ranking << endl;
            	}

                break;
            }

            case 4: //Print table contents
            	h.printInventory(); //print the hashtable
                break;

            case 5: //Print in alphebetical order
            {
                h.buildBSTString(h.root);
                h.PrintThatTreeString(h.root);
                break;
            }

            case 6: //Print in rank order
                h.buildBSTNum(h.root);
                h.PrintThatTreeNum(h.root);
                break;

            case 7: //Quit
                cout << "Goodbye!" << endl;
                quit = true; //end program
                break;

            default: // invalid input
                cout << "Invalid Input" << endl;
                cin.clear();
                cin.ignore(10000,'\n');
                break;
        }
    }
    return 0;
}

void displayMenu(){ //displays the Main Menu for the program
    cout << "======Main Menu======" << endl;
    cout << "1. Insert movie" << endl;
    cout << "2. Delete movie" << endl;
    cout << "3. Find movie" << endl;
    cout << "4. Print table contents" << endl;
    cout << "5. Print in alphebetical order" << endl;
    cout << "6. Print in rank order" << endl;
    cout << "7. Quit" << endl;
    return;
}

string askInput(){ //waits for user for input, returns a string (works with spaces)
	char input[100];
	string inputString;
	cin >> inputString;
	cin.getline(input,100);
	inputString += string(input);

	return inputString;
}