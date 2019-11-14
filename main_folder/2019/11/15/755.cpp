#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <cctype>
using namespace std;

string A[8] = {"ABC", "DEF", "GHI", "JKL", "MNO", "PRS", "TUV", "WXY"};
int B[8] = {'2', '3', '4', '5', '6', '7', '8', '9'};

string clean(string a)
{
	string res;
	for (char c : a)
		if (c != '-')
			res.append(string(1,c));
	return res;
}

string convert(string a)
{
	string res;
	for (char c : a)
	{
		if (isdigit(c))
		{
			res.append(string(1, c));
			continue;
		}
		
		int ind;
		for (int i = 0; i < 8; ++i)
			if (any_of(A[i].begin(), A[i].end(), [c](char x){return x == c;}))
			{
				ind = i;
				break;
			}
		
		res.append(string(1, B[ind]));
	}
	return res;
}

string form(string a)
{
	return a.insert(3, "-");
}

int main()
{
	int N, n;
	cin >> N;
	while (N--)
	{	
		map<string, int> M;
		cin >> n;
		while (n--)
		{	
			string str;
			cin >> str;
			str = clean(str);
			str = convert(str);
			M[str]++;
		}
		
		string res = "";		
		
		for (auto it = M.begin(); it != M.end(); ++it)
			if (it->second > 1)
				res.append(form(it->first) + " " + to_string(it->second) + '\n');
				
		cout << (res == "" ? "No duplicates.\n" : res);
		if (N != 0)
			cout << '\n';
	}
}
