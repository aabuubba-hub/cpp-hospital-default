#pragma once
#include <windows.h>
#include <string>
#include "Hospital.h"

// Window Control IDs
#define ID_BUTTON_ADD_PATIENT 1
#define ID_BUTTON_VIEW_PATIENTS 2
#define ID_BUTTON_ADD_STAFF 3
#define ID_BUTTON_VIEW_STAFF 4
#define ID_BUTTON_EXIT 5

#define ID_EDIT_NAME 101
#define ID_EDIT_AGE 102
#define ID_EDIT_DISEASE 103
#define ID_EDIT_DATE 104
#define ID_Button_SUBMIT_PATIENT 105

#define ID_EDIT_STAFF_NAME 201
#define ID_EDIT_STAFF_ROLE 202
#define ID_EDIT_STAFF_SHIFT 203
#define ID_BUTTON_SUBMIT_STAFF 204

#define ID_LISTBOX_DISPLAY 301

// Global variables
extern HospitalSystem hospital;
extern HWND hName, hAge, hDisease, hDate, hRole, hShift, hListDisplay, hMainWindow;

// Function declarations
LRESULT CALLBACK WindowProcedure(HWND, UINT, WPARAM, LPARAM);
void AddMainMenu(HWND);
void ShowAddPatientForm(HWND);
void ShowViewPatients(HWND);
void ShowAddStaffForm(HWND);
void ShowViewStaff(HWND);
void ClearScreen(HWND);
