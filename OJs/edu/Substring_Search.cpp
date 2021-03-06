// https://codeforces.com/edu/course/2/lesson/2/2

// O(NlogN)
// using counting sort

#include <bits/stdc++.h>

using namespace std;

void count_sort(vector<int> &p ,vector<int> &c){
	int n = p.size();
	// counting sort twice
	{
		vector<int> cnt(n);
		for (auto x: c){
			cnt[x]++;
		}
		vector<int> p_new(n);
		vector<int> pos(n);
		pos[0] = 0;
		for(int i = 1; i <n ;i++){
			pos[i] = pos[i-1] + cnt[i-1];
		}
		for (auto x : p){
			int i = c[x];
			p_new[pos[i]] = x;
			pos[i]++;
		}
		p = p_new;
	}
}

int main(){
	string s ,s1;
	cin >> s;
	s1 = s;
	s += "$";
	int n = s.size();
	vector<int> p(n) ,c(n);
	{
		// k = 0
		vector<pair<char ,int>> a(n);
		// save characters and positions then sort
		for (int i = 0; i < n ; i++) a[i] = {s[i] ,i};
		sort(a.begin() ,a.end());

		// save array [p]
		for (int i = 0; i < n; ++i) p[i] = a[i].second;
		// create array [c]
		c[p[0]] = 0;
		for(int i = 1 ; i < n; ++i){
			if (a[i].first == a[i-1].first) {
				c[p[i]] = c[p[i-1]];
			} else {
				c[p[i]] = c[p[i-1]] + 1;
			}
		}
	}
	// now transitions of k
	int k = 0;
	while ((1<<k) < n){
		// k -> K + 1
		
		for(int i = 0 ; i< n ;i++){
			p[i] = (p[i] - (1<<k) + n) % n;
		}

		count_sort(p ,c);
		
		vector<int> c_new(n);
		c_new[p[0]] = 0;
		for(int i = 1 ; i < n; ++i){
			pair<int ,int> prev = {c[p[i - 1]] ,c[(p[i - 1] + (1<<k)) % n]};
			pair<int ,int> now = {c[p[i]] ,c[(p[i] + (1<<k)) % n]};
			if (now == prev) {
				c_new[p[i]] = c_new[p[i-1]];
			} else {
				c_new[p[i]] = c_new[p[i-1]] + 1;
			}
		}
		c = c_new;
		k++;
	}
	// testing
	// for (int i = 0; i < n ; ++i){
		// cout << p[i] << " " << s.substr(p[i] ,n - p[i]) << "\n";  
		// cout << p[i] << "\n"; 
	// }
	int t = 0;
	cin >> t ;
	vector<int> p_temp(n);
	while( t-- ){
		string q;
		cin >> q;
		int n1 = q.size();
		string temp ;
		int l = 0 ,r = n ,mid;
		bool flag = true;
		while (l < r){
			mid = (l+r)/2;
			temp = s1.substr(p[mid] ,n1);
			// cout << " -- "<< p[mid] << "  " << p[mid] + n1 << " " << temp<< " \n";
			int ck = q.compare(temp);
			// cout << mid << "  " << temp << " " << q <<"  "<< ck << " \n";
			if (ck > 0) l = mid + 1;
			else if (ck == 0){
				cout << "Yes" << "\n";flag = false;
				break;
			}
			else r = mid;
		}
		if (flag) cout << "No" << "\n";
	}
}
