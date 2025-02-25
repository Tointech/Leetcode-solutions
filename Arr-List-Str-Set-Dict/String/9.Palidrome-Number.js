var isPalindrome = function(x) {
    let strNum = x.toString();
    let result = strNum.split('').reverse().join('');

    if (strNum == result) {
        return true;
    } else {
        return false;
    }
}

x=101
console.log(isPalindrome(x))