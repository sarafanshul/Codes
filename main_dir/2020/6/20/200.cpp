#include <iostream>
#include <queue>
#include <string> 
#include <vector>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

void kahn(vvi& AdjList, vi& IND, vi& seen)
{
    queue<int> Q;
    for (int i = 0; i < IND.size(); ++i)
		if (seen[i] && IND[i] == 0)
			Q.push(i);

    while (!Q.empty())
	{
		int x = Q.front(); Q.pop();
        cout << char(x + 'A');
		for (int y : AdjList[x])
			if (--IND[y] == 0)
				Q.push(y);
	}
}

int main()
{
    string s, t;

    while (cin >> s >> t)
    {
        vvi AdjList(26);
        vi IND(26, 0), seen(26, 0);
        if (t == "#")
        {
            cout << s << "\n";
            continue;
        }

        for (char c : s)
            seen[c - 'A'] = 1;
    
        while (t != "#")
        {
            for (char c : t)
                seen[c - 'A'] = 1;
            int it = 0;
            while (it < min(s.size(), t.size()))
            {
                if (s[it] != t[it])
                {
                    AdjList[s[it] - 'A'].push_back(t[it] - 'A');
                    ++IND[t[it] - 'A'];
                    break;
                }
                ++it;
            }

            s = t;
            cin >> t;
        }

        kahn(AdjList, IND, seen);
        cout << "\n";
    }
}
