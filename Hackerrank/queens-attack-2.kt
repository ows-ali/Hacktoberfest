import kotlin.collections.*
import kotlin.io.*
import kotlin.math.abs
import kotlin.ranges.*
import kotlin.text.*

/**
 * @author: Jenna Franco
 * This problem comes from HackerRank: https://www.hackerrank.com/challenges/queens-attack-2/problem
 *
 * queensAttack() Function Description:
 * Given the queen's position and the locations of all the obstacles,
 * find and print the number of squares the queen can attack from her position at (r, c)
 *
 * @param:
 *   - int n: the number of rows and columns in the board
 *   - nt k: the number of obstacles on the board
 *   - int r_q: the row number of the queen's position
 *   - int c_q: the column number of the queen's position
 *   - int obstacles[k][2]: each element is an array of integers, the row and col of an obstacle
 *
 * @return:
 *   - int: the number of squares the queen can attack
 *
 * Constraints:
 *   - 0 < n <= 10^5
 *   - 0 <= k <= 10 ^5
 *   - A single cell may contain more than one obstacle
 *   - There will never be an obstacle at the position where the queen is located
 *
 * Notes:
 *   Because there can be duplicate obstacles and because the obstacles are not in order,
 *   we have to iterate through the entire array of obstacles, checking the location of each.
 *   This results in a time complexity of O(n), where n = length of obstacles array
 *
 */
fun queensAttack(n: Int, k: Int, r_q: Int, c_q: Int, obstacles: Array<Array<Int>>): Int {
    // subtract one to get the indices since r_q and c_q use base-1 indexing
    val queenRow = r_q - 1
    val queenCol = c_q - 1

    // iterate through entire array of obstacles, keeping track of the ones closet to the queen in every direction
    val nearestObstacles: HashMap<Direction, Pair<Int, Int>> = HashMap()
    obstacles.forEach {
        val row = it[0]
        val col = it[1]

        val (direction, isDiagonal) = when {
            row == queenRow && col < queenCol -> Direction.HORIZONTAL_RIGHT to false
            row == queenRow && col > queenCol -> Direction.HORIZONTAL_LEFT to false
            row < queenRow && col == queenCol -> Direction.VERTICAL_DOWN to false
            row > queenRow && col == queenCol -> Direction.VERTICAL_UP to false
            row < queenRow && col < queenCol -> Direction.LOWER_LEFT_DIAGONAL to true
            row > queenRow && col > queenCol -> Direction.UPPER_RIGHT_DIAGONAL to true
            row < queenRow && col > queenCol -> Direction.LOWER_RIGHT_DIAGONAL to true
            row > queenRow && col < queenCol -> Direction.UPPER_LEFT_DIAGONAL to true
            else -> Direction.INVALID to false
        }

        // determine of the obstacle lies in a space along a path the queen can move
        if (spaceInQueensPath(isDiagonal, queenRow to row, queenCol to col) &&
            row < n &&
            col < n
        ) {
            val previousObstacle = nearestObstacles[direction]
            val currentObstacle = row to col

            // each time we encounter an obstacle, save it if it is closer to the queen than the last one we saved along the same path
            if (previousObstacle == null ||
                distanceBetween(queenRow, currentObstacle.first) < distanceBetween(queenRow, previousObstacle.first) ||
                distanceBetween(queenCol, currentObstacle.second) < distanceBetween(queenRow, previousObstacle.second)
            ) {
                nearestObstacles[direction] = row to col
            }
        }
    }
    // calculate spaces moved along each direction by passing in the nearest obstacle coordinates or the game board size
    return Direction.values().sumBy {
        val obstacle = if (nearestObstacles[it]?.first != null && nearestObstacles[it]?.second != null) nearestObstacles[it]!!.first to nearestObstacles[it]!!.second else null
        calculateSpacesToMove(it, queenRow to queenCol, n - 1, obstacle)
    }
}

fun calculateSpacesToMove(d: Direction, queen: Pair<Int, Int>, maxSpace: Int, obstacle: Pair<Int, Int>?): Int {
    val queenRow = queen.first
    val queenCol = queen.second
    return when {
        obstacle != null -> minOf(abs(obstacle.first - queenRow) - 1, abs(obstacle.second - queenCol) - 1)
        d == Direction.VERTICAL_UP -> maxSpace - queenRow
        d == Direction.VERTICAL_DOWN -> queenRow
        d == Direction.HORIZONTAL_LEFT -> queenCol
        d == Direction.HORIZONTAL_RIGHT -> maxSpace - queenCol
        d == Direction.UPPER_LEFT_DIAGONAL -> minOf(abs(maxSpace - queenRow), queenCol)
        d == Direction.LOWER_RIGHT_DIAGONAL -> minOf(queenRow,  abs(maxSpace - queenCol))
        d == Direction.UPPER_RIGHT_DIAGONAL -> minOf(abs(maxSpace - queenRow), abs(maxSpace - queenCol))
        d == Direction.LOWER_LEFT_DIAGONAL -> minOf(queenRow, queenCol)
        else -> 0
    }
}

fun distanceBetween(num1: Int, num2: Int) = abs(num1 - num2)
fun spaceInQueensPath(isDiagonal: Boolean, rows: Pair<Int, Int>, columns: Pair<Int, Int>) =
    isDiagonal.not() || hasValidSlope(rows, columns)

fun hasValidSlope(rows: Pair<Int, Int>, columns: Pair<Int, Int>) =
    distanceBetween(rows.first, rows.second) == distanceBetween(columns.first, columns.second)

enum class Direction {
    HORIZONTAL_LEFT,
    HORIZONTAL_RIGHT,
    VERTICAL_UP,
    VERTICAL_DOWN,
    UPPER_LEFT_DIAGONAL,
    UPPER_RIGHT_DIAGONAL,
    LOWER_LEFT_DIAGONAL,
    LOWER_RIGHT_DIAGONAL,
    INVALID;
}

/** The logic in main() was provided by HackerRank  */
fun main(args: Array<String>) {
    val first_multiple_input = readLine()!!.trimEnd().split(" ")

    val n = first_multiple_input[0].toInt()
    val k = first_multiple_input[1].toInt()
    val second_multiple_input = readLine()!!.trimEnd().split(" ")
    val r_q = second_multiple_input[0].toInt()
    val c_q = second_multiple_input[1].toInt()

    val obstacles = Array<Array<Int>>(k, { Array<Int>(2, { 0 }) })
    for (i in 0 until k) {
        obstacles[i] = readLine()!!.trimEnd().split(" ").map { it.toInt() }.toTypedArray()
    }
    val result = queensAttack(n, k, r_q, c_q, obstacles)
    println(result)
}
