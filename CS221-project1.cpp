// Jana Alhumaidan - Bayan Alghamdi - Ghala Alqhahtani - Sadeem Alturki - Baneen - Shahad
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const int rows = 50;
const int cols = 50;
int rowCount = 0;
int colCount = 0;
string data[rows][cols];

int readingData();
int print();


int main(){
    if (readingData() == 1) {
        return 1; // If readingData fails, exit the program
    }
    print();
    cout << rowCount << " " << colCount; // test
    return 0;
}

int readingData() {
    ifstream file("D:\\Data\\GameSystemData.csv");
    if (!file.is_open()) {
        cerr << "Error opening file." << endl;
        return 1;
    }

    string line;
    while (getline(file, line) && rowCount < rows) {
        string cellValue = ""; // Temporarily store the value of each cell
        colCount = 0; // Reset column count for each row

        for (char c : line) { // Loop through each character in the line
            if (c == ',') { // If the character is a comma
                data[rowCount][colCount++] = cellValue; // Store the cell value in the array
                cellValue = ""; // Reset the cell value for the next cell
            } else {
                cellValue += c; // Append the character to the cell value
            }
        }
        data[rowCount][colCount++] = cellValue; // Store the last cell value in the array
        rowCount++; // Move to the next row
    }
    return 0;
}

int print(){
    for (int i = 0; i < rowCount; ++i) {
        for (int j = 0; j < cols && !data[i][j].empty(); ++j) {
            cout << data[i][j] << " ";
        }
        cout << endl;
    }
    return 0; // Indicate success
}
