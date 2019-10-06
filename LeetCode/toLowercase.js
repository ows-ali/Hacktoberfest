// https://leetcode.com/problems/to-lower-case/

/**
 * @param {string} str
 * @return {string}
 */
const toLowerCase = (str) => {
    const lowercased = []
    for(let i = 0; i<str.length; i++) {
        const lowerCaseNum = str[i].charCodeAt(0) + 32
        lowercased.push(String.fromCharCode(lowerCaseNum))
    }
    return lowercased.join('')
};