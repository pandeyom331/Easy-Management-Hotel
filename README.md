# 🏨 Easy Management V1 – Hotel Booking System

Welcome to **Easy Management V1 – Hotel Version**, a simple and interactive **console-based hotel room booking system** built in C++. This project simulates a basic hotel front desk operation, allowing staff to manage room bookings, view customer information, edit records, and much more – all through a user-friendly terminal interface.

---

## 🚀 How to Run

1. **Make sure you have a C++ compiler** installed on your system (e.g., `g++`).
2. **Compile the code** using the following command:
   ```bash
   g++ HOTEL.CPP -o hotel

3. **Run the executable:**
    ```bash    
   ./hotel

---

## 🔐 Login Credentials
When you start the program, you’ll be prompted to log in.

Username: admin

Password: ******

⚠️ You can change the login credentials by modifying the main() function in the code.

---


## 📋 Features & How to Use (Detailed)
Once logged in, you’ll see a Main Menu with several options. Here’s what each one does:

**1️⃣ Book A Room**
Enter a room number and customer details (name, address, phone, days of stay).

The system checks if the room is already booked.

If available, it books the room and stores the information in a file.

The fare is auto-calculated as ₹900 per day.

💡 Great for when a new guest arrives and needs to book a room.


**2️⃣ Customer Record**
Enter a room number to fetch the customer’s information.

Displays:

Name

Address

Phone number

Days stayed

Total fare

💡 Use this to look up details of any current guest.


**3️⃣ Rooms Allotted**
Shows a list of all rooms that are currently booked.

Displays customer details for each room.

💡 Perfect for viewing room occupancy at a glance.


**4️⃣ Edit Record**
You can either:

Modify: Update a customer’s details and duration of stay.

Delete: Cancel a booking and remove the record from the system.

💡 Useful for handling cancellations or updates.


**5️⃣ Exit**
Closes the application.

---


ℹ️ All customer data is saved automatically in a file called Record.dat, so no need to worry about saving before exiting.

**📁 Data Handling**
All customer information is stored in a binary file named Record.dat.

Deletion is handled safely using a temporary file (Temp.dat) to preserve other data.

Data is preserved between sessions.

---

**📷 Working Demo** (Screenshots)
To get a quick look at how the system works, check out the screenshots inside the Working Demo folder included in this repository.

📁 Working Demo/ — Contains step-by-step visuals of the system in action.

---


**✅ Requirements**
A C++ compiler (like g++)

Works on:

Linux/Unix (Terminal)

Windows (Command Prompt or PowerShell)

macOS (Terminal)

---


**📌 Note**
This is a simple terminal-based app, ideal for learning file handling and OOP in C++.

No external libraries are used.

Password input is not hidden (plaintext) – feel free to improve this!

---


**🙌 Contributions**
Feel free to fork this repository and enhance the project with:

GUI or Web Interface

Encrypted login

Room availability calendar

Better file formats (like JSON or CSV)


🛎️ Thanks for using Easy Management V1 – Hotel Booking System!
