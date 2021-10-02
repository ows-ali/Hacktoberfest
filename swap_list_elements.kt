import java.lang.NumberFormatException
import java.math.BigDecimal
import java.util.*
import java.util.concurrent.atomic.DoubleAccumulator
import kotlin.collections.ArrayList

fun main() {

    val numbers = mutableListOf(1,7,9,4,5)
    println(numbers.swap(1,3)) //[10, 1, 2]ss
}

fun MutableList<Int>.swap(index1:Int, index2:Int) : MutableList<Int>{
    var tmp = this[index1]
    this[index1] = this[index2]
    this[index2] = tmp
    return this
}
