#include <iostream>
#include <iomanip>
using namespace std;

double e = 0;

double F(double a, double b)
{
    return 1/(1+(1/(1+(1/(2*a+b)))));
}

void euler(double i, double k)
{
    if(i>1)
    {
        euler(i-1,F(i,k));
    }
    if(i==1)
    {
        e = 2+(1/(1+(1/(2+k))));
    }
    return;
}

int main()
{
    euler(1,0);
    cout << setprecision(15) << e << endl;
    euler(2,0);
    cout << setprecision(15) << e << endl;
    euler(3,0);
    cout << setprecision(15) << e << endl;
    euler(4,0);
    cout << setprecision(15) << e << endl;
    euler(5,0);
    cout << setprecision(15) << e << endl;
    euler(6,0);
    cout << setprecision(15) << e << endl;
    euler(1000,0);
    cout << setprecision(20) << e << endl;
    return 0;
}
