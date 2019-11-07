#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	int N;
	cin >> N;
	
	for (int it = 0; it < N; ++it)
	{
		if (it)
			cout << '\n';
		
		int n, w, nr;
		cin >> n >> w;
		int A[n];
		memset(A, 0, n * sizeof(int));
		//0 = ?, 1 = potencijalno lakša, 2 = potencijalno teža, 3 = ista
		
		for (int i = 0; i < w; ++i)
		{
			cin >> nr;
			int C[2 * nr];
			for (int j = 0; j < 2 * nr; ++j)
				cin >> C[j];
				
			char s, S[2] = {'<', '>'};
			cin >> s;
			
			if (s == '=')
				for (int c : C)
					A[c - 1] = 3;
			for (int k = 0; k < 2; ++k) 
				if (s == S[k]) 	//s == < ili s == >
					for (int j = 0; j < 2 * nr; ++j)
						if (A[j] == 0 && j < nr)
							A[j] = (k ? 2 : 1);
						else if (A[j] == 0 && j >= nr)
							A[j] = (k ? 1 : 2);
		}
				
		int index = -1, flag = 0;
		for (int k = 0; k < n; ++k)
			if (A[k] == 2 || A[k] == 1 || A[k] == 0)
				index = k + 1, flag++;
		
		if (flag == 1)
			cout << index << "\n";
		else
			cout << 0 << "\n";
	}	
}
