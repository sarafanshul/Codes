#include <iostream>
#include <algorithm>
#include <utility>
#include <tuple>
#include <vector>
using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef tuple<int, int, int> iii;
typedef vector<iii > viii;

#define MP make_pair

bool comparator(iii a, iii b)
{
	if (get<0>(a) > get<0>(b))
		return true;
	else if (get<0>(a) < get<0>(b))
		return false;
	else if (get<1>(a) < get<1>(b))
		return true;
	else if (get<1>(a) > get<1>(b))
		return false;
	else 
		return get<2>(a) < get<2>(b);
}

int main()
{
	int n;
	cin >> n;
	while (n--)
	{
		viii Res;
		vector <vii> A(100);
		for (int i = 0; i < 100; ++i)
			A[i] = vii(10, MP(0, 0)); //[1 = AC 2 = Tried, Time]
			
		do 
		{
			int team, problem, time;
			char verdict;
			cin >> team >> problem >> time >> verdict;
			cin.ignore();
			
			if (A[team - 1][problem - 1].first != 1) //If not yet solved
			{
				if (verdict == 'C')
				{
					A[team - 1][problem - 1].second += time;
					A[team - 1][problem - 1].first = 1;
				}
				else if (verdict == 'I')
				{
					A[team - 1][problem - 1].second += 20; //Penalty
					A[team - 1][problem - 1].first = 2;	
				}
				else
					A[team - 1][problem - 1].first = 2;			
			}
		} while (cin.peek() != '\n' && cin.peek() != EOF);
		
		//Filter out teams w/o submit and count AC's
		for (int i = 0; i < 100; ++i)
			if (any_of(A[i].begin(), A[i].end(), [](ii x){return x.first > 0;}))
			{
				Res.emplace_back(0, 0, i + 1);
				for (int j = 0; j < 10; ++j)
					if (A[i][j].first == 1)
					{
						get<0>(Res[Res.size() - 1])++;
						get<1>(Res[Res.size() - 1]) += A[i][j].second;
					}
			}		
			
		sort(Res.begin(), Res.end(), comparator);
		for (iii elem : Res)
			cout << get<2>(elem) << ' ' << get<0>(elem) << ' ' << get<1>(elem) << '\n';	
		if (n > 0)
			cout << '\n';
	}
}
