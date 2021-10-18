def binary_search(n, arr)
  middle = arr[arr.length / 2]
  i = 0
  j = arr.length - 1

  while i < j
    if middle == n
      return true
    elsif middle < n
      i = middle
      middle = i + j / 2
    else
      p "Middle is greater than n"
      j = middle
      p "j: #{j}"
      middle = i + j / 2
      p "middle: #{middle}"
    end
  end
  false
end 