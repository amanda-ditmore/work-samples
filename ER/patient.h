//header for patient class

#include <string>
using namespace std;


class Patient
{
    private:
        string name;
        int priority;
    public:
        Patient() { priority = 0; }
        Patient(string nm, int pr) { name = nm; priority = pr;}
        void setName(string nm) { name = nm; }
        void setPriority(int pr) { priority = pr;}
        string getName() { return name; }
        int getPriority() { return priority; }
        bool operator < (const Patient& rhs) const { return (priority < rhs.priority); }
        bool operator > (const Patient& rhs) const { return (priority > rhs.priority); }
        bool operator <= (const Patient& rhs) const { return (priority <= rhs.priority); }
        bool operator >= (const Patient& rhs) const { return (priority >= rhs.priority); }
        bool operator == (const Patient& rhs) const { return (priority == rhs.priority); }
};
