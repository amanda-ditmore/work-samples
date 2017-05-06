//Amanda Ditmore
//emergency room

#include <iostream>
#include "heap.h"
#include "patient.h"
using namespace std;

void addPatient(Heap<Patient>& H, string nm, int pr);
void callNextPatient(Heap<Patient>& H);

int main()
{
    Heap<Patient> ER;

    addPatient(ER,"Bob",5);
    addPatient(ER,"Mary",9);
    addPatient(ER,"Max",1);

    callNextPatient(ER);

    addPatient(ER, "Stacy", 7);
    addPatient(ER, "Paul", 4);
    addPatient(ER, "Reiko", 2);
    addPatient(ER, "Jennifer", 6);
    addPatient(ER, "Chang", 5);

    callNextPatient(ER);
    callNextPatient(ER);
    callNextPatient(ER);
    callNextPatient(ER);
    callNextPatient(ER);
    callNextPatient(ER);
    callNextPatient(ER);
}

void addPatient(Heap<Patient>& H, string nm, int pr)
{
    Patient tempPt(nm, pr);
    H.add(tempPt);
}

void callNextPatient(Heap<Patient>& H)
{
    cout << (H.peekTop()).getName() << " will see the doctor now." << endl;
    H.remove();
}
