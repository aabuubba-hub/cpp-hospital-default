#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>

using namespace std;

class Patient {
public:
    int id;
    string name;
    int age;
    string disease;
    string admissionDate;

    Patient(int id = 0, string name = "", int age = 0, string disease = "", string date = "")
        : id(id), name(name), age(age), disease(disease), admissionDate(date) {}

    string toString() const {
        return to_string(id) + "," + name + "," + to_string(age) + "," + disease + "," + admissionDate;
    }
    
    static Patient fromString(string line) {
        stringstream ss(line);
        string segment;
        vector<string> seglist;
        while(getline(ss, segment, ',')) {
            seglist.push_back(segment);
        }
        if (seglist.size() < 5) return Patient();
        return Patient(stoi(seglist[0]), seglist[1], stoi(seglist[2]), seglist[3], seglist[4]);
    }
};

class Staff {
public:
    int id;
    string name;
    string role; // Doctor, Nurse, Admin
    string shift;

    Staff(int id = 0, string name = "", string role = "", string shift = "")
        : id(id), name(name), role(role), shift(shift) {}

    string toString() const {
        return to_string(id) + "," + name + "," + role + "," + shift;
    }

    static Staff fromString(string line) {
        stringstream ss(line);
        string segment;
        vector<string> seglist;
        while(getline(ss, segment, ',')) {
            seglist.push_back(segment);
        }
        if (seglist.size() < 4) return Staff();
        return Staff(stoi(seglist[0]), seglist[1], seglist[2], seglist[3]);
    }
};

class HospitalSystem {
private:
    const string PATIENT_FILE = "patients.dat";
    const string STAFF_FILE = "staff.dat";

public:
    vector<Patient> patients;
    vector<Staff> staff;
    
    HospitalSystem() {
        loadData();
    }

    void loadData();
    void saveData();
    void addPatient(const Patient& p);
    void addStaff(const Staff& s);
    int getNextPatientId();
    int getNextStaffId();
};
