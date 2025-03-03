package main
class a{
    var x:int
    private fun get()->int{
        return this.x
    }
    public fun get2()->int{
        return this.get();
    }
}
fun main() -> int{
    var x:a
    x.get2();
    var b = 1+1
    return 0
}