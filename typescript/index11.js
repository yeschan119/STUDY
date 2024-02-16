function timeoutFunc() {
    var ret
    console.log('timeout start.');
    return new Promise(function(resolve, reject) {
        setTimeout(function () {
            ret = 'timeout loading...'
            resolve(ret)
        }, 2000);
    })
}

//promise then
timeoutFunc().then(function(data) {
    console.log(data + ' then')
    console.log('timeout end then.')
}).catch(function(error) {
    console.log(error)
})

//async await
async function logName() {
    try {
        var result = await timeoutFunc();
    console.log(result + ' await')
    console.log('timeout end await.')
    } catch(error) {
        console.log(error)
    }
}

//동일 함수를 두 가지 방법으로 순차적 수행
setTimeout(function(){
    console.log('=============')
    logName()
}, 3000)