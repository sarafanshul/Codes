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
	var n = readInt()
	var adj = Array( n ) { Array( n ) { it -> 0} }

	val set_edge = { a: Int , b : Int , win : Int ->
		adj[ a ][ b ] = win
		adj[ b ][ a ] = -win
	}

	val get_sum = { a : Int -> adj[ a ].sum() }

	if( n%2 == 0 ){
		for( i in 0 until n step 2 )
			set_edge( i , (i + 1)%n ,0 )

		if( n%4 != 0 ){
			for( i in 1 until n step 2 )
				set_edge( i , (i + 1)%n , 1 )

			for( i in 0 until n step 2 )
				set_edge( i , (i + n / 2)%n , 1 )

		}else {
			for( i in 1 until n step 2 )
				set_edge( i , (i + 1)%n , if( i < n / 2 ) 1 else -1 )

			for( i in 0 until n / 2 ){
				var _sum = get_sum( i )
				myAssert( _sum != 0 && get_sum( i + n / 2 ) == -_sum )
				set_edge( i , i + n / 2 , if( _sum < 0 ) 1 else -1 )
			}
		}
	}else {
		for (i in 0 until n)
			set_edge( i , (i + 1)%n , 1 )
	}
	if( n == 2 )
		set_edge( 0 , 1 , 0 )

	for( len in 2 .. (n - 1) / 2 ){
		for( i in 0 until n )
			set_edge( i , (i + len)%n , 1 )
	}
	for( i in 0 until n )
		for (j in i + 1 until n)
			print("${adj[i][j]} ")

	println()
}

fun main(){
	var tt = 1
    tt = readInt()
	for(qq in 0 until tt){
		solve()
	}
}

