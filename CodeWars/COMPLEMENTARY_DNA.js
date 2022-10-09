//link for solution: https://www.codewars.com/kata/554e4a2f232cdd87d9000038/train/javascript

function DNAStrand(dna){
    //your code here
      let result = "";
      for (let i = 0; i < dna.length; i++) {
        if (dna[i] == 'A'){
            result = result + 'T';
        } else if (dna[i] == 'T') {
            result = result + 'A';
        } else if (dna[i] == 'G') {
            result = result + 'C';
        } else if (dna[i] == 'C') {
            result = result + 'G';
        }
      }
      return result;
}
  
console.log(DNAStrand('TTGACG'));
  
  