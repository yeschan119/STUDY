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

setTimeout(function() {
    console.log('=============')
    logName()
}, 3000)