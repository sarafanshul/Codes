#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

struct node;
string F = "ACGT";
int max_depth, best;
node* res;

struct node
{
    node(char ch) : p(), v(0), c(), let(ch) {}

    node* p;
    node* c[4];
    int v;
    char let;
};

void insert(node* p, string& s, int i)
{
    for (int j = i; j < s.size(); ++j)
    {
        int ind = F.find(s[j]);
        if (!p->c[ind])
        {
            p->c[ind] = new node(F[ind]);
            p->c[ind]->p = p;
        }

        p = p->c[ind];
        ++p->v;
    }
}

void dfs(node* p, int depth)
{
    if (depth > max_depth && p->v > 1)
        res = p, best = p->v, max_depth = depth;

    for (int i = 0; i < 4; ++i)
        if (p->c[i])
            dfs(p->c[i], depth + 1);
}

int main()
{
    int t;
    cin >> t;
    string s;
    while (cin >> s, t--)
    {
        node* r = new node('*');
        for (int i = 0; i < s.size(); ++i)
            insert(r, s, i);

        res = r;
        max_depth = best = 0;
        dfs(r, 0);

        string str;
        while (res->p)
        {
            str += string(1, res->let);
            res = res->p;
        }
        
        reverse(str.begin(), str.end());
        if (best)
            cout << str << ' ' << best << '\n';
        else
            cout << "No repetitions found!\n";
    }
}
