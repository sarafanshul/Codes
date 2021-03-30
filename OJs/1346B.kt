import java.lang.AssertionError
import kotlin.math.min

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
		var ( n , k1 , k2 ) = readLongs()
		var s = readLn()
		var ( ans , last)  = mutableListOf<Long>(0 , 0)

		for( i in 0 until n){
			if(s[i.toInt()] == '0'){
				last = 0
				continue
			}
			ans += min( k2 - last , k1 )
			last = min( k2 - last , k1 )
//			print( "($ans $last) , " )
		}
		println(ans)
	}
}

