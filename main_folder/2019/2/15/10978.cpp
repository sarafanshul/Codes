#include <iostream>
#include <string>
#include <bitset>
#include <algorithm>
using namespace std;

int main()
{
	int N;
	while (cin >> N, N != 0)
	{
		string res[N];
		int curr = 0;
		bitset<52> B; //(in)valid indices
		
		for (int i = 0; i < N; ++i)
		{
			string card, card_name;
			cin >> card >> card_name;
			
			for (int j = 0; j < card_name.size(); ++j)
			{				
				while (B[curr])
					curr = (curr + 1) % N;
				curr = (curr + 1) % N;
			}
			int ind = curr - 1 < 0 ? N - 1 : curr - 1;
			B.set(ind);
			res[ind] = card;
		}
		
		for (int k = 0; k < N; ++k)
			cout << res[k] << (k == N - 1 ? '\n' : ' ');
	}
}
