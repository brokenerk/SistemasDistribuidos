const time = require('convert-hrtime')
var cadenota=''
var num = 1757600
console.log("cadenas: "+num)
var init =process.hrtime()
for(var i=0;i<num;i++){
cadenota+=makeid(3)
}
console.log(ocurrences(cadenota,"IPN"))
console.log(time(process.hrtime(init)))
function ocurrences(cad,subcad){
return cad.split(subcad).length-1
}
function makeid(length) { var result = '';
var characters = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ';

var charactersLength = characters.length;
for ( var i = 0; i < length; i++ ) { 
result += characters.charAt(Math.floor(Math.random() * charactersLength)); 
} 
return result+' ';
}