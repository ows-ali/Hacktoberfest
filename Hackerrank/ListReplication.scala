def f(num:Int,arr:List[Int]):List[Int] = {
    arr flatMap (x => List(x).padTo(num, x))
}