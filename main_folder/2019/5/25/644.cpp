#include <algorithm> 
#include <iostream>
#include <string>
#include <vector> 
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    int c = 1;
    string s;
    vector<string> A;
    bool flag = false;
    while (getline(cin, s))
    {
        if (s == "9")
        {
            sort(A.begin(), A.end());
            for (int i = 0; i < A.size() - 1; ++i)
                if (A[i] == A[i + 1].substr(0, A[i].size()))
                {
                    flag = true;
                    break;
                }
            
            cout << "Set " << c++ << " is " << (flag ? "not " : "") << "immediately decodable\n";
            flag = false;
            A.clear();
            continue;
        }

        A.push_back(s);
    }
}
