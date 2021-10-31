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
    // subtract one to get the indices since r_q and c_q use base-1 indexing
    val queenRow = r_q - 1
    val queenCol = c_q - 1

    val spacesUp = maxRowCol - queenRow
    val spacesDown = queenRow
    val spacesRight = maxRowCol - queenCol
    val spacesLeft = queenCol

    val minimumSpacesToMove = mapOf(
        Direction.UP to spacesUp,
        Direction.DOWN to spacesDown,
        Direction.RIGHT to spacesRight,
        Direction.LEFT to spacesLeft,
        Direction.UPPER_LEFT to minOf(spacesUp, spacesLeft),
        Direction.LOWER_LEFT to minOf(spacesDown, spacesLeft),
        Direction.UPPER_RIGHT to minOf(spacesUp, spacesRight),
        Direction.LOWER_RIGHT to minOf(spacesDown, spacesRight)
    )

    // iterate through entire array of obstacles, keeping track of the ones closet to the queen in every direction
    val nearestObstacles: HashMap<Direction, Pair<Int, Int>> = HashMap()
    obstacles.forEach {
        val obstacleRow = it[0] - 1
        val obstacleCol = it[1] - 1

        fun hasNegativeSlopeOf1(r1: Int, r2: Int, c1: Int, c2: Int) = (c2 - c1) == -1*(r2 - r1)
        fun hasPositiveSlopeOf1(r1: Int, r2: Int, c1: Int, c2: Int) = (c2 - c1) == (r2 - r1)

        when {
            queenCol == obstacleCol -> {
                if (queenRow < obstacleRow) minimumSpacesToMove[Direction.UP] = minOf(minimumSpacesToMove[Direction.UP], obstacleRow - queenRow - 1)
                else minimumSpacesToMove[Direction.DOWN] = minOf(minimumSpacesToMove[Direction.DOWN], queenRow - obstacleRow - 1)
            }
            queenRow == obstacleRow -> {
                if (queenCol < obstacleCol) minimumSpacesToMove[Direction.RIGHT] = minOf(minimumSpacesToMove[Direction.RIGHT], obstacleCol - queenCol - 1)
                else minimumSpacesToMove[Direction.LEFT] = minOf(minimumSpacesToMove[Direction.LEFT], queenCol - obstacleCol - 1)
            }
            // since the slope along the diagonal paths are 1 or -1, the difference in the rows and columns will be the same, so can use either
            hasNegativeSlopeOf1(queenRow, obstacleRow, queenCol, obstacleCol) -> {
                if (queenRow < obstacleRow) minimumSpacesToMove[Direction.UPPER_LEFT] = minOf(minimumSpacesToMove[Direction.UPPER_LEFT], obstacleRow - queenRow - 1)
                else minimumSpacesToMove[Direction.LOWER_RIGHT] = minOf(minimumSpacesToMove[Direction.LOWER_RIGHT], queenRow - obstacleRow - 1)
            }
            hasPositiveSlopeOf1(queenRow, obstacleRow, queenCol, obstacleCol) -> {
                if (queenRow < obstacleRow) minimumSpacesToMove[Direction.UPPER_RIGHT] = minOf(minimumSpacesToMove[Direction.UPPER_RIGHT], obstacleRow - queenRow - 1)
                else minimumSpacesToMove[Direction.LOWER_LEFT] = minOf(minimumSpacesToMove[Direction.LOWER_LEFT], queenRow - obstacleRow - 1)
            }
        }

    // calculate spaces moved along each direction by passing in the nearest obstacle coordinates or the game board size
    return Direction.values().sumBy { minimumSpacesToMove[it] }
}

enum class Direction {
    LEFT,
    RIGHT,
    UP,
    DOWN,
    UPPER_LEFT,
    UPPER_RIGHT,
    LOWER_LEFT,
    LOWER_RIGHT
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
