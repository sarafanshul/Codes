import java.lang.AssertionError
import java.lang.Math.pow
import java.lang.Math.round
import java.util.*
import kotlin.collections.ArrayList
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

private fun sort(arr: LongArray) {
	val r = Random()
	for (i in arr.indices) {
		val j = i + r.nextInt(arr.size - i)
		val t = arr[i]
		arr[i] = arr[j]
		arr[j] = t
	}
	Arrays.sort(arr)
}


private fun check(): Unit {
	var n = readInt()
	var a = readLongs().toMutableList()
	var b = a
	a.sort()

	fun can( x : Int ) : Boolean{
		var power = a[ x ]
		for( i in 0 until n ){
			if( i == x ) continue
			if( power < a[i] )
				return false
			power += a[i]
		}
		return true
	}

	var l = -1
	var r = n - 1
	while( l + 1 < r ){
		var m = (l + r) / 2
		if( can( m ) )
			r = m
		else
			l = m
	}
	var ans = mutableListOf<Int>()
	for(i in 0 until n){
		if( b[ i ] >= a[ r ] )
			ans.add( i + 1 )
	}
	println( ans.size )
	for(i in ans)
		print("$i ")
	println()
}

fun main(){
	var tt = 1
    tt = readInt()
	repeat(tt){
		check()
	}
}

