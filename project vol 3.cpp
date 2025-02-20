#include<bits/stdc++.h>
using namespace std;
#define TABLE_SIZE 10

//doubly linked


class enrollmentNode{
public:
    int course_ID;
    enrollmentNode *next;
    enrollmentNode *prev;

    enrollmentNode(int id){
        course_ID = id;
        next = NULL;
        prev = NULL;
    }

};

class enrollment_list{
private:
    enrollmentNode *head;
    enrollmentNode *tail;

public:
    enrollment_list(){
        head = NULL;
        tail = NULL;
    }


    void add_enrollment(int course_ID){
        enrollmentNode *newNode = new enrollmentNode(course_ID);
        if(head==NULL){
            head = tail= newNode;
        }else{
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        cout<<"Course enrolled  for : "<< course_ID <<endl;
    }



    void display_enrollment(){
        if(head==NULL){
            cout<<"No courses enrolled"<<endl;
            return;
        }
        cout<<"enrollment history"<<endl;
        enrollmentNode *temp = head;
        while (temp!=NULL){
            cout<<"Course ID: "<<temp->course_ID<<endl;
            temp = temp->next;
        }

    }
};

class student{
public:
    string student_name;
    int student_ID;
    enrollment_list enrollmenthistory;


    student(string name, int ID){
        student_name = name;
        student_ID = ID;
    }

    void enroll(int course_ID){
        enrollmenthistory.add_enrollment(course_ID);
    }

    void display_enrollment(){
        cout<<"Student Name: "<<student_name<<endl;
        cout<<"Student ID: "<<student_ID<<endl;
        enrollmenthistory.display_enrollment();
    }

};

class Node{
    public:
    int id;
    string name;
    string phone;
    string address;
    int password;
    Node *next;
    Node *prev;
    enrollment_list* enrollmenthistory;  // This links the student's enrollment history



    Node(int student_ID, string student_Name, string student_Phone, string student_Address, int student_Password){
        id = student_ID;
        name = student_Name;
        phone = student_Phone;
        address = student_Address;
        password = student_Password;
        next = NULL;
        prev = NULL;
        enrollmenthistory = new class enrollment_list(); // Allocating memory for enrollment list
    }
    };

class student_record_management{
    private:
    Node *head;
    public:
    student_record_management(){
        head = NULL;
    }

//ADD

    void add_student(int student_ID, string student_Name, string  student_Phone, string student_Address, int student_Password){
        Node *newNode = new Node(student_ID, student_Name, student_Phone, student_Address, student_Password);
        if(head==NULL){
            head = newNode;
            cout<<"Student added"<<endl;
            return;
        }
        Node *temp = head;
        while(temp!=NULL && temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newNode;
        cout<<"Student added"<<endl;
    }

//delete

    void delete_student(int student_ID){

        if(head==NULL){
            cout<<"student not found"<<endl;
            return;
        }

        Node *temp = head;
        if(temp->id==student_ID){
            head = head->next;
            delete temp;
            cout<<"Student removed"<<endl;
            return;
        }

        Node *curr = head;
        while(curr->next!=NULL && curr->next->id!=student_ID){
             curr = curr->next;
        }
        if(curr->next==NULL){
            cout<<"Student not found"<<endl;
        }else{
            Node *del = curr->next;
            curr->next = curr->next->next;
            delete del;
            cout<<"Student removed"<<endl;
        }

    }  

    //display
        
    void display(){
        if(head==NULL){
            cout<<"List is empty"<<endl;   
            return;
        }    
    Node *temp = head;
    cout << "Student Records:\n";
    while(temp!=NULL){
        cout<<"ID: "<<temp->id<<endl;
        cout<<"Name: "<<temp->name<<endl;
        cout<<"Phone: "<<temp->phone<<endl;
        cout<<"Address: "<<temp->address<<endl;
        cout<<"Password: "<<temp->password<<endl;
        cout<<"----------------------"<<endl;
        temp = temp->next;
    }
    cout << endl;
    }
    Node* search_student(int student_ID) {  /////////search student by ID /// linear search
        Node* curr = head;
        while (curr != NULL) {
            if (curr->id == student_ID) {
                cout<<"Student found "<<endl;
                return curr;
            }
            curr = curr->next;
        }
        cout << "student not found ! " << endl;
        return 0 ; //if not found
    }

    void swap(int &a, int &b) {
        int temp = a;
        a = b;
        b = temp;
    }
    void swap(string &a, string &b) { ///overloading
        string temp = a;
        a = b;
        b = temp;
    }

    void sort_students_by_id() { ////bubble
        if (head == NULL) return;

        bool swapped = true;
        while (swapped) {
            swapped = false;
            Node* curr = head;

            while (curr != NULL && curr->next != NULL) {
                if (curr->id > curr->next->id) {
                    // Swap data (not nodes)
                    swap(curr->id, curr->next->id);
                    swap(curr->name, curr->next->name);
                    swap(curr->phone, curr->next->phone);
                    swap(curr->address, curr->next->address);
                    swap(curr->password, curr->next->password);  
                    swapped = true;
                }
                curr = curr->next;
            }
        }
    }


    // Node* get_student(int student_ID) {
    //     Node* curr = head;
    //     while (curr != NULL) {
    //         if (curr->id == student_ID) {
    //             cout << "Student found" << endl;
    //             return curr;  // Return pointer to the student node
    //         }
    //         curr = curr->next;
    //     }
    //     cout << "Student not found!" << endl;
    //     return nullptr;  // Return nullptr if student is not found
    // }

};


// bst

class coursNode{
    private:
    coursNode *root;
    coursNode *left;
    coursNode *right;
    int course_ID;
    string course_name;
    string course_instructor;
    int Credits;

    public:
    coursNode() { ////default
        root = NULL;
        left = NULL;
        right = NULL;
        course_ID = 0;
        course_name = "";
        course_instructor = "";
        Credits = 0;
    }
    coursNode(int id, string name, string instructor, int credits){
        root = NULL;
        left = NULL;
        right = NULL;
        course_ID = id;
        course_name = name;
        course_instructor = instructor;
        Credits = credits;
    }

    void add_course(int id, string name, string instructor, int credits){
        coursNode *newNode = new coursNode(id, name, instructor, credits);
        if(root==NULL){
            root = newNode;
            cout<<"Course added"<<endl;
            return;
        }
        coursNode *curr = root;
        while(curr!=NULL){
            if(id < curr->course_ID){
                if(curr->left==NULL){
                    curr->left = newNode;
                    cout<<"Course added"<<endl;
                    return;
                }
                curr = curr->left;    
            } else if(id > curr->course_ID){
                if(curr->right==NULL){
                    curr->right = newNode;
                    cout<<"Course added"<<endl;
                    return;
                }
                curr = curr->right;
            } else {
                cout << "Course already exists" << endl;
                return;
            }
        }
    }
    coursNode* minValue(coursNode* root) {
        while (root->left != NULL) {
            root = root->left;
        }
        return root;
    }
    coursNode* getRoot() {
        return root;
    }

//drop course

coursNode* DropCourse(coursNode* root, int id) {
    if (root == NULL) {
        cout << "Course not found or already deleted" << endl;
        return NULL;
    }

    if (id < root->course_ID) {
        root->left = DropCourse(root->left, id);
    } else if (id > root->course_ID) {
        root->right = DropCourse(root->right, id);
    } else {
        //node found
        if (root->left == NULL && root->right == NULL) {
            // no children
            delete root;
            return NULL;
        } else if (root->left == NULL) {
            ///only right child
            coursNode* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == NULL) {
            ////only left child
            coursNode* temp = root->left;
            delete root;
            return temp;
        }
        //two children
        coursNode* temp = minValue(root->right);
        root = someFunction(root, temp);
    }

    return root;
}
coursNode* someFunction(coursNode* root, coursNode* temp) {
    if (root == NULL || temp == NULL) {
        cerr << "Error: Null pointer dereference" << endl;
        return NULL;
    }
    root->course_ID = temp->course_ID;
    root->course_name = temp->course_name;
    root->course_instructor = temp->course_instructor;
    root->Credits = temp->Credits;
    root->right = DropCourse(root->right, temp->course_ID);

    return root;
}
void display_in_order(coursNode *node) {
    if (node == NULL) {
        return;
    }
    display_in_order(node->left);
    cout << "ID: " << node->course_ID
         << ", Name: " << node->course_name
         << ", Instructor: " << node->course_instructor
         << ", Credits: " << node->Credits << endl;

    display_in_order(node->right);
}

void display_courses() {
        if (root == NULL) {
            cout << "No courses available!" << endl;
            return;
        }
        cout << "Courses in the system:" << endl;
        display_in_order(root);
    }
    coursNode* search_course(coursNode* root, int course_ID) {
        if (root == NULL) {
            cout << "Course not found or already deleted" << endl;
            return NULL;
        }
        if (root->course_ID == course_ID) {
            cout << "Found course ID: " << course_ID << ", Name: " << root->course_name << endl;
            return root;
        }
        if (course_ID < root->course_ID) {
            return search_course(root->left, course_ID);
        } else {
            return search_course(root->right, course_ID);
        }
    }

    void sort_courses(coursNode* root) { //LHR
        if (root == NULL) return;
        display_in_order(root);
    }
};

//stack
class stackNode {
    public:
    string data;
    int studentID;
    stackNode *next;

    stackNode(string course, int student_id) {
        data = course;
        studentID = student_id;
        next = nullptr;
    }
};
class prerequisiteStack {
    public:
    stackNode *top;
     map<string, vector<string>> coursePrerequisites;
     map<int, vector<string>> studentRecords;
    public:
    prerequisiteStack() {
        top = nullptr;

     coursePrerequisites = {
            {"Math102", {"Math101"}},
            {"CS201", {"CS101"}},
            {"Physics202", {"Physics101", "Math101"}}
        };

    studentRecords = {
            {12345, {"Math101", "Physics101"}},
            {67890, {"CS101", "Math101"}}
        };
    }

        ~prerequisiteStack() {
            while (top != nullptr) {
                pop();
            }
        }
    void push(string courseID, int studentID) {
            stackNode *newNode = new stackNode(courseID, studentID);
            newNode->next = top;
            top = newNode;
            cout << "Course " << courseID << " added to the stack." << endl;
        }
    bool pop() {
        if (top == nullptr) {
            cout << "Stack is empty. Cannot pop." << endl;
            return false;
        }
        stackNode *temp = top;
        top = top->next;
        delete temp;
        return true;
    }


void validatePrerequisites(string courseID, int studentID, map<string, vector<string>> &coursePrerequisites, map<int, vector<string>> &studentRecords) {
    vector<string> studentCourses = studentRecords[studentID];
    if (coursePrerequisites.find(courseID) == coursePrerequisites.end()) {
        cout << "Course " << courseID << " has no prerequisites. Eligible to register!" << endl;
        return;
    }
    vector<string> prerequisites = coursePrerequisites[courseID];
    for (const string &prereq : prerequisites) {
        push(prereq, studentID);
    }
    for (const string &completedCourse : studentCourses) {
        if (top != nullptr && top->data == completedCourse) {
            pop();
        }
    }
    if (top == nullptr) {
        cout << "Student ID " << studentID << ": All prerequisites are met for " << courseID << ". Eligible to register!" << endl;
    } else {
        cout << "Student ID " << studentID << ": Remaining prerequisites for " << courseID << ": ";
        stackNode *temp = top;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
}
};
//queue
class queueNode {
public:
    int studentID;
    string courseID;
    queueNode *next;

    queueNode(int student_id, string course_id) {
        studentID = student_id;
        courseID = course_id;
        next = nullptr;
    }
};
class waitlist{
private:
    queueNode *front;
    queueNode *rear;

public:
    waitlist(){
        front = NULL;
        rear = NULL;
    }

    void enqueue(int studentID, string courseID){
        queueNode *newNode = new queueNode(studentID, courseID);
        if(front==NULL){
            front = rear = newNode;
        }else{
            rear->next = newNode;
            rear = newNode;
        }
        cout<<"Student ID: "<<studentID<<" has been added to the waitlist for course ID: "<<courseID<<endl;
    }

    void dequeue(){
        if(front==NULL){
            cout<<"The waitlist is empty. No students to enroll."<<endl;
            return;
        }
        queueNode *temp = front;
        front = front->next;
        cout<<"Student ID: "<<temp->studentID<<" has been enrolled from the waitlist for course ID: "<<temp->courseID<<endl;
        delete temp;
    }
    void displayWaitlist(){
        if(front==NULL){
            cout<<"The waitlist is empty."<<endl;
            return;
        }
        queueNode *temp = front;
        cout<<"Current waitlist: ";
        while(temp!=NULL){
            cout<<endl<<temp->studentID <<" ( "<<temp->courseID<<" )";
            temp = temp->next;
        }
        cout<<endl;
    }
};

class HashNode {
public:
    int course_ID;
    string course_name;
    string course_instructor;
    int Credits;
    HashNode* next;

    HashNode(int id, string name, string instructor, int credits) {
        course_ID = id;
        course_name = name;
        course_instructor = instructor;
        Credits = credits;
        next = nullptr;
    }
};

class HashTable {
private:

    HashNode* table[TABLE_SIZE];
    int hashFunction(int course_ID) {
        return course_ID % TABLE_SIZE;
    }
public:

    HashTable() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            table[i] = nullptr;
        }
    }
    void insertCourse(int course_ID, string course_name, string course_instructor, int Credits) {
        int index = hashFunction(course_ID);
        HashNode* newNode = new HashNode(course_ID, course_name, course_instructor, Credits);
        if (table[index] == nullptr) {
            table[index] = newNode; // if no collisions
        } else {
           HashNode* temp = table[index]; ///using chaining
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
        cout << "Course added: " << course_name << " (ID: " << course_ID << ")" << endl;
    }
    HashNode* searchHashing(int course_ID) {
        int index = hashFunction(course_ID);
        HashNode* temp = table[index];

        while (temp != nullptr) {
            if (temp->course_ID == course_ID) {
                cout << "Course found: " << temp->course_name << " (ID: " << temp->course_ID << ")" << endl;
                return temp;
            }
            temp = temp->next;
        }

        cout << "Course not found " <<  endl;
        return nullptr;
    }
    void displayCourses() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            HashNode* temp = table[i];
            while (temp != nullptr) {
                cout << "ID: " << temp->course_ID
                     << ", Name: " << temp->course_name
                     << ", Instructor: " << temp->course_instructor
                     << ", Credits: " << temp->Credits << endl;
                temp = temp->next;
            }
        }
    }
    ~HashTable() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            HashNode* temp = table[i];
            while (temp != nullptr) {
               HashNode* next = temp->next;
                delete temp;
                temp = next;
            }
        }
    }
};

int main(){
     student_record_management studentManager;
    coursNode courseManager;
    prerequisiteStack prerequisiteManager;
    waitlist waitlistManager;
    HashTable hashTableManager;

    int choice;
    do {
        cout << "---------------------------" << endl;
        cout << "1. Add Student" << endl;
        cout << "2. Delete Student" << endl;
        cout << "3. Display All Students" << endl;
        cout << "4. Search for a Student" << endl;
        cout << "5. Sort Students by ID" << endl;
        cout << "6. Enroll in a Course" << endl;
        cout << "7. Display Enrollment History" << endl;
        cout << "8. Add Course" << endl;
        cout << "9. Drop Course" << endl;
        cout << "10. Display All Courses" << endl;
        cout << "11. Search for a Course" << endl;
        cout << "12. Sort Courses by ID" << endl;
        cout << "13. Validate Prerequisites" << endl;
        cout << "14. Add to Waitlist" << endl;
        cout << "15. Display Waitlist" << endl;
        cout << "16. Add Course to Hash Table" << endl;
        cout << "17. Search Course in Hash Table" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int id, password;
                string name, phone, address;
                cout << "Enter Student ID: ";
                cin >> id;
                cout << "Enter Name: ";
                cin.ignore();
                getline(cin, name);
                cout << "Enter Phone: ";
                cin >> phone;
                cout << "Enter Address: ";
                cin.ignore();
                getline(cin, address);
                cout << "Enter Password: ";
                cin >> password;
                studentManager.add_student(id, name, phone, address, password);
                break;
            }
            case 2: {
                int id;
                cout << "Enter Student ID to Delete: ";
                cin >> id;
                studentManager.delete_student(id);
                break;
            }
            case 3:
                studentManager.display();
                break;
            case 4: {
                int id;
                cout << "Enter Student ID to Search: ";
                cin >> id;
                studentManager.search_student(id);
                break;
            }
            case 5:
                studentManager.sort_students_by_id();
                cout << "Students sorted by ID!" << endl;
                break;
            case 6: {
                int studentID, courseID;
                cout << "Enter Student ID: ";
                cin >> studentID;
                Node* studentNode = studentManager.search_student(studentID);
                if (studentNode == NULL) {
                    cout << "Student not found!" << endl;
                    break;
                }
                cout << "Enter Course ID to Enroll: ";
                cin >> courseID;
                studentNode->enrollmenthistory->add_enrollment(courseID);
                break;
            }
            case 7: {
                int studentID;
                cout << "Enter Student ID to Display Enrollment History: ";
                cin >> studentID;
                Node* studentNode = studentManager.search_student(studentID);
                if (studentNode == NULL) {
                    cout << "Student not found!" << endl;
                    break;
                }
                studentNode->enrollmenthistory->display_enrollment();
                break;

            }
            case 8: {
                int id, credits;
                string name, instructor;
                cout << "Enter Course ID: ";
                cin >> id;
                cout << "Enter Course Name: ";
                cin.ignore();
                getline(cin, name);
                cout << "Enter Instructor Name: ";
                getline(cin, instructor);
                cout << "Enter Credits: ";
                cin >> credits;
                courseManager.add_course(id, name, instructor, credits);
                break;
            }
            case 9: {
                int id;
                cout << "Enter Course ID to Drop: ";
                cin >> id;
                courseManager.DropCourse(courseManager.getRoot(), id);
                cout << "course deleted" << endl;
                break;
            }
            case 10:
                courseManager.display_courses();
                break;
            case 11: {
                int id;
                cout << "Enter Course ID to Search: ";
                cin >> id;
                courseManager.search_course(courseManager.getRoot(), id);
                break;
            }
            case 12:
                cout << "Courses sorted by ID:" << endl;
            courseManager.sort_courses(courseManager.getRoot());
            break;
            case 13: {
                string courseID;
                int studentID;
                cout << "Enter Course ID to Validate: ";
                cin >> courseID;
                cout << "Enter Student ID: ";
                cin >> studentID;
                prerequisiteManager.validatePrerequisites(courseID, studentID, prerequisiteManager.coursePrerequisites, prerequisiteManager.studentRecords);
                break;
            }
            case 14: {
                int studentID;
                string courseID;
                cout << "Enter Student ID: ";
                cin >> studentID;
                cout << "Enter Course ID: ";
                cin >> courseID;
                waitlistManager.enqueue(studentID, courseID);
                break;
            }
            case 15: {
                waitlistManager.displayWaitlist();
                break;
            }
            case 16: {
                int id, credits;
                string name, instructor;
                cout << "Enter Course ID: ";
                cin >> id;
                cout << "Enter Course Name: ";
                cin.ignore();
                getline(cin, name);
                cout << "Enter Instructor Name: ";
                getline(cin, instructor);
                cout << "Enter Credits: ";
                cin >> credits;
                hashTableManager.insertCourse(id, name, instructor, credits);
                break;
            }

            case 17: {
                int courseID;
                cout << "Enter Course ID to Search: ";
                cin >> courseID;
                hashTableManager.searchHashing(courseID);
                break;
            }

            case 0:
                cout << "Exiting program..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 0);

    return 0;
}
