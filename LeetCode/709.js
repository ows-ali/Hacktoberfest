var toLowerCase = function(str) {
    const uppercase = ['A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z']
    const lowercase = ['a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z']
    let letters = str.split('')
    for (let i = 0; i<letters.length; i++) {
        if (uppercase.indexOf(letters[i]) != -1) {
            letters[i] = lowercase[`uppercase.indexOf(letters[i])`]
        }
    }

    return str.toLowerCase()
};
