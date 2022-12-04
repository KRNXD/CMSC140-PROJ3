//Class: CMSC140 CRN
//Instructor: Professor Ara Kechiantz
//Programming Project 3
//Description: A program that calculates info about your hotel and gives you the price of what room you want
//I have not given my code to any student.
//Print your Name here: Kieran Yalla

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main() {
string LOCATION;
int i, FLOORS, ROOMS[30], SINGLE[10], DOUBLE_ROOM[10], KING[10], SUITE[10];
int SINGLE_ROOM_PRICE = 60, DOUBLE_ROOM_PRICE = 75, KING_ROOM_PRICE = 100, SUITE_ROOM_PRICE = 150;
int UNOCCUPIED, MIN;
double TOTAL_ROOMS = 0, OCCUPIED_ROOMS = 0, INCOME = 0.0, OCCUPANCY_RATE;
int SUM = 0;

cout << fixed << setprecision(2);
cout << "==============================================\n";
cout << right << setw(30) << "BlueMount Hotel\n";
cout << "==============================================\n";
cout << "Enter the Location of this hotel chain: ";
cin >> LOCATION;
cout << "Enter total number of floors of the hotel: ";
cin >> FLOORS;

while (FLOORS <= 0 || FLOORS > 5) {
    
    cout << "number of floors should be between 1 and 5 !! please try again.\n";
    cout << "\nEnter total number of floors of the hotel: ";
    cin >> FLOORS;

}

for (i = 1; i <= FLOORS; i++) {

    cout << "\n\nEnter total number of rooms in the " << i << "th floor: ";
    cin >> ROOMS[i];
    while (ROOMS[i] <= 0 || ROOMS[i] > 30) {
      cout << "number of rooms should be between 1 and 30 !! please try again.\n\n";
      cout << "Enter total number of rooms in the " << i << "th floor : ";
      cin >> ROOMS[i];
    }

    cout << "How many SINGLE rooms are occupied in the " << i << "th floor : ";
    cin >> SINGLE[i];
    cout << "How many DOUBLE rooms are occupied in the " << i << "th floor : ";
    cin >> DOUBLE_ROOM[i];
    cout << "How many KING rooms are occupied in the " << i << "th floor : ";
    cin >> KING[i];
    cout << "How many SUITE rooms are occupied in the " << i << "th floor : ";
    cin >> SUITE[i];
    SUM = SINGLE[i] + DOUBLE_ROOM[i] + KING[i] + SUITE[i];

    while (SUM > ROOMS[i]) {
      cout << "Total number of occupied rooms exceeds the total number of rooms on this floor. Please try again!!";
      SUM = 0;
      cout << "\n\nEnter total number of rooms in the " << i << "th floor : ";
      cin >> ROOMS[i];
      while (ROOMS[i] <= 0 || ROOMS[i] > 30) {
        cout << "number of rooms should be between 1 and 30 !! please try again.\n\n";
        cout << "Enter total number of rooms in the " << i << "th floor : ";
        cin >> ROOMS[i];
      }

      cout << "How many SINGLE rooms are occupied in the " << i << "th floor : ";
      cin >> SINGLE[i];
      cout << "How many DOUBLE rooms are occupied in the " << i << "th floor : ";
      cin >> DOUBLE_ROOM[i];
      cout << "How many KING rooms are occupied in the " << i << "th floor : ";
      cin >> KING[i];
      cout << "How many SUITE rooms are occupied in the " << i << "th floor : ";
      cin >> SUITE[i];
      SUM = SINGLE[i] + DOUBLE_ROOM[i] + KING[i] + SUITE[i];

    }

}

cout << "\n\n=================================================================\n";
cout << right << setw(36) << "BlueMont Hotel located in " << LOCATION << endl << endl;
cout << right << setw(43) << "TODAY'S ROOM RATES<US$/night>" << endl << endl;
cout << "Single Room" << setw(20) << "Double Room" << setw(15) << "King Room" << setw(17) << "Suite Room";
cout << endl << endl;
cout << SINGLE_ROOM_PRICE << setw(20) << DOUBLE_ROOM_PRICE << setw(20) << KING_ROOM_PRICE << setw(20) << SUITE_ROOM_PRICE;
cout << "\n=================================================================\n";

for (i = 1; i <= FLOORS; i++) {
    INCOME = INCOME + (SINGLE[i] * SINGLE_ROOM_PRICE) + (DOUBLE_ROOM[i] * DOUBLE_ROOM_PRICE) + (KING[i] * KING_ROOM_PRICE) + (SUITE[i] * SUITE_ROOM_PRICE);
    TOTAL_ROOMS = TOTAL_ROOMS + ROOMS[i];
    OCCUPIED_ROOMS = OCCUPIED_ROOMS + SINGLE[i] + DOUBLE_ROOM[i] + KING[i] + SUITE[i];
}

UNOCCUPIED = TOTAL_ROOMS - OCCUPIED_ROOMS;
OCCUPANCY_RATE = (OCCUPIED_ROOMS / TOTAL_ROOMS) * 100;

cout << "\n" << right << setw(30) << "Hotel Income: " << setw(10) << "$" << INCOME;
cout << "\n" << right << setw(30) << "Total # of rooms: " << setw(10) << TOTAL_ROOMS;
cout << "\n" << right << setw(30) << "Total # Occupied Rooms: "<< setw(10) << OCCUPIED_ROOMS;
cout << "\n" << right << setw(30) << "Total # Unoccupied Rooms: " << setw(10) << UNOCCUPIED;
cout << "\n" << right << setw(30) << "Occupancy rate: " << setw(10) << OCCUPANCY_RATE << "%";

int r = 1;
MIN = ROOMS[1];

for (i = 2; i <= FLOORS; i++) {
    if (ROOMS[i] < MIN) {
      MIN = i;
      r = i;
    }

}

cout << "\n\n" << r << "th Floor with " << ROOMS[r] << " rooms, has the least number of rooms.";
if (OCCUPANCY_RATE < 60) {
    cout << "\nNeed to improve Hotel occupancy rate!!\n\n";

}

cout << "\n\nThank you for testing my program!!";
cout << "\nPROGRAMEER : Kieran Yalla";
cout << "\nCMSC140 Project 3";
cout << "\nDue Date: 07/17/22\n\n";


return 0;

}