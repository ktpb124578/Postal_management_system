
# 📮 Postal Service Management System — OOP Project

A self-developed **console-based Postal Service Information System** created by **Krityapriya Bhaumik**, a B.Tech Mechanical Engineering student, using Object Oriented Programming in C++. The project simulates key operations of a postal delivery workflow including customer orders, payment processing, and staff roles.

---

## 🧩 Functional Overview

### 👤 User Authentication
- **Sign Up / Sign In** functionalities for:
  - Customers
  - Clerks
  - Postmen
  - Officers
  - Head (Admin)

### 📦 Order Management
- Customers can:
  - Place parcel orders by providing weight, dimensions, address, and contact info
  - View their placed orders
- Orders are assigned unique IDs and stored persistently

### 💰 Payment Processing
- Calculates bill based on parcel weight
- Generates breakdown of stamp denominations (Rs. 5, 10, 20, 50, 100)
- Appends billing data to `Payment.txt`

### 🧾 Invoice Generation
- Displays complete order summary:
  - Sender/Receiver details
  - Parcel info (weight, size, duration)
  - Final bill

### 📊 Admin (Head) Role
- Views daily transactions
- Reads and analyzes stamp usage and revenue

---

## ⚙️ Technologies Used

- **C++** (with classes, inheritance, file I/O)
- Console-based interface
- Text file storage (e.g., `Customer.txt`, `Parcel.txt`, `Payment.txt`)

---

## 👤 Developer

**Krityapriya Bhaumik**  
B.Tech Mechanical Engineering  
Self-directed project for deepening OOP and system design skills.
