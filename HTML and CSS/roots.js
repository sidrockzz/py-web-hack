var a = prompt("What is the value of 'a'?\n","");
var b = prompt("What is the value of 'b'?\n","");
var c = prompt("What is the value of 'c'?\n","");

var root_part = Math.sqrt(b * b - 4.0 * a * c);
var denom = 2.0 * a;

var root1 = (-b + root_part) / denom;
var root2 = (-b - root_part) / denom;
document.write("The first root is:",root1,"<br/>");
document.write("The second root is:",root2,"<br/>");
console.log("The roots are",root1,root2);

var question = confirm("Do you want to continue to download?");
alert("The roots are:"+root1+"\n"+root2);
