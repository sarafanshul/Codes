#include <iostream>
#include <vector>
#include <stack>
#include <utility>
#include <cmath>
#include <algorithm>
#include <string>
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<ii, int> iii;
#define MP make_pair

int low_bound(int c, int a)
{
	//(2n + 1) * c - 5 > a
	return ceil((a + 5.0 - c)/(2 * c));
}

int upp_bound(int c, int b)
{
	//2n * c < b
	return floor(float(b) / (2 * c));
}

int main()
{
	string read;
	int case_nr = 0;
	while (getline(cin, read))
	{
		if (*(read.rbegin()) != ' ')
			read.append(" ");
		vi A;
		A.reserve(10); // signal cycle
		string tmp = "";
		int res = -1;
		for (char c : read)
		{	
			if (c == ' ')
			{	
				A.push_back(stoi(tmp));
				tmp = "";
				continue;
			}
			tmp.append(string(1,c));
		}
		sort(A.begin(), A.end());
		
		//Algorithm
		stack<iii> S; //(begin, end, tier)
		int full = floor(3600.0 / A[0]);
		int a = full % 2 ? --full * A[0] : full * A[0], b = a + A[0]- 5;
		
		while (a >= 2 * A[0]) //Kandidati za presjek iz prvog semafora
		{
			//Treba sačekati da jedan požuti, to će biti prvi (v.49)
			S.push(MP(MP(a,b), 0));
			a -= 2 * A[0];
			b -= 2 * A[0];
		}
		
		while (!S.empty())
		{
			a = S.top().first.first;
			b = S.top().first.second;
			int tier = S.top().second + 1;
			S.pop();
			
			int low = low_bound(A[tier], a);
			int up = upp_bound(A[tier], b);
		
			//Pronađi presjek sa [a,b]
			for (int j = low; j <= up; ++j)
			{
				int aa = max(a, 2 * j * A[tier]);
				int bb = min (b, (2 * j + 1) * A[tier] - 5);
				if (aa < bb && tier == A.size() - 1)
				{
					res = aa;
					goto stop;
				}
				if (aa < bb)
					S.push(MP(MP(aa,bb), tier));
			}
		}		
		
		stop:
		
		if (res != -1 && res <= 3600)
			cout << "Set " << ++case_nr << " synchs again at " << res/60 << " minute(s) and " << res % 60 << " second(s) after all turning green.\n";
		else
			cout << "Set " << ++case_nr << " is unable to synch after one hour.\n";
	}	
}
