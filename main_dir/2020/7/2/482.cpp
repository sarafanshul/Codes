#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

typedef vector<int> vi;

int main()
{
	int n, a;
	cin >> n;
		
	while (n--)
	{
		cin.ignore(2);
		string str;
		getline(cin, str);
		vi A;
		istringstream iss(str);
		while (iss >> a)
			A.push_back(a);
				
		vector<string> R(A.size());	
		for (int i = 0; i < A.size(); ++i)
			cin >> R[A[i] - 1];
			
		for (string x : R)	
			cout << x << '\n';
		
		if (n)
			cout << '\n';
	}
}
