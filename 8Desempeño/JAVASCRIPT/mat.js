const time = require('convert-hrtime')
console.log("Calculos")
var i = 0
var seno
var cos
var tan
var log
var raiz
var max =1757600
var init =process.hrtime()
while(i<max){
seno+=Math.sin(i)
cos+=Math.cos(i)
tan+=Math.tan(i)
log+=Math.log(i)
raiz+=Math.sqrt(i)
i++
}
console.log(time(process.hrtime(init)))
console.log('done')