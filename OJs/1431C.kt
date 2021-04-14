import java.lang.AssertionError
import java.lang.Math.pow
import java.lang.Math.round
import java.util.*
import kotlin.collections.ArrayList
import kotlin.collections.HashMap
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

private fun myAssert(x: Boolean) { if (!x) { throw AssertionError() } }

private fun minv(v: Long): Long { return mpow(v, mod - 2) }

private fun mpow(base: Long, exp: Long): Long {
	var base = base ; var exp = exp ; var res: Long = 1
	while (exp > 0) {
		if (exp and 1 == 1L) { res = res * base % mod }
		base = base * base % mod ; exp = exp shr 1
	}
	return res
}

private fun gcd(x: Int, y: Int): Int {
	if (x == 0) return y
	return if (y == 0) x else gcd(y % x, x)
}

private fun check(): Unit {
	val ( n ,k ) = readInts()
	val a = readInts()

	var ans = 0L
	for(i in 0 until n ){
		// number of items = i -> discount = i/k items from n-i-1 .. n-1
		var st = n - i - 1 ; var ed = st + (n - st)/k ; var sm = 0L
		for( j in st until ed ) sm += a[j]
//		println( "${st} , ${ed} , ${n} , ${sm}")
		ans = maxOf( ans , sm ) ;
	}
	println( ans )
}

fun main(){
	var tt = 1
	tt = readInt()
	repeat(tt){
		check()
	}
}
