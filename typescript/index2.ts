function test_func1 (x :number) : number {
    return x * 2;
}

function void_func (x :number) : void {
    console.log(x+2);
}
//x가 안들어와도 됨
//x?은 x :number | undefined 와 같음
function test_func2 (x? : number) : number {
    if (x) {
        return x + 2;
    }
    else {
        return 0;
    }
}

//or type은 애매해서 연산이 안됨. 이 경우 아래처럼 narrowing 해줌
function narrow_func(x :number | string) : number | string{
    if (typeof(x) === 'string') {
        return x + 1;
    }
    else if (typeof(x) == 'number') {
        return x * 2;
    }
    else {
        return 0;
    }
}

//narrowing을 쓰는 게 귀찮으면 아래처럼 assertion 쓰기
//왼쪽에 있는 x를 number type으로 덮어씀.
//as문법은 type이 확정일 때 쓰기 때문에 잘 쓰지 않기
function assert_func(x :number | string) : void{
    let array :number[] = [];
    array[0] = x as number;
}

console.log(narrow_func(10));
console.log(narrow_func('1'));