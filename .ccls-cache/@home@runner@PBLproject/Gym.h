#pragma once
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include <string>
#include "find.h"
using namespace std;

#define size 100

class Gym {
  static int i;
public:
  void get_data();
  void search(int id);
  void display();
  void disp_memb(Member p);
  Member bmi_cal(int id);
  void target(int id);
  void update(int id);
  void find(int id);
  void del();
  //friend void operator= (Member p, Member q);
};

int Gym::i = 1;

void Gym::get_data() {
  /*fstream fil;
  fil.open("member_data.bin", ios::binary | ios::in | ios::out);
  if(fil.eof() == 0) {
    for (int i = 0; i < size; i++) {
      Member p;
      p.mem_id = p.height = p.weight = p.age = p.contact = p.bmi = p.target_wt = p.month_plan = p.age = p.cost = 0;
      strcpy(p.name, "_____");
      strcpy(p.gender, "_____");
      strcpy(p.address, "_____");
      strcpy(p.dob, "_____");
      fil.write((char*)&p, sizeof(Member));
    }
  }
  fil.close();*/
  Member p,q;
  cout << endl << "Enter Member Id: ";
  cin >> p.mem_id;
  cout << "Enter name: ";
  cin >> p.name;
  cout << "Enter age: ";
  cin >> p.age;
  cout << "Enter gender: ";
  cin >> p.gender;
  cout << "Enter height (in m): ";
  cin >> p.height;
  cout << "Enter weight (in kg): ";
  cin >> p.weight;
  cout << "Enter address: ";
  cin >> p.address;
  cout << "Enter contact: ";
  cin >> p.contact;
  cout << "Enter date of birth: ";
  cin >> p.dob;
  int key = (p.mem_id % size);
  int b = (sizeof(p)) * (key - 1);
  fstream file;
  file.open("member_data.bin", ios::out | ios::binary | ios::in);
  file.seekg(b);
  file.read((char*)&q, sizeof(q));
  if(q.mem_id == 0) {
    file.seekg(-sizeof(q), ios::cur);
    //q = p;
    file.write((char*)&p, sizeof(p));
  }
  else {
    file.read((char*)&q, sizeof(q));
    while (q.mem_id != 0) {
      if (file.eof() == 0) {
        file.seekg(0, ios::beg);
      }
      file.read((char*)&q, sizeof(q));
    }
    file.seekg(-sizeof(q), ios::cur);
    //q = p;
    file.write((char*)&p, sizeof(p));
  }
  file.close();
}

void Gym::display() {
    Member p;
    cout << endl << setw(10) << "Member Id" << setw(20) << "Name" << setw(20) << "Height" << setw(20) << "Weight" << endl;
    fstream file;
    file.open("member_data.bin", ios::in | ios::out | ios::binary);
    file.read((char*)&p, sizeof(p));
    while(file.good()) {
      if (p.mem_id != 0) {
        disp_memb(p);
      }
      file.read((char*)&p, sizeof(p));
    }
    file.close();
}

void Gym::disp_memb(Member p) {
  cout << setw(10) << p.mem_id << setw(20);
  cout << setw(20) << p.name << setw(10);
  cout << setw(20) << p.height << setw(10);
  cout << setw(20) << p.weight << endl;
}

void Gym::search(int id) {
  Member p;
  int key = (id % size);
  int b = (sizeof(p)) * (key - 1);
  fstream file;
  file.open("member_data.bin", ios::in | ios::out | ios::binary);
  file.seekg(b);
  file.read((char*)&p, sizeof(p));
  if (id == p.mem_id) {    
    cout << "___________________________" << endl << endl;
    cout << "Name : " << p.name << endl;
    cout << "Age : " << p.age << endl;
    cout << "Height : " << p.height << endl;
    cout << "Weight : " << p.weight << endl;
    cout << "___________________________" << endl;
  }
  else {
    file.read((char*)&p, sizeof(p));
    while (file.good()) {
      if (id == p.mem_id) {
        cout << "___________________________" << endl << endl;
        cout << "Name : " << p.name << endl;
        cout << "Age : " << p.age << endl;
        cout << "Height : " << p.height << endl;
        cout << "Weight : " << p.weight << endl;
        cout << "___________________________" << endl;
        break;
      }
      if(file.eof()==0){
        file.seekg(0);
      }
      file.read((char*)&p, sizeof(p));
    }
  }
  file.close();
}

void Gym::update(int id) {
  Member p;
  int key = (id % size);
  int b = (sizeof(p)) * (key - 1);
  fstream file;
  file.open("member_data.bin", ios::in | ios::out | ios::binary);
  file.seekg(b);
  file.read((char*)&p, sizeof(p));
  if (id == p.mem_id) {
    file.seekg(-sizeof(p), ios::cur);
    cout << "Enter new height: ";
    cin >> p.height;
    cout << "Enter new weight: ";
    cin >> p.weight;
    cout << "Enter age: ";
    cin >> p.age;
    file.write((char*)&p, sizeof(p));
  }
  else {
    file.read((char*)&p, sizeof(p));
    while (file.good()) {
      if (id == p.mem_id) {
        file.seekg(-sizeof(p), ios::cur);
        cout << "Enter new height: ";
        cin >> p.height;
        cout << "Enter new weight: ";
        cin >> p.weight;
        cout << "Enter age: ";
        cin >> p.age;
        file.write((char*)&p, sizeof(p));
        break;
      }
      if(file.eof()==0){
        file.seekg(0);
      }
      file.read((char*)&p, sizeof(p));
    }
  }
  file.close();
}

Member Gym::bmi_cal(int id) {
  Member p;
  int key = (id % size);
  int b = (sizeof(p)) * (key - 1);
  fstream file;
  file.open("member_data.bin", ios::in | ios::out | ios::binary);
  file.seekg(b);
  file.read((char*)&p, sizeof(p));
  if (id == p.mem_id) {
    p.bmi = p.weight / (p.height * p.height);
  }
  else {
    file.read((char*)&p, sizeof(p));
    while (file.good()) {
      if (id == p.mem_id) {
        p.bmi = p.weight / (p.height * p.height);
        break;
      }
      if(file.eof()==0){
        file.seekg(0);
      }
      file.read((char*)&p, sizeof(p));
    }
  }
  file.close();
  cout << "Your BMI is " << p.bmi << endl;
  return p;
}

void Gym::target(int id) {
    float wt;
    Member p;
    p = bmi_cal(id);
    fstream file;
    file.open("member_data.bin", ios::out | ios::binary | ios::in);
    if (p.bmi < 18.5) {
      cout << "You are underweight" << endl;
      wt = (18.5)*(p.height * p.height);
      cout << "We recommend your weight to be near about " << wt << " kg" << endl;
      cout << "Enter your target weight: ";
      cin >> p.target_wt;
    } 
    else if (p.bmi >= 18.5 && p.bmi <= 24.9) {
      cout << "You have normal weight" << endl;
      cout << "Enter your target weight: ";
      cin >> p.target_wt;
    } 
    else if (p.bmi >= 25 && p.bmi <= 29.9) {
      cout << "You are overweight" << endl;
      wt = (25)*(p.height * p.height);
      cout << "We recommend your weight to be near about " << wt << " kg" << endl;
      cout << "Enter your target weight: ";
      cin >> p.target_wt;
    } 
    else {
      cout << "Obesse!!!!!" << endl;
      wt = (25)*(p.height * p.height);
      cout << "We recommend your weight to be near about " << wt << " kg" << endl;
      cout << "Enter your target weight: ";
      cin >> p.target_wt;
    }
  file.close();
}

void Gym::find(int id) {
  float bm;
  Member p;
  p = bmi_cal(id);
  //bm = p.target_wt / (p.height * p.height);
  //cout << "BMI based on your target wt: " << bm << endl;
  if (p.bmi < 18.5) {
    underwt();
  } 
  else if (p.bmi >= 18.5 && p.bmi <= 24.9) {
    normal();
  }
  else {
    overwt();
  }
}

void Gym::del() {
  int id;
  cout << "Enter id: ";
  cin >> id;
  Member p;
  int key = (id % size);
  int b = (sizeof(p)) * (key - 1);
  fstream file;
  fstream newFile;
  file.open("member_data.bin", ios::binary | ios::out | ios::in);
  newFile.open("PrevMem.bin",ios::app | ios::binary | ios::out);
  file.seekg(b);
  file.read((char*)&p, sizeof(p));
  if (id == p.mem_id) {
    newFile.write((char*)&p,sizeof(p));
    file.seekg(-sizeof(p), ios::cur);
    p.mem_id = p.height = p.weight = p.age = p.contact = p.bmi = p.target_wt = p.month_plan = p.age = p.cost = 0;
      strcpy(p.name, "_____");
      strcpy(p.gender, "_____");
      strcpy(p.address, "_____");
      strcpy(p.dob, "_____");
    file.write((char*)&p, sizeof(p));
  }
  else {
    file.read((char*)&p, sizeof(p));
    while (file.good()) {
      if (id == p.mem_id) {
        newFile.write((char*)&p,sizeof(p));
        file.seekg(-sizeof(p), ios::cur);
        p.mem_id = p.height = p.weight = p.age = p.contact = p.bmi = p.target_wt = p.month_plan = p.age = p.cost = 0;
      strcpy(p.name, "_____");
      strcpy(p.gender, "_____");
      strcpy(p.address, "_____");
      strcpy(p.dob, "_____");
        file.write((char*)&p, sizeof(p));
        break;
      }
      if(file.eof()==0){
        file.seekg(0);
      }
      file.read((char*)&p, sizeof(p));
    }
  }
  file.close();
}
