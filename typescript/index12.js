"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
exports.name = void 0;
exports.name = 'Kang';
var age = 30;
//generic 함수
function 함수(x) {
    return x[0];
}
var a = 함수([10, 5]);
//let b = a + 1;  에러 발생함. 함수 파라미터 타입을 unknown으로 지정했기 때문
//위와 같은 문제를 해결하기 위해 generic함수 사용(narrowing이 필요 없음)
function 함수2(x) {
    return x[0];
}
var b = 함수2([10, 5]);
var c = b + 10;
