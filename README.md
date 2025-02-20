# university-management-system

## Overview
This project implements a **University Management System** using various data structures to efficiently manage student records, course information, enrollment histories, and course registrations. The system integrates:
- **Single Linked List (SLL)** for student records management
- **Binary Search Tree (BST)** for course records management
- **Double Linked List (DLL)** for tracking course enrollment history
- **Stack** for course prerequisite validation
- **Queue** for course waitlists
- **Hash Table** for fast access and optimized searching
- **Linear and Binary Search** for additional search functionalities

---

## Functional Components

### 1. Student Records Management (Single Linked List)
**Operations:**
- `add(ID, Name, Email, Phone, Address, Password)`: Adds a new student.
- `delete(ID)`: Removes a student by their ID.
- `display()`: Prints all student details.

### 2. Course Records Management (Binary Search Tree)
**Structure:**
- Each node contains `CourseID, CourseName, CourseCredits, CourseInstructor`.
- Left subtree holds courses with smaller IDs, right subtree holds courses with larger IDs.

**Operations:**
- `addCourse(CourseID, CourseName, CourseCredits, CourseInstructor)`: Adds a course.
- `dropCourse(CourseID)`: Removes a course.

### 3. Course Enrollment History (Double Linked List)
**Operations:**
- `add(studentID, CourseID)`: Adds an enrollment record for a student.
- `view(studentID)`: Displays the enrollment history of a student.

### 4. Course Registration (Stack)
**Operations:**
- `validatePrerequisites(courseID, studentID)`: Checks if a student meets course prerequisites.
- Displays remaining prerequisites if validation fails.

### 5. Course Waitlist Management (Queue)
**Operations:**
- `enqueue(studentID, courseID)`: Adds a student to the waitlist when a course is full.
- `dequeue(courseID)`: Enrolls the first student from the waitlist when a seat is available.

### 6. Search and Sort Operations
- **Search students by ID (Linear/Binary Search)**
- **Search courses by ID (Binary Search)**

### 7. Fast Access Using Hashing 
- **Hash Table Implementation**
- **Hashing function for efficient lookups**
- **Collision handling using Chaining/Open Addressing**
- `searchWithHashing(courseID)`: Improves course search efficiency.

---

## Installation and Usage
### Prerequisites
- A C++ compiler (e.g., GCC, MSVC)
- Microsoft SQL Server (if integrating with a database)

### Compilation and Execution
1. Compile the C++ source code:
   ```sh
   g++ university_management_system.cpp -o ums
   ```
2. Run the executable:
   ```sh
   ./ums
   ```

---

## Future Improvements
- Implement a **Graph** structure for better course prerequisite tracking.
- Introduce **File Handling** to persist student and course data.
- Develop a **GUI** for a user-friendly interface.

---

## Authors
- **[kaazzy]** - Developer

---

## License
This project is licensed under the gdu License.

