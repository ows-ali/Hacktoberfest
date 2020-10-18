def f(delim:Int,arr:List[Int]):List[Int] = {
    def g(d: Int, a:List[Int]):List[Int] = {
        if (a.isEmpty) {
            return a
        }
        a.head match {
            case x if x >= d => List[Int]() ++ g(delim, a.tail)
            case _ => List[Int](a.head) ++ g(delim, a.tail)
        }
    }
    g(arr head, arr tail)
}