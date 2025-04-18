#include <iostream>
#include <fstream>
#include <string>
#include <thread>
#include <chrono>

using namespace std;

//MARK:- Interface Functions

void intro() {
    cout << "\n\n\t            ";
    cout << "     EASY MANAGEMENT V1 Hotel version       ";
}

void head() {
    cout << string(50, '\n');
    cout << "==============================================";
    cout << "\n\t\t Om Group of Hotels\n";
    cout << "==============================================";
}

void wait_with_dots() {
    cout << "\n\n\tConnecting to Server\n\tSyncing Data";
    for (int i = 0; i < 10; ++i) {
        this_thread::sleep_for(chrono::milliseconds(250));
        cout << ".";
        cout.flush();
    }
    cout << endl;
}

//MARK:- Hotel Class

class Hotel {
private:
    int room_no;
    string name;
    string address;
    string phone;
    int days;
    float fare;

public:
    void main_menu();
    void add();
    void display();
    void rooms();
    void edit();
    int check(int);
    void modify(int);
    void delete_rec(int);
};

void Hotel::main_menu() {
    int choice = 0;
    while (choice != 5) {
        head();
        cout << "\n\t\t*************";
        cout << "\n\t\t* MAIN MENU *";
        cout << "\n\t\t*************";
        cout << "\n\n\t1. Book A Room";
        cout << "\n\t2. Customer Record";
        cout << "\n\t3. Rooms Allotted";
        cout << "\n\t4. Edit Record";
        cout << "\n\t5. Exit";
        cout << "\n\n\tEnter Your Choice: ";
        cin >> choice;
        cin.ignore();
        switch (choice) {
            case 1: add(); break;
            case 2: display(); break;
            case 3: rooms(); break;
            case 4: edit(); break;
            case 5: break;
            default:
                cout << "\nInvalid choice. Press Enter to continue...";
                cin.ignore();
        }
    }
}

void Hotel::add() {
    head();
    int r;
    cout << "\n Enter Customer Details";
    cout << "\n ----------------------";
    cout << "\n\n Room no: ";
    cin >> r;
    cin.ignore();
    if (check(r)) {
        cout << "\n Sorry..!!! Room is already booked";
    } else {
        room_no = r;
        cout << " Name: ";
        getline(cin, name);
        cout << " Address: ";
        getline(cin, address);
        cout << " Phone No: ";
        getline(cin, phone);
        cout << " No of Days to Checkout: ";
        cin >> days;
        fare = days * 900;

        ofstream fout("Record.dat", ios::app | ios::binary);
        fout.write(reinterpret_cast<char*>(this), sizeof(Hotel));
        fout.close();

        cout << "\n Room is booked...!!!";
    }
    cout << "\n Press Enter to continue.....!!";
    cin.ignore(); cin.get();
}

void Hotel::display() {
    head();
    ifstream fin("Record.dat", ios::in | ios::binary);
    int r;
    bool found = false;
    cout << "\n Enter room no: ";
    cin >> r;
    while (fin.read(reinterpret_cast<char*>(this), sizeof(Hotel))) {
        if (room_no == r) {
            head();
            cout << "\n Customer Details";
            cout << "\n ----------------";
            cout << "\n Room no: " << room_no;
            cout << "\n Name: " << name;
            cout << "\n Address: " << address;
            cout << "\n Phone no: " << phone;
            cout << "\n Days: " << days;
            cout << "\n Total Fare: " << fare;
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "\n Room not found or vacant....!!";
    }
    fin.close();
    cout << "\n\n Press Enter to continue....!!";
    cin.ignore(); cin.get();
}

void Hotel::rooms() {
    head();
    ifstream fin("Record.dat", ios::in | ios::binary);
    cout << "\n\t List Of Rooms Allotted";
    cout << "\n\t ----------------------";
    while (fin.read(reinterpret_cast<char*>(this), sizeof(Hotel))) {
        cout << "\n Room no: " << room_no;
        cout << "\n Name: " << name;
        cout << "\n Address: " << address;
        cout << "\n Phone: " << phone;
        cout << "\n Days: " << days;
        cout << "\n Total: " << fare;
        cout << "\n**********************************";
    }
    fin.close();
    cout << "\n\n Press Enter to continue.....!!";
    cin.ignore(); cin.get();
}

void Hotel::edit() {
    head();
    int choice, r;
    cout << "\n EDIT MENU";
    cout << "\n ---------";
    cout << "\n\n 1. Modify Customer Record";
    cout << "\n 2. Delete Customer Record";
    cout << "\n Enter your choice: ";
    cin >> choice;
    cout << "\n Enter room no: ";
    cin >> r;
    cin.ignore();
    switch (choice) {
        case 1: modify(r); break;
        case 2: delete_rec(r); break;
        default:
            cout << "\n Invalid choice.";
    }
    cout << "\n Press Enter to continue....!!!";
    cin.get();
}

int Hotel::check(int r) {
    ifstream fin("Record.dat", ios::in | ios::binary);
    while (fin.read(reinterpret_cast<char*>(this), sizeof(Hotel))) {
        if (room_no == r) {
            fin.close();
            return 1;
        }
    }
    fin.close();
    return 0;
}

void Hotel::modify(int r) {
    head();
    fstream file("Record.dat", ios::in | ios::out | ios::binary);
    bool found = false;
    while (!file.eof()) {
        streampos pos = file.tellg();
        file.read(reinterpret_cast<char*>(this), sizeof(Hotel));
        if (room_no == r) {
            cout << "\n Enter New Details";
            cout << "\n Name: ";
            getline(cin, name);
            cout << " Address: ";
            getline(cin, address);
            cout << " Phone no: ";
            getline(cin, phone);
            cout << " Days: ";
            cin >> days;
            fare = days * 900;
            file.seekp(pos);
            file.write(reinterpret_cast<char*>(this), sizeof(Hotel));
            cout << "\n Record modified.";
            found = true;
            break;
        }
    }
    if (!found)
        cout << "\n Room not found or vacant...!!";
    file.close();
}

void Hotel::delete_rec(int r) {
    head();
    ifstream fin("Record.dat", ios::in | ios::binary);
    ofstream fout("Temp.dat", ios::out | ios::binary);
    bool found = false;
    char ch;
    while (fin.read(reinterpret_cast<char*>(this), sizeof(Hotel))) {
        if (room_no == r) {
            cout << "\n Name: " << name;
            cout << "\n Address: " << address;
            cout << "\n Phone No: " << phone;
            cout << "\n Days: " << days;
            cout << "\n Total Fare: " << fare;
            cout << "\n\n Do you want to delete this record (y/n)? ";
            cin >> ch;
            if (ch != 'y' && ch != 'Y')
                fout.write(reinterpret_cast<char*>(this), sizeof(Hotel));
            found = true;
        } else {
            fout.write(reinterpret_cast<char*>(this), sizeof(Hotel));
        }
    }
    fin.close();
    fout.close();
    remove("Record.dat");
    rename("Temp.dat", "Record.dat");
    if (!found)
        cout << "\n Room not found or vacant...!!";
}

//MARK:- Main Function

int main() {
    Hotel h;
    intro();
    wait_with_dots();
    cout << "\n\n\tPress Enter to continue....!!";
    cin.get();

    string id, pass;
    head();
    cout << "\n\n\t\t\t\tUsername => ";
    cin >> id;
    cout << "\n\t\t\t\tPassword => ";
    cin >> pass;
    wait_with_dots();
    if (id == "admin" && pass == "******") {
        cout << "\n\n\t\t\t  !!!Login Successful!!!";
    } else {
        cout << "\n\n\t\t\t!!!INVALID CREDENTIALS!!!";
        return 1;
    }
    cin.ignore(); cin.get();
    h.main_menu();
    return 0;
}
