var numUniqueEmails = function(emails) {
    let array = []
    for (let i = 0;i<emails.length;i++) {
        let email;
        email = (emails[i].split(emails[i].match(/\+(.*?)\@/g)))
        email[0] = email[0].replace(/[.]/g, "")
        email = email.join('')
        console.log(email)
        if (array.indexOf(email) === -1) {
            array.push(email)
        }
    }
    return array.length
};
