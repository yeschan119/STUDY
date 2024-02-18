//type, var export
export type NAME = string;
export var name = 'Kang';

//type을 object로 감싸서 감춘다.
//import 할 때 이름이 겸칠 수 있기 때문에 namespace를 만들어 export
export namespace NEW_NAME {
    export type NEWNAME = string | number;
}

var age:NEW_NAME.NEWNAME = 30

//generic 함수
function 함수(x : unknown[]) {
    return x[0]
}

let a = 함수([10,5])

//let b = a + 1;  에러 발생함. 함수 파라미터 타입을 unknown으로 지정했기 때문
//위와 같은 문제를 해결하기 위해 generic함수 사용(narrowing이 필요 없음)
function 함수2<Type>(x :Type[]):Type {
    return x[0]
}

let b = 함수2<number>([10, 5])
let c = b + 10