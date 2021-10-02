function isValidSubsequence(array, sequence) {
  let seqId =0;
      for(const value of array){
          if(seqId === sequence.length) break;
          if(sequence[seqId] === value) seqId++;
      }
      return seqId === sequence.length
  }
  
  exports.isValidSubsequence = isValidSubsequence;
  