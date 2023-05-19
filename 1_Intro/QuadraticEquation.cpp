#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    int d = pow(b,2) - 4*a*c;
    if (d < 0)
    {
        cout << "No real roots";
    } else if (d==0)
    {
        cout << (-b)/(2*a) << " " << (-b)/(2*a);
    } else
    {
        cout << ((-1)*b - sqrt(d))/(2*a) << " " << ((-1)*b + sqrt(d))/(2*a);
    }
    return 0;
}