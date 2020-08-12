#include <iostream>
using namespace std;

int main()
{
    int N, a, b, c;
    cin >> N;
    while (N--)
    {
        cin >> a >> b >> c;
        bool flag = false;
        for (int x = -100; x <= 100 && !flag; ++x)
            for (int y = -100; y <= 100 && !flag; ++y)
                for (int z = -100; z <= 100 && !flag; ++z)
                    if (x != y && y!= z && x!= z && x + y + z == a && x * y * z == b && x * x + y * y + z * z == c)
                        cout << x << " " << y << " " << z << "\n", flag = true;

        if (!flag)
            cout << "No solution.\n";
    }
}
