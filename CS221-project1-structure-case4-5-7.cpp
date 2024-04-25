#include <iostream>
#include <fstream>
#include <sstream> 
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

int main() {
    readDataFromFile("gameData.txt"); 
    cout << "ID GamerName GameName Score" << endl;
    Display();

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
                // Find gamer by ID functionality
                break;
            case 6:
                // Sort gamers by ID functionality  --out
                break;
            case 7:
                cout << "Exiting program...";      // --out
                return 0;
            default:
                cout << "\n Incorrect menu option. Please try another option.";
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
    string line;
    while (!inFile.eof()) {
        if (rowCount >= rowMax) {
            cout << "Maximum row limit reached. Cannot read more data." << endl;
            break;
        }
        // txt format is: ID,Name,Game,Score
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
    displayCount ++;
}
