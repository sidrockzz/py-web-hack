var today = new Date();

var dateString = today.toLocaleString();
var day = today.getDay();
var month = today.getMonth();
var year = today.getFullYear();
var timeMilliseconds = today.getTime();
var hour = today.getHours();
var minute= today.getMinutes();
var second = today.getSeconds();
var milliseconds = today.getMilliseconds();

document.write(
  "Date: " + dateString + "<br/>",
  "Day: " + day +"<br />",
  "Month: "+ month + "<br/>",
  "Year:" + year + "<br/>",
  "Time in Milliseconds:" + timeMilliseconds + "<br/>",
  "Hour:" + hour + "<br/>",
  "Minute: "+ minute + "<br/>",
  "Second"+ second + "<br/>",
  "Milliseconds:" + milliseconds + "<br/>"
);

var dum1 = 1.00149265,product =1;
var start = new Date();

for(var count=0; count < 10000;count++)
product = product + 1.000002 * dum1 /1.00001;

var end = new Date();
var diff = end.getTime()-start.getTime();
document.write("<br/> The loop took"+diff + "milliseconds <br/>");
