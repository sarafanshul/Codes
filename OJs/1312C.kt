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
	val ( n , k ) = readLongs()
	val a = readLongs().toLongArray()

	var max_pow = 1L
	while( max_pow < 1e16.toLong() ) max_pow *= k

	while( max_pow > 0 ){
		val pos = a.withIndex().filter{ it.value >= max_pow }.map{ it.index }
		if( pos.isNotEmpty() ){
			if( pos.size > 1 ){
				println( "NO" )
				return
			}
			a[ pos[0] ] -= max_pow
		}
		max_pow /= k
	}
	if( a.max()!! > 0L ){
		println( "NO")
		return
	}
	println( "YES" )
}

fun main(){
	var tt = 1
	tt = readInt()
	repeat(tt){
		check()
	}
}

