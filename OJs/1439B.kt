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
	val mir = mutableListOf<Int>( 0 , 1 , 5 , 1000 , 1000 , 2 , 1000 , 1000 , 8 , 1000 )

	val ( H , M ) = readInts()

	fun can( a : MutableList<Int> ) : Boolean {
		var h1 = mir[a[0]!!]
		var h2 = mir[a[1]!!]
		var m1 = mir[a[2]!!]
		var m2 = mir[a[3]!!]
		return (( m2*10 + m1 ) < H && ( h2*10 + h1 ) < M )
	}

	var a = readLine()
	var lst = mutableListOf<Int>( a?.get(0)!!.toInt() - 48 , a?.get(1)!!.toInt() - 48, a?.get(3)!!.toInt() - 48 , a?.get(4)!!.toInt() - 48 )
	while( !can( lst ) ){
//		println("${ lst.toString() } ${can(lst)}")
		lst[ 3 ]++
		if( lst[3] == 10 ) {
			lst[2]++
			lst[3] = 0
		}
		if( lst[2]*10 + lst[3] == M ){
			lst[1]++
			lst[2] = 0
			lst[3] = 0
		}
		if( lst[1] == 10 ){
			lst[0]++
			lst[1] = 0
		}
		if( lst[0]*10 + lst[1] == H ){
			lst[0] = 0
			lst[1] = 0
		}
	}
	println( " ${lst[0]}${lst[1]}:${lst[2]}${lst[3]}" )

}

fun main(){
	var tt = 1
    tt = readInt()
	repeat(tt){
		check()
	}
}

