/** Jennifer Byrne
    02/10/2017
    Lab 7
    Decimal / Binary Conversion */

/** Preprocessor directives */
#include <iostream>
#include <iomanip>
/** allows getchar() */
#include <cstdio>
/** allows system(cls) */
#include <windows.h>
#include <math.h>
/** allows inverse tan function */
#include <cmath>

/** Enables cout, cin and endl */
using namespace std;


    char displayMenu(void);
    void cartPol(void);
    void polCart(void);

    void calCartPol (double real, double imag, double *magPtr, double *anglePtr);
    void calPolCart (double *realPtr, double *imagPtr, double mag, double angle);


    /** Main gunction */
int main(void)
{
    /** declare variables */
    char choice;
    /** do while loop to get the user to select which operation they want to use */
    do
    {
        choice = displayMenu();
        /** switch case to select whoch subfunctions operations to carry out */
        switch (choice)
        {
            case 'c':       polCart();
                            break;

            case 'p':       cartPol();
                            break;

            case 'q':       system("cls");
                            cout <<"Goodbye...\n";
                            break;

            default:	    cout <<"\nInvalid input, press any key to continue..." ;
                            fflush(stdin);
                            getchar();
                            break;
    }
}
    while (choice != 'q' );

    return 0;
}

/** function header */
char displayMenu(void)
{
    /** declaring variable type char */
    char choice;
    /** turns previous screen off */
    system("cls");
    /** user enters which command they want to use */
    cout <<"Coordinate Conversion" ;
    cout <<"\n\nPress 'c' to convert from Polar to Cartesian ...";
    cout <<"\nPress 'p' to convert from Cartesian to Polar ...";
    cout <<"\nPress 'q' to quit ...\n\nChoice: ";
    /** gets rid of bugs */
    fflush(stdin);
    choice = getchar();
    return choice;
}

/** function header */
void cartPol(void)
{
    /** declaring variables */
    cout <<"in function cartPol\n";
    double real, imag, mag, angle;
    double *magPtr = &mag, *anglePtr = &angle;

    /** closes previous screen down */
    system("cls");
    /** read in values from the user */
    cout <<"Cartesian to Polar Conversion\n\n";
    cout << "Enter real part:\t";
    cin >> real ;
    cout << "Enter imaginary part:\t";
    cin >> imag ;

    /** invoking calCartPol subfunction */
    calCartPol (real, imag, magPtr, anglePtr);

    /** display results from equations */
    cout << "\nMagnitude:\t\t" << mag ;
    cout << "\nAngle:\t\t\t" << angle ;
    cout << "\n\nPress any key to return to the main menu..." ;
    fflush(stdin);
    /** operation to get the char value */
    getchar();

    return;

}
/** Sub function */
void calCartPol (double real, double imag, double *magPtr, double *anglePtr)
{
    *magPtr = sqrt(pow(real, 2) + pow(imag, 2));

    *anglePtr = atan(imag / real) ;

    return ;
}


/** function header */
void polCart(void)
{
    cout << "in function polCart\n" ;
    /** declaring variables */
    double real, imag, mag, angle;
    double *realPtr = &real, *imagPtr = &imag;

    /** closes previous screen */
    system("cls");
    /** read in values */
    cout << "Polar to Cartesian Conversion\n\n" ;
    cout << "Enter magnitude:\t" ;
    cin >> mag ;
    cout << "Enter angle :\t" ;
    cin >> angle ;

    calPolCart (realPtr, imagPtr, mag, angle);

    /** equations for real and imaginary */
    real = mag * cos(angle);

    imag = mag * sin(angle);
    /** display answers */
    cout << "\nReal part:\t\t" << real << endl;
    cout << "\nImaginary part:\t\t" << imag << endl;
    cout << "\n\nPress any key to return to the main menu..." ;
    fflush(stdin);
    getchar();
    /** returns something back to main functon */
    return;
}

void calPolCart (double *realPtr, double *imagPtr, double mag, double angle)
{
    /** equations for real and imaginary */
    *realPtr = mag * cos(angle);

    *imagPtr = mag * sin(angle);

    return ;
}
