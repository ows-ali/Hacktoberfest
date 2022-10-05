def positive_sum(arr)
    arr2 = []
    arr.each{|num| if (num > 0); arr2.push(num) end}
    arr2.sum()
  end