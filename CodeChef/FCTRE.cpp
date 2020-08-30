#pragma GCC optimize("O3")
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(),(v).end()
#define lb lower_bound
#define mp make_pair
#define eb emplace_back
#define fi first
#define se second

using pii = pair<int, int>;
using ll = long long;
using ppi = pair<pii, pii>;
const int N = 1e6 + 10;
const int kMod = 1e9 + 7;
int n, q, LOGN, sqrtN, T;
int least[N];
vector<vector<int>> adj, Path;
vector<int> depth, here, there, arr, val;
vector<int> primes(N, 0);
vector<vector<pii>> factors;


struct customInt {
	long long n;
	customInt(long long n = 0) : n(n % kMod) {}
	customInt operator+(const customInt& oth) { return n + oth.n; }
	customInt operator-(const customInt& oth) { return n - oth.n; }
	customInt operator*(const customInt& oth) { return n * oth.n; }
	long long get() { return n < 0 ? n + kMod : n; }
};


customInt lnPw(customInt b) {
	int e = -1;
	if (b.get() == 0) return 0;
	customInt r; 
	e = e % (kMod - 1);
	if (e < 0) e += kMod - 1;
	for (r = 1; e; e >>= 1, b = b * b) if (e & 1) r = r * b;
	return r;
}


vector<customInt> inv(N);
customInt curr = 1;

bool compare(ppi& a, ppi& b) {
	int ak = 1 + ((a.fi.fi - 1) / (sqrtN + 1));
	int bk = 1 + ((b.fi.fi - 1) / (sqrtN + 1));
	if (ak != bk) return ak < bk;
	else if (a.fi.se != b.fi.se) return a.fi.se < b.fi.se;
	else return a.fi.fi < b.fi.fi;
}

void sieve() {
	for (int i = 2; i < N; i += 2)
		least[i] = 2;
	for (int i = 3; i < N; i += 2) {
		if (least[i]) continue;
		least[i] = i;
		if (N / i < i) continue;
		int j = i * i;
		while (j < N) least[j] = i, j += i;
	}
}

void lnPwcreate(){
	for (int i = 0; i < N; i++) inv[i] = lnPw(i);
}

void recycle() {
	adj.clear(); 
	Path.clear(); 
	arr.clear(); 
	factors.clear();
	here.clear(); 
	there.clear(); 
	depth.clear(); 
	val.clear();
	adj.resize(n);
	Path.resize(n, vector<int>(LOGN));
	depth.resize(n);
	here.resize(n);
	there.resize(n);
	factors.resize(n);
	arr.resize(2 * n);
	primes.assign(N, 0);
	val.assign(n, 0);
}

void dfs(int v, int pr = -1) {
	Path[v][0] = pr;
	here[v] = T++;
	for (int u : adj[v]) {
		if (u == pr) continue;
		depth[u] = depth[v] + 1;
		dfs(u, v);
	}
	there[v] = T++;
}

int lowestAnc(int p, int q) {
	if (depth[p] < depth[q]) swap(p, q);
	for (int i = LOGN - 1; i >= 0; i--)
		if (depth[p] - depth[q] >= (1 << i))
			p = Path[p][i];
	if (p == q)	return p;
	for (int i = LOGN - 1; i >= 0; i--)
		if (Path[p][i] != -1 && Path[p][i] != Path[q][i])
			p = Path[p][i], q = Path[q][i];
	return Path[p][0];
}

void update(int pos, int c , bool optn = true) {
	val[arr[pos]] += c;
	if (val[arr[pos]] == 2 && c == 1) c = -1;
	if (val[arr[pos]] == 1 && c == -1) c = 1;
	if (!optn) return;
	for (pii pi : factors[arr[pos]]) {
		curr = curr * inv[primes[pi.fi] + 1];
		primes[pi.fi] += c * pi.se;
		curr = curr * (primes[pi.fi] + 1);
	}
}

void queries(){
	vector<ll> ans(q);
	vector<ppi> pathbtwn(q);
	int x;
	for (int i = 0; i < q; i++) {
		int u, v;
		cin >> u >> v;
		u--; v--;
		if (here[u] > here[v]) swap(u, v);
		int pr = lowestAnc(u, v);
		x = pr;
		pii p1, p2;
		if (u == pr) {
			p1 = mp(here[u], here[v]);
			p2 = mp(-1, i);
		} else {
			p1 = mp(there[u], here[v]);
			p2 = mp(here[pr], i);
		}
		pathbtwn.eb(mp(p1, p2));
	}
	sort(all(pathbtwn), compare);

	int L = 0, R = -1;
	int l ,r ,pr ,id ,mr ;
	ll mx = 0;
	customInt tmp;
	for (ppi p : pathbtwn) {
		l = p.fi.fi;
		r = p.fi.se;
		pr = p.se.fi; 
		id = p.se.se;
		mr = min(r ,pr);
		while (R < r) update(++R, 1);
		while (L < l) update(L++, -1);
		while (L > l) update(--L, 1);
		while (R > r) update(R--, -1);
		tmp = curr;
		if (pr != -1) {
			for (pii pi : factors[arr[pr]]) {
				tmp = tmp * inv[primes[pi.fi] + 1];
				tmp = tmp * (primes[pi.fi] + pi.se + 1);
			}
		}
		ans[id] = tmp.get();
		mx = max(ans[id] ,mx);
	}
	for (ll i : ans) cout << i << "\n";
}

void createDP(bool ref = false){
	for (int j = 1; j < LOGN; j++)
		for (int i = 0; i < n; i++)
			if (Path[i][j - 1] != -1) Path[i][j] = Path[Path[i][j - 1]][j - 1];

	if (ref){
		for (int i = 0; i < n; i++)
			arr[here[i]] = arr[there[i]] = i;}
}

void solve() {
	cin >> n;
	T = 0; curr = 1;
	int j = 0;
	ll nds = -1, u, v ,mu = 0 ,mv = 0;
	for (; (1 << j) < n; j++);
	LOGN = j;
	j = sqrt(2 * n);
	sqrtN = j;
	recycle();

	for (int i = 1; i < n; i++) {
		cin >> u >> v;
		adj[--u].eb(--v);
		adj[v].eb(u);
		mu = min(u ,mu);
		mv = min(v ,mv);
	}

	ll num; 
	for (int i = 0; i < n; i++) {
		cin >> num;
		while (num > 1) {
			int p = least[num], cnt = 0;
			while (num % p == 0) num /= p, cnt++;
			factors[i].eb(mp(p, cnt));
		}
	}
	depth[0] = 0; 
	dfs(0);
	createDP(true);
	cin >> q;
	queries();
	
}

void blah(){
	sieve();
	lnPwcreate();
	int t; 
	cin >> t;
	while (t--) solve();
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	blah();
} 