    const randomColor = () => {
        const r = Math.floor(Math.random() * 256); // 0-255
        const g = Math.floor(Math.random() * 256); // 0-255
        const b = Math.floor(Math.random() * 256); // 0-255
        return `rgb(${r}, ${g}, ${b})`;
    }

    let intervalID;
    let isChanging = false;

    // Toggle function
    function toggleColors() {
        if (!isChanging) {
            intervalID = setInterval(() => {
                document.querySelector('body').style.backgroundColor = randomColor();
            }, 200);
            isChanging = true;
        } else {
            clearInterval(intervalID);
            isChanging = false;
        }
    }

    // Desktop - Spacebar
    addEventListener('keydown', function(event) {
        if (event.code === 'Space') {
            toggleColors();
        }
    });

    // Mobile - Double tap
    let lastTap = 0;
    document.addEventListener('touchend', function(event) {
        const currentTime = new Date().getTime();
        const tapLength = currentTime - lastTap;
        if (tapLength < 300 && tapLength > 0) { // double tap within 300ms
            toggleColors();
        }
        lastTap = currentTime;
    });


    if (window.innerWidth < 768) {
    document.querySelector("h3").innerText = 
    "Double tap anywhere to start/stop changing background colors";
    }


        
