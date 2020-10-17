function arrayDiff(a, b) {
    let output = a.filter(function(x) { return b.indexOf(x) == -1 } );
    return output;
    
    // filter function filters out all elements in the array that pass a test into a different array.
    // x is the element of array 'a'.
    
  }