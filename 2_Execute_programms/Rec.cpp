#include <iostream>

using namespace std;


void rec()
{
    int a=0;
    cin >> a;
    if ( a ==0 ) return;
    rec();
    cout << a << " ";
   
}

int main()
{
    rec();
   
    return 0;
}