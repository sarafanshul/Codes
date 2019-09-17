#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	vector<string> S(16);
	for (int i = 0; i < 16; ++i)
	{
		if (i % 4 == 0)
			S[i] = "Happy\n";
		else if (i % 4 == 1)
			S[i] = "birthday\n";
		else if (i % 4 == 2)
			S[i] = "to\n";
		else if (i != 11)
			S[i] = "you\n" ;
		else
			S[i] = "Rujia\n";
	}
	
	int n;
	cin >> n;
	vector<string> N(n);
		
	for (int i = 0; i < n; ++i)
		cin >> N[i];
	
	int L = n / 16 + 1;
	for (int i = 0; i < L * 16; ++i)
		cout << N[i % n] << ": " << S[i % 16];
	
	
	return 0;
}
