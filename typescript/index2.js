function test_func1(x) {
    return x * 2;
}
function void_func(x) {
    console.log(x + 2);
}
//x가 안들어와도 됨
//x?은 x :number | undefined 와 같음
function test_func2(x) {
    if (x) {
        return x + 2;
    }
    else {
        return 0;
    }
}
//or type은 애매해서 연산이 안됨. 이 경우 아래처럼 narrowing 해줌
function narrow_func(x) {
    if (typeof (x) === 'string') {
        return x + 1;
    }
    else if (typeof (x) == 'number') {
        return x * 2;
    }
}
console.log(narrow_func(10));
console.log(narrow_func('1'));
