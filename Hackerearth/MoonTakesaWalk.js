process.stdin.resume();
process.stdin.setEncoding("utf-8");
var stdin_input = "";
let chunks=[]
process.stdin.on("data", function (input) {
    stdin_input += input;                               // Reading input from STDIN
});
 
process.stdin.on("end", function () {
   chunks=stdin_input.split("\n")
let testcase=chunks[0]
for(let i=0;i<testcase;i++){
   main(chunks[i+1]);
   
}});
 
function main(input) {
    let count=0
    for(input of input){
    if(input.includes('A')||input.includes('E')||input.includes('I')||input.includes('O')||input.includes('U')||input.includes('a')||input.includes('e')||input.includes('i')||input.includes('o')||input.includes('u'))
{
    count++
}
}
    console.log(count)
}
