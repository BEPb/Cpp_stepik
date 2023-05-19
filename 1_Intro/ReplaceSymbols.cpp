#include <iostream>
using namespace std;

int main(){
    bool pb = false;
    char p = ' ', c = '\0';
    while (cin.get(c)) {
        if(c != 1){
            if (pb == false || c != p) cout << c;
            if (c == p) pb = true;
            else if (c != p ) pb = false;
        }
    }

  return 0;
}