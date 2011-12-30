#include "Factor.h"

using namespace std;

int main()
{
    Factor myFactor; //initialization of constructor
wrong:
    // ask the user to input the correct coefficients for the current problem they are working on
    cout << "Please enter the coefficient for x^2: ";
        int terms;
        cin >> terms;
        myFactor.setA(terms);
        cout << endl;

        cout << "Please enter the coefficient for x: ";
        cin >> terms;
        myFactor.setB(terms);
        cout << endl;

        cout << "Please enter the constant term (c): ";
        cin >> terms;
        myFactor.setC(terms);
        cout << endl;

    // tell user what the current setting initialized by the constructor are
    cout << "The polynomial you entered has coefficients:\n" << "A: " << myFactor.getA()
     << "\nB: " << myFactor.getB() << "\nC: " << myFactor.getC() << endl;

    // ask if they would like to change the default choice
     int choice;
     do
     {
         cout << "Does this look correct?\n"
            << "1. Yes\n2. No" << endl;
            cin >> choice;
     } while(choice != 1 && choice != 2);

    // if the coefficients entered are correct then go to the start of the algorithm section of the progrma
     if (choice == 1)
    {
        goto start;
    }

    // to enter your own number choose 2
    if (choice == 2)
    {
        goto wrong;

    }

start:

        if(myFactor.getA() > 1 || myFactor.getA() < 0)
    {
        cout << "\nFactoring A (" << myFactor.getA() << ").......\n" << endl;
        myFactor.aFactor(myFactor.getA());

        cout << "\nFactoring B (" << myFactor.getB() << ")........\n" << endl;
        myFactor.bFactor(myFactor.getB());

        cout << "\nFactoring C (" << myFactor.getC() << ")........\n" << endl;
        myFactor.cFactor(myFactor.getC());

        myFactor.testFactorsOfA();
    }

    if(myFactor.getA() == 1)
    {
        cout << "\nFactoring C (" << myFactor.getC() <<")......\n" << endl;

        myFactor.cFactor(myFactor.getC());
        // run the test factors program to determine what the proper factors are to use
        myFactor.testFactorsOfC();

        // this line just tells you what a and b are
        cout << "in (x+a)(x+b)\n" << "\na is " << myFactor.getFactoredaOfC()
        << "\nand\nb is " << myFactor.getFactoredbOfC() << endl;

        // this block of if statements will spit out the correct syntax of (x+a)(x+b) depending
        // on whether one or both factors are positive or negative respectively.
        if (myFactor.getFactoredaOfC() < 0 && myFactor.getFactoredbOfC() > 0)
        {
            cout << "\nSo your final form is (x" << myFactor.getFactoredaOfC() << ")(x+" << myFactor.getFactoredbOfC() << ") " << endl;
        }

        if (myFactor.getFactoredaOfC() > 0 && myFactor.getFactoredbOfC() < 0)
        {
            cout << "\nSo your final form is (x+" << myFactor.getFactoredaOfC() << ")(x" << myFactor.getFactoredbOfC() << ") " << endl;
        }

        if (myFactor.getFactoredaOfC() < 0 && myFactor.getFactoredbOfC() < 0)
        {
            cout << "\nSo your final form is (x" << myFactor.getFactoredaOfC() << ")(x" << myFactor.getFactoredbOfC() << ") " << endl;
        }

        if (myFactor.getFactoredaOfC() > 0 && myFactor.getFactoredbOfC() > 0)
        {
            cout << "\nSo your final form is (x+" << myFactor.getFactoredaOfC() << ")(x+" << myFactor.getFactoredbOfC() << ") " << endl;
        }

        // delete dynamically allocated memory when program ends.
        myFactor.deleteArrayOfC();
    }

    int choice2 = 0;
    do
    {
        int i =0;
        if (i != 0)
        {
            cout << "\nYou did not enter a value choice, please choose a 1 or a 2" << endl;
        }
        cout << "\n\nAre you done using the program?\n" << "1. Yes\n2. No" << endl;
        cin >> choice2;
        i++;
    } while (choice2 != 1 && choice2 != 2);

    if (choice2 == 1)
    {
        ;
    }

    if (choice2 == 2)
    {
        goto wrong;
    }
    return 0;
}
