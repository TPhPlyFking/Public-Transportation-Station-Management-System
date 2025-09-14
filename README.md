# Public Transportation Station Management System

## 📖 Introduction
This project is a **C++ Object-Oriented Programming (OOP)** implementation of a simple **Public Transportation Station Management System**. The program demonstrates the use of **inheritance, encapsulation, constructors/destructors, and method overriding**. It avoids the use of `virtual` functions and STL containers like `vector`, instead relying on **arrays and pointers** to manage objects. This makes the project suitable for beginners who want to practice OOP concepts in a clear and straightforward way.

## 🏗️ Design Overview
The system consists of several key classes:

- **Vehicle (Base Class)**:  
  Contains general attributes such as ID, route, capacity, and number of booked passengers.  

- **Bus (Derived Class)**:  
  Inherits from `Vehicle` and adds a specific property (`wifi`).  

- **Train (Derived Class)**:  
  Inherits from `Vehicle` and adds the number of train cars.  

- **Passenger**:  
  Represents a passenger with ID and name. Passengers can book tickets for a specific vehicle.  

- **Station**:  
  Manages a collection of vehicles using a fixed-size array of pointers. It provides methods to add vehicles and display them.

## ⚙️ How It Works
1. Vehicles (`Bus`, `Train`) are created with specific attributes.  
2. A `Station` object stores multiple vehicles.  
3. `Passenger` objects attempt to book tickets. If capacity is available, the booking is successful; otherwise, it fails.  
4. The program prints detailed information about vehicles before and after booking.  

This setup mimics a small transportation hub where passengers reserve seats on available buses and trains.

## 🎯 Purpose
The main goal of this project is to provide a **hands-on example of OOP in C++** while following assignment requirements:
- Apply inheritance and encapsulation.  
- Implement constructors and destructors.  
- Avoid advanced STL features (e.g., `vector`) and `virtual` functions.  
- Show practical testing in the `main` function.  

## ✅ Conclusion
This system highlights the essentials of OOP in C++ without unnecessary complexity. It is extendable, easy to understand, and a strong foundation for future projects such as full ticketing systems or timetable management.
