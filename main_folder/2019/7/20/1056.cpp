#include <iostream>
#include <vector>

#include <string>
#include <unordered_map>
using namespace std;

typedef vector<int> vi;

int main()
{
	int p, r, net = 0;
	while (cin >> p >> r, p || r)
	{
		vector<vi> A(p, vi(p, 100));
		for (int i = 0; i < p; ++i)
			A[i][i] = 0;
		
		unordered_map<string, int> M;
		string s[2];
		int size = 1;
		for (int i = 0; i < r; ++i)
		{
			cin >> s[0] >> s[1];
			for (int k = 0; k < 2; ++k)
				if (M[s[k]] == 0)
					M[s[k]] = size++;
					
			A[M[s[0]] - 1][M[s[1]] - 1] = 1;
			A[M[s[1]] - 1][M[s[0]] - 1] = 1;
		}
		
		for (int k = 0; k < p; ++k)
			for (int i = 0; i < p; ++i)
				for (int j = 0; j < p; ++j)
					if (A[i][j] > A[i][k] + A[k][j])
						A[i][j] = A[i][k] + A[k][j];
						
		int res = 0;
		for (int i = 0; i < p; ++i)
			for (int j = 0; j < p; ++j)
				res = ::max(res, A[i][j]);
				
		cout << "Network " << ++net << ": "<< (res < 100 ? to_string(res) + "\n\n" : "DISCONNECTED\n\n");
	}	
}
