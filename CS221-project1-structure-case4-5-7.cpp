#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const int rowMax = 50;
const int cols = 4;
int rowCount = 0;

int displayCount = 0;

struct info {
    string id;
    string name;
    string game;
    string score;
} data[rowMax];

// Function prototypes
int menu();
void readDataFromFile(const string& filename);
void Display();
int search(const string& chosenId);

int main() {
    readDataFromFile("gameData.txt"); 
    cout << "ID GamerName GameName Score" << endl;
    Display();
    
    string chosenId;
    do {
        switch (menu()) {
            case 1:
                // Add gamer functionality  -- ios::app
                break;
            case 2:
                // Delete gamer functionality  --out
                break;
            case 3:
                // Update score functionality   --out
                break;
            case 4:
                Display();
                break;
            case 5:
                cout << "Enter the ID:: ";
                cin >> chosenId;
                int i = search(chosenId);
                if (i != -1) {
                    cout << data[i].id << " " << data[i].name << " " << data[i].game << " " << data[i].score << endl;
                } else {
                    cout << "ID not found" << endl;
                }
                break;
            /*case 6:
                // Sort gamers by ID functionality  --out
                break;
            case 7:
                cout << "Exiting program..." << endl;      // --out
                return 0;
            default:
                cout << "\n Incorrect menu option. Please try another option." << endl;*/
        }
    } while (true);
    return 0;
}

int menu() {
    int choice;
    cout << "\n Please choose an option:"
         << "\n1  - Add a gamer"
         << "\n2  - Delete a gamer"
         << "\n3  - Update the score"
         << "\n4  - Display all gamers"
         << "\n5  - Find a gamer by ID"
         << "\n6  - Sort gamers by their ID"
         << "\n7  - Exit "
         << "\n>> ";
    cin >> choice; 
    return choice;
}

void readDataFromFile(const string& filename) {
    ifstream inFile(filename);
    if (!inFile.is_open()) {
        cout << "Error opening file: " << filename << endl;
        return;
    }
    while (!inFile.eof() && rowCount < rowMax) {
        getline(inFile, data[rowCount].id);
        getline(inFile, data[rowCount].name);
        getline(inFile, data[rowCount].game);
        getline(inFile, data[rowCount].score);
        rowCount++;
    }
    inFile.close();
}

void Display() {
    if (rowCount == 0) {
        cout << "No data to display." << endl;
        return;
    }

    for (int i = 0; i < rowCount; ++i) {
        cout << data[i].id << " " << data[i].name << " " << data[i].game << " " << data[i].score << endl;
    }
    displayCount++;
}

int search(const string& chosenId) {
    for (int i = 0; i < rowCount; i++) {
        if (data[i].id == chosenId) {
            return i; // Return the index of the found gamer
        }
    }
    return -1; // ID not found
}
