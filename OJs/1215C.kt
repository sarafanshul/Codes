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
	val n = readInt()
	var s = readLn()
	var t = readLn()

	var pos_a = mutableListOf<Int>()
	var pos_b = mutableListOf<Int>()

	for( i in 0 until n ){
		if( s[i] != t[i] ){
			if( s.get(i) == 'a' )
				pos_a.add( i )
			else
				pos_b.add( i )
		}
	}

	if( (pos_a.size % 2) != (pos_b.size % 2) ){
		println( -1 ) ;return ;
	}

	var ans = mutableListOf<Pair<Int , Int>>(  ) ;
	for( i in 0 until pos_a.size - 1 step 2 )
		ans.add( Pair( pos_a[i] , pos_a[i + 1] ) )

	for( i in 0 until pos_b.size - 1 step 2 )
		ans.add( Pair( pos_b[ i ] , pos_b[i + 1] ) )

	if( pos_a.size % 2 == 1){
		var x = pos_a.last() ; var y = pos_b.last()
		ans.add( Pair( x , x ) )
		ans.add( Pair( x , y ) )
	}
	println( ans.size )
	ans.forEach {  println( "${it.first + 1} ${it.second + 1}" ) }
}

fun main(){
	var tt = 1
//	tt = readInt()
	repeat(tt){
		check()
	}
}
