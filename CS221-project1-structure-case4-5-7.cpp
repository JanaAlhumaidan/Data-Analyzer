#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

const int rowMax = 50;
const int cols = 4;
int rowCount = 0;
int i;

int displayCount = 0;
int searchCount = 0;
int Addcount = 0;
int DeleteCount = 0;
int updateCount = 0;
int sortCount = 0;

struct info {
    string id;
    string name;
    string game;
    string score;
} data[rowMax];

// Function prototypes
int menu();
void readDataFromFile(const string& filename);
void Add();
void Delete();
void Display();
int search(const string& chosenId);
void sortById();
void saveToFile();
void updateScore(string idToUpdate, string newScore);

int main() {
    readDataFromFile("gameData.txt");
    cout << "ID GamerName GameName Score" << endl;
    Display();

    string newScore, idToUpdate;
    string chosenId;
    do {
        switch (menu()) {
            case 1:
                Add();
                break;
            case 2:
                Delete();
                break;
            case 3:
                cout << "id to update: " ;
                cin >> idToUpdate;
                cout << "new score: ";
                cin >> newScore;
                updateScore(idToUpdate, newScore);
                break;
            
            case 4:
                Display();
                break;
            case 5:
                cout << "Enter the ID: ";
                cin >> chosenId;
                i = search(chosenId);
                if (i != -1) {
                    cout << data[i].id << " " << data[i].name << " " << data[i].game << " " << data[i].score << endl;
                }
                else {
                    cout << "ID not found" << endl;
                }
                break;
            case 6:
                sortById();
                break;
            case 7:
                saveToFile();
                cout    << "Times of display: " << displayCount << endl
                        << "Times of search: " << searchCount << endl
                        << "Times of add: " << Addcount << endl
                        << "Times of delete: " << DeleteCount << endl
                        << "Times of update: " << updateCount << endl
                        << "Times of sort: " << sortCount << endl
                        << "Exiting program..." << endl;  
                return 0;
            default:
                cout << "\n Incorrect menu option. Please try another option." << endl;
                break;
        }
    } while (true);
    return 0;
}

int menu() {
    int choice;
    cout << "\n Please choose an option:"
        << "\n 1 - Add a gamer"
        << "\n 2 - Delete a gamer"
        << "\n 3 - Update the score"
        << "\n 4 - Display all gamers"
        << "\n 5 - Find a gamer by ID"
        << "\n 6 - Sort gamers by their ID"
        << "\n 7 - Exit "
        << "\n >> ";
    cin >> choice;
    return choice;
}

void readDataFromFile(const string& filename) {
    for (i = 0; i < rowCount; ++i) {
            data[i].id = "";
            data[i].name  = "";
            data[i].game = "";
            data[i].score  = "";
    }
    rowCount = 0;
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

void Add() {
    Addcount ++;
    string newId, newName, newGame, newScore;
    cout << "Enter new gamer details:" << endl;
    cout << "ID: ";
    cin >> newId;
    cout << "Name: ";
    cin.ignore();
    getline(cin, newName);
    cout << "Game: ";
    getline(cin, newGame);
    cout << "Score: ";
    getline(cin, newScore);

    // Open the file in append mode (ios::app)
    ofstream outFile("gameData.txt", ios::app);

    if (!outFile.is_open()) {
        cout << "Error opening file for writing." << endl;
    }
    outFile 
        << newId << endl 
        << newName << endl 
        << newGame << endl 
        << newScore << endl;

    cout << "New gamer added successfully!" << endl;
    outFile.close();
}

void Delete() {
    DeleteCount++;
    string x;
    cout << "Enter the ID of the gamer to delete: ";
    cin >> x;

    int foundIndex = search(x);

    if (foundIndex == -1) {
        cout << "ID not found. No gamer deleted." << endl;
        return;
    }

    // Shift elements to remove the deleted gamer
    for (int j = foundIndex; j < rowCount - 1; ++j) {
        data[j] = data[j + 1];
    }
    rowCount--;

    // Rewrite data to the file
    ofstream outFile("gameData.txt");
    if (!outFile.is_open()) {
        cout << "Error opening file for writing." << endl;
        return;
    }

    // Rewrite data to the file
    for ( i = 0; i < rowCount; ++i) {
        outFile
            << data[i].id << endl
            << data[i].name << endl
            << data[i].game << endl
            << data[i].score << endl;
    }
    outFile.close();
    readDataFromFile("gameData.txt");

    cout << "Gamer deleted successfully!" << endl;
}

void Display() {
    displayCount++;
    readDataFromFile("gameData.txt");
    if (rowCount == 0) {
        cout << "No data to display." << endl;
        return;
    }
    for ( i = 0; i < rowCount; ++i) {
        cout << data[i].id << " " 
            << data[i].name << " " 
            << data[i].game << " " 
            << data[i].score << endl;
    }
    cout << "--------------";

}

int search(const string& chosenId) {
    searchCount ++;
    for ( i = 0; i < rowCount; i++) {
        if (data[i].id == chosenId) {
            return i; // Return the index of the found gamer
        }
    }
    return -1; // ID not found
}

void sortById(){
    sortCount ++;
    for ( i = 0; i < rowCount - 1; ++i) {
        for (int j = 0; j < rowCount - i - 1; ++j) {
            if (data[j].id > data[j + 1].id){
                // Swap data[j] and data[j+1]
                info temp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = temp;
            }
        }
    }
   saveToFile();
}

void saveToFile() {
    ofstream outFile("gameData.txt");
    if (!outFile.is_open()) {
        cout << "Error opening file for writing." << endl;
        return;
    }
    for ( i = 0; i < rowCount; ++i) {
        outFile 
            << data[i].id << endl 
            << data[i].name << endl 
            << data[i].game << endl 
            << data[i].score << endl;
    }
    cout << "Data saved to gameData.txt successfully!" << endl;
    outFile.close();
}

void updateScore(string idToUpdate,string newScore) {
    updateCount ++;
    int index = search(idToUpdate);
    if (index != -1) {
        data[index].score = newScore;
        cout << "Score updated successfully!" << endl;
    } else {
        cout << "ID not found. Score not updated." << endl;
    }
        saveToFile();
    Display();
}