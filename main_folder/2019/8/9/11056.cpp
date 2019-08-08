#include <algorithm> 
#include <cctype>
#include <iostream>
#include <string>
#include <tuple>
using namespace std;

struct ci_char_traits;
typedef basic_string<char, ci_char_traits> ci_string;

struct ci_char_traits : public char_traits<char>
{
    static bool eq (char c1, char c2)
    {
        return tolower(c1) == tolower(c2);
    }

    static bool lt (char c1, char c2)
    {
        return tolower(c1) < tolower(c2);
    }

    static int compare (const char*p, const char* q, size_t n)
    {
        while (n--)
        {
            if (!eq(*p, *q))
                return lt(*p, *q) ? -1 : 1;
            ++p; ++q;
        }
        return 0;
    }
};

istream& operator>> (istream& in, ci_string& str)
{
    string tmp;
    in >> tmp;
    str.assign(tmp.begin(), tmp.end());
    return in;
}

int main()
{
    int n, min, sec, ms;

    while (cin >> n)
    {
        pair<int, ci_string> A[100];
        string s;
        for (int i = 0; i < n; ++i)
        {
            cin >> A[i].second >> s >> min >> s >> sec >> s >> ms >> s;
            A[i].first = ms + sec * 1000 + min * 60 * 1000;
        }
        
        sort(A, A + n);
        for (int i = 0; i < n; ++i)
        {
            if (!(i % 2))
                cout << "Row " << i / 2 + 1 << '\n';
            cout << A[i].second.c_str() << '\n';
        }
        cout << '\n';
    }    
}
