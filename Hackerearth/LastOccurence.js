process.stdin.resume();
process.stdin.setEncoding("utf-8");
var stdin_input = "";
let chunks=[]
 
process.stdin.on("data", function (input) {
    stdin_input += input;                               // Reading input from STDIN
});
 
process.stdin.on("end", function () {
   chunks=stdin_input.split("\n")
   let num=chunks[0].split(" ")
 
    let input1=chunks[1].split(" ").map(Number)
   let yes=[]
   for(let i=num[0];i>=0;i--){
       if(input1[i] == num[1]){
       
           yes.push(i+1)
       }
      
   }
  (yes[0] !== undefined)?console.log(yes[0]):console.log(-1)
 
   
});
