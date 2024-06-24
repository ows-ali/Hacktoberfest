findOdd = function(arr) {
  obj = {};
  arr.forEach(num => {
    obj[num] ? (obj[num] += 1) : (obj[num] = 1);
  });
  const odd = Object.keys(obj).find(key => obj[key] % 2 != 0);

  return parseInt(odd);
};
