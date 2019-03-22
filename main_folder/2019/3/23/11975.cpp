#include <iostream>
using namespace std;

int cor[4] = {0, 4, 20, 24}, mid[5] = {10, 11, 12, 13, 14}, diag[9] = {0, 4, 6, 8, 12, 16, 18, 20, 24};
int main()
{
    int cases, n, l, A[75], V[4], T[25], len;
    cin >> cases;
    for (int no = 1; no <= cases; ++no)
    {
        cout << (no > 1 ? "\n" : "") << "Case " << no << ":\n";
                                 cin >> n >> l;
        for (int i = 0; i < n; ++i)
            cin >> A[i];

        for (int i = 0; i < 4; ++i)
            cin >> V[i];

        for (int i = 0; i < l; ++i)
        {
            for (int j = 0; j < 25; ++j)
                cin >> T[j];

            bool win[4] = {};
            bool trial = true;
            len = ::min(35, n);
            for (int k = 0; k < 4 && trial; ++k)
            {
                bool found = false;
                for (int j = 0; j < len && !found; ++j)
                    found |= T[cor[k]] == A[j];
                trial &= found;
            }
            win[0] |= trial; trial = true;

            len = ::min(40, n);
            for (int k = 0; k < 5 && trial; ++k)
            {
                bool found = false;
                for (int j = 0; j < len && !found; ++j)
                    found |= T[mid[k]] == A[j];
                trial &= found;
            }
            win[1] |= trial; trial = true;

            len = ::min(n, 45);
            for (int k = 0; k < 9 && trial; ++k)
            {
                bool found = false;
                for (int j = 0; j < len && !found; ++j)
                    found |= T[diag[k]] == A[j];
                trial &= found;
            }
            win[2] |= trial; trial = true;

            for (int k = 0; k < 25 && trial; ++k)
            {
                bool found = false;
                for (int j = 0; j < n && !found; ++j)
                    found |= T[k] == A[j];
                trial &= found;             
            }
            win[3] |= trial;

            int prize = 0;
            for (int p = 0; p < 4; ++p)
                prize += V[p] * win[p];
            cout << prize << "\n";
        }

       
    }
}
