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

private fun sq_dist( x1 : Long , y1 : Long , x2 : Long , y2 : Long ) : Long {
	return ( (x2 - x1)*(x2 - x1) + (y2 - y1)*(y2 - y1) )
}

private fun solve(): Unit {
	var (x2 , y2) = readLongs()
	val s : String = readLn()
	var x1 = 0L
	var y1 = 0L
	var dist = sq_dist(x1 , y1, x2 , y2)

	for( i in s){
		var xx = x1
		var yy = y1
		when( i ){
			'U' -> yy++
			'D' -> yy--
			'R' -> xx++
			'L' -> xx--
		}
		if( sq_dist(xx, yy , x2 , y2) <= dist ){
			x1 = xx
			y1 = yy
			dist = sq_dist(xx, yy , x2 , y2)
		}
	}
	if( dist == 0L ) println("YES")
	else println("NO")
}

fun main(){
	var tt = 1
	tt = readInt()
	for(qq in 0 until tt){
		solve()
	}
}

