#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Student
{
private:
	string name_;
    int id_number;
    string speciality_;
public:
    Student(string name, int idnumber, string speciality) :
        name_(name),
        id_number(idnumber),
        speciality_(speciality)
    {
    }

    Student() :
        name_(""),
        id_number(0),
        speciality_("")
    {
    }

    string get_name() const
    {
        return name_;
    }
    
    int get_id_number() const
    {
        return id_number;
    }

    string get_speciality() const
    {
        return speciality_;
    }

    //void print(ostream& os) const 
    //{
    //    os << "Name: " << name_ << endl;
    //    os << "ID: " << id_number << endl;
    //    os << "Specialty: " << speciality_ << endl;
    //}

    //friend ostream& operator<<(ostream& os, const Student& student)
    //{
    //    os << "Student: " << student.name_ << " (ID: " << student.id_number
    //       << ", Speciality: " << student.speciality_ << ")";
    //    return os;
    //}

    //friend istream& operator>>(istream& is, Student& student) {
    //    cout << "Enter student name: ";
    //    getline(is, student.name_);
    //    cout << "Enter student ID: ";
    //    is >> student.id_number;
    //    //is.ignore(); // Ignore newline character
    //    cout << "Enter student speciality: ";
    //    getline(is, student.speciality_);
    //    return is;
    //}

    

   };

//bool operator==(const Student& other) const {
//    return (id_number == other.id_number &&
//        name_ == other.name_ &&
//        speciality_ == other.speciality_);
//}

class Course
{
private:
    string name_;
    int number_;
    string speciality_;
public:
    Course(string name, const int number, const string speciality) :
        name_(name),
        number_(number),
        speciality_(speciality)
    {
    }

    Course() :
        name_(""),
        number_(0),
        speciality_("")
    {
    }

    string get_name()
    {
        return name_;
    }

    int get_number()
    {
        return number_;
    }

    string get_speciality()
    {
        return speciality_;
    }

    //void print(ostream& os) const 
    //{
    //    os << "Name: " << name_ << endl;
    //    os << "Number: " << number_ << endl;
    //    os << "Specialty: " << speciality_ << endl;
    //}

    //friend ostream& operator<<(ostream& os, const Course& course) {
    //    os << "Course: " << course.name_ << " (Number: " << course.number_
    //        << ", Speciality: " << course.speciality_ << ")";
    //    return os;
    //}

    //friend istream& operator>>(istream& is, Course& course) {
    //    cout << "Enter course name: ";
    //    getline(is, course.name_);
    //    cout << "Enter course number: ";
    //    is >> course.number_;
    //    //is.ignore(); // Ignore newline character
    //    cout << "Enter course speciality: ";
    //    getline(is, course.speciality_);
    //    return is;
    //}


};

class University
{
private:
    string name_;
    string location_;
    vector<Student> students_;
    vector<Course> courses_;

public:
    University(string name, string location):
        name_(name),
        location_(location)
    {
    }

    University() :
        name_(""),
        location_("")
    {
    }
    
    void AddCourse(Course course)
    {
        courses_.push_back(course);
    }

    void AddStudent(Student student)
    {
        students_.push_back(student);
    }

    

    void removeCourse(Course course)
    { 
       
        for (int i = 0; i < courses_.size(); i++)
        {
            if (courses_[i].get_number() == course.get_number())
            {
                courses_.erase(courses_.begin() + i);
                break;
            }
        }
    }

    void removeStudent(Student student)
    {
        for (int i = 0; i < students_.size(); i++)
        {
            if (students_[i].get_id_number() == student.get_id_number())
            {
                students_.erase(students_.begin() + i);
                break;
            }
        }
   
    }

    vector<Student> getStudentsForCourse(Course course) 
    {
        vector<Student> result;
        for (int i = 0; i < students_.size(); i++) 
        {
            if (students_[i].get_speciality() == course.get_speciality()) 
            {
                result.push_back(students_[i]);
            }
        }
        return result;
    }

    vector<Course> getCoursesForStudent(Student student)
    {
        vector<Course> result;
        for (int i = 0; i < courses_.size(); i++) 
        {
            if (courses_[i].get_speciality() == student.get_speciality()) 
            {
                result.push_back(courses_[i]);
            }
        }
        return result;
    }

    void PrintStudents() 
    {

        cout << "Students in " << name_ << ":" << endl;

        for (int i = 0; i < students_.size(); ++i) {

            cout << students_[i].get_name() << ",ID: " << students_[i].get_id_number() << ", Speciality: " << students_[i].get_speciality() << endl;

        }

        cout << endl;

    }

    void PrintCourses() 
    {

        cout << "Courses in " << name_ << ":" << endl;

        for (int i = 0; i < courses_.size(); ++i) {

            cout << courses_[i].get_name() << ",Number: " << courses_[i].get_number << "<Speciality: " << courses_[i].get_speciality() << endl;

        }

        cout << endl;

    
};


int main() {
    string name, address;
    cout << "Enter university name: ";
    getline(cin, name);
    cout << "Enter university address: ";
    getline(cin, address);

    University uni(name, address);

    bool exit = false;
    int choice;
    while(!exit) {
        cout << "\n---- University Management System ----" << endl;
        cout << "1. Add course" << endl;
        cout << "2. Remove course" << endl;
        cout << "3. Add student" << endl;
        cout << "4. Remove student" << endl;
        cout << "5. List students for a course" << endl;
        cout << "6. List courses for a student" << endl;
        cout << "7. Print all students" << endl;
        cout << "8. Print all courses" << endl;
        cout << "9. Exit" << endl;
        cout << "Enter your choice: ";

        cin >> choice;
        cin.ignore();

        switch (choice) {
        case 1: {

            string name_, speciality_;

            int id_number;

            cout << "Enter name: ";

            cin >> name_;

            cout << "Enter ID: ";

            cin >> id_number;

            cout << "Enter speciality: ";

            cin >> speciality_;

            Student student(name_, id_number, speciality_);

            uni.AddStudent(student);

            break;

        }

        case 2: {

            int id_number;

            cout << "Enter ID of student you want to remove: ";

            cin >> id_number;

            Student student("", id_number, "");

            uni.removeStudent(student);

            break;

        }

        case 3: {

            string name_, specialty_;

            int number_;

            cout << "Enter name: ";

            cin >> name_;

            cout << "Enter number: ";

            cin >> number_;

            cout << "Enter specialty: ";

            cin >> specialty_;

            Course course(name_, number_, specialty_);

            uni.AddCourse(course);

            break;

        }

        case 4: {

            int number_;

            cout << "Enter number of course you want to remove: ";

            cin >> number_;

            Course course("", number_, "");

            uni.removeCourse(course);

            break;

        }

        case 5: {

            int number_;

            cout << "Enter number of course: ";

            cin >> number_;

            Course course("", number_, "");

            vector<Student> students_ = uni.getStudentsForCourse(course);

            cout << "Students in course " << number_ << ":" << endl;

            for (int i = 0; i < students_.size(); i++) {

                cout << students_[i].get_name() << ", ID: " << students_[i].get_id_number() << ", Specialty: " << students_[i].get_speciality() << endl;

            }

            cout << endl;

            break;

        }

        case 6: {

            int id_number;

            cout << "Enter ID of student: ";

            cin >> id_number;

            Student s("", id_number, "");

            vector<Course> courses_ = uni.getCoursesForStudent(s);

            cout << "Courses for student " << id_number << ":" << endl;

            for (int i = 0; i < courses_.size(); i++) {

                cout << courses_[i].get_name() << ", Number: " << courses_[i].get_number() << ", Specialty: " << courses_[i].get_speciality() << endl;

            }

            cout << endl;

            break;

        }

        case 7: {

            uni.PrintStudents();

            break;

        }

        case 8: {

            uni.PrintCourses();

            break;

        }

        case 9: {

            exit = true;

            break;

        }

        default: {

            cout << "try again" << endl;

            break;

        }

        }
    return 0;
}
