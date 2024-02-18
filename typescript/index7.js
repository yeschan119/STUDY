function rest_param() {
    var a = [];
    for (var _i = 0; _i < arguments.length; _i++) {
        a[_i] = arguments[_i];
    }
    console.log(a);
}
rest_param(1, 2, 3, 4, 5);
//narrowing
function narrowing_func(a) {
    if (a && typeof a == 'string') {
        console.log('undefined, null, string narrow');
    }
}
//생성된 type은 typeof 변수 이런 반법으로 narrowing인 안됨
//narrowing이 되는 type은 string, number, boolean 등. 따라서 아래와 같이 narrowing
function animal_func(animal) {
    if ('swim' in animal) {
    }
    else if ('fly' in animal) {
    }
}
var the_date = new Date();
if (the_date instanceof Date) {
    console.log('object instanceof parent class로 narrowing');
}