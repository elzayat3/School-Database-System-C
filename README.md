# 🎓 School Database System (C)

A console-based **School Management System** implemented in pure C, designed with a modular architecture and interactive UI.

The system allows managing students, their personal data, and family information with full CRUD operations and persistent storage.

---

## 🚀 Features

* ➕ Add new students
* 📄 Print all students
* 🔍 Search students (by name or number)
* ✏️ Update student information (name, age, grade, parents, brothers)
* ❌ Delete students (by name or number)
* 📊 Sort students by:

  * Age
  * Name
  * Grade
* 📞 Call student (simulate retrieving parent phone)
* 💾 Save & Load data from file
* 🎮 Interactive console UI with:

  * Arrow key navigation
  * Highlighted menu
  * Submenus
  * Smooth rendering (no flickering)

---

## 🧠 Project Structure

```
School-Database-System-C/
│
├── src/
│   ├── main.c          # Entry point
│   ├── ui.c            # UI & menu system
│   ├── student.c       # Student & person handling
│   ├── student_db.c    # Core database logic
│   ├── utils.c         # Helper functions (strings, etc.)
│   └── storage.c       # File handling (save/load)
│
├── include/
│   ├── ui.h
│   ├── student.h
│   ├── student_db.h
│   ├── utils.h
│   └── storage.h
│
├── data/
│   └── students.dat    # Binary database file
│
└── README.md
```

---

## ⚙️ How It Works

* The system stores students in a static array.
* Each student contains:

  * Name, Age, Grade
  * Father & Mother data
  * Dynamic list of brothers
* Data is saved in a binary file (`students.dat`) and restored on startup.

---

## 🖥️ UI Preview

* Navigate using:

  * ⬆️ Arrow Up
  * ⬇️ Arrow Down
  * ⏎ Enter
* Console colors are used for highlighting selections.

---

## 🛠️ Build & Run

### 🔧 Using GCC (Windows - MinGW)

```bash
gcc src/*.c -Iinclude -o school.exe
./school.exe
```

---

## 📦 Data Persistence

* Data is stored in:

```
data/students.dat
```

* Automatically:

  * Loaded at startup
  * Saved on exit

---

## 🧩 Technologies Used

* C (ANSI C)
* Windows Console API
* File Handling (Binary I/O)
* Dynamic Memory Allocation

---

## 🧠 Concepts Applied

* Modular Programming
* Separation of Concerns
* Dynamic Memory Management
* Custom Console Rendering
* Menu-driven Architecture
* Basic Data Structures

---

## 📌 Future Improvements

* Replace `scanf` with full keyboard input system
* Add GUI (using SDL / Qt)
* Implement search optimization
* Add student IDs
* Improve file format (versioning)

---

## 👨‍💻 Author

**Abdelrahman Elzayat**

---

## ⭐ Notes

This project demonstrates building a complete system in C starting from low-level memory handling up to user interface design.

---
