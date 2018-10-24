function sym(args) {
  var output;
  output = [].slice.apply(arguments).reduce(function(previous, current) {
    current.filter(function(value, index, self) { //for unique
      return self.indexOf(value) === index;
    }).map(function(element) { //pushing array
      var loc = previous.indexOf(element);
      var a = [loc !== -1 ? previous.splice(loc, 1) : previous.push(element)];
    });
    return previous;
  }, []);
  return output.sort();
}
