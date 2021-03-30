import java.lang.AssertionError

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

fun solve(){
    var (n , k) = readLongs()
    var x = 1L + k + k*k + k*k*k
    var ans = n / x
    println("$ans ${ans * k} ${ans * k * k} ${ans * k * k * k}");
}

fun main(){
    var tt = readInt()
    for(qq in 0 until tt){
        solve()
    }
}
