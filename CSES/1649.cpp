#include <bits/stdc++.h>
using namespace std;

struct segtree {
	int size;
	vector<long long> mins;

	void init(int n){
		size = 1;
		while (size < n) size *= 2;
		mins.assign(2*size , LLONG_MAX);
	}

	long long min(long long a ,long long b){
		return (a < b) ? a : b;
	}

	void build(vector<int> &a ,int x ,int lx ,int rx){
		if(rx - lx == 1){
			if (lx < (int)a.size()) mins[x] = a[lx];
			return;
		}
		int m = (lx +rx) / 2;
		build(a ,2*x + 1 ,lx ,m);
		build(a ,2*x + 2 ,m ,rx);
		mins[x] = min(mins[2*x + 1] , mins[2*x + 2]);
	}

	void build(vector<int> &a){
		build(a ,0 ,0 ,size);
	}

	void set(int i ,int v ,int x ,int lx ,int rx){
		if (rx - lx == 1){
			mins[x] = v;
			return;
		}
		int m = (lx + rx) /2;
		if (i < m) set (i ,v ,2*x + 1 ,lx ,m);
		else set(i ,v ,2*x + 2 ,m ,rx);
		mins[x] = min(mins[2*x + 1] , mins[2*x + 2]);
	}

	void set(int i  ,int v){
		set(i ,v ,0  ,0 ,size);
	}

	long long _min(int l ,int r , int x ,int lx ,int rx){
		// 3 cases
		if (lx >= r || l >= rx) return LLONG_MAX;
		if (lx >= l && rx <= r) return mins[x];
		int m = (lx + rx)/2;
		long long s1 = _min(l ,r ,2*x + 1 ,lx ,m);
		long long s2 = _min(l ,r ,2*x + 2 ,m ,rx);
		return min(s1 ,s2);  
	}

	long long _min(int l ,int r){
		return _min(l ,r ,0 ,0 ,size);
	}
};

int main(){
	ios::sync_with_stdio(false);

	int n , m ;
	cin  >> n >> m;

	segtree st;
	st.init(n);
	vector<int> a(n);

	for (int  i = 0; i < n; i++) cin >> a[i];

	st.build(a);

	while (m-- ){
		int op;
		cin >> op;
		if (op == 1){
			int i ,v;
			cin >> i >> v;
			st.set(i-1 ,v);
		} else {
			int l ,r;
			cin >> l >> r;
			cout << st._min(l-1 ,r) << "\n";
		}
	}

	return 0;
}
