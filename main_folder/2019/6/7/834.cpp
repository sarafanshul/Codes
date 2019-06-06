#include <iostream>
using namespace std;

int main()
{
    int a, b;
    while (cin >> a >> b)
    {
        cout << "[";
        int c = 0;
        while (b > 1)
        {
            cout << a / b << (++c > 1 ? ',' : ';');
            a = a % b;
            swap(a, b);
        }
        cout << a << "]\n";
                
    }
}
