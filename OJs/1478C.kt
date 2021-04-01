import java.lang.AssertionError
import java.util.*

private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readLong() = readLn().toLong() // single long
private fun readDouble() = readLn().toDouble() // single double
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() } // list of longs
private fun readDoubles() = readStrings().map { it.toDouble() } // list of doubles

private fun myAssert(x: Boolean) {
	if (!x) {
		throw AssertionError()
	}
}

fun solve() {
	var n = readInt()
	var a = readLongs().sorted().reversed()
	var s = 0L
	var t = n
	var ans = "YES"
	for( i in 0 until n ){
		if( a[ 2*i ] != a[ 2*i + 1] ){
			ans = "NO"
			break
		}
	}
	a = a.toSet().sorted().reversed()
	if( a.size != n ) ans = "NO"
	else for( it in a ){
		val cur = it - s
		if( cur <= 0L  || cur % (2 * t) != 0L){
			ans =  "NO"
			break
		}
		s += cur / t--
	}
	println(ans)
}

fun main(){
	var tt : Int = 0
    tt = readInt()
	for(qq in 0 until tt){
		solve()
	}
}

