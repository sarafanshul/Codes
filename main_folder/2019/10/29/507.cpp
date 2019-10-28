#include <iostream>
#include <vector>
#include <tuple>
using namespace std;

typedef vector<int> vi;
typedef tuple<int, int, int> iii;
typedef vector<iii> viii;

bool cmp(iii lhs, iii rhs)
{
	int a, b, c, d, e, f;
	tie(a, b, c) = lhs; tie(d, e, f) = rhs;
	return c > f || c == f && b - a > e - d || c == f && b - a == e - d && a < d;
}

int main()
{
	int T, b;
	cin >> T;
	for (int no = 1; no <= T; ++no)
	{
		cin >> b; --b;
		vi A(b);
		for (int i = 0; i < b; ++i)
			cin >> A[i];
		
		int max = A[0], ind = 0;
		viii S; //(starting index, ending index, sum of niceness)
		// Concatenate + and - blocks together
		S.emplace_back(0, 1, A[0]);
		bool flag = A[0] >= 0;
		for (int i = 1; i < b; ++i)
		{
			if (A[i] >= 0 == flag)
				get<1>(S.back())++, get<2>(S.back()) += A[i];
			else			
				flag = !flag, S.emplace_back(i, i + 1, A[i]);				
			
			if (cmp(S.back(), S[ind]))
					max = get<2>(S.back()), ind = S.size() - 1;			
		}
				
		if (max <= 0)
			cout << "Route " << no << " has no nice parts\n";
		else
		{
			// Go to the left and right if the route can be improved
			int sum = 0;
			for (int i = ind + 2; i < S.size(); i = i + 2)
			{
				sum += get<2>(S[i]) + get<2>(S[i - 1]);
				if (sum >= 0)
					get<1>(S[ind]) = get<1>(S[i]), sum = 0;
			}
			
			sum = 0;
			for (int i = ind - 2; i >= 0; i = i - 2)
			{
				sum += get<2>(S[i]) + get<2>(S[i + 1]);
				if (sum >= 0)
					get<0>(S[ind]) = get<0>(S[i]), sum = 0;
			}
			
			cout << "The nicest part of route " << no << " is between stops " << get<0>(S[ind]) + 1 << " and " << get<1>(S[ind]) + 1 << "\n";
		}		
	}
}
