import java.lang.AssertionError
import java.util.*
import kotlin.collections.ArrayList
import kotlin.math.*
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
	var n = readInt()
	var s = readInts().toMutableList()

	var total = 0L
	var arrive = Array( n + 1 ){ 0L }

	for( i in 0 until n ){
		var add = 0L
		if( i + s[i] >= n ){
			var interm = i + s[i] - ( n - 1 ) + if( i == n - 1 ) -1 else 0
			add += interm
			s[i] -= interm
			myAssert( i == n - 1 || i + s[i] < n )
		}
		while( s[i] > 1 ){
			add++
			arrive[ i + s[i] ]++
			s[i]--
		}
		var reduce = minOf( add , arrive[ i ])
		add -= reduce
		arrive[ i ] -= reduce
		arrive[ i + 1 ] += arrive[ i ]
		total += add
	}
	println( total )
}

fun main(){
	var tt = 1
	tt = readInt()
	repeat(tt){
		check()
	}
}

