#include <iostream>
#include "Gym.h"
using namespace std;

void boss() {
  int n = 0;
  string st, pass;
  //cout << "Enter password for manager: ";
  //cin >> st;
  Gym g1;
  do {
    cout << endl;
    cout << "1. Enter data for members" << endl;
    cout << "2. Display all member data" << endl;
    cout << "3. Delete specific member data" << endl;
    cout << "4. Exit" << endl;
    cout << "Enter choice: ";
    cin >> n;
    switch (n) {
    case 1: g1.get_data(); break;
    case 2: g1.display(); break;
    case 3: g1.del(); break;
    case 4: return ;
    }
  } while (n != 5);
}

void mem() {
  int n = 0;
  int id;
  Gym g1;
  cout << "Enter ID: ";
  cin >> id;
  do {
    cout << endl;
    cout << "1. Find your data" << endl;
    cout << "2. Update your data" << endl;
    cout << "3. Find your BMI" << endl;
    cout << "4. Set your target weight" << endl;
    cout << "5. Find our diet and workout plan for you" << endl;
    cout << "6. Exit" << endl;
    cout << "Enter choice: ";
    cin >> n;
    switch (n) {
      case 1: g1.search(id); break;
      case 2: g1.update(id); break;
      case 3: g1.bmi_cal(id); break;
      case 4: g1.target(id); break;
      case 5: g1.find(id); break;
      case 6: return ;
    }
  } while (n != 7);
}

int main() {
  int n = 0;
  do {
    cout << endl;
    cout << "1. Gym Manager" << endl;
    cout << "2. Member" << endl;
    cout << "3. Exit" << endl;
    
    cout << "Enter choice: ";
    cin >> n;
    switch (n) {
      case 1: boss(); break;
      case 2: mem(); break;
    }
  } while (n != 3);
}
