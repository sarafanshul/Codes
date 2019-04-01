#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
	int n, m, price;
	cin >> n;
	
	while (n--)
	{			
		cin >> m;
		
		vector<string> A(m);
		vector<int> L(m), H(m);
		for (int i = 0; i < m; ++i)
			cin >> A[i] >> L[i] >> H[i];
			
		cin >> m;
		for (int i = 0; i < m; ++i)
		{
			cin >> price;
			int cnt = 0, ind;
			for (int j = 0; j < A.size(); ++j)
				if (price >= L[j] && price <= H[j])
					++cnt, ind = j;
			
			cout << (cnt == 1 ? A[ind] + "\n" : "UNDETERMINED\n");
		}
		
		if (n)
			cout << "\n";
	}
}
