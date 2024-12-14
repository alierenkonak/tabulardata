#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

const int maxsize = 16; // maximum number of players on the list
int numPlayers = 0;     // current number of players entered

// arrays to store players data
string playerName[maxsize];
string playerSurname[maxsize];
string playerNationality[maxsize];
int playerRanking[maxsize];
int playerRating[maxsize];
int playerBirthYear[maxsize];
int playerFIDEID[maxsize];

// prototypes functions 
void insertNewRow();
void displayRow(int index);
void editSingleRow(int index);
void deleteRow(int index);
void displayTable();
int findRow(int playerFIDEID);

bool getValidateString(string &input);
bool getValidateNumber(int &number);

int main() {
    int choice;
    int playerID;
    int index;

    while (true) {
        // creating menu
        cout << "\nMenu:\n";
        cout << "1. New\n";
        cout << "2. Find\n";
        cout << "3. List\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        
        if (!getValidateNumber(choice)) {
            continue; // if input is invalid retry
        }

        switch (choice) {
            case 1: // adding new player
                insertNewRow();
                break;

            case 2: // find player the player by using fide id on the list
                cout << "Enter Player FIDE ID: ";
                if (getValidateNumber(playerID)) {
                    index = findRow(playerID);
                    if (index != -1) {
                        displayRow(index);
                        int subChoice;
                        cout << "Edit (1), Delete (2), Exit (3): ";
                        if (getValidateNumber(subChoice)) {
                            if (subChoice == 1) {
                                editSingleRow(index);
                            } else if (subChoice == 2) {
                                deleteRow(index);
                            }
                        }
                    } else {
                        cout << "Player not found.\n";
                    }
                }
                break;

            case 3: // list of the all players which is entered
                displayTable();
                break;

            case 4: // exits from progrram
                cout << "Exiting...\n";
                return 0;

            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }
}

bool getValidateString(string &input) {
    getline(cin, input);

    if (input.empty()) { // cheks for empty input 
        cout << "Input cannot be empty. Please try again.\n";
        return false;
    }

    for (size_t i = 0; i < input.length(); ++i) {
        char c = input[i];
        if (!isalpha(c) && c != ' ') { // checks for non-letter and non-space characters
            cout << "Invalid input. Please enter a valid string (letters only)!\n";
            return false;
        }
    }
    return true;
}

bool getValidateNumber(int &number) {
    string input;
    cin >> input;

    for (size_t i = 0; i < input.length(); ++i) {
    char c = input[i];
        if (!isdigit(c)) {
            cout << "Invalid input. Please enter a valid number!\n";
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // clears remaining input
            return false;
        }
    }

    try {
        number = stoi(input);
        return true;
    } catch (const exception &) {
        cout << "Invalid input. Please enter a valid number!\n";
        return false;
    }
}

void insertNewRow() {
    if (numPlayers >= maxsize) {
        cout << "Table is full. Cannot add more players.\n";
        return;
    }

    string tempString;
    int tempNumber;

    cin.ignore(); // clean up any newline characters which is left from previous entries

    cout << "Enter Player's Name: ";
    while (!getValidateString(tempString));
    playerName[numPlayers] = tempString;

    cout << "Enter Player's Surname: ";
    while (!getValidateString(tempString));
    playerSurname[numPlayers] = tempString;

    cout << "Enter Player's Nationality: ";
    while (!getValidateString(tempString));
    playerNationality[numPlayers] = tempString;

    cout << "Enter Player's Current Ranking: ";
    while (!getValidateNumber(tempNumber));
    playerRanking[numPlayers] = tempNumber;

    cout << "Enter Player's Current Rating: ";
    while (!getValidateNumber(tempNumber));
    playerRating[numPlayers] = tempNumber;

    cout << "Enter Player's Birth Year: ";
    while (!getValidateNumber(tempNumber));
    playerBirthYear[numPlayers] = tempNumber;

    cout << "Enter Player's FIDE ID: ";
    while (!getValidateNumber(tempNumber));
    playerFIDEID[numPlayers] = tempNumber;

    numPlayers++;
    cout << "Player added successfully.\n";
}

void displayRow(int index) {
    cout << "Player " << index + 1 << " Details:\n";
    cout << "Name: " << playerName[index] << "\n";
    cout << "Surname: " << playerSurname[index] << "\n";
    cout << "Nationality: " << playerNationality[index] << "\n";
    cout << "Ranking: " << playerRanking[index] << "\n";
    cout << "Rating: " << playerRating[index] << "\n";
    cout << "Birth Year: " << playerBirthYear[index] << "\n";
    cout << "FIDE ID: " << playerFIDEID[index] << "\n";
}

void editSingleRow(int index) {
    int choice;
    cout << "Edit Player " << index + 1 << ":\n";
    cout << "1. Name\n";
    cout << "2. Surname\n";
    cout << "3. Nationality\n";
    cout << "4. Ranking\n";
    cout << "5. Rating\n";
    cout << "6. Birth Year\n";
    cout << "7. FIDE ID\n";
    cout << "Enter the number of the field to edit (0 to exit): ";

    if (!getValidateNumber(choice)) return;

    string tempString;
    int tempNumber;

    switch (choice) {
        case 1:
            cout << "Enter new Name: ";
            cin.ignore();
            while (!getValidateString(tempString));
            playerName[index] = tempString;
            break;
        case 2:
            cout << "Enter new Surname: ";
            cin.ignore();
            while (!getValidateString(tempString));
            playerSurname[index] = tempString;
            break;
        case 3:
            cout << "Enter new Nationality: ";
            cin.ignore();
            while (!getValidateString(tempString));
            playerNationality[index] = tempString;
            break;
        case 4:
            cout << "Enter new Ranking: ";
            while (!getValidateNumber(tempNumber));
            playerRanking[index] = tempNumber;
            break;
        case 5:
            cout << "Enter new Rating: ";
            while (!getValidateNumber(tempNumber));
            playerRating[index] = tempNumber;
            break;
        case 6:
            cout << "Enter new Birth Year: ";
            while (!getValidateNumber(tempNumber));
            playerBirthYear[index] = tempNumber;
            break;
        case 7:
            cout << "Enter new FIDE ID: ";
            while (!getValidateNumber(tempNumber));
            playerFIDEID[index] = tempNumber;
            break;
        case 0:
            return;
        default:
            cout << "Invalid choice.\n";
    }
    cout << "Player details updated.\n";
}

void deleteRow(int index) {
    // shift all data down to delete the row
    for (int i = index; i < numPlayers - 1; i++) {
        playerName[i] = playerName[i + 1];
        playerSurname[i] = playerSurname[i + 1];
        playerNationality[i] = playerNationality[i + 1];
        playerRanking[i] = playerRanking[i + 1];
        playerRating[i] = playerRating[i + 1];
        playerBirthYear[i] = playerBirthYear[i + 1];
        playerFIDEID[i] = playerFIDEID[i + 1];
    }
    numPlayers--; // decrease the current number of players
    cout << "Player deleted successfully.\n";
}

void displayTable() {
    cout << left; // align output to the left for better list appearance
    cout << setw(5) << "No"
         << setw(15) << "Name"
         << setw(15) << "Surname"
         << setw(15) << "Nationality"
         << setw(10) << "Ranking"
         << setw(10) << "Rating"
         << setw(15) << "Birth Year"
         << setw(10) << "FIDE ID" << endl;

    for (int i = 0; i < numPlayers; i++) {
        cout << setw(5) << i + 1
             << setw(15) << playerName[i]
             << setw(15) << playerSurname[i]
             << setw(15) << playerNationality[i]
             << setw(10) << playerRanking[i]
             << setw(10) << playerRating[i]
             << setw(15) << playerBirthYear[i]
             << setw(10) << playerFIDEID[i] << endl;
    }
}
int findRow(int playerFIDEIDToFind) {
    for (int i = 0; i < numPlayers; i++) {
        if (playerFIDEID[i] == playerFIDEIDToFind) {
            return i; // return the index of the found player
        }
    }
    return -1; // return -1 if player is not found
}
