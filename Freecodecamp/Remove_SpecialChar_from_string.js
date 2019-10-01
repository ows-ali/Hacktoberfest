var mystring = "Your$@string^&*";
mystring = mystring.replace(/[&\/\\#,+()$~%.'":*?<>{}]/g, '');
alert(mystring);
