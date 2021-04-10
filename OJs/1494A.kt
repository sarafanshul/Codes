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

	var a = readLn()
	var c = "ABC"

	fun repl( x: Char , y : Char , z : Char ) : String{
		var b = a ;
		b = b.replace( x , '0' )
		b = b.replace( y , '1' )
		b = b.replace( z , '1' )
		return b
	}

	fun can(x : String) : Boolean{
		var cnt = 0
		for( i in x ){
			if( i == '0' ) cnt++ ;
			else cnt-- ;
			if( cnt < 0 ) return false
		}
		return cnt == 0
	}
	fun rev( x :String ) : String{
		var r = ""
		for(i in x ) {
			if (i == '0')
				r += '1'
			else r += '0'
		}
		return r
	}
	for( i in c.indices ){
		var d = repl( c[i] , c[(i+1)%3] , c[(i + 2)%3] )
		if( can( d ) || can( rev(d) )) {
			println( "YES" )
			return
		}
	}
	println( "NO" )
}

fun main(){
	var tt = 1
	tt = readInt()
	repeat(tt){
		check()
	}
}

