#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

class Shpargalka
{
protected:
    string subject;
    int number;
public:
    virtual void input(istream& in)
    {
        in >> subject >> number;
    }

    virtual void output(ostream& on)
    {
        on << "Sublect: " << subject << "Number: " << number;
    }

    friend ostream& operator<<(ostream& os, Shpargalka& file1)
    {
        file1.output(os);

        return os;
    }

    friend istream& operator>>(istream& in, Shpargalka& file1)
    {
        file1.input(in);
        return in;
    }

    string get_subject() const 
    {
        return subject;
    }

    int get_number() const
    {
        return number;
    }

};

class Paper : public Shpargalka
{
private:
    string size;
    string enumeration_place;
public:
    void input(istream& in)
    {
        Shpargalka::input(in);
        in >> size >> enumeration_place ;
    }

    void output(ostream& os)
    {
        Shpargalka::output(os);
        os << "Size: " << size << "Enumeration place: " << enumeration_place;

    }
};

class Electronic : public Shpargalka
{
protected:
    string media_name;
public:
    void input(istream& in)
    {
        Shpargalka::input(in);
        in >> media_name ;
    }

    void output(ostream& os)
    {
        Shpargalka::output(os);
        os << "Media name: " << media_name ;

    }

    string get_media_name() const
    {
        return media_name;
    }
};

class Student
{
private:
    string full_name;
    string group;
    vector<Shpargalka> shpargalky;
public:
    void input(istream& in)
    {
        in >> full_name >> group;

        while (true)
        {
            char type;
            in >> type;

            if (type == 'P')
            {
                Paper p;
                in >> p;
                shpargalky.push_back(p);
            }
            else if (type == 'E')
            {
                Electronic e;
                in >> e;
                shpargalky.push_back(e);
            }
            else
            {
                break;
            }
        }
    }

    void output(ostream& os)
    {
        os << "Full name: " << full_name << " Group: " << group << endl;

        for (auto s : shpargalky)
        {
            os << s;
        }
    }

    friend ostream& operator<<(ostream& os, Student& s)
    {
        s.output(os);

        return os;
    }

    vector<Shpargalka> get_shpargalky() const 
    {
        return shpargalky;
    }
};

bool compare_subjects(const Shpargalka& s1, const Shpargalka& s2)
{
    if (s1.get_subject() == s2.get_subject())
    {
        return s1.get_number() < s2.get_number();
    }
    else
    {
        return s1.get_subject() < s2.get_subject();
    }
}

int main ()
{
    vector<Student> students;
    ifstream input_file("file1.txt");

    // read data from input file and store in vector
    while (!input_file.eof())
    {
        Student s;
        s.input(input_file);
        students.push_back(s);
    }

    // sort shpargalky for each student by subject and number
    for (auto& s : students)
    {
        sort(s.get_shpargalky().begin(), s.get_shpargalky().end(), compare_subjects);
    }

    // write sorted shpargalky to output file
    ofstream output_file1("output1.txt");

    for (auto s : students)
    {
        output_file1 << s << endl;
    }

    // find electronic shpargalky on media named "comp" and write to output file
    ofstream output_file2("output2.txt");
    int count = 0;

    for (auto s : students)
    {
        for (auto shpargalka : s.get_shpargalky())
        {
            Electronic* e = dynamic_cast<Electronic*>(&shpargalka);

            if (e != nullptr && e->get_media_name() == "comp")
            {
                output_file2 << s << endl;
                count++;
                break;
            }
        }
    }

    output_file2 << "Number of electronic shpargalky on media named \"comp\": " << count;

    return 0;

}