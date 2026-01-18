# 🐦 Bird Merchant  
### CCPROG1 Machine Project (C Language)
Author: Adrian George Andres B. Lascano

---

## 📌 Overview
**Bird Merchant** is a console-based game written in **C**, developed as a **CCPROG1 Machine Project**.  
The objective of the game is to **gather 30 units of corn within 25 days** by traveling between different lands and trading seeds and corn strategically.

This project focuses on applying **fundamental programming concepts** through a simple but complete game system.

---

## 🎯 Game Objective
- Start with **5 seeds**
- Travel between different lands
- Trade **Seed ↔ Corn**
- Manage resources wisely
- Reach **30 corn before Day 25**

---

## 🗺️ Locations
The game consists of four lands:

1. **Quail Land**
2. **Duck Land**
3. **Turkey Land**
4. **Parrot Land**

Each location has:
- Different exchange rates
- Different travel times
- Limited valid travel paths

⚠️ Not all lands are directly connected.

---

## ⚙️ Game Modes

### 🟢 Normal Mode (MPLascano_SecretCode.c)
- Fixed starting location (Quail Land)
- Fixed exchange rates per land
- Standard gameplay mechanics
- Secret Code

### 🔴 Extreme Mode (MP_RandomSpawnValues.c)
- Secret Code
- Random starting location
- Randomized exchange rates every transaction
- Bulk buying option
- Higher difficulty and unpredictability

---

## ✨ Features
- Text-based interactive interface
- Travel system with valid and invalid routes
- Dynamic resource management
- Bulk buying mechanics
- Secret code system (usable once)
- Modular function-based design
- Randomized values (Extreme Mode)

---

## 🛠️ Compilation & Execution
Compile the program using **GCC** with C99 standard:

```bash
gcc -Wall -std=c99 MP_RandomSpawnValues.c -o run.exe
./run.exe
📦 Bird-Merchant
 ┣ 📄 MP_RandomSpawnValues.c   # Main program
 ┣ 📄 MPLascano_fn.c           # Normal mode functions
 ┣ 📄 MPLascano_fn2.c          # Extreme mode functions
 ┗ 📄 README.md                # Project documentation
