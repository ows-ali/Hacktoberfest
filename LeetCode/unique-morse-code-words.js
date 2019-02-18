var uniqueMorseRepresentations = function(words) {
    morseAlphabet = [".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."]
    alphabet = ['a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z']

    let transformations = [];

    for(word of words) {
        let transformation = [];
        for (letter of word.split('')) {
            transformation.push(morseAlphabet[alphabet.indexOf(letter)])
        }
        if (transformations.indexOf(transformation.join('')) === -1) {
            transformations.push(transformation.join(''))
        }
    }

    return transformations.length

};
