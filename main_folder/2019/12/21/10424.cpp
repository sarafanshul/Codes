#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

void ReduceToOne(int &a)
{
	while (a > 9)
	{
		int res = 0;
		while (a > 0)
		{
			res += a % 10;
			a /= 10;
		}
		a = res;
	}
}

int main()
{
	string s, t, abc; 
	abc = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	
	while (getline(cin, s))
	{
		getline(cin, t);
		string a, b;
		for (int i = 0; i < s.size(); ++i)
			if (abc.find_first_of(string(1,s[i])) != string::npos )
				a.append(1, s[i]);
		for (int i = 0; i < t.size(); ++i)
			if (abc.find_first_of(string(1,t[i])) != string::npos )
				b.append(1, t[i]);
		
		transform(a.begin(), a.end(), a.begin(), [](unsigned char c){return tolower(c);});
		transform(b.begin(), b.end(), b.begin(), [](unsigned char c){return tolower(c);});
		//a-z ... 97-122
		int sumA = 0, sumB = 0;
		for (char let : a)
			sumA += let - 96;
		for (char let : b)
			sumB += let - 96;
			
		ReduceToOne(sumA);
		ReduceToOne(sumB);
		
		if (sumA == 0 && sumB == 0)
		{
			cout << '\n';
			continue;
		}
		
		float ratio = (sumA < sumB ? float(sumA) / sumB : float(sumB) / sumA) * 100;
		cout.precision(2);
		
		cout << fixed << ratio << " %\n";		
	}
	
	return 0;
}
