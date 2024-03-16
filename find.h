#pragma once
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cstring>
#include "Diet_and_work.h"
using namespace std;

void underwt() {
  int choice;
  Wt_gain wt;
  do {
    cout << endl << "1. Diet \n2. Workout \n3. Exit " << endl;
    cout << "What do you want to see: ";
    cin >> choice;
    switch(choice) {
      case 1: wt.diet(); break;
      case 2: wt.work(); break;
      case 3: return;
    }
  } while(choice != 4);
}

void normal() {
  int choice;
  Wt_maintain wt;
  do {
    cout << endl << "1. Diet \n2. Workout \n3. Exit " << endl;
    cout << "What do you want to see: ";
    cin >> choice;
    switch(choice) {
      case 1: wt.diet(); break;
      case 2: wt.work(); break;
      case 3: return;
    }
  } while(choice != 4);
}

void overwt() {
  int choice;
  Wt_loss wt;
  do {
    cout << endl << "1. Diet \n2. Workout \n3. Exit " << endl;
    cout << "What do you want to see: ";
    cin >> choice;
    switch(choice) {
      case 1: wt.diet(); break;
      case 2: wt.work(); break;
      case 3: return;
    }
  } while(choice != 4);
}