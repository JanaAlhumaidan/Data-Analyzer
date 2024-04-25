#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct info {
    int id;
    string name;
    string game;
    int score;
};

const int rows = 50;
const int cols = 4;
int rowCount = 0;

// Function prototypes
int readingData(info data[]);
bool emptyArray();
void display(int &displayCount);
int menu();
void report(int displayCount);
int search(info data[]);

int main() {
    int displayCount = 0;
    info data[rows];
    if (readingData(data) == 1) {
        return 1;
    }
    do {
        switch (menu()) {
            case 4: // print all gamers
                if (!emptyArray()) {
                    display(displayCount);
                    break;
                }

            case 5: // Find a gamer by ID
                if (!emptyArray()) {
                    int index = search(data);
                    if (index != -1) {
                        cout << "Gamer found:\n";
                        cout << "ID: " << data[index].id << ", Name: " << data[index].name << ", Game: " << data[index].game << ", Score: " << data[index].score << endl;
                    } else {
                        cout << "Gamer not found." << endl;
                    }
                }
                break;

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
    //cin >> choice;
    return 4;
}

int readingData(info data[]) {
    ifstream iFile("D:\\Data\\game data.txt");
    if (!iFile.is_open()) {
        cerr << "Error opening file." << endl;
        return 1;
    }
    while (!iFile.eof() && rowCount < rows) {
        iFile >> data[rowCount].id;
        iFile >> data[rowCount].name;
        iFile >> data[rowCount].game;
        iFile >> data[rowCount].score;
        rowCount++;
    }
    return 0;
}

void display(int &displayCount, info data[]) {
    for (int i = 0; i < rowCount; i++) {
        cout << "ID: " << data[i].id << ", Name: " << data[i].name << ", Game: " << data[i].game << ", Score: " << data[i].score << endl;
    }
    displayCount++;
}

bool emptyArray() {
    if (rowCount == 0) {
        cout << "\n The array is empty!\n";
        return true;
    }
    return false;
}

void report(int displayCount) {
    cout << "Number of displays: " << displayCount;
}

int search(info data[]) {
    int ID;
    cout << "Enter the ID: ";
    cin >> ID;
    for (int i = 0; i < rowCount; i++) {
        if (data[i].id == ID) {
            return i;
        }
    }
    return -1;
}
