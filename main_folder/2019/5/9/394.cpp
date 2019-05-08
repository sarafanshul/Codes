#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>
#include <iterator>
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

#define MP make_pair

int main()
{
	int n, r;
	cin >> n >> r;
	vector<string> N(n);
	vi B(n,0);
	vi Cd(n,0);
	vi Dim(n,0);
	vector<vii> Bounds;
	
	for (int i = 0; i < n; ++i)
	{
		cin >> N[i] >> B[i] >> Cd[i] >> Dim[i];
		vii tmp;
		for (int j = 0; j < Dim[i]; ++j)
		{
			int l, d;
			cin >> l >> d;
			tmp.push_back(MP(l, d));
		}
		Bounds.push_back(tmp);
	}
	
	while (r--)
	{
		string name;
		cin >> name;
		vector<string>::iterator it = find(N.begin(), N.end(), name);
		int ind = distance(N.begin(), it);
		vi Q(Dim[ind],0);
		
		for (int i = 0; i < Q.size(); ++i)
			cin >> Q[i];
		
		int D = Dim[ind];
		vi C(D,0);
		C[D - 1] = Cd[ind];
		int res = B[ind] - Cd[ind] * Bounds[ind][D - 1].first;
		
		for (int i = C.size() - 2; i >= 0; --i)
		{
			C[i] = C[i + 1] * (Bounds[ind][i+1].second - Bounds[ind][i+1].first + 1);
			res -= C[i] * Bounds[ind][i].first;
		}
		
		string out = N[ind] + "[";
		
		for (int i = 0; i < D; ++i)
		{
			res += C[i] * Q[i];
			out += to_string(Q[i]) + ", ";
		}
		
		out.pop_back(); out.pop_back();		
		cout << out << "] = " << res << '\n';	
	}	
}
