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
	var i = 0
	var (n , k) = readInts()
	var a = readInts()

	var h = mutableListOf<Int>()
	a.forEach { h.add(it) }

	var pos = mutableListOf<Int>( 0 )

	while( pos[i] != -1 ){
		var cur : Int = -1
		for( j in 0 until (n - 1) ){
			if( h[ j ] >= h[ j + 1 ] ) continue
			cur = j
			break
		}
		if( cur != -1 ) h[cur]++
		pos.add(cur)
		i++
	}
//	println( pos.toString() )
	if( k >= pos.size || pos[k] == -1) println( -1 )
	else println( ++pos[ k ] )
}

fun main(){
	var tt = 1
	tt = readInt()
	for(qq in 0 until tt){
		solve()
	}
}

