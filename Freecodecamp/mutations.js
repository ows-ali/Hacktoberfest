function mutation(arr) {
  var s1 = arr[0];
  var s2 = arr[1];
  var found;

  for(var i = 0; i < s2.length; i++){
    var cur = s2[i].toLowerCase();

    for(var j = 0; j < s1.length; j++){
        if(cur == s1[j].toLowerCase()){
            found = true;
            break;  
        } else{
          found = false;
        }
    }

    if(!found){
      return false;
    }
  }
  return true;
}

mutation(["hello", "hey"]);