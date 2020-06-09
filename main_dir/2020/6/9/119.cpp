#include <iostream>
#include <cstring>
#include <vector>
#include <map>
#include <string>
using namespace std;

int main()
{
	int n; 
	bool first = true;
	while (cin >> n)
	{
		if (!first)
			cout << "\n";
		first = false;
		
		map<string, int> N;
		vector<string> Names(10);
		int A[10], B[10];
		memset(A, 0, 10 * sizeof(int));
		memset(B, 0, 10 * sizeof(int));
		for (int i = 0; i < n; ++i)
		{
			string s;
			cin >> s;
			Names[i] = s;
			N[s] = i;
		}
		for (int i = 0; i < n; ++i)	
		{
			string s;
			int q, gift, fond;
			cin >> s >> fond >> q;
			A[N[s]] += fond;
			B[N[s]] += fond;	
			
			gift = ( q == 0 ? 0 : fond / q);
			A[N[s]] -= gift * q;
			for (int j = 0; j < q; ++j)
			{
				cin >> s;
				A[N[s]] += gift;
			}
		}
		
		for (int c = 0; c < n; ++c)
			cout << Names[c] << " " << A[c] - B[c] << "\n";
		
	}
	
}
