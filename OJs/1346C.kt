import java.lang.AssertionError
import java.util.*
import kotlin.math.ceil

private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readLong() = readLn().toLong() // single long
private fun readDouble() = readLn().toDouble() // single double
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() } // list of longs
private fun readDoubles() = readStrings().map { it.toDouble() } // list of doubles

private fun myAssert(x: Boolean) {
	if (!x) {
		throw AssertionError()
	}
}

fun main(){
	var tt = 1
    tt = readInt()
	for(qq in 0 until tt){

		var (n , k , x , y) = readLongs()
		var a : List<Long> = readLongs().sorted()

		val maxsum = k * n
		var sum = 0L
		var ans = 0L
		var ok = true
		var i = 0

		while( i < n && sum + a[i] <= maxsum){
			sum += a[i]
			if( ok && a[i] > k ){
				ok = false
				ans = (n - i) * x
			}
			i++
		}
		ans = if( ok ) ( n - i ) * x
			else minOf(ans , (n - i) *x + y)

		println(ans)
	}
}

