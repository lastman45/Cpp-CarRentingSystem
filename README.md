# 🚗 Car Rental System

A console-based Car Rental System written in C++ that allows users to browse a catalog of available cars, view vehicle details, and complete a rental booking — all secured behind a password-protected login.

---

## Table of Contents

- [Overview](#overview)
- [Features](#features)
- [Car Catalog](#car-catalog)
- [Prerequisites](#prerequisites)
- [Compilation & Running](#compilation--running)
- [Usage](#usage)
- [Project Structure](#project-structure)
- [Known Issues & Limitations](#known-issues--limitations)
- [Future Improvements](#future-improvements)

---

## Overview

This is a beginner-level C++ project demonstrating the use of structs, functions, loops, and basic input/output to simulate a car rental workflow. A user logs in with a password, selects a car from the menu, reviews its details, and provides personal and payment information to complete a rental.

---

## Features

- **Password-protected login** — masks input characters with `*` for basic security
- **Car selection menu** — choose from 7 different vehicles
- **Car detail view** — displays model, colour, maximum speed, and price for the selected car
- **Rental booking** — collects user name, ID, and payment amount
- **Payment validation** — confirms whether the entered amount meets the rental price
- **Loop-based session** — continue renting or exit after each transaction

---

## Car Catalog

| # | Company   | Model     | Colour | Max Speed | Price (KES) |
|---|-----------|-----------|--------|-----------|-------------|
| 1 | Nissan    | GT-R      | Yellow | 80 km/h   | 10,000      |
| 2 | Toyota    | Camry     | Black  | 200 km/h  | 20,000      |
| 3 | Audi      | A4        | Red    | 300 km/h  | 30,000      |
| 4 | BMW       | 3 Series  | Silver | 250 km/h  | 40,000      |
| 5 | Honda     | C         | Grey   | 320 km/h  | 35,000      |
| 6 | Ford      | R8        | Blue   | 400 km/h  | 27,000      |
| 7 | Mercedes  | Q7        | Aqua   | 250 km/h  | 450,000     |

---

## Prerequisites

| Requirement | Details |
|---|---|
| **Operating System** | Windows only (uses `<conio.h>` and `system("cls")`) |
| **Compiler** | MinGW g++ / MSVC / any Windows-compatible C++ compiler |
| **C++ Standard** | C++11 or later |

> ⚠️ **Note:** This project relies on `<conio.h>` (`getch()`) and `system("cls")` / `system("pause")`, which are **Windows-specific**. It will not compile or run on Linux or macOS without modification.

---

## Compilation & Running

### Using g++ (MinGW on Windows)

```bash
g++ -o CarRentalSystem CarRentalSystem.cpp -std=c++11
./CarRentalSystem
```

### Using MSVC (Developer Command Prompt)

```bash
cl CarRentalSystem.cpp
CarRentalSystem.exe
```

### Using an IDE

Open `CarRentalSystem.cpp` in **Code::Blocks**, **Dev-C++**, or **Visual Studio** and build/run directly.

---

## Usage

### 1. Login

On launch, you will be prompted for a password. Input is hidden behind `*` characters.

```
CAR RENTALS SYSTEM LOGIN

Enter Password: ****
Access Granted
```

> 🔑 **Default password:** `pass`

### 2. Select a Car

```
CAR RENTAL SYSTEM

Select an option from the menu:
Enter 1  - To Select Nissan
Enter 2  - To Select Toyota
...
Enter 7  - To Select Mercedes

Your Choice(1-7):
```

### 3. View Car Details

```
You Have Selected - BMW

Model    : 3 Series
Colour   : Silver
Max Speed: 250km/h
Price    : 40000
```

### 4. Confirm & Enter Details

```
Are you sure you want to proceed? (Yes/No/Exit):
```

If `Yes`, you will be prompted to enter:
- Your **Name**
- Your **ID**
- Your **Payment amount**

The system will then confirm whether your payment meets the quoted rental price.

### 5. Continue or Exit

```
Do you want to continue? (Yes/No):
```

Type `No` to end the session, or `Yes` to return to the menu. You can also type `Exit` at the confirmation prompt to quit immediately.

---

## Project Structure

```
CarRentalSystem.cpp
│
├── struct Cars          — Stores car data (company, model, colour, speed, date, price)
├── struct LeaseInfo     — Stores up to 100 rental records (name, ID, payment)
│
├── Menu()               — Displays the car selection menu
├── Details(int)         — Shows details for the selected car
├── CheckLease(int)      — Validates payment against rental price
├── UserInput(int)       — Collects user personal and payment details
├── Login()              — Handles password authentication (recursive on failure)
└── main()               — Entry point; drives the main rental loop
```

---

## Known Issues & Limitations

| Issue | Description |
|---|---|
| **Windows-only** | Uses `<conio.h>`, `system("cls")`, `system("pause")` — not portable |
| **Hardcoded password** | Password `"pass"` is stored in plain text in the source code |
| **No data persistence** | All rental data is lost when the program exits |
| **Recursive login** | Failed login calls `Login()` recursively — deep failures could cause a stack overflow |
| **No return value in `Login()`** | The function is declared `int` but never returns a value |
| **Single-word name/ID input** | `cin >>` stops at spaces, so multi-word names are not supported |
| **Array size mismatch risk** | `LeaseInfo` arrays are sized 100 but indexed by car choice (0–6), which is functionally fine but semantically inconsistent |
| **No input validation on payment** | Non-numeric payment input will cause undefined behaviour |
| **Car model mislabelling** | Ford is assigned model "R8" (an Audi model) and Audi is assigned "A4" — appears to be a data entry error |

---

## Future Improvements

- [ ] Replace `<conio.h>` with cross-platform input handling for Linux/macOS support
- [ ] Store rental records in a file (e.g., CSV or binary) for persistence between sessions
- [ ] Use a secure password hashing mechanism instead of plain-text comparison
- [ ] Replace recursive login with an iterative loop with a maximum attempt limit
- [ ] Add support for multi-word names using `getline()`
- [ ] Implement date-based rental periods and dynamic pricing
- [ ] Add an admin panel to manage car listings and view rental history
- [ ] Migrate from raw arrays in structs to `std::vector` and `std::string` with proper OOP design

---

## License

This project is provided for educational purposes. Feel free to use and modify it as you see fit.
