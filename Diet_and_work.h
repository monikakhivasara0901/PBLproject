#pragma once
#include <iostream>
#include <fstream>
using namespace std;

struct Member {
  char name[50], address[50], gender[50], dob[50], pass[50];
  float height, weight, bmi;
  int target_wt, month_plan, age;
  long int mem_id, contact, cost;
};

class Diet {
  public: 
    virtual void veg() = 0;
    virtual void non_veg() = 0;
    virtual void diet() = 0;
};
class Work_out {
  public:
    int z=0, y=0, g=0;
    virtual void zumba() = 0;
    virtual void work() = 0;
    virtual void yoga() = 0;
    virtual void gym() = 0;
};

class Wt_loss : protected Diet, protected Work_out {
  public:
    void non_veg() {
      string line;
      fstream file;
      file.open("non_veg_loss.txt", ios::in);
      file.seekg(0);
      while(file.good()) {
        getline(file, line);
        cout << line << endl;
      }
    }
    void veg() {
      string line;
      fstream file;
      file.open("veg_loss.txt", ios::in);
      file.seekg(0);
      while(file.good()) {
        getline(file, line);
        cout << line << endl;
      }
    }
    void diet() {
      int choice;
      cout << "1. Vegeterian \n2. Non-vegeterian\n";
      cout << "Which one are you: ";
      cin >> choice;
      switch(choice) {
        case 1: veg(); break;
        case 2: non_veg(); break;
      }
    }
    void zumba() {
      int n;
      cout << "Do you have any previous experience in zumba (1 for yes and 2 for no)?";
      cin >> n;
      if (n==1) {
        cout << "The zumba course takes place 3 times a week." << endl;
        cout << "Following are the plans: " << endl;
        cout << "1. 1 month      ₹1000" << endl;
        cout << "2. 3 month      ₹2500" << endl;
        cout << "3. 6 month      ₹5000" << endl;
        cout << "4. 12 month     ₹10500" << endl;
        cout << "Which do you choose: ";
        cin >> n;
        switch(n) {
          case 1: z = 1000; break;
          case 2: z = 2500; break;
          case 3: z = 5000; break;
          case 4: z = 10500; break;
        }
      }
      else {
        cout << "Advantages of zumba: " << endl;
        cout << "1. It Strengthens Your Core And Helps You Get Rid Of  Belly Fat." << endl;
        cout << "2. It Improves Cardiovascular Health And Overall Physical Fitness." << endl;
        cout << "3. It Burns More Calories And Fat Than Other Exercises." << endl;
        cout << "4. It Improves Flexibility." << endl;
        cout << "5. It Builds Muscle Mass And A Toned Physique." << endl;
        cout << "The zumba course takes place 3 times a week." << endl;
        cout << "Following are the plans: " << endl;
        cout << "1. 1 month      ₹1000" << endl;
        cout << "2. 3 month      ₹2500" << endl;
        cout << "3. 6 month      ₹5000" << endl;
        cout << "4. 12 month     ₹10500" << endl;
        cout << "Which do you choose: ";
        cin >> n;
        switch(n) {
          case 1: z = 1000; break;
          case 2: z = 2500; break;
          case 3: z = 5000; break;
          case 4: z = 10500; break;
        }
      }
    }
    void yoga() {
      int n;
      cout << "Do you have any previous experience in yoga (1 for yes and 2 for no)?";
      cin >> n;
      if (n==1) {
        cout << "The yoga course takes place for 1 hr every week." << endl;
        cout << "Following are the plans: " << endl;
        cout << "1. 1 month      ₹800" << endl;
        cout << "2. 3 month      ₹2000" << endl;
        cout << "3. 6 month      ₹4000" << endl;
        cout << "Which do you choose: ";
        cin >> n;
        switch(n) {
          case 1: y = 800; break;
          case 2: y = 2000; break;
          case 3: y = 4000; break;
        }
      }
      else {
        cout << "Advantages of Yoga: " << endl;
        cout << "1. Increased flexibility, muscle tone" << endl;
        cout << "2. Improved respiration, energy and vitality, athletic health, cardio health" << endl;
        cout << "3. Balanced metabolism" << endl;
        cout << "4. Stress management" << endl;
        cout << "The yoga course takes place for 1 hr every week." << endl;
        cout << "Following are the plans: " << endl;
        cout << "1. 1 month      ₹800" << endl;
        cout << "2. 3 month      ₹2000" << endl;
        cout << "3. 6 month      ₹4000" << endl;
        cout << "Which do you choose: ";
        cin >> n;
        switch(n) {
          case 1: y = 800; break;
          case 2: y = 2000; break;
          case 3: y = 4000; break;
        }
      }
      cout << "Would you like to buy a yoga mat (1 for yes 2 for no): ";
      cin >> n;
      switch(n) {
          case 1: y = y + 350; break;
          case 2: y = y; break;
      }
    }
    void gym() {
      string line;
      fstream file;
      file.open("gym_loss.txt", ios::in);
      file.seekg(0);
      while(file.good()) {
        getline(file, line);
        cout << line << endl;
      }
      int n;
      cout << "Do you require a personal trainer (1 for yes and 2 for no): ";
      cin >> n;
      if (n==1) {
        cout << "Following are the plans: " << endl;
        cout << "1. 1 month      ₹3000" << endl;
        cout << "2. 3 month      ₹6000" << endl;
        cout << "3. 6 month      ₹10500" << endl;
        cout << "4. 12 month     ₹17000" << endl;
        cout << "Which do you choose: ";
        cin >> n;
        switch(n) {
          case 1: g = 3000; break;
          case 2: g = 6000; break;
          case 3: g = 10500; break;
          case 4: g = 17000; break;
        }
      }
      else {
        cout << "Following are the plans: " << endl;
        cout << "1. 1 month      ₹2000" << endl;
        cout << "2. 3 month      ₹4500" << endl;
        cout << "3. 6 month      ₹8000" << endl;
        cout << "4. 12 month     ₹13500" << endl;
        cout << "Which do you choose: ";
        cin >> n;
        switch(n) {
          case 1: g = 2000; break;
          case 2: g = 4500; break;
          case 3: g = 8000; break;
          case 4: g = 13500; break;
        }
      }
    }
    void work() {
      int choice;
      cout << "1. Gym \n2. Zumba \n3. Yoga \n";
      cout << "Which one would you choose you: ";
      cin >> choice;
      switch(choice) {
        case 1: gym();
                cout << endl << "Total cost: " << g << endl;
                break;
        case 2: zumba();
                cout << endl << "Total cost: " << z << endl;
                break;
        case 3: yoga();
                cout << endl << "Total cost: " << y << endl;
                break;
      }
    }
};

class Wt_gain : protected Diet, protected Work_out {
  public:
    void non_veg() {
      string line;
      fstream file;
      file.open("non_veg_gain.txt", ios::in);
      file.seekg(0);
      while(file.good()) {
        getline(file, line);
        cout << line << endl;
      }
    }
    void veg() {
      string line;
      fstream file;
      file.open("veg_gain.txt", ios::in);
      file.seekg(0);
      while(file.good()) {
        getline(file, line);
        cout << line << endl;
      }
    }
    void diet() {
      int choice;
      cout << "1. Vegeterian \n2. Non-vegeterian\n";
      cout << "Which one are you: ";
      cin >> choice;
      switch(choice) {
        case 1: veg(); break;
        case 2: non_veg(); break;
      }
    }
    void zumba() {
      cout << "\0";
    }
    void yoga() {
      cout << "\0";
    }
    void gym() {
      string line;
      fstream file;
      file.open("gym_gain.txt", ios::in);
      file.seekg(0);
      while(file.good()) {
        getline(file, line);
        cout << line << endl;
      }
      int n;
      cout << "Do you require a personal trainer (1 for yes and 2 for no): ";
      cin >> n;
      if (n==1) {
        cout << "Following are the plans: " << endl;
        cout << "1. 1 month      ₹3000" << endl;
        cout << "2. 3 month      ₹6000" << endl;
        cout << "3. 6 month      ₹10500" << endl;
        cout << "4. 12 month     ₹17000" << endl;
        cout << "Which do you choose: ";
        cin >> n;
        switch(n) {
          case 1: g = 3000; break;
          case 2: g = 6000; break;
          case 3: g = 10500; break;
          case 4: g = 17000; break;
        }
      }
      else {
        cout << "Following are the plans: " << endl;
        cout << "1. 1 month      ₹2000" << endl;
        cout << "2. 3 month      ₹4500" << endl;
        cout << "3. 6 month      ₹8000" << endl;
        cout << "4. 12 month     ₹13500" << endl;
        cout << "Which do you choose: ";
        cin >> n;
        switch(n) {
          case 1: g = 2000; break;
          case 2: g = 4500; break;
          case 3: g = 8000; break;
          case 4: g = 13500; break;
        }
      }
    }
    void work() {
      gym();
      cout << endl << "Total cost: " << g << endl;
    }
};

class Wt_maintain : protected Diet, protected Work_out {
  public:
    void non_veg() {
      string line;
      fstream file;
      file.open("non_veg_mtain.txt", ios::in);
      file.seekg(0);
      while(file.good()) {
        getline(file, line);
        cout << line << endl;
      }
    }
    void veg() {
      string line;
      fstream file;
      file.open("veg_mtain.txt", ios::in);
      file.seekg(0);
      while(file.good()) {
        getline(file, line);
        cout << line << endl;
      }
    }
    void diet() {
      int choice;
      cout << "1. Vegeterian \n2. Non-vegeterian\n";
      cout << "Which one are you: ";
      cin >> choice;
      switch(choice) {
        case 1: veg(); break;
        case 2: non_veg(); break;
      }
    }
    void zumba() {
      int n;
      cout << "Do you have any previous experience in zumba (1 for yes and 2 for no)?";
      cin >> n;
      if (n==1) {
        cout << "The zumba course takes place 3 times a week." << endl;
        cout << "Following are the plans: " << endl;
        cout << "1. 1 month      ₹1000" << endl;
        cout << "2. 3 month      ₹2500" << endl;
        cout << "3. 6 month      ₹5000" << endl;
        cout << "4. 12 month     ₹10500" << endl;
        cout << "Which do you choose: ";
        cin >> n;
        switch(n) {
          case 1: z = 1000; break;
          case 2: z = 2500; break;
          case 3: z = 5000; break;
          case 4: z = 10500; break;
        }
      }
      else {
        cout << "Advantages of zumba: " << endl;
        cout << "1. It Strengthens Your Core And Helps You Get Rid Of  Belly Fat." << endl;
        cout << "2. It Improves Cardiovascular Health And Overall Physical Fitness." << endl;
        cout << "3. It Burns More Calories And Fat Than Other Exercises." << endl;
        cout << "4. It Improves Flexibility." << endl;
        cout << "5. It Builds Muscle Mass And A Toned Physique." << endl;
        cout << "The zumba course takes place 3 times a week." << endl;
        cout << "Following are the plans: " << endl;
        cout << "1. 1 month      ₹1000" << endl;
        cout << "2. 3 month      ₹2500" << endl;
        cout << "3. 6 month      ₹5000" << endl;
        cout << "4. 12 month     ₹10500" << endl;
        cout << "Which do you choose: ";
        cin >> n;
        switch(n) {
          case 1: z = 1000; break;
          case 2: z = 2500; break;
          case 3: z = 5000; break;
          case 4: z = 10500; break;
        }
      }
    }
    void yoga() {
      int n;
      cout << "Do you have any previous experience in yoga (1 for yes and 2 for no)?";
      cin >> n;
      if (n==1) {
        cout << "The yoga course takes place for 1 hr every week." << endl;
        cout << "Following are the plans: " << endl;
        cout << "1. 1 month      ₹800" << endl;
        cout << "2. 3 month      ₹2000" << endl;
        cout << "3. 6 month      ₹4000" << endl;
        cout << "Which do you choose: ";
        cin >> n;
        switch(n) {
          case 1: y = 800; break;
          case 2: y = 2000; break;
          case 3: y = 4000; break;
        }
      }
      else {
        cout << "Advantages of zumba: " << endl;
        cout << "1. Increased flexibility, muscle tone" << endl;
        cout << "2. Improved respiration, energy and vitality, athletic health, cardio health" << endl;
        cout << "3. Balanced metabolism" << endl;
        cout << "4. Stress management" << endl;
        cout << "The yoga course takes place for 1 hr every week." << endl;
        cout << "Following are the plans: " << endl;
        cout << "1. 1 month      ₹800" << endl;
        cout << "2. 3 month      ₹2000" << endl;
        cout << "3. 6 month      ₹4000" << endl;
        cout << "Which do you choose: ";
        cin >> n;
        switch(n) {
          case 1: y = 800; break;
          case 2: y = 2000; break;
          case 3: y = 4000; break;
        }
      }
      cout << "Would you like to buy a yoga mat (1 for yes 2 for no): ";
      cin >> n;
      switch(n) {
          case 1: y = y; break;
          case 2: y = y + 350; break;
        }
    }
    void gym() {
      string line;
      fstream file;
      file.open("gym_mtain.txt", ios::in);
      file.seekg(0);
      while(file.good()) {
        getline(file, line);
        cout << line << endl;
      }
      int n;
      cout << "Do you require a personal trainer (1 for yes and 2 for no): ";
      cin >> n;
      if (n==1) {
        cout << "Following are the plans: " << endl;
        cout << "1. 1 month      ₹3000" << endl;
        cout << "2. 3 month      ₹6000" << endl;
        cout << "3. 6 month      ₹10500" << endl;
        cout << "4. 12 month     ₹17000" << endl;
        cout << "Which do you choose: ";
        cin >> n;
        switch(n) {
          case 1: g = 3000; break;
          case 2: g = 6000; break;
          case 3: g = 10500; break;
          case 4: g = 17000; break;
        }
      }
      else {
        cout << "Following are the plans: " << endl;
        cout << "1. 1 month      ₹2000" << endl;
        cout << "2. 3 month      ₹4500" << endl;
        cout << "3. 6 month      ₹8000" << endl;
        cout << "4. 12 month     ₹13500" << endl;
        cout << "Which do you choose: ";
        cin >> n;
        switch(n) {
          case 1: g = 2000; break;
          case 2: g = 4500; break;
          case 3: g = 8000; break;
          case 4: g = 13500; break;
        }
      }
    }
    void work() {
      int choice;
      cout << "1. Gym \n2. Zumba \n3. Yoga \n";
      cout << "Which one would you choose you: ";
      cin >> choice;
      switch(choice) {
        case 1: gym();
                cout << endl << "Total cost: " << g << endl;
                break;
        case 2: zumba();
                cout << endl << "Total cost: " << z << endl;
                break;
        case 3: yoga();
                cout << endl << "Total cost: " << y << endl;
                break;
      }
    }
};
