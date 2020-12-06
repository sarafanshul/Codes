#pragma GCC optimize("O3")
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
const int kMod = 998244353;

struct customInt {
	long long n;
	customInt(long long n = 0) : n(n % kMod) {}
	customInt operator+(const customInt& oth) const { return n + oth.n; }
	customInt operator-(const customInt& oth) const { return n - oth.n; }
	customInt operator*(const customInt& oth) const { return n * oth.n; }
	long long get() { return n < 0 ? n + kMod : n; }
};

struct fMOpr {
	customInt x, y ,z;
	fMOpr() {x = 1; y = 4;}
	fMOpr operator+(const fMOpr& oth) const {
		fMOpr _out; 
		_out.y = y * oth.y;
		_out.x = x * oth.y + y * oth.x;
		return _out;
	}
	fMOpr operator-(const fMOpr& oth) const {
		fMOpr _out; 
		_out.y = y * oth.y;
		_out.x = x * oth.y - y * oth.x;
		return _out;
	}
	fMOpr operator*(const fMOpr& oth) const {
		fMOpr _out; 
		_out.y = y * oth.y;
		_out.x = x * oth.x;
		return _out;
	}
};

struct myInp {
	fMOpr one;
	fMOpr zero;
	fMOpr a;
	fMOpr A;
};

myInp andOp(const myInp& a1, const myInp& a2) {
	myInp ans;
	ans.one = a1.one * a2.one;
	ans.a = a1.one * a2.a + a1.a * a2.one + a1.a * a2.a;
	ans.A = a1.one * a2.A + a1.A * a2.one + a1.A * a2.A;
	ans.zero = (a1.one + a1.a + a1.A + a1.zero) * (a2.one + a2.a + a2.A + a2.zero);
	ans.zero = ans.zero - (ans.a + ans.A + ans.one);
	return ans;
}
myInp orOp(const myInp& a1, const myInp& a2) {
	myInp ans;
	ans.zero = a1.zero * a2.zero;
	ans.a = a1.zero * a2.a + a1.a * a2.zero + a1.a * a2.a;
	ans.A = a1.zero * a2.A + a1.A * a2.zero + a1.A * a2.A;
	ans.one = (a1.one + a1.a + a1.A + a1.zero) * (a2.one + a2.a + a2.A + a2.zero);
	ans.one = ans.one - (ans.a + ans.A + ans.zero);
	return ans;
}
myInp xorOp(const myInp& a1, const myInp& a2) {
	myInp ans;
	ans.zero = a1.one * a2.one + a1.zero * a2.zero + a1.A * a2.A + a1.a * a2.a;
	ans.A = a1.one * a2.a + a1.a * a2.one + a1.A * a2.zero + a1.zero * a2.A;
	ans.a = a1.one * a2.A + a1.A * a2.one + a1.a * a2.zero + a1.zero * a2.a;
	ans.one = a1.one * a2.zero + a1.zero * a2.one + a1.a * a2.A + a1.A * a2.a;
	return ans;
}
customInt logPow(customInt b, int e = -1) {
	if (b.get() == 0) return 0;
	customInt r; 
	e = e % (kMod - 1);
	if (e < 0) e += kMod - 1;
	for (r = 1; e; e >>= 1, b = b * b) if (e & 1) r = r * b;
	return r;
}

void calculate(stack<myInp> res ,int out){
	myInp ans = res.top();
	customInt ans0 = ans.zero.x * logPow(ans.zero.y);
	customInt ans1 = ans.one.x * logPow(ans.one.y);
	customInt ansa = ans.a.x * logPow(ans.a.y);
	customInt ansA = ans.A.x * logPow(ans.A.y);
	cout << ans0.get() << " " << ans1.get() << " ";
	cout << ansa.get() << " " << ansA.get() << "\n";
}

void solve() {
	int out = 0;
	string s; cin >> s;
	stack<char> operators, operands;
	stack<myInp> res;
	int amp_cnt = 0 ,hs_cnt = 0;
	for (char c : s) {
		if (c == '&' || c == '|' || c == '^') {
			operators.push(c);
			amp_cnt++;
			continue;
		}
		if (c == '#') {
			myInp curr;
			res.push(curr);
			hs_cnt++;
			continue;
		}
		if (c == ')') {
			operands.push(c);
			while (operands.top() == ')') {
				char optr = operators.top(); operators.pop();
				operands.pop();
				myInp a1 = res.top(); res.pop();
				myInp a2 = res.top(); res.pop();
				if (optr == '&'){ 
					res.push(andOp(a1, a2));
					amp_cnt++;}
				else if (optr == '|') res.push(orOp(a1, a2));
				else if (optr == '^') res.push(xorOp(a1, a2));
				out++;
			}
			continue;
		}
		if (c == '(') {
			operands.push(c);
			continue;
		}
	}
	out = max(amp_cnt ,max(hs_cnt ,out));
	calculate(res ,out);
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t; cin >> t;
	while (t--) solve();
}