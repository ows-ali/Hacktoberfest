/**
 * In this algorithm, it is returned the id value of
 * the most common type of bird in an array of birds.
 * At first, the algorithm separate the birds ids by their sum,
 * and then find the one that is the most common and returns it.
 * @param arr Array of birds by id (Ex: [1, 2, 2, 5, 5, 2])
 * @returns number of most common bird with lowest id
 * */
function migratoryBirds(arr) {
   const sumValues = arr.reduce((a, b) => {
      a[b] = a[b] ? a[b] + 1 : 1;
      return a;
   }, {});

   let mostCommon;

   for (var [key, value] of Object.entries(sumValues)) {
      if (!mostCommon) {
         mostCommon = key;
      }
      if (value > sumValues[mostCommon]) {
         mostCommon = key;
      }
   }

   return mostCommon;
}
