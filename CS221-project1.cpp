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
bool emptyArray();
void display(int &displayCount); 
int menu();
void report(int displayCount); 
int search(int ID);

struct info {
    string name;
    string game;
    int id;
    int score;
};

int main(){
    int displayCount = 0;
    if (readingData() == 1) {
        return 1; 
    }
    do{
        switch (menu()){
            case 1: //Add new gamer
                if (rowCount < rows)
                    //..... 
                //else 
                    cout<<"\nERROR: The array is full. Please delete a gamer first!";
                break;
        
            case 2: //delete a gamer
                if (!emptyArray())
                    //......
                break;
                    
            case 3: //Update score
                if (!emptyArray()) 
                    //.... 
                    break;
                    
            case 4: //print all gamers    
                if (!emptyArray()){
                    display(displayCount); 
                    break;}

            case 5: // Find a gamer by ID
                int ID, rownum;
                if (!emptyArray())
                    cout << "enter the ID";
                    cin >> ID;
                    rownum = search(ID);
                    for(int j=0; j< colCount; j++){
                     cout<<data[rownum][j];}
                break;

                        
            case 6: //Sort gamers by their ID
                if (!emptyArray())
                    //....
                break;
                        
            case 7: 
                cout<<"\t\n Thank you for using our program\n";
                report(displayCount); 
                return 0; 
                        
            default: cout<<"\n Incorrect menu option. Please try another option.";
        } 
    }while (true);
    return 0; 
}

int menu(){
    int choice;
    cout<<"\n Please choose an option:"
        <<"\n1  - Add a gamer"
        <<"\n2  - Delete a gamer"
        <<"\n3  - Update the score"
        <<"\n4  - Display all gamers"
        <<"\n5  - Find a gamer by ID"
        <<"\n6  - Sort gamers by their ID"
        <<"\n7  - Exit "
        <<"\n>> ";    
    cin>>choice;
    return choice;
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
                cellValue += c;
            }
        }
        data[rowCount][colCount++] = cellValue; // Store the last cell value in the array
        rowCount++; // Move to the next row
    }
    return 0;
}

void display(int &displayCount){
    for (int i = 0; i < rowCount; ++i) {
        for (int j = 0; j < cols && !data[i][j].empty(); ++j){
            cout << data[i][j] << " ";
        }
        cout << endl;
        displayCount++ ;
    }
}

bool emptyArray(){
    if (rowCount==0){
        cout<<"\n The array is empty!\n";
        return true;
    }
    return false;
}

void report(int displayCount){
    cout << "number of displays: " << displayCount;
}

int search(int ID){
    int index = -1;
    for(int i = 0; i < rowCount; ++i){
        if (stoi(data[i][0]) == ID){
            index = i;
            return i;
            break;
        }
    }
    if(index < 0)
        cout << "ID not found";
    return index;
}