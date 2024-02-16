function logName() {
    console.log('timeout start');
    setTimeout(function () {
        console.log('timeout loading...');
    }, 2000);
    console.log('timeout end');
}
logName();
