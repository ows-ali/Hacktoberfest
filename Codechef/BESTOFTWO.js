//coded by CodeBreaker https://github.com/CodeBreaker518 

importPackage(java.io);
importPackage(java.lang);
 
let reader = new BufferedReader( new InputStreamReader(System['in']) );

let t = parseInt(reader.readLine());

for (let i = 0; i<t; i++){
    let v = reader.readLine().split(" ").map(function(i){return parseInt(i)});
    print(Math.max(v[0],v[1]))
}
