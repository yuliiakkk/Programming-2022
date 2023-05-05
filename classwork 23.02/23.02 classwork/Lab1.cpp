


#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


using namespace std;

class Student 
{
private:
    string full_name;
public:
    Student() :
        full_name("")
    {
    }

    Student(string name) :
        full_name(name)
    {
    }

    void set_full_name(string name)
    {
        full_name = name;
    }

    string get_full_name() const
    {
        return full_name;
    }

    friend ostream& operator<<(ostream& os, const Student& ad) {
        os << "Full name: " <<  ad.full_name ;
            
        return os;
    }

    friend istream& operator>>(istream& is, Student& ad) {
        is >> ad.full_name;

        return is;
    }
};

class Group
{
private:
    vector<Student> _students;
    string _name;
    int _enterance_year;
    //int num_students;
public:
    Group() :
        _name(""),
        _enterance_year(0)
    {
    }

    Group(vector<Student>& students, string& group_name, int enterance_year) :
        _students(students),
        _name(group_name), 
        _enterance_year(enterance_year) 
    {
    }

    Group(const Group& other) :
        _students(other._students),
        _name(other._name),
        _enterance_year(other._enterance_year)
    {
    }

    ~Group()
    {
        _students.~vector();
    }

    string get_name() const
    {
        return _name;
    }

    int get_entrance_year() const
    {
        return _enterance_year;
    }

    int get_students_amount() const
    {
        return _students.size();
    }

    void set_students_amount(int num_students)
    {
        _students.resize(num_students);
    }

    void set_name(string name)
    {
        _name = name;
    }

    void set_entrance_year(int entyear)
    {
        _enterance_year = entyear;
    }

    Student& operator[](int index)
    {
        return _students[index];
    }

    const Student& operator[](int index) const
    {
        return _students[index];
    }

    Group& operator=(const Group& other)
    {
        if (this != &other)
        {
            _students = other._students;
            _name = other._name;
            _enterance_year = other._enterance_year;
        }
        return *this;
    }

    friend ostream& operator<<(ostream& os, const Group& group)
    {
        os << "Group name: " << group._name << endl;
        os << "Entrance year: " << group._enterance_year << endl;
        os << "Number of students: " << group.get_students_amount() << endl;
        os << "Students:" << endl;
        for (int i = 0; i < group.get_students_amount(); i++)
        {
            os << "\t" << group[i].get_full_name() << endl;
        }
        return os;
    }

    friend istream& operator>>(istream& is, Group& group)
    {
        cout << "Enter group name: ";
        is >> group._name;
        cout << "Enter entrance year: ";
        is >> group._enterance_year;
        cout << "Enter number of students: ";
        int num_students;
        is >> num_students;
        group.set_students_amount(num_students);
        cout << "Enter student names:" << endl;
        for (int i = 0; i < num_students; i++)
        {
            Student student;
            is >> student;
            group[i] = student;
        }
        return is;
    }
};

int main()
{
    vector<Group> groups;

    
    Group group1, group2;
    cin >> group1 >> group2;
    groups.push_back(group1);
    groups.push_back(group2);

    if (group1.get_name() < group2.get_name())
    {
        cout << group1 << group2;
    }
    else
        cout << group2 << group1;

    /*bool group_name_comarison = group1.get_name() < group2.get_name();
    cout << (group_name_comarison ? group1 : group2)
         << (group_name_comarison ? group2 : group1)
         << endl;*/

    /*cout << (group1.get_entrance_year() > group2.get_entrance_year() ?
        group1 : group2);*/

    if (group1.get_entrance_year() > group2.get_entrance_year())
    {
        cout << group1 << group2;
    }

    /*Group group3 = group1.get_students_amount() < group2.get_students_amount() ?
        group1 : group2;*/
    Group group3;
    if (group1.get_students_amount() < group2.get_students_amount()) {
        group3 = group1;
    }
    else {
        group3 = group2;
    }

    return 0;
}

