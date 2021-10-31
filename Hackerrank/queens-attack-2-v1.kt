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
 * Given the queen's position and the locations of all the obstacles on a chess board,
 * find and print the number of squares the queen can attack from her position at (r, c)
 *
 * @param:
 *   - int n: the number of rows and columns in the board
 *   - int k: the number of obstacles on the board
 *   - int r_q: the row number of the queen's position
 *   - int c_q: the column number of the queen's position
 *   - int obstacles[k][2]: each element is an array of integers, the row number and column number of an obstacle
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
    val queenRow = r_q
    val queenCol = c_q

    var spacesUp = n - queenRow
    var spacesDown = queenRow - 1
    var spacesRight = n - queenCol
    var spacesLeft = queenCol - 1
    var spacesUpperLeft = minOf(spacesUp, spacesLeft)
    var spacesLowerRight = minOf(spacesDown, spacesRight)
    var spacesUpperRight = minOf(spacesUp, spacesRight)
    var spacesLowerLeft = minOf(spacesDown, spacesLeft)

    // Iterate through array of obstacles, calculating the distance between the queen and each obstacle.
    // Keep track of the nearest obstacles by always storing the shortest distances.
    obstacles.forEach {
        val obstacleRow = it[0]
        val obstacleCol = it[1]

        fun hasNegativeSlopeOf1(row1: Int, row2: Int, col1: Int, col2: Int) = (row2 - row1) == -1 * (col2 - col1)
        fun hasPositiveSlopeOf1(row1: Int, row2: Int, col1: Int, col2: Int) =  (row2 - row1) == (col2 - col1)
        fun distanceBetween(num1: Int, num2: Int) = abs(num1 - num2) - 1

        when {
            queenCol == obstacleCol -> {
                val spacesBetweenRows = distanceBetween(obstacleRow, queenRow)
                if (queenRow < obstacleRow) spacesUp = minOf(spacesUp, spacesBetweenRows)
                else spacesDown = minOf(spacesDown, spacesBetweenRows)
            }
            queenRow == obstacleRow -> {
                val spacesBetweenColumns = distanceBetween(obstacleCol, queenCol)
                if (queenCol < obstacleCol) spacesRight = minOf(spacesRight, spacesBetweenColumns)
                else spacesLeft = minOf(spacesLeft, spacesBetweenColumns)
            }
            // since the slope along the diagonal paths is 1 or -1,
            // the difference in the rows and columns will be the same, so can use either
            hasPositiveSlopeOf1(queenRow, obstacleRow, queenCol, obstacleCol) -> {
                val spacesBetweenRows = distanceBetween(obstacleRow, queenRow)
                if (queenRow < obstacleRow) spacesUpperRight = minOf(spacesUpperRight, spacesBetweenRows)
                else spacesLowerLeft = minOf(spacesLowerLeft, spacesBetweenRows)
            }
            hasNegativeSlopeOf1(queenRow, obstacleRow, queenCol, obstacleCol) -> {
                val spacesBetweenRows = distanceBetween(obstacleRow, queenRow)
                if (queenRow < obstacleRow) spacesUpperLeft = minOf(spacesUpperLeft, spacesBetweenRows)
                else spacesLowerRight = minOf(spacesLowerRight, spacesBetweenRows)
            }
        }
    }
    val allMoves = listOf(
        spacesUp,
        spacesDown,
        spacesRight,
        spacesLeft,
        spacesUpperLeft,
        spacesLowerRight,
        spacesUpperRight,
        spacesLowerLeft
    )
    return allMoves.sumBy { it }
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
