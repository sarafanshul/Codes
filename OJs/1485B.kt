import java.lang.AssertionError
import java.util.*

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

private fun solve(): Unit {
	var ( n , q , k ) = readInts()
	var a = readLongs()

	var choices = LongArray(n)
	for( i in 1 until n - 1)
		choices[i] = a[ i + 1 ] - a[ i - 1 ] - 2

	var choices_sum = LongArray( n + 1 )
	for( i in 0 until n)
		choices_sum[i + 1] = choices[ i ] + choices_sum[ i ]

	repeat(q) z@{
		var (l , r) = readInts()
		l--
		if( r - l == 1 ) {
			println(k - 1)
			return@z
		}
		var ans = choices_sum[ r - 1 ] - choices_sum[ l + 1 ]
		ans += maxOf( a[l + 1] - 2 , 0 )
		ans += maxOf( k - 1 - a[ r - 2 ] , 0 )
		println( ans )
	}
}

fun main(){
	var tt = 1
//	tt = readInt()
	for(qq in 0 until tt){
		solve()
	}
}

