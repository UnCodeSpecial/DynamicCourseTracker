# Dynamic Course Tracker (C++)

A C++ console application for managing a list of courses using a **dynamically resizing array**. Supports adding courses, listing them, sorting by multiple fields, and serializing data to a binary file on exit.

---

## Features

- Dynamic array that automatically doubles in capacity when full
- Add courses with name, year, units, and grade
- Sort by course name, year, units, or grade (descending)
- Binary file serialization to `cards.dat` on quit
- Displays current array size and capacity in the menu

---

## Concepts Demonstrated

- Dynamic memory allocation and reallocation (`new` / `delete[]`)
- Array doubling / capacity management
- Struct-based data storage
- Sorting a dynamic array by multiple fields using selection sort
- Binary file I/O with `fstream` and `reinterpret_cast`
- `toupper()` for consistent input normalization

---

## How to Run

### Online (easiest)
Paste `Lab8SC.cpp` into [onlinegdb.com](https://onlinegdb.com), set language to C++, and hit Run.

### Local (requires g++)
```bash
g++ -o course_tracker Lab8SC.cpp
./course_tracker
```

No input files required.

---

## Usage

```
Array size: 0 capacity: 2
MENU
Press A ..Add a course
Press L ..List all courses
Press C ..Arrange by course
Press Y ..arrange by Year
Press U ..arrange by Units
Press G ..arrange by Grade
Press Q ..Quit

Your choice > A

Enter a courses' name:
COMSC200
Enter the year for COMSC200 [like 2016]:
2024
Enter the units for COMSC200 [0, 1, 2,...]:
3
Enter the grade for COMSC200 [A, B,..., X if still in progress or planned]:
A
```

---

## Notes

- Starting capacity is 2 — the array doubles automatically as courses are added
- Course names are stored as uppercase char arrays (max 12 characters)
- On quit, data is serialized to `cards.dat` in binary format
- Known limitation: the binary write on quit serializes only one record due to a `sizeof(Course)` vs `size * sizeof(Course)` oversight — a known issue left as-is from the original lab submission
