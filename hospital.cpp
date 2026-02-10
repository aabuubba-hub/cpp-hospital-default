#include "Hospital.h"

void HospitalSystem::loadData() {
    ifstream pFile(PATIENT_FILE);
    string line;
    if (pFile.is_open()) {
        while (getline(pFile, line)) {
            if(!line.empty()) patients.push_back(Patient::fromString(line));
        }
        pFile.close();
    }

    ifstream sFile(STAFF_FILE);
    if (sFile.is_open()) {
        while (getline(sFile, line)) {
            if(!line.empty()) staff.push_back(Staff::fromString(line));
        }
        sFile.close();
    }
}

void HospitalSystem::saveData() {
    ofstream pFile(PATIENT_FILE);
    for (const auto& p : patients) {
        pFile << p.toString() << endl;
    }
    pFile.close();
    
    ofstream sFile(STAFF_FILE);
    for (const auto& s : staff) {
        sFile << s.toString() << endl;
    }
    sFile.close();
}

void HospitalSystem::addPatient(const Patient& p) {
    patients.push_back(p);
    saveData();
}

void HospitalSystem::addStaff(const Staff& s) {
    staff.push_back(s);
    saveData();
}

int HospitalSystem::getNextPatientId() {
    if (patients.empty()) return 1;
    int maxId = 0;
    for (const auto& p : patients) {
        if (p.id > maxId) maxId = p.id;
    }
    return maxId + 1;
}

int HospitalSystem::getNextStaffId() {
    if (staff.empty()) return 1;
    int maxId = 0;
    for (const auto& s : staff) {
        if (s.id > maxId) maxId = s.id;
    }
    return maxId + 1;
}
