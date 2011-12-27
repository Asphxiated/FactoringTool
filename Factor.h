#ifndef FACTOR_H_INCLUDED
#define FACTOR_H_INCLUDED
#include <iostream>
#include <string>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>


// class definition for factoring tool
class Factor
{
public:
    Factor(int A, int B, int C); // constructor for factor program
    void aFactor(int A); // find factors of a
    void bFactor(int B); // find factors of b
    void cFactor(int C); //c factorizor (not necessarily prime factors, but they are included)
    int getA(); // function to return the current value of A
    int getB(); // function to return the current value of B
    int getC(); // function to return the current value of C
    int getD(); // function to return the value of the commonFactor
    int getNumberOfFactorsOfA(); // returns the integer value of the number of known factors of a
    int getNumberOfFactorsOfB(); // returns the integer value of the number of known factors of b
    int getNumberOfFactorsOfC(); // returns the integer number of factors found by the cFactor function
    void testFactorsOfA(); // this function will be run when a != 1 and testFactorsOfC will not be ran
    void testFactorsOfC(); // tests factors based on a number of conditions to cover all possibilities
    int getFactoredaOfC(); // returns the proper factor to use with sign
    int getFactoredbOfC(); // returns other proper factor to use with sign
    void setA(int); // allows user to set the coefficient A
    void setB(int); // allows user to set the coefficient B
    void setC(int); // allows user to set the coefficient C
    void deleteArrayOfC(); // deletion of dynamically allocated memory
    int getCommonFactor(); // returns the common factor between a b and c
    int gcd(int a, int b); // function to gelp find greatest common divisor


private:
    int a; // coefficient of second order term
    int b; // coefficient of first order term
    int c; // constant offset term
    int d; // integer value that can be factored out of the the equation if a != 1
    int numberOfFactorsOfA; // variable to hold number of factors of a
    int numberOfFactorsOfB; // variable to hold number of factors of b
    int numberOfFactorsOfC; // variable to hold number of factors of c
    int *pdivisorOfA; // pointer that is used to create a dynamic array to store "good" divisors of a
    int *pfactorsOfA; // pointer used to store the results of division for a (cooresponding factor)
    int *pdivisorOfB; // pointer used to store "good" divisors of b
    int *pfactorsOfB; // pointer used to store the results of division for b
    int *pdivisorOfC; // pointer that is used to create a dynamic array to store "good" divisors of c
    int *pfactorsOfC; // pointer that is used to create a dynamic array to store the results of devision (cooresponding factor)
    int factoredaOfC; // variable to store the correct factor value, signed
    int factoredbOfC; // variable to store the other correct factor value, signed
    int commonFactor; // variable to hold the common factor of a b and c
    bool isANeg; // variable to keep track of whether a is negative or not
    bool isBNeg; // variable to keep track of whether b is negative or not
    bool isCNeg; // variable to kepp track of whether c is negative or not
    bool found; // variable to keep track of whether a correct pair of factors has been found
    int factoredA1; // variable to store the value found for a1
    int factoredA2; // variable to store the value found for a2
    int factoredC1; // variable to store the value found for c1
    int factoredC2; // variable to store the value found for c2
}; // end class definition


#endif // FACTOR_H_INCLUDED
