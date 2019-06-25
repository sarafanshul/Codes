#include <algorithm> 
#include <cctype>
#include <iostream>
#include <string>
#include <tuple>
#include <vector> 
using namespace std;

int main()
{
    int n;
    cin >> n;
    cin.ignore();
    vector<pair<int, char> > F(26);
    for (int i = 0; i < 26; ++i)
        F[i].second = 'A' + i;
    
    while (n--)
    {
        string s;
        getline(cin, s);
        for (char c : s)
            if (isalpha(c))
                F[toupper(c) - 'A'].first++;                
    }

    sort(F.begin(), F.end(), [](pair<int, char> i, pair<int, char> j){return i.first > j.first || (i.first == j.first && i.second < j.second);});
    for (auto& f : F)
    {
        if (f.first < 1)
            break;
        cout << f.second << ' ' << f.first << '\n';
    }
}
