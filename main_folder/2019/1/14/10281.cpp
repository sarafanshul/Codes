#include <iostream>
#include <ios>
#include <string>
using namespace std;

int main()
{
	cout.precision(2);
	string s;
	double v = 0, sum = 0, t1 = 0, t2  = 0;
	while (getline(cin, s))
	{
		t1 = t2;
		t2 = stoi(s.substr(0, 2)) + stoi(s.substr(3, 5)) / 60.0 + stoi(s.substr(6, 8)) / 3600.0;
		sum += v * (t2 - t1);
		
		if (s.size() > 9)
			v = stoi(s.substr(9));
		else
			cout << fixed << s + " " << sum << " km\n";		
	}
}
