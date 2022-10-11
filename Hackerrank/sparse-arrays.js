// There is a collection of input strings and a collection of query strings. 
// This function determine how many times a query string occurs in the list of input strings. 
// Returns an array of the results.
// Example
strings= ['ab', 'ab', 'abc']
queries = ['ab', 'abc', 'bc']

// return the results
result = [2,1,0]


// Here is my solution

function matchingStrings(strings, queries) {
      const memory = {};
    
    // O(n), where n = number of string
    for(const string of strings)
     memory[string] = (memory[string] || 0) + 1;

    // O(m), where m = number of queries (the lookup is constant time, O(1))
    return queries.map(query=> memory[query] || 0);
    

}
