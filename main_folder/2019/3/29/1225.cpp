#include <iostream>
using namespace std;

int main()
{
    int n, C;
    cin >> C;
    while (C--)
    {
        cin >> n;
        int A[10] = {};
        // Ones
        for (int i = 1; i < n % 10 + 1; ++i)
            A[i]++;

        for (int i = 0; i < 10; ++i)
            A[i] += n / 10;
        
        // Tens
        if (n > 9)
        {
            for (int i = 0; i < (n / 10) % 10; ++i)
                A[i] += 10;            
            A[(n / 10) % 10] += n % 10 + 1;
            A[0] -= 10;

            for (int i = 0; i < 10; ++i)
                A[i] += (n / 100) * 10;
        }

        // Hundreds
        if (n > 99)
        {
            for (int i = 1; i < (n / 100) % 10; ++i)
                A[i] += 100;
            A[(n / 100) % 10] += n % 100 + 1;

            for (int i = 0; i < 10; ++i)
                A[i] += (n / 1000) * 100;
        }

        // Thousands
        if (n > 999)
        {
            for (int i = 1; i < (n / 1000) % 10; ++i)
                A[i] += 1000;
            A[(n / 1000) % 10] += n % 1000 + 1;
        }
        

        for (int i = 0; i < 10; ++i)
            cout << (i ? " " : "") << A[i];
        cout << endl;
    }
}
