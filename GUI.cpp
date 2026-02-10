#include "GUI.h"

HospitalSystem hospital;
HWND hName, hAge, hDisease, hDate, hRole, hShift, hListDisplay, hMainWindow;
HWND hLabelName, hLabelAge, hLabelDisease, hLabelDate, hLabelRole, hLabelShift;
HWND hBtnSubmitPatient, hBtnSubmitStaff;

// Helper to remove all child windows (clearing the "screen")
void ClearScreen(HWND hWnd) {
    // Destroy all child windows except the main menu buttons if we had them separate, 
    // but here we will just destroy the form controls and list box.
    // For simplicity in this raw API demo, we'll just destroy specific handles we know about.
    if(hName) DestroyWindow(hName); hName = NULL;
    if(hAge) DestroyWindow(hAge); hAge = NULL;
    if(hDisease) DestroyWindow(hDisease); hDisease = NULL;
    if(hDate) DestroyWindow(hDate); hDate = NULL;
    if(hRole) DestroyWindow(hRole); hRole = NULL;
    if(hShift) DestroyWindow(hShift); hShift = NULL;
    if(hListDisplay) DestroyWindow(hListDisplay); hListDisplay = NULL;
    if(hBtnSubmitPatient) DestroyWindow(hBtnSubmitPatient); hBtnSubmitPatient = NULL;
    if(hBtnSubmitStaff) DestroyWindow(hBtnSubmitStaff); hBtnSubmitStaff = NULL;
    
    // Labels
    if(hLabelName) DestroyWindow(hLabelName); hLabelName = NULL;
    if(hLabelAge) DestroyWindow(hLabelAge); hLabelAge = NULL;
    if(hLabelDisease) DestroyWindow(hLabelDisease); hLabelDisease = NULL;
    if(hLabelDate) DestroyWindow(hLabelDate); hLabelDate = NULL;
    if(hLabelRole) DestroyWindow(hLabelRole); hLabelRole = NULL;
    if(hLabelShift) DestroyWindow(hLabelShift); hLabelShift = NULL;
}

void ShowAddPatientForm(HWND hWnd) {
    ClearScreen(hWnd);
    
    hLabelName = CreateWindowW(L"Static", L"Name:", WS_VISIBLE | WS_CHILD, 220, 50, 100, 20, hWnd, NULL, NULL, NULL);
    hName = CreateWindowW(L"Edit", L"", WS_VISIBLE | WS_CHILD | WS_BORDER, 330, 50, 200, 20, hWnd, (HMENU)ID_EDIT_NAME, NULL, NULL);

    hLabelAge = CreateWindowW(L"Static", L"Age:", WS_VISIBLE | WS_CHILD, 220, 80, 100, 20, hWnd, NULL, NULL, NULL);
    hAge = CreateWindowW(L"Edit", L"", WS_VISIBLE | WS_CHILD | WS_BORDER, 330, 80, 100, 20, hWnd, (HMENU)ID_EDIT_AGE, NULL, NULL);

    hLabelDisease = CreateWindowW(L"Static", L"Disease:", WS_VISIBLE | WS_CHILD, 220, 110, 100, 20, hWnd, NULL, NULL, NULL);
    hDisease = CreateWindowW(L"Edit", L"", WS_VISIBLE | WS_CHILD | WS_BORDER, 330, 110, 200, 20, hWnd, (HMENU)ID_EDIT_DISEASE, NULL, NULL);

    hLabelDate = CreateWindowW(L"Static", L"Date:", WS_VISIBLE | WS_CHILD, 220, 140, 100, 20, hWnd, NULL, NULL, NULL);
    hDate = CreateWindowW(L"Edit", L"", WS_VISIBLE | WS_CHILD | WS_BORDER, 330, 140, 150, 20, hWnd, (HMENU)ID_EDIT_DATE, NULL, NULL);

    hBtnSubmitPatient = CreateWindowW(L"Button", L"Save Patient", WS_VISIBLE | WS_CHILD, 330, 180, 150, 30, hWnd, (HMENU)ID_Button_SUBMIT_PATIENT, NULL, NULL);
}

void ShowAddStaffForm(HWND hWnd) {
    ClearScreen(hWnd);

    hLabelName = CreateWindowW(L"Static", L"Name:", WS_VISIBLE | WS_CHILD, 220, 50, 100, 20, hWnd, NULL, NULL, NULL);
    hName = CreateWindowW(L"Edit", L"", WS_VISIBLE | WS_CHILD | WS_BORDER, 330, 50, 200, 20, hWnd, (HMENU)ID_EDIT_STAFF_NAME, NULL, NULL);

    hLabelRole = CreateWindowW(L"Static", L"Role:", WS_VISIBLE | WS_CHILD, 220, 80, 100, 20, hWnd, NULL, NULL, NULL);
    hRole = CreateWindowW(L"Edit", L"Doctor", WS_VISIBLE | WS_CHILD | WS_BORDER, 330, 80, 200, 20, hWnd, (HMENU)ID_EDIT_STAFF_ROLE, NULL, NULL);

    hLabelShift = CreateWindowW(L"Static", L"Shift:", WS_VISIBLE | WS_CHILD, 220, 110, 100, 20, hWnd, NULL, NULL, NULL);
    hShift = CreateWindowW(L"Edit", L"Day", WS_VISIBLE | WS_CHILD | WS_BORDER, 330, 110, 200, 20, hWnd, (HMENU)ID_EDIT_STAFF_SHIFT, NULL, NULL);

    hBtnSubmitStaff = CreateWindowW(L"Button", L"Save Staff", WS_VISIBLE | WS_CHILD, 330, 150, 150, 30, hWnd, (HMENU)ID_BUTTON_SUBMIT_STAFF, NULL, NULL);
}

void ShowViewPatients(HWND hWnd) {
    ClearScreen(hWnd);
    hListDisplay = CreateWindowW(L"ListBox", L"", WS_VISIBLE | WS_CHILD | WS_BORDER | WS_VSCROLL, 220, 50, 500, 400, hWnd, (HMENU)ID_LISTBOX_DISPLAY, NULL, NULL);
    
    // Load data into listbox
    for (const auto& p : hospital.patients) {
        string str = "ID: " + to_string(p.id) + " | Name: " + p.name + " | Disease: " + p.disease;
        SendMessageA(hListDisplay, LB_ADDSTRING, 0, (LPARAM)str.c_str());
    }
}

void ShowViewStaff(HWND hWnd) {
    ClearScreen(hWnd);
    hListDisplay = CreateWindowW(L"ListBox", L"", WS_VISIBLE | WS_CHILD | WS_BORDER | WS_VSCROLL, 220, 50, 500, 400, hWnd, (HMENU)ID_LISTBOX_DISPLAY, NULL, NULL);

    for (const auto& s : hospital.staff) {
        string str = "ID: " + to_string(s.id) + " | Name: " + s.name + " | Role: " + s.role + " | Shift: " + s.shift;
        SendMessageA(hListDisplay, LB_ADDSTRING, 0, (LPARAM)str.c_str());
    }
}

void AddMainMenu(HWND hWnd) {
    CreateWindowW(L"Button", L"Add Patient", WS_VISIBLE | WS_CHILD, 20, 50, 180, 40, hWnd, (HMENU)ID_BUTTON_ADD_PATIENT, NULL, NULL);
    CreateWindowW(L"Button", L"View Patients", WS_VISIBLE | WS_CHILD, 20, 100, 180, 40, hWnd, (HMENU)ID_BUTTON_VIEW_PATIENTS, NULL, NULL);
    CreateWindowW(L"Button", L"Add Staff", WS_VISIBLE | WS_CHILD, 20, 150, 180, 40, hWnd, (HMENU)ID_BUTTON_ADD_STAFF, NULL, NULL);
    CreateWindowW(L"Button", L"View Staff", WS_VISIBLE | WS_CHILD, 20, 200, 180, 40, hWnd, (HMENU)ID_BUTTON_VIEW_STAFF, NULL, NULL);
    CreateWindowW(L"Button", L"Exit", WS_VISIBLE | WS_CHILD, 20, 300, 180, 40, hWnd, (HMENU)ID_BUTTON_EXIT, NULL, NULL);
}

LRESULT CALLBACK WindowProcedure(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp) {
    switch (msg) {
    case WM_CREATE:
        AddMainMenu(hWnd);
        break;
    case WM_COMMAND:
        switch (LOWORD(wp)) {
        case ID_BUTTON_ADD_PATIENT:
            ShowAddPatientForm(hWnd);
            break;
        case ID_BUTTON_VIEW_PATIENTS:
            ShowViewPatients(hWnd);
            break;
        case ID_BUTTON_ADD_STAFF:
            ShowAddStaffForm(hWnd);
            break;
        case ID_BUTTON_VIEW_STAFF:
            ShowViewStaff(hWnd);
            break;
        case ID_BUTTON_EXIT:
            DestroyWindow(hWnd);
            break;
        case ID_Button_SUBMIT_PATIENT:
            {
                char name[100], age[10], disease[100], date[50];
                GetWindowTextA(hName, name, 100);
                GetWindowTextA(hAge, age, 10);
                GetWindowTextA(hDisease, disease, 100);
                GetWindowTextA(hDate, date, 50);
                
                if (strlen(name) > 0) {
                    hospital.addPatient(Patient(hospital.getNextPatientId(), name, atoi(age), disease, date));
                    MessageBoxW(hWnd, L"Patient Added Successfully!", L"Success", MB_OK);
                    ShowViewPatients(hWnd);
                }
            }
            break;
        case ID_BUTTON_SUBMIT_STAFF:
            {
                char name[100], role[50], shift[50];
                GetWindowTextA(hName, name, 100);
                GetWindowTextA(hRole, role, 50);
                GetWindowTextA(hShift, shift, 50);

                if (strlen(name) > 0) {
                    hospital.addStaff(Staff(hospital.getNextStaffId(), name, role, shift));
                    MessageBoxW(hWnd, L"Staff Added Successfully!", L"Success", MB_OK);
                    ShowViewStaff(hWnd);
                }
            }
            break;
        }
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProcW(hWnd, msg, wp, lp);
    }
    return 0;
}

int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR args, int ncmdshow) {
    WNDCLASSW wc = {0};
    wc.hbrBackground = (HBRUSH)COLOR_WINDOW;
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.hInstance = hInst;
    wc.lpszClassName = L"HMS_WindowClass";
    wc.lpfnWndProc = WindowProcedure;

    if (!RegisterClassW(&wc)) return -1;

    hMainWindow = CreateWindowW(L"HMS_WindowClass", L"Hospital Management System", 
        WS_OVERLAPPEDWINDOW | WS_VISIBLE, 100, 100, 800, 600, NULL, NULL, NULL, NULL);

    MSG msg = {0};
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}
