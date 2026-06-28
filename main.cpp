
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Patient {
public:
    int id;
    string name;
    int age;
    string disease;
    string phone;
};

vector<Patient> patients;

void addPatient() {
    Patient p;
    cout << "\nEnter Patient ID: ";
    cin >> p.id;
    cin.ignore();

    cout << "Enter Name: ";
    getline(cin, p.name);

    cout << "Enter Age: ";
    cin >> p.age;
    cin.ignore();

    cout << "Enter Disease: ";
    getline(cin, p.disease);

    cout << "Enter Phone: ";
    getline(cin, p.phone);

    patients.push_back(p);
    cout << "\nPatient Added Successfully!\n";
}

void displayPatients() {
    if (patients.empty()) {
        cout << "\nNo Patient Records Found.\n";
        return;
    }

    cout << "\n=========== PATIENT LIST ===========\n";
    for (const auto &p : patients) {
        cout << "-----------------------------------\n";
        cout << "ID       : " << p.id << endl;
        cout << "Name     : " << p.name << endl;
        cout << "Age      : " << p.age << endl;
        cout << "Disease  : " << p.disease << endl;
        cout << "Phone    : " << p.phone << endl;
    }
}

void searchPatient() {
    int id;
    cout << "\nEnter Patient ID to Search: ";
    cin >> id;

    for (const auto &p : patients) {
        if (p.id == id) {
            cout << "\nPatient Found\n";
            cout << "ID       : " << p.id << endl;
            cout << "Name     : " << p.name << endl;
            cout << "Age      : " << p.age << endl;
            cout << "Disease  : " << p.disease << endl;
            cout << "Phone    : " << p.phone << endl;
            return;
        }
    }
    cout << "\nPatient Not Found.\n";
}

void updatePatient() {
    int id;
    cout << "\nEnter Patient ID to Update: ";
    cin >> id;
    cin.ignore();

    for (auto &p : patients) {
        if (p.id == id) {
            cout << "Enter New Name: ";
            getline(cin, p.name);

            cout << "Enter New Age: ";
            cin >> p.age;
            cin.ignore();

            cout << "Enter New Disease: ";
            getline(cin, p.disease);

            cout << "Enter New Phone: ";
            getline(cin, p.phone);

            cout << "\nRecord Updated Successfully.\n";
            return;
        }
    }
    cout << "\nPatient Not Found.\n";
}

void deletePatient() {
    int id;
    cout << "\nEnter Patient ID to Delete: ";
    cin >> id;

    for (size_t i = 0; i < patients.size(); i++) {
        if (patients[i].id == id) {
            patients.erase(patients.begin() + i);
            cout << "\nRecord Deleted Successfully.\n";
            return;
        }
    }
    cout << "\nPatient Not Found.\n";
}

void menu() {
    cout << "\n=====================================\n";
    cout << "     HOSPITAL MANAGEMENT SYSTEM\n";
    cout << "=====================================\n";
    cout << "1. Add Patient\n";
    cout << "2. Display Patients\n";
    cout << "3. Search Patient\n";
    cout << "4. Update Patient\n";
    cout << "5. Delete Patient\n";
    cout << "6. Exit\n";
    cout << "Enter Choice: ";
}

int main() {
    int choice;

    do {
        menu();
        cin >> choice;

        switch (choice) {
        case 1:
            addPatient();
            break;
        case 2:
            displayPatients();
            break;
        case 3:
            searchPatient();
            break;
        case 4:
            updatePatient();
            break;
        case 5:
            deletePatient();
            break;
        case 6:
            cout << "\nThank You!\n";
            break;
        default:
            cout << "\nInvalid Choice!\n";
        }

    } while (choice != 6);

    return 0;
}
