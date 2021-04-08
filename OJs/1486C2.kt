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

	var mp = mutableMapOf<Pair<Int , Int> , Int>()

	fun query( l : Int , r : Int ) : Int {

		if( mp.contains(Pair( l , r )) ) return mp[ Pair( l , r ) ]!!

		if( l >= r ) return -1

		println( "? $l $r" )
		System.out.flush()
		val ans = readInt()
		mp[ Pair( l , r ) ] = ans
		return mp[ Pair( l , r ) ]!!
	}

	var n = readInt()

	var mx2 = query( 1 , n )
	var ans = -1
	if( mx2 == query( 1 , mx2 ) ) {
		// mx in [1 .. mx2]
		var l = 1 ; var r = mx2 - 1
		while( l <= r ){
			val m = (l + r) / 2
			if( query( m , mx2 ) == mx2 ){
				ans = m
				l = m + 1
			}else {
				r = m - 1
			}
		}
	}
	else {
		// mx in [mx2 .. n]
		var l = mx2 + 1 ; var r = n
		while( l <= r ){
			val m = ( l + r ) / 2
			if( query(mx2 ,m) == mx2 ){
				ans = m
				r = m - 1
			}else {
				l = m + 1
			}
		}
	}
	println("! $ans")
	System.out.flush()
}

fun main(){
	var tt = 1
//    tt = readInt()
	repeat(tt){
		check()
	}
}

