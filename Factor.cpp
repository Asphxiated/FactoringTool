#include "Factor.h"
using namespace std;

Factor::Factor()
{

    a = 0;
    b = 0;
    c = 0;

}

// function to factor the first term in a polynomial
void Factor::aFactor(int A)
{
    // we just want the positive factors of A, leave out -1
    // this will be tested for by the testFactors function
    if (A < 0)
    {
        A=-A;
        isANeg = true;
    }
    else
    {
        isANeg = false;
    }
    numberOfFactorsOfA = 0;

    pdivisorOfA = NULL;
    pfactorsOfA = NULL;
    // calculation phase
    for(int iii=1;iii<=A;iii++) // note we use A here as a limit so that we will get all factors twice
    {                           // which means I don't need another if statement in testFactorsOfA
        if ((A % iii) == 0)
        {
            // define new storage to fit new factors
            int *pd = new int[numberOfFactorsOfA+1];
            int *pf = new int[numberOfFactorsOfA+1];

            // copy over old data
            for(int i=0; i < numberOfFactorsOfA; i++)
            {
                pd[i] = pdivisorOfA[i];
                pf[i] = pfactorsOfA[i];
            }

            // add the new value to the array
            pd[numberOfFactorsOfA] = iii; // keep track of evenly divisable numbers
            pf[numberOfFactorsOfA] = (A / iii);// place the cooresponding factor in another array but the same column

            // free up data of old arrays
            delete[] pdivisorOfA;
            delete[] pfactorsOfA;

            // set old arrays to new arrays with new data found
            pdivisorOfA = pd;
            pfactorsOfA = pf;

            // increment number of known factors by 1
            numberOfFactorsOfA++;

        }
    }

    //termination phase
    cout << "\nFormat of results: \n\n" << "Factor on top\n" << "Divisor on bottom\n" << endl;

    for (int nRow=0; nRow < numberOfFactorsOfA; nRow++)
    {
        cout << pfactorsOfA[nRow] << "\t";
    }
    cout << endl;
    for (int nRow=0; nRow< numberOfFactorsOfA; nRow++)
    {
        cout << pdivisorOfA[nRow] << "\t";
    }

    cout << "\n\nWith a total of " << numberOfFactorsOfA << " possible factors  of a to use." << endl;
} // end a factorization function

// function to factor the second term of a polynomial
void Factor::bFactor(int B)
{
    // we need to keep track of whether b is positive or negative because it will have bearing
    // on the final form of our factored equation
    if (B < 0)
    {
        B = -B;
        isBNeg = true;
    }
    else
    {
        isBNeg = false;
    }

    numberOfFactorsOfB = 0;

    pdivisorOfB = NULL;
    pfactorsOfB = NULL;
    // calculation phase
    for (int iii = 1; iii <= B; iii++)
    {
        if ((B % iii)  == 0)
        {
            // define temporary dynamic storage to fit new factor and all previously know factors
            int *pd = new int[numberOfFactorsOfB+1];
            int *pf = new int[numberOfFactorsOfB+1];

            //copy over old data
            for (int i=0; i < numberOfFactorsOfB; i++)
            {
                pd[i] = pdivisorOfB[i];
                pf[i] = pfactorsOfB[i];
            }

            // add the new value found to the end of the temporary store created
            pd[numberOfFactorsOfB] = iii;
            pf[numberOfFactorsOfB] = (B / iii);

            // free up room on the data member pointers
            delete[] pdivisorOfB;
            delete[] pfactorsOfB;

            // set data member points to point to the same memory address as the temporary pointers
            pdivisorOfB = pd;
            pfactorsOfB = pf;

            // increment the known factors of b by one
            numberOfFactorsOfB++;
        } // end if
    } // end for

        //termination phase
    cout << "\nFormat of results: \n\n" << "Factor on top\n" << "Divisor on bottom\n" << endl;

    for (int nRow=0; nRow < numberOfFactorsOfB; nRow++)
    {
        cout << pfactorsOfB[nRow] << "\t";
    }
    cout << endl;
    for (int nRow=0; nRow< numberOfFactorsOfB; nRow++)
    {
        cout << pdivisorOfB[nRow] << "\t";
    }

    cout << "\n\nWith a total of " << numberOfFactorsOfB << " possible factors  of b to use." << endl;
} // end bFactor function

// function to factor the third term in a polynomial
void Factor::cFactor(int C)
{
    // we just want the positive factors of C, leave out -1
    // this will be tested for by the testFactors function
    if (C < 0)
    {
        C=-C;
        isCNeg = true;
    }
    else
    {
        isCNeg = false;
    }
    numberOfFactorsOfC = 0;

    pdivisorOfC = NULL;
    pfactorsOfC = NULL;
    // calculation phase
    for(int iii=1;iii<=C;iii++) // note we use C here as a limit so that we will get all factors twice
    {                           // which means I don't need another if statement in testFactorsOfC
        if ((C % iii) == 0)
        {
            // define new storage to fit new factors
            int *pd = new int[numberOfFactorsOfC+1];
            int *pf = new int[numberOfFactorsOfC+1];

            // copy over old data
            for(int i=0; i < numberOfFactorsOfC; i++)
            {
                pd[i] = pdivisorOfC[i];
                pf[i] = pfactorsOfC[i];
            }

            // add the new value to the array
            pd[numberOfFactorsOfC] = iii; // keep track of evenly divisable numbers
            pf[numberOfFactorsOfC] = (C / iii);// place the cooresponding factor in another array but the same column

            // free up data of old arrays
            deleteArrayOfC();

            // set old arrays to new arrays with new data found
            pdivisorOfC = pd;
            pfactorsOfC = pf;

            // increment number of known factors by 1
            numberOfFactorsOfC++;

        }
    }

    //termination phase
    cout << "\nFormat of results: \n\n" << "Factor on top\n" << "Divisor on bottom\n" << endl;

    for (int nRow=0; nRow < numberOfFactorsOfC; nRow++)
    {
        cout << pfactorsOfC[nRow] << "\t";
    }
    cout << endl;
    for (int nRow=0; nRow< numberOfFactorsOfC; nRow++)
    {
        cout << pdivisorOfC[nRow] << "\t";
    }

    cout << "\n\nWith a total of " << numberOfFactorsOfC << " possible factors  of c to use." << endl;
} // end c factorization function

// function to get the current value of A
int Factor::getA()
{
    return a;
}

//function to get the current value of B
int Factor::getB()
{
    return b;
}

// function to get the current value of C
int Factor::getC()
{
    return c;
}

// function to get the current value of D
int Factor::getD()
{
    return d;
}

// function to get the number of factors of a
int Factor::getNumberOfFactorsOfA()
{
    return numberOfFactorsOfA;
}

// function to get the number of factors of b
int Factor::getNumberOfFactorsOfB()
{
    return numberOfFactorsOfB;
}

// function to get number of factors of C
int Factor::getNumberOfFactorsOfC()
{
    return numberOfFactorsOfC;
}

// this is the alternative algorithm for factoring a polynomial when
// a != 1, this includes when a = -1
void Factor::testFactorsOfA()
{
    commonFactor = 0;
    d = 0;

    // I have now implemented a seperate function to find the greatest common divisor
    // of all of the coefficients supplied. This makes this section more readable and
    // actually produces correct results, finally
    commonFactor = gcd(getA(),gcd(getB(),getC()));
    if(commonFactor == -1)
    {
        commonFactor = -commonFactor;
    }
    d = commonFactor;

    if(commonFactor == 0 || commonFactor == 1)
    {
        cout << "\nThere were no common factors between A: " << getA() << " B: " << getB() << " and C: " << getC() << endl;
    } // end if
    else
    {
        cout << "\nThe common factor between A: " << getA() << " B: " << getB() << " and C: " << getC() << " was: " << getCommonFactor() << endl;
    } // end else

    if (isANeg == true)
    {
        d = -commonFactor;
    }
    if(commonFactor != 0 && isANeg == false)
    {
        // set the coefficients to the the factored form and then report the new form of the equation
        a = a / d;
        b = b / d;
        c = c / d;

        cout << "\n\nSo your equation now has the form:\n";

       if(isBNeg == false && isCNeg == false)
       {
            cout << getD() << "(" << getA() << "x^2+" << getB() << "x+" << getC() << ")" << endl;
       }

       if(isBNeg == true && isCNeg == false)
       {
            cout << getD() << "(" << getA() << "x^2" << getB() << "x+" << getC() << ")" << endl;
       }

       if(isBNeg == false && isCNeg == true)
       {
            cout << getD() << "(" << getA() << "x^2+" << getB() << "x" << getC() << ")" << endl;
       }

       if(isBNeg == true && isCNeg == true)
       {
            cout << getD() << "(" << getA() << "x^2" << getB() << "x" << getC() << ")" << endl;
       }
    }

    if(commonFactor != 0 && isANeg == true)
    {
        // set the coefficients to the the factored form and then report the new form of the equation
        a = a / d;
        b = b / d;
        c = c / d;

        cout << "\n\nSo your equation now has the form:\n";

       if(isBNeg == false && isCNeg == false)
       {
            cout << getD() << "(" << getA() << "x^2" << getB() << "x" << getC() << ")" << endl;
       }

       if(isBNeg == true && isCNeg == false)
       {
            cout << getD() << "(" << getA() << "x^2+" << getB() << "x" << getC() << ")" << endl;
       }

       if(isBNeg== true && isCNeg == true)
       {
            cout << getD() << "(" << getA() << "x^2+" << getB() << "x+" << getC() << ")" << endl;
       }

       if(isBNeg == false && isCNeg == true)
       {
            cout << getD() << "(" << getA() << "x^2" << getB() << "x+" << getC() << ")" << endl;
       }
    }

    if (commonFactor == 0 )
    {
        cout << "\nDue to the fact that there were no common factors between a b and c your equation remains unchanged" << endl;
        cout << "\nContinuing to factor the problem anyway (note it was not necessary to have a common factor)\n" << endl;
    }

    found = false;

    // formatting reasons
    cout << "\n" << endl;
    // continue finding the factored form of the polynomial
    if (isCNeg == false)
    {
        for(int i = 0; found == false && i < numberOfFactorsOfA; i++)
        {
            for(int j = 0; found == false && j < numberOfFactorsOfC; j++)
            {
                if (abs((pfactorsOfA[i]*pfactorsOfC[j])+ (pdivisorOfA[i]*pdivisorOfC[j])) == abs(b))
                {
                    factoredA1 = pfactorsOfA[i];
                    factoredA2 = pdivisorOfA[i];
                    factoredC1 = pfactorsOfC[j];
                    factoredC2 = pdivisorOfC[j];

                    cout << "Format of results: (a1,c1)" << endl;
                    cout << "                   (a2,c2)\n";

                    cout << "\nThe correct factors of a to use are: (" << factoredA1 << "," << factoredA2 << ")" << endl;
                    cout << "The correct factors of c to use are: (" << factoredC1 << "," << factoredC2 << ")" << endl;

                    switch (isBNeg)
                    {
                        case true:
                            cout << "\nThe final form of the factored equation is then: \n";
                            cout << ((d !=0) ? (d) : 1 ) << "*(" << factoredA1 << "x-" << factoredC1 << ")("
                                << factoredA2 << "x-" << factoredC2 << ")" << endl;
                            break;

                        case false:
                            cout << "\nThe final form of the factored equation is then: \n";
                            cout << (d != 0 ? d :1) << "*(" << factoredA1 << "x+" << factoredC1 << ")("
                                << factoredA2 << "x+" << factoredC2 << ")" << endl;
                            break;
                    } // end switch

                    found = true;
                    break;
                } // end if

                if (abs((pfactorsOfA[i]*pdivisorOfC[j])+ (pdivisorOfA[i]*pfactorsOfC[j])) == abs(b))
                {
                    factoredA1 = pfactorsOfA[i];
                    factoredA2 = pdivisorOfA[i];
                    factoredC1 = pfactorsOfC[j];
                    factoredC2 = pdivisorOfC[j];

                    cout << "Format of results: (a1,c1)" << endl;
                    cout << "                   (a2,c2)\n";


                    cout << "\nThe correct factors of a to use are: (" << factoredA1 << "," << factoredA2 << ")" << endl;
                    cout << "The correct factors of c to use are: (" << factoredC1 << "," << factoredC2 << ")" << endl;

                    switch (isBNeg)
                    {
                        case true:
                            cout << "\nThe final form of the factored equation is then: \n";
                            cout << (d != 0 ? d :1) << "*(" << factoredA1 << "x-" << factoredC1 << ")("
                                << factoredA2 << "x-" << factoredC2 << ")" << endl;
                            break;

                        case false:
                            cout << "\nThe final form of the factored equation is then: \n";
                            cout << (d != 0 ? d :1) << "*(" << factoredA1 << "x+" << factoredC1 << ")("
                                << factoredA2 << "x+" << factoredC2 << ")" << endl;
                            break;
                    } // end switch

                    found = true;
                    break;
                } // end if
            } // end nested for
        } // end for
    } // end if

    if (isCNeg == true)
    {
        for (int i=0; found == false && i < numberOfFactorsOfA; i++)
        {
            for (int j = 0; found == false && j < numberOfFactorsOfC; j++)
            {
                if (abs((pfactorsOfA[i]*pfactorsOfC[j])-(pdivisorOfA[i]*pdivisorOfC[j]))== abs(b))
                {
                    factoredA1 = pfactorsOfA[i];
                    factoredA2 = pdivisorOfA[i];
                    factoredC1 = pfactorsOfC[j];
                    factoredC2 = pdivisorOfC[j];

                    cout << "Format of results: (a1,c1)" << endl;
                    cout << "                   (a2,c2)\n";


                    cout << "\nThe correct factors of a to use are: (" << factoredA1 << "," << factoredA2 << ")" << endl;
                    cout << "The correct factors of c to use are: (" << factoredC1 << "," << factoredC2 << ")" << endl;

                    switch (isBNeg)
                    {
                        case true:
                            cout << "\nThe final form of the factored equation is then: \n";
                            cout << (d != 0 ? d :1) << "*(" << factoredA1 << "x-" << factoredC1 << ")("
                                << factoredA2 << "x+" << factoredC2 << ")" << endl;
                            break;

                        case false:
                            cout << "\nThe final form of the factored equation is then: \n";
                            cout << (d != 0 ? d :1) << "*(" << factoredA1 << "x+" << factoredC1 << ")("
                                << factoredA2 << "x-" << factoredC2 << ")" << endl;
                            break;
                    } // end switch

                    found = true;
                    break;
                } // end if

                if (abs((pfactorsOfA[i]*pdivisorOfC[j])-(pdivisorOfA[i]*pfactorsOfC[j]))== abs(b))
                {
                    factoredA1 = pfactorsOfA[i];
                    factoredA2 = pdivisorOfA[i];
                    factoredC1 = pfactorsOfC[j];
                    factoredC2 = pdivisorOfC[j];

                    cout << "Format of results: (a1,c1)" << endl;
                    cout << "                   (a2,c2)\n";


                    cout << "\nThe correct factors of a to use are: (" << factoredA1 << "," << factoredA2 << ")" << endl;
                    cout << "The correct factors of c to use are: (" << factoredC1 << "," << factoredC2 << ")" << endl;

                    switch (isBNeg)
                    {
                        case true:
                            cout << "\nThe final form of the factored equation is then: \n";
                            cout << (d != 0 ? d :1) << "*(" << factoredA1 << "x+" << factoredC1 << ")("
                                << factoredA2 << "x-" << factoredC2 << ")" << endl;
                            break;

                        case false:
                            cout << "\nThe final form of the factored equation is then: \n";
                            cout << (d != 0 ? d :1) << "*(" << factoredA1 << "x-" << factoredC1 << ")("
                                << factoredA2 << "x+" << factoredC2 << ")" << endl;
                            break;
                    } // end switch
                    found = true;
                    break;
                } // end if
            } // end nested for
        } // end for
    } // end if
}

void Factor::testFactorsOfC()
{
    cout << "\n\nTesting known factors of C.......\n" << endl;

    for(int iii=0;iii<numberOfFactorsOfC;iii++)
    {
        // testing with positive factors
        if(pdivisorOfC[iii]+pfactorsOfC[iii] == b)
        {
            if(pdivisorOfC[iii]*pfactorsOfC[iii] == c)
            {
                factoredaOfC = pdivisorOfC[iii];
                factoredbOfC = pfactorsOfC[iii];
            } // end nested if
        } // end if

        // testing with negative factors, there is no need to check the other way as
        // all factors are found twice with the cFactor algorithm thus we
        // technically check the vice versa case here automatically.
        if (-pdivisorOfC[iii]+pfactorsOfC[iii] == b)
        {
            if(-pdivisorOfC[iii]*pfactorsOfC[iii] == c)
            {
                factoredaOfC = -pdivisorOfC[iii];
                factoredbOfC = pfactorsOfC[iii];
            } // end nested if
        } // end if

        // testing with both factors negative
        if (-pdivisorOfC[iii]-pfactorsOfC[iii] == b)
        {
            if(-pdivisorOfC[iii]*(-pfactorsOfC[iii]) == c)
            {
                factoredaOfC = -pdivisorOfC[iii];
                factoredbOfC = -pfactorsOfC[iii];
            } // end nested if
        } // end if
    } // end for
} // end testFactorsOfC function

int Factor::getFactoredaOfC()
{
    return factoredaOfC;
}

int Factor::getFactoredbOfC()
{
    return factoredbOfC;
}

int Factor::getCommonFactor()
{
    return commonFactor;
}

void Factor::setA(int A)
{
    a = A;
}

void Factor::setB(int B)
{
    b = B;
}

void Factor::setC(int C)
{
    c = C;
}


void Factor::deleteArrayOfC()
{
    delete [] pdivisorOfC;
    delete [] pfactorsOfC;
}


// this is the euclidean algorithm for finding GCD's
int Factor::gcd(int a, int b)
{
    do
    {
        int t = b;
        b = a % b;
        a = t;
    } while (b != 0);

    return a;
}
