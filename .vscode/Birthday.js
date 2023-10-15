function birthday(s, d, m) {
  let res = 0
  const sum = arr => arr.reduce((acc, el) => acc + el, 0)
  for (let i = 0; i < s.length - m + 1; i++) {
    if (sum(s.slice(i, i + m)) === d) {
      res++
    }
  }
  return res
}
