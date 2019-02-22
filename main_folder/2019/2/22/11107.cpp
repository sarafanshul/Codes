#include <algorithm>
#include <bitset>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> vi;
typedef vector<string> vs;

struct suffix
{
    int index;
    int rank[2];
};

int cmp(suffix a, suffix b)
{
    return a.rank[0] < b.rank[0] ? 1 : (a.rank[0] == b.rank[0] ? a.rank[1] < b.rank[1] : 0);
}

vi buildSA(string& txt)
{
    // Build suffix array in O(n * log n * log n)
    int n = txt.size();
    suffix sfxs[n];
    for (int i = 0; i < n; ++i)
    {
        sfxs[i].index = i;
        sfxs[i].rank[0] = txt[i];
        sfxs[i].rank[1] = i + 1 < n ? txt[i + 1] : -1;
    }

    sort(sfxs, sfxs + n, cmp);
    // Now the suffixes are sorted according to the first 2 characters.
    // Let us sort the suffixes according to the first k characters...
    
    int ind[n];
    for (int k = 4; k < 2 * n; k *= 2)
    {
        int rank = 0;
        int prev_rank = sfxs[0].rank[0];
        sfxs[0].rank[0] = rank;
        ind[sfxs[0].index] = 0;

        // Assigning rank to suffixes
        for (int i = 1; i < n; ++i)
        {
            if (sfxs[i].rank[0] == prev_rank && sfxs[i].rank[1] == sfxs[i - 1].rank[1])
                sfxs[i].rank[0] = rank;
            else
            {
                prev_rank = sfxs[i].rank[0];
                sfxs[i].rank[0] = ++rank;
            }

            ind[sfxs[i].index] = i;
        }

        // Assigning next rank to suffixes
        for (int i = 0; i < n; ++i)
        {
            int next_idx = sfxs[i].index + k / 2;
            sfxs[i].rank[1] = next_idx < n ? sfxs[ind[next_idx]].rank[0] : -1;
        }

        // Sort the suffixes according to the first k characters
        sort (sfxs, sfxs + n, cmp);
    }

    // Generate suffix array
    vi SA(n);
    for (int i = 0; i < n; ++i)
        SA[i] = sfxs[i].index;

    return SA;
}

vi computeLCP(vi& SA, string& txt)
{
    // Lowest common prefix between consecutive suffixes in SA order
    int i, L, n = SA.size();
    vi Phi(n), PLCP(n);
    Phi[SA[0]] = -1;
    for (i = 1; i < n; ++i)
        Phi[SA[i]] = SA[i - 1]; // Remember which suffix is before this suffix
    for (i = L = 0; i < n; ++i)
    {
        if (Phi[i] == -1){ PLCP[i] = 0; continue; }
        
        while (txt[i + L] == txt[Phi[i] + L] && txt[i + L] != '$')
            ++L;
        
        PLCP[i] = L;
        L = max(L - 1, 0); // The point: we use the fact the the suffixes are traversed in initial order
                           // e.g. if 'anana' and 'ana' had 3 common chars, 'nana' and its consecutive
                           // will have at least 2 common chars
    }

    vi LCP(n);
    for (i = 0; i < n; ++i)
        LCP[i] = PLCP[SA[i]]; // Put the permuted LCP to the correct position
    return LCP;
}

vi owners(vs& dna, vi& SA)
{
    // Determines the owner of each suffix
    vi O(SA.size());
    for (int i = 0; i < SA.size(); ++i)
    {
        int v = SA[i];
        int p = 0, acc = -1;
        while (v > acc)
            acc += dna[p++].size() + 1;
        O[i] = p - 1;
    }

    return O;
}

vi check(vi& SA, vi& LCP, vi& O, int m, int h)
{
    // Checks if at least h suffixes have a common suffix of length (at least) m
    // Returns a vector of suffix indices (of suffixes that are in h+ other suffixes)
    vi r;
    bitset<100> b;
    for (int i = 1; i < LCP.size(); ++i)
    {
        if (LCP[i] < m)
        {
            b.reset();
            continue;
        }

        b[O[i]] = b[O[i - 1]] = true;
        if (b.count() == h)
            r.emplace_back(SA[i]);
    }

    return r;
}

vi bs(vi& SA, vi& LCP, vi& O, int h, int& l)
{
    // Binary search the LCS of at least h substrings and save it in l
    vi r;
    int u = *max_element(LCP.begin(), LCP.end()) + 1;
    l = 1;

    while (l != u)
    {
        int m = (l + u) / 2;
        r = check(SA, LCP, O, m, h);
        if (r.empty())
            u = m;
        else
            l = m + 1;
    }

    --l;
    if (l)
        r = check(SA, LCP, O, l, h);
    return r;
}

int main()
{
    int n, c = 0;
    while (cin >> n, n)
    {
        if (c++)
            cout << '\n';
        
        vs dna(n);
        string s;
        for (int i = 0; i < n; ++i)
            cin >> dna[i], s += dna[i] + "$";

        if (n == 1)
        {
            cout << dna[0] << '\n';
            continue;
        }
        
        vi SA = buildSA(s);
        vi LCP = computeLCP(SA, s);
        vi O = owners(dna, SA);
        int len;
        vi r = bs(SA, LCP, O, n / 2 + 1, len);
        if (r.empty())
        {
            cout << "?\n";
        }
        else
        {
            string last;
            for (int ind : r)
            {
                string tmp = s.substr(ind, len);
                if (tmp == last) // Skip duplicates
                    continue;
                cout << tmp << '\n';
                last = tmp;
            }
        }
     }
}
