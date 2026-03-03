#include <iostream>

using namespace std;

int main()
{
    cout << "\n---------- ex 01 ---------- \n\n";

    int x = 10; 
    int y = 20;
    int *p;
    p = &x;

    cout << "X: " << x << "  |  Y: " << y <<  "  |  *p: " << *p << endl;


    return 0;
}
