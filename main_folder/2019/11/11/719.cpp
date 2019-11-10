#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

typedef vector<int> vi;

struct line
{
    int i;
    int rank[2];
};

bool cmp(line a, line b)
{
    return a.rank[0] < b.rank[0] ? 1 :
        (a.rank[0] == b.rank[0] ? a.rank[1] < b.rank[1] : 0);
}

int sa(string& t)
{
    int n = t.size();
    vector<line> lines(n);
    for (int i = 0; i < n; ++i)
    {
        lines[i].i = i;
        lines[i].rank[0] = t[i];
        lines[i].rank[1] = t[(i + 1) % n];
    }
    
    stable_sort(lines.begin(), lines.end(), cmp);

    vi inv(n);
    for (int k = 2; k < n; k *= 2)
    {
        int prev_rank = lines[0].rank[0];
        int rank = lines[0].rank[0] = 0;
        inv[lines[0].i] = 0;

        for (int i = 1; i < n; ++i)
        {
            if (lines[i].rank[0] == prev_rank && lines[i].rank[1] == lines[i - 1]. rank[1])
                lines[i].rank[0] = rank;
            else
                prev_rank = lines[i].rank[0], lines[i].rank[0] = ++rank;

            inv[lines[i].i] = i;
        }

        for (int i = 0; i < n; ++i)
        {
            int next = (lines[i].i + k) % n;
            lines[i].rank[1] = lines[inv[next]].rank[0];
        }

        stable_sort(lines.begin(), lines.end(), cmp);
    }

    return lines[0].i + 1;
}

int main()
{
    int n;
    cin >> n;
    string s;
    while (n--)
    {
        cin >> s;
        cout << sa(s) << '\n';
    }
}
