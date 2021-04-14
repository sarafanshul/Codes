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
	val s = readLn().toMutableList()
	var a = Array(100){ 0 }
	val v = 'v' ; var w = 'w'
	var i = 0 ; var ans = 0
	while( i in s.indices ){
		if( s[i] == v && i + 1 in s.indices && (s[i + 1] == v || s[i + 1] == w) ){
			ans ++ ; i += 2 ; continue
		}
		if( s[i] == w ) ans++
		i++
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
