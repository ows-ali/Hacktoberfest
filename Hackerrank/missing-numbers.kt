import java.io.*
import java.math.*
import java.security.*
import java.text.*
import java.util.*
import java.util.concurrent.*
import java.util.function.*
import java.util.regex.*
import java.util.stream.*
import kotlin.collections.*
import kotlin.comparisons.*
import kotlin.io.*
import kotlin.jvm.*
import kotlin.jvm.functions.*
import kotlin.jvm.internal.*
import kotlin.ranges.*
import kotlin.sequences.*
import kotlin.text.*

// Complete the missingNumbers function below.
fun missingNumbers(arr: Array<Int>, brr: Array<Int>): Array<Int> {
    var mem = HashMap<Int, Int>()
    for(i in 0 until brr.size) {
        if (mem.containsKey(brr[i])) {
            mem[brr[i]] = mem[brr[i]]!! + 1
        } else {
            mem[brr[i]] = 1
        }
    }

    for (i in 0 until arr.size) {
        if (mem.containsKey(arr[i])) {
            if (mem[arr[i]] == 1) {
                mem.remove(arr[i])
            } else {
                mem[arr[i]] = mem[arr[i]]!! - 1
            }
        }
    }
    var sorted = mem.toSortedMap()
    var result = ArrayList<Int>()
    for (i in sorted.keys) {
        for (j in 1..sorted[i]!!) {
            result.add(i)
        }
    }
    return result.toSortedSet().toTypedArray()
}

fun main(args: Array<String>) {
    val scan = Scanner(System.`in`)

    val n = scan.nextLine().trim().toInt()

    val arr = scan.nextLine().split(" ").map{ it.trim().toInt() }.toTypedArray()

    val m = scan.nextLine().trim().toInt()

    val brr = scan.nextLine().split(" ").map{ it.trim().toInt() }.toTypedArray()

    val result = missingNumbers(arr, brr)

    println(result.joinToString(" "))
}
