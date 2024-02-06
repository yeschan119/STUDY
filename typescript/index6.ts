type square = {color : string, width : number}
interface triangle {color : string, height : number}

let nemo : square = {color : 'red', width : 100}
let samgak : triangle = {color : 'blue', height : 100}

//type대신 instance를 쓰는 이유는 extends가 가능하기 때문
interface student {
    name : string,
    age : number
}

interface teacher extends student{
    subject : string
}

let st : student = {name : 'kim', age : 10}
let th : teacher = {name : 'kang', age : 30, subject : 'Computer Science'}

// & 으로도 extends처럼 씀
type Animal = {name : string}
//정확히는 intersection으로 왼쪽과 오른쪽을 모두 만족하는 타입이 생성됨.
type Cat = {age : number} & Animal

//type과 interface가 다른 점은 extends외에 중복선언이 가능함
//아래처럼 중복으로 선언하면 자동 extends가 됨
interface Parent {
    name : string
}
interface Parent {
    age : number
}