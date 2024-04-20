#include <iostream>
#include <fstream>
#include <sstream> // Include this for istringstream
#include <string>

using namespace std;

const int rowMax = 50;
const int cols = 4;
int rowCount = 0;

struct info {
    int id;
    string name;
    string game;
    int score;
} data[rowMax];

// Function prototypes
int menu();
void readDataFromFile(const string& filename);
void Display();

int main() {
    readDataFromFile("D:\\github\\Data-Analyzer\\GameSystemData.csv"); // Call the function to read data from the file
    cout << "ID GamerName GameName Score" << endl;
    Display();

    int displayCount = 0;
    do {
        switch (menu()) {
            case 1:
                // Add gamer functionality
                break;
            case 2:
                // Delete gamer functionality
                break;
            case 3:
                // Update score functionality
                break;
            case 4:
                Display();
                break;
            case 5:
                // Find gamer by ID functionality
                break;
            case 6:
                // Sort gamers by ID functionality
                break;
            case 7:
                cout << "Exiting program...";
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
    cin >> choice; // You might want to enable user input here
    return choice;
}

void readDataFromFile(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Error opening file: " << filename << endl;
        return;
    }

    string line;
    while (getline(file, line)) {
        if (rowCount >= rowMax) {
            cout << "Maximum row limit reached. Cannot read more data." << endl;
            break;
        }
        istringstream ss(line);
        string token;

        // Assuming CSV format is: ID,Name,Game,Score
        getline(ss, token, ',');
        data[rowCount].id = stoi(token);

        getline(ss, data[rowCount].name, ',');
        getline(ss, data[rowCount].game, ',');
        getline(ss, token, ',');
        data[rowCount].score = stoi(token);

        rowCount++;
    }
    file.close();
}

void Display() {
    if (rowCount == 0) {
        cout << "No data to display." << endl;
        return;
    }

    for (int i = 0; i < rowCount; ++i) {
        cout << data[i].id << " " << data[i].name << " " << data[i].game << " " << data[i].score << endl;
    }
}
