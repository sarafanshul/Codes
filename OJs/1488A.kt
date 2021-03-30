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

fun sum(n :Long) :Long{
    var tmp = n
    var sum = 0L
    while(tmp > 0){
        sum += tmp%10
        tmp /= 10
    }
    return sum
}

fun main(args :Array<String>){
    var tt = readInt()
    for(q in 0 until tt){
        var (x , y) = readLongs()
        var ans = y%x + sum(y / x)
        println(ans)
    }

}
