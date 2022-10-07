console.log("Welcome to Tic Tac Toe")
let audioTurn = new Audio("ting.mp3")
let gameover = new Audio("gameover.mp3")
let newgame= new Audio("newgame.wav")
let justnew = new Audio("justnew.wav")
let music=new Audio("music.mp3")
let turn = "X"
let win=new Audio("win.mp3");
let isgameover = false;
var moves=0;
// Function to change the turn
const changeTurn = ()=>{
    return turn === "X"? "0": "X"
}

// music.play();
const checkWin = ()=>{    
    let boxtext = document.getElementsByClassName('boxtext');
    let wins = [
        [0, 1, 2, 5, 5, 0],
        [3, 4, 5, 5, 15, 0],
        [6, 7, 8, 5, 25, 0],
        [0, 3, 6, -5, 15, 90],
        [1, 4, 7, 5, 15, 90],
        [2, 5, 8, 15, 15, 90],
        [0, 4, 8, 5, 15, 45],
        [2, 4, 6, 5, 15, 135],
    ]
    wins.forEach(e =>{
        if((boxtext[e[0]].innerText === boxtext[e[1]].innerText) && (boxtext[e[2]].innerText === boxtext[e[1]].innerText) && (boxtext[e[0]].innerText !== "") ){
            document.querySelector('.info').innerText = boxtext[e[0]].innerText + " Won";
            win.play(); 
            isgameover = true
            document.querySelector('.imgbox').getElementsByTagName('img')[0].style.width = "300px";
            document.querySelector(".line").style.transform = `translate(${e[3]}vw, ${e[4]}vw) rotate(${e[5]}deg)`
            document.querySelector(".line").style.width = "20vw";
        }

    })
}

// Game Logic
// music.play()
let boxes = document.getElementsByClassName("box");
Array.from(boxes).forEach(element =>{
    let boxtext = element.querySelector('.boxtext');
    element.addEventListener('click', ()=>{
        if(boxtext.innerText === ''){
            boxtext.innerText = turn;
            turn = changeTurn();
            audioTurn.play();
            checkWin();
            if (!isgameover){
                document.getElementsByClassName("info")[0].innerText  = "Turn for " + turn;
                moves++;  
            } 

            else {
                document.getElementsByClassName("movesinfo")[0].innerText = "You took " + (moves + 1)  + " turns in total!";     
                moves=0;
                }
            }
            
        }) 
    })



// Add onclick listener to reset button
reset.addEventListener('click', ()=>{
    let boxtexts = document.querySelectorAll('.boxtext');
    Array.from(boxtexts).forEach(element => {
        element.innerText = ""
    });
    win.pause();
    win.currentTime=0;  
    if(isgameover)
        newgame.play();
    else 
        justnew.play();
    // turn==="X" ? turn="0" : turn="X"; 
    isgameover = false
     document.getElementsByClassName("movesinfo")[0].innerText = ""; 
     moves=0;
    document.querySelector(".line").style.width = "0vw";
    document.getElementsByClassName("info")[0].innerText  = "Turn for " + turn;
    document.querySelector('.imgbox').getElementsByTagName('img')[0].style.width = "0px"
})
