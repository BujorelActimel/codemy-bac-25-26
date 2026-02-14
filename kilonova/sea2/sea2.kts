import java.io.BufferedReader
import java.io.FileReader
import java.io.PrintWriter
import java.util.StringTokenizer
import java.util.TreeMap

fun main() {
    val reader = BufferedReader(FileReader("sea2.in"))
    val out = PrintWriter("sea2.out")

    val n = reader.readLine().trim().toInt()
    val skyline = TreeMap<Int, Int>() // x -> y

    repeat(n) {
        val st = StringTokenizer(reader.readLine())
        val x = st.nextToken().toInt()
        val y = st.nextToken().toInt()

        // SAME X handling (critical fix)
        val sameY = skyline[x]
        if (sameY != null) {
            if (sameY > y) {
                out.println(-1)
                return@repeat
            } else {
                skyline.remove(x)
            }
        }

        // Check domination from the right
        val higher = skyline.higherEntry(x)
        if (higher != null && higher.value > y) {
            out.println(-1)
            return@repeat
        }

        // Remove dominated ships on the left
        var lower = skyline.lowerEntry(x)
        while (lower != null && lower.value < y) {
            skyline.remove(lower.key)
            lower = skyline.lowerEntry(x)
        }

        skyline[x] = y
        out.println(skyline.size)
    }

    out.flush()
    out.close()
}
