#include <iostream>
#include <string>
using namespace std;

// class Vehicle
class Vehicle {
protected:
    string id;
    string route;
    int capacity;
    int booked; 
public:
    Vehicle(string i = "", string r = "", int c = 0) {
        id = i;
        route = r;
        capacity = c;
        booked = 0;
    }
    ~Vehicle() {}

    // getter
    string getId() { return id; }
    int getCapacity() { return capacity; }
    int getBooked() { return booked; }

    // booked ticket
    bool bookTicket() {
        if (booked < capacity) {
            booked++;
            return true;
        }
        return false;
    }

    void display() {
        cout << "Vehicle ID: " << id
            << " | Route: " << route
            << " | Capacity: " << capacity
            << " | Booked: " << booked << endl;
    }
};

// class Bus ( inheritance )
class Bus : public Vehicle {
private:
    bool wifi;
public:
    Bus(string i = "", string r = "", int c = 0, bool w = false)
        : Vehicle(i, r, c) {
        wifi = w;
    }
    void display() {
        cout << "[Bus] ID: " << id
            << " | Route: " << route
            << " | Capacity: " << capacity
            << " | Booked: " << booked
            << " | Wifi: " << (wifi ? "Yes" : "No") << endl;
    }
};

// class Train
class Train : public Vehicle {
private:
    int cars;
public:
    Train(string i = "", string r = "", int c = 0, int ca = 0)
        : Vehicle(i, r, c) {
        cars = ca;
    }
    void display() {
        cout << "[Train] ID: " << id
            << " | Route: " << route
            << " | Capacity: " << capacity
            << " | Booked: " << booked
            << " | Cars: " << cars << endl;
    }
};

// class Passenger
class Passenger {
private:
    string pid;
    string name;
public:
    Passenger(string i = "", string n = "") {
        pid = i;
        name = n;
    }

    void book(Vehicle& v) {
        if (v.bookTicket()) {
            cout << "Passenger " << name << " booked successfully!\n";
        }
        else {
            cout << "Passenger " << name << " booking failed (full capacity).\n";
        }
    }

    void display() {
        cout << "Passenger ID: " << pid << " | Name: " << name << endl;
    }
};

// class Station
class Station {
private:
    string name;
    Vehicle* vehicles[10]; 
    int count;
public:
    Station(string n = "") {
        name = n;
        count = 0;
    }
    ~Station() {}

    // thêm phương tiện
    void addVehicle(Vehicle* v) {
        if (count < 10) {
            vehicles[count++] = v;
        }
    }

    // in danh sách phương tiện
    void showVehicles() {
        cout << "-- Station: " << name << " --" << endl;
        for (int i = 0; i < count; i++) {
            vehicles[i]->display();
        }
    }
};

int main() {
    // Tạo station
    Station st("Central Station");

    // Tạo vehicle
    Bus b1("B001", "Downtown", 3, true);
    Train t1("T001", "City Express", 5, 8);
    Bus b2("B002", "Airport", 2, false);

    // Thêm vehicle vào station
    st.addVehicle(&b1);
    st.addVehicle(&t1);
    st.addVehicle(&b2);

    // Hiển thị danh sách phương tiện
    st.showVehicles();

    cout << "\n--- Passenger Booking ---\n";

    // Tạo passenger
    Passenger p1("P01", "Alice");
    Passenger p2("P02", "Bob");
    Passenger p3("P03", "Charlie");
    Passenger p4("P04", "David");

    // Passenger đặt vé
    p1.book(b1);
    p2.book(b1);
    p3.book(b1);
    p4.book(b1); // full capacity

    cout << "\n Vehicles after booking\n";
    st.showVehicles();

    return 0;
}
