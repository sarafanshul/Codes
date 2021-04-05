import java.lang.AssertionError
import java.lang.Math.pow
import java.lang.Math.round
import java.util.*
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
	var x = readLong()

	for(a in 1L .. 20000L){
		var b : Long = x - (a*a*a)
		var t = round(pow( b*1.0 , 1.0/3.0 ))
		if( t*t*t == b && b > 0){
			println( "YES" )
			return
		}
	}
	println("NO")

}

fun main(){
	var tt = 1
    tt = readInt()
	repeat(tt){
		check()
	}
}

