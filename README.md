#Quack Watch

## C++ Template
<details>
<summary>Here Senpai </summary>
<br>

```c++
#ifndef CUST_DEBUG
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma") 
#pragma GCC optimize("unroll-loops")
#endif
#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
#define PB push_back
#define F first
#define S second
#define MP make_pair
using ll = long long ;
using db = long double ; // or double, if TL is tight
template< class T , size_t SZ> using ar = std::array<T , SZ> ; 
using namespace std;
#ifdef CUST_DEBUG
template<class K, class V>ostream& operator<<(ostream&s,const pair<K,V>&p){s<<'<'<<p.F<<','<<p.S<<'>';return s;}
template<class T, class=typename T::value_type, class=typename enable_if<!is_same<T,string>::value>::type>
ostream& operator<<(ostream&s,const T&v){s<<'[';for(auto&x:v){s<<x<<", ";}if(!v.empty()){s<<"\b\b";}s<<']';return s;}
void __prnt(){cerr<<endl;} template<class T, class...Ts>void __prnt(T&&a,Ts&&...etc){cerr<<a<<' ';__prnt(etc...);}
#define print(...) __prnt(__VA_ARGS__)
#else
#define print(...)
#endif
template<class T> using pqg = priority_queue<T,vector<T>,greater<T>>;
const long long MAXN = 2e5 +7;

void check(){
	
}

int32_t main(){
	#ifndef CUST_DEBUG
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	#endif
	int t_c = 1;	
	cin >> t_c;
	for(int i = 1 ; i <= t_c ;i++){ print("Case : " , i) ; check(); }
	return 0;
}
```
<br>
</details>

<details>
<summary>Compile with </summary>
<br>
```shell
g++ -std=c++17 -D CUST_DEBUG -D_GLIBCXX_ASSERTIONS -Wall -Wshadow $F
```
<br>
</details>

## Kotlin Template
<details> 
<summary> Hit Me !! </summary>
<br>
```kotlin
import java.lang.AssertionError
import java.util.*
import kotlin.collections.ArrayList
import java.util.Collections as JavaUtilCollections

private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readLong() = readLn().toLong() // single long
private fun readDouble() = readLn().toDouble() // single double
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() } // list of longs
private fun readDoubles() = readStrings().map { it.toDouble() } // list of doubles

private const val mod: Long = 1000000007

private fun myAssert(x: Boolean) {
	if (!x) {
		throw AssertionError()
	}
}

private fun minv(v: Long): Long {
	return mpow(v, mod - 2)
}

private fun mpow(base: Long, exp: Long): Long {
	var base = base
	var exp = exp
	var res: Long = 1
	while (exp > 0) {
		if (exp and 1 == 1L) {
			res = res * base % mod
		}
		base = base * base % mod
		exp = exp shr 1
	}
	return res
}

private fun gcd(x: Int, y: Int): Int {
	if (x == 0) return y
	return if (y == 0) x else gcd(y % x, x)
}

private fun check(): Unit {
	
}

fun main(){
	var tt = 1
    tt = readInt()
	repeat(tt){
		check()
	}
}
```

</details>



## Profile (powershell)

<details>
<summary>Ara Ara</summary>
<br>
```shell
# alias for sublime
Set-Alias subl "C:\Program Files\Sublime Text 3\sublime_text.exe"

# compiling a file with g++
function run { 
	[string[]]$F = $args
	Write-Host "Compiling $F with c++17 " -ForegroundColor yellow
	( Measure-Command { 
		g++ -std=c++17 -D CUST_DEBUG -D_GLIBCXX_ASSERTIONS -Wall -Wshadow $F
	} |Format-List -Property TotalMilliseconds| Out-String ).Trim()
}

# creating a new ".cc" file with a default template
function new {
	param ( 
		[string[]]$F 
	)
	[string[]]$ext = ".cc"
	$filename = $F.Trim() + $ext.Trim()
	$startTime = Get-Date

	Write-Host ""
	Write-Host "$startTime  " -ForegroundColor yellow
	if( (Test-Path -Path E:\PRO\Comp\default.cpp) ){
		if( !(Test-Path -Path $filename) ){
			Write-Host "Create Mode:"$filename -ForegroundColor blue
			Copy-Item E:\PRO\Comp\default.cpp $filename
		} else{
			Write-Host "Error:"$filename" already exists" -ForegroundColor red
		}
	} else{
		Write-Host "Error default.cpp not found"  -ForegroundColor red
	}

	subl $filename
	Write-Host ""
}

# for saving clipboard to a file
function scl{
	param(
		[string[]]$F
	)
	$filename = $F.Trim()
	$startTime = Get-Date
	Write-Host ""
	Write-Host "$startTime  " -ForegroundColor yellow

	Get-Clipboard | Out-File $filename -Encoding utf8
	subl $filename
	Write-Host ""
}
```
</details>