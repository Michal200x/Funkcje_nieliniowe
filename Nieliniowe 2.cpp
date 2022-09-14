#include <iostream>
#include <math.h>
#include <cstdlib>


using namespace std;

double f1(double x)
{
    return cos(x * x * x - (2 * x));
}

int main()
{
    double a = 0.0;
    double b = 2.0;
    double E = 0.01;
    double x0;
    double fx0;
    //sprawdzamy
    
    cout << endl << "przedzial = [" << a << ", " << b << "]" << endl << endl;
    cout << "f(a) = " << f1(a) << endl;
    cout << "f(b) = " << f1(b) << endl;

    if (f1(a) * f1(b) < 0)
    {
        //cout << "warunek spelniony funkcja posiada pierwiastek" << endl;
        while (1)
        {  
            x0 = (a + b) / 2;
            cout << "x0 = " << x0 << endl;
            cout << "f(x0) = " << f1(x0) << endl;
            if (abs(f1(x0)) > E)
            {
                //cout << "warunek f(x0)>E spelniony liczymy dalej" << endl;
                if (f1(a) * f1(x0) < 0)
                {
                    cout << "f(a)f(x0) = " << f1(a)* f1(x0) << endl;
                   // cout << "warunek f(a)f(x0)<0 spelniony liczymy podstawiamy b=x0" << endl;
                    b = x0;
                    cout << endl << "Nowy przedzial = [" << a << ", " << b << "]" << endl << endl;
                    cout << "f(a) = " << f1(a) << endl;
                    cout << "f(b) = " << f1(b) << endl;
                }
                else
                {
                    cout << "f(a)f(x0) = " << f1(a) * f1(x0) << endl;
                    //cout << "warunek f(a)f(x0)<0 nie spelniony podstawiamy a=x0" << endl;
                    a = x0;
                    cout << endl << "Nowy przedzial = [" << a << ", " << b << "]" << endl << endl;
                    cout << "f(a) = " << f1(a) << endl;
                    cout << "f(b) = " << f1(b) << endl;
                }
            }
            else
            {
                cout << "warunek f(x0)>E nie spelniony koniec obliczen" << endl;
                break;
            }
        }
    }
    else
    {
        cout << "zly przedzial funkcja nie posiada pierwiastka" << endl;
    }

    cout << endl << "--------------------------------------------------------------------------" << endl << endl;



}
