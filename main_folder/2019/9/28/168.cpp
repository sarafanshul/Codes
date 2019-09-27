#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int main()
{
	string s;
	char M, T;
	long k;
	while (cin >> s, s != "#")
	{
		string G[26];
		s.pop_back();
		istringstream iss(s);
		string str;
		while(getline(iss, str, ';') && !iss.eof())
			if (str.size() > 2) 
				G[str[0] - 'A'] = str.substr(2, -1);
		
		if (str.size() > 2) 
			G[str[0] - 'A'] = str.substr(2, -1);
		cin >> M >> T >> k;
		
		int B[26] = {}; //Bitset of forbidden squares
		B[T - 'A'] = 1;  //Hunter's cavern
		int cave = M - 'A', it = 0, cnt = 1, run;
		while (it < G[cave].size() && B[G[cave][it] - 'A'])
			++it;
		
		bool flag = true;
		if (it == G[cave].size())
				flag = false;
		else
		{
			run = G[cave][it] - 'A';
			B[T - 'A'] = 0;  //Hunter is missing
		}
		
		while (flag)
		{
			//cout << "From: " << cave << " to " << run << endl;
			it = 0;
			if (cnt == k)
				B[cave] = 2, cout << char(cave + 'A') << ' ';
			cnt = cnt % k + 1;	
			
			if (B[cave] < 2)
				B[cave] = 1; //No coming back!
			while (it < G[run].size() && B[G[run][it] - 'A'])
				++it;

			if (it == G[run].size())
				break;
			
			if (B[cave] < 2)
				B[cave] = 0;
			cave = run;
			run = G[run][it] - 'A';	
		}
		cout << '/' << char((!flag ? cave : run) + 'A') << '\n';
	}
}
