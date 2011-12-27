#include "Factor.h"

using namespace std;

int main()
{
    Factor myFactor(1, 8, 15); //initialization of constructor

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

    // for a quick demo choose 1
     if (choice == 1)
    {
        cout << "Factoring C (" << myFactor.getC() <<")......\n" << endl;

        myFactor.cFactor(myFactor.getC());
    }

    // to enter your own number choose 2
    if (choice == 2)
    {
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

        // tell the user what they entered again before proceeding, however i do not ask if this is correct again
        cout << "The polynomial you entered has coefficients:\n" << "A: " << myFactor.getA()
     << "\nB: " << myFactor.getB() << "\nC: " << myFactor.getC() << endl;


    }

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

    return 0;
}
