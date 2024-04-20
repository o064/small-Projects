#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
class Course
{
private:
    string name,input_name, input_grade,grade;
    int number_of_credits,input_credits;
public:
    Course() : name(""), number_of_credits(0), grade(""),input_credits(0),input_grade(""),input_name(""){};
    ~Course() = default;
    int get_credit() { return number_of_credits; }
    string get_name() { return name; }
    string get_grade() { return grade; }

    void set_name()
    {
        cout << "enter course details:\n";
        cout << "course name : ";
        cin >> input_name;
        name = input_name;

    }
    void set_credit()
    {
        cout << "course credits : ";
        while (!(cin >> input_credits))
        {
            cout << "Invalid input. Please enter an integer.\n";
            cin.clear();
            cin.ignore();
            cout << "course credits : ";
        }
        number_of_credits =input_credits;
    }
    void set_grade()
    {
        cout << "course grade : ";
        while (true)
        {
            cin >> input_grade;
            transform(input_grade.begin(), input_grade.end(), input_grade.begin(), ::toupper);
            if (input_grade == "A+" || input_grade == "A" || input_grade == "A-" || input_grade == "B+" || input_grade == "B" || input_grade == "B-" || input_grade == "C+" || input_grade == "C" || input_grade == "C-" || input_grade == "D+" || input_grade == "D" || input_grade == "D-" || input_grade == "E" || input_grade == "F")
            {
                grade = input_grade;
                break;
            }
            else
            {
                cout << "Invalid grade. Please enter a valid grade (A+, A, A-, B+, B, B-, C+, C, C-, D, F).\n";
                cout << "course grade : ";
            }
        }
    }
    void set_course_details()
    {
        set_name();
        // enter course credits
        set_credit();
        // enter course grade
        set_grade();
    }
};
// global variables
vector<Course> Courses;
vector<Course>::iterator it;
char input_option;
// ---------
int findByIdx()
{
    int idx;
    cout << "enter index: ";
    cin >> idx;
    if (idx > 0 && idx <= Courses.size())
    {
        return idx;
    }
    else
    {
        return 0;
    }
}
void choice()
{
    cout << "-----------------------\n";
    while (true)
    {
        cout << "Choice: ";
        cin >> input_option;
        input_option = tolower(input_option);
        if (input_option == 'a' || input_option == 'b' || input_option == 'c' || input_option == 'd' || input_option == 'x')
        {
            break;
        }
        else
        {
            cout << "Invalid option. Please try again.\n";
        }
    }
}
void add_course()
{
    Course temp;
    temp.set_course_details();
    Courses.push_back(temp);
}
void CalcGPA(int &sum_of_credits,float &GPA ,float &sum){
        for (it = Courses.begin(); it != Courses.end(); it++)
            {
                sum_of_credits += it->get_credit();
                if (it->get_grade() == "A+" || it->get_grade() == "A")
                {
                    sum = sum + (it->get_credit() * 4);
                }
                else if (it->get_grade() == "A-")
                {
                    sum = sum + (it->get_credit() * 3.7);
                }
                else if (it->get_grade() == "B+")
                {
                    sum = sum + (it->get_credit() * 3.3);
                }
                else if (it->get_grade() == "B")
                {
                    sum = sum + (it->get_credit() * 3.0);
                }
                else if (it->get_grade() == "B-")
                {
                    sum = sum + (it->get_credit() * 2.7);
                }
                else if (it->get_grade() == "C+")
                {
                    sum = sum + (it->get_credit() * 2.3);
                }
                else if (it->get_grade() == "C")
                {
                    sum = sum + (it->get_credit() * 2.0);
                }
                else if (it->get_grade() == "C-")
                {
                    sum = sum + (it->get_credit() * 1.7);
                }
                else if (it->get_grade() == "D+")
                {
                    sum = sum + (it->get_credit() * 1.3);
                }
                else if (it->get_grade() == "D")
                {
                    sum = sum + (it->get_credit() * 1.0);
                }
                else if (it->get_grade() == "D-")
                {
                    sum = sum + (it->get_credit() * 0.7);
                }
                else if (it->get_grade() == "F" || it->get_grade() == "E")
                {
                }
            }
            GPA = sum / sum_of_credits;

}
int main()
{
    Courses.clear();
    while (1)
    {
        for (int i = 0; i < Courses.size(); i++)
        {
            cout << i + 1 << " | couse name = " << Courses[i].get_name() << " | credit hours = " << Courses[i].get_credit()
                << " | grade = " << Courses[i].get_grade() << endl;
        }
        cout << "-----------------------\n";
        cout << "[a] add course\n";
        cout << "[b] remove course\n";
        cout << "[c] calculate GPA\n";
        cout << "[d] modify\n";
        cout << "[x] exit\n";
        if (Courses.empty())
        {
            cout << "---------------------------------------\n";
            cout << "\tWelcome to GPA clacluters \n";
            cout << "---------------------------------------\n";
            cout << "to continue you should add at least one course\n";
            add_course();
            continue;
        }
        choice();
        if (input_option == 'a')
        {
            // add new course to the list of courses
            add_course();
        }
        else if (input_option == 'b')
        {
            // remove a particular course from the list of courses by entering its index in the array
            while (true)
            {
                int index = findByIdx();
                if (index)
                {
                    Courses.erase(Courses.begin() + index - 1);
                    break;
                }
                else
                {
                    cout << "invalid id entered" << endl;
                    cout << "press enter (x) to retun to menu || press (b) to enter another id\n";
                    choice();
                    if (input_option == 'x')
                        break;
                    else if (input_option == 'b')
                    {
                    }
                    else
                    {
                        cout << "invalid option selected\n";
                    }
                }
            }
        }
        else if (input_option == 'd')
        {
            while (true)
            {
                int id = findByIdx();
                if (id)
                {
                    cout << "-----------------------\n";
                    cout << "[a] modify whole course\n";
                    cout << "[b] modify course name\n";
                    cout << "[c] modify course credit\n";
                    cout << "[d] modify course grade\n";
                    cout << "[x] return to menu\n";
                    choice();
                    switch (input_option)
                    {
                    case 'a':
                        Courses[id - 1].set_course_details();
                        break;
                    case 'b':
                        Courses[id - 1].set_name();
                        break;
                    case 'c':
                        Courses[id - 1].set_credit();
                        break;
                    case 'd':
                        Courses[id - 1].set_grade();
                        break;
                    case 'x':
                        break;
                    }
                    break;
                }
                else
                {
                    cout << "invalid id entered" << endl;
                }
            }
        }
        else if (input_option == 'c')
        {
            // calculate gpa and display it on screen
            int sum_of_credits=0;
            float GPA=0.0 , sum =0.0 ;
            CalcGPA(sum_of_credits,GPA,sum);
            cout << "Your GPA is = " << GPA << endl;
            cout << "Total credits: " << sum_of_credits << endl;
            cout << "-----------------------\n";
        }
        else if (input_option == 'x')
        {
            cout << "thanks for using our calculator\n";
            break;
        }
    }

    return 0;
}
