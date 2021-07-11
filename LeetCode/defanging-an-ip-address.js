// https://leetcode.com/problems/defanging-an-ip-address/


/**
 * @param {string} address
 * @return {string}
 */

// assuming the address is valid already, so there is no validity check
const defangIPaddr = (address) => {
    return address.replace(/\./g,"[.]")
};