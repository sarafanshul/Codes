#include <algorithm>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
vector<string> res;
vi V;
vvi G;

void dfs(int curr, vi inD, string s)
{
    inD[curr]--;

    if (count(inD.begin(), inD.end(), -1) == V.size())
        res.push_back(s);
    
    for (int i = 0; i < G[curr].size(); ++i)
        --inD[G[curr][i]];

    for (int v : V)
        if (inD[v] == 0)
            dfs(v, inD, s + " " + string(1, v + 'A'));
}

int main()
{
    int T;
    cin >> T;
    cin.ignore();
    while (T--)
    {
        cin.ignore();
        G.assign(26, vi());
        V.clear();
        
        string s, cmp;
        getline(cin, s);
        istringstream iss(s);
        char c;

        while (iss >> c)
            V.push_back(c - 'A');

        getline(cin, s);
        iss.clear(); iss.str(s);

        vi inD(26);
        while (iss >> cmp)
        {
            G[cmp[0] - 'A'].push_back(cmp[2] - 'A');
            inD[cmp[2] - 'A']++;
        }

        res.clear();
        for (int v : V)
            if (inD[v] == 0)
                dfs(v, inD, string(1, v + 'A'));

        sort(res.begin(), res.end());
        for (string& r : res)
            cout << r << '\n';

        if (res.empty())
            cout << "NO\n";

        if (T)
            cout << '\n';
    }
}
