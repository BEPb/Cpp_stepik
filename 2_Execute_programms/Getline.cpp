#include <iostream>
using namespace std;

char *getline()
{
  int i = 0;
  char c;
  char * tmp = new char[1];
  while (cin.get(c) && (c != '\n')) {
    i++;
    tmp[i-1] = c;
    char * new_tmp = new char[i+1];
    for (int n=0;n<i;n++) new_tmp[n] = tmp[n];
    delete [] tmp;
    tmp = new_tmp;
  }
  tmp[i] = '\0';
  return tmp;
}