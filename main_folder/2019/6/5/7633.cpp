#include <algorithm>
#include <iostream>
#include <string> 
using namespace std;

string sol[21] = {"1", "64", "729", "4096", "15625", "46656", "117649", "262144", "531441", "1000000",
                "1771561", "2985984", "4826809", "7529536", "11390625", "16777216", "24137569",
                "34012224", "47045881", "64000000", "85766121"};

int main()
{
    string s;
    while (cin >> s, s != "0")
        if (find(sol, sol + 21, s) != sol + 21)
            cout << "Special\n";    
        else
            cout << "Ordinary\n";

}
