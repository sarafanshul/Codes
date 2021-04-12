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
	val ( n , k ) = readInts()
	val s = readLn().toMutableList()
	val MIN_CHAR = 'a'

	if( n %k != 0 ){
		println( -1 ) ; return
	}


	val freq = Array(26) { 0 }
	for( i in s )
		freq[ i - MIN_CHAR ]++

	var prefix = s.toMutableList()

	fun can() : Boolean {
		var add = 0
		for( c in 0 until 26 ){
			if( freq[ c ] % k != 0 )
				add += k - freq[ c ] % k
		}
		if( prefix.size + add > n )
			return false
		var remain = ""
		for( c in 0 until 26 ){
			if( freq[ c ] % k != 0 )
				remain += ( c + 97 ).toChar().toString().repeat(  maxOf(k - freq[ c ]%k , 0)  )
		}
		var extra = n - (prefix.size + remain.length)
		remain = "a".repeat( maxOf(extra , 0) ) + remain
		println( prefix.joinToString("") + remain )
		return true
	}

	if( can() ) return

	for( i in n - 1 downTo 0 ){
		freq[ prefix.removeLast() - MIN_CHAR ]--
		for( c in (s.get( i ) - MIN_CHAR + 1) until 26 ){
			prefix.add( (c + 97).toChar() )
			freq[ c ]++
			if( can() ) return
			freq[ c ]--
			prefix.removeLast()
		}
	}
	myAssert(false)
}

fun main(){
	var tt = 1
	tt = readInt()
	repeat(tt){
		check()
	}
}
