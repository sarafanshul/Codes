#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
vector<char> A(20);
vector<string> sol;

void f(int n, map<char, int>& M, vvi G, vi inD, string str)
{
	if (count(inD.begin(), inD.end(), -1) == n)
	{
		sol.push_back(str);
		return;
	}
	
	for (int i = 0; i < n; ++i)
		if (inD[i] == 0)
		{
			vi recInD(inD);
			vvi recG(G);
			recInD[i] = -1;
			for (int j = 0; j < n; ++j)
				if (recG[i][j] && recInD[j] > 0)
				{
					recInD[j]--;
					recG[i][j] = 0;
				}
						
			f(n, M, recG, recInD, str + string(1, A[i]));
		}
}

int main()
{
	string s;
	while (getline(cin, s))
	{
		if(!sol.empty())
			cout << "\n";
		
		map<char, int> M;
		A.assign(20, '*');
		int n = 0;
		char a, b;
		vvi G(20, vi(20, 0));
		vi inD(20, 0);
		
		istringstream iss(s);
		while (iss >> a)
		{
			A[n] = a;
			M[A[n]] = n;
			++n;
		}
			
		getline(cin, s);
		iss.clear();
		iss.str(s);
		while (iss >> a >> b)
		{
			G[M[a]][M[b]] = 1;
			inD[M[b]]++;
		}
		
		sol.clear();
		f(n, M, G, inD, "");
		sort(sol.begin(), sol.end());
		for (string str : sol)
			cout << str + string("\n");
	}
	
}
