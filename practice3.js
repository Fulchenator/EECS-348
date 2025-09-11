function check_password() {
    var pass1 = document.getElementById("pass1").value;
    var pass2 = document.getElementById("pass2").value;


    if (pass1.length < 8) {
        alert("Sorry! Password 1 is less than 8 letters")
    } else if (pass2.length < 8) {
        alert("Sorry! Password 2 is less than 8 letters.")
    } else if (pass1 != pass2) {
        alert("Two passwords don't match!")
    } else {
        alert("Everything is OK!")
    }
}