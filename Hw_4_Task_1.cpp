#include <iostream>
#include <string>

struct Student_of_mipt
{
    std::string name;
    int course;
    double done_zadavalnik;
    double time_until_deadline;

    //Constructor
    Student_of_mipt() : course(0), done_zadavalnik(0.0), time_until_deadline(0.0) {}

    //Constructor
    Student_of_mipt(std::string name, int course, double done_zadavalnik, double time_until_deadline)
        : name(name), course(course), done_zadavalnik(done_zadavalnik), time_until_deadline(time_until_deadline) {}

    //Destructor
    ~Student_of_mipt()
    {
        std::cout << "Student_of_mipt " << name << " is died in the end of MIPT" << std::endl;
    }

    
    void setInfo(std::string name, int course, double done_zadavalnik, double time_until_deadline)
    {
        this->name = name;
        this->course = course;
        this->done_zadavalnik = done_zadavalnik;
        this->time_until_deadline = time_until_deadline;
    }

    
    void printInfo()
    {
        std::cout << "Name: " << name << std::endl;
        std::cout << "Rang at MIPT: " << course << std::endl;
        std::cout << "Done zadavalnik %: " << done_zadavalnik << std::endl;
        std::cout << "Life expectancy days: " << time_until_deadline << std::endl;
    }

   
    std::string getCategory()
    {
        if (course < 2)
        {
            return "Pekus_baby";
        }
        else if (course < 4)
        {
            return "Senior";
        }
        else
        {
            return "Veteran";
        }
    }

    
    std::string getState()
    {
        double healka = time_until_deadline / (100 - done_zadavalnik);

        if (healka < 0.034)
        {
            return "Wasted";
        }
        else if (healka < 0.067)
        {
            return "Bistro botay clown.";
        }
        else if (healka < 0.1)
        {
            return "The game has begun. Big Prepod is watching you.";
        }
        else
        {
            return "Are you UBOTOK ?! How are you debt free?!";
        }
    }
};

int main()
{
    Student_of_mipt student("Ryan Gosling", 1, 40, 4);
    student.printInfo();
    std::cout << "Position in society: " << student.getCategory() << std::endl;
    std::cout << "Student's condition: " << student.getState() << std::endl;

    return 0;
}
