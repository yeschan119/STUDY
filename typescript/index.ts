/*terminal에서 tsc -w 입력해 놓으면 js파일 생성*/
/* main grammar*/
type MY_TYPE = string | number;
type OBJ_TYPE = {
    name? : string,
}
//object속성을 모두 string type으로 지정하면 어떤 속성이 들어와도 싸잡아서 string 체크
type OBJ_TYPE_LIST = {
    [key : string] : string,
}

let my_name :string = 'Kang';
let name_list :string[] = ['Kang', 'Ko'];
let union_name_list :MY_TYPE[] = ['Kane', 35];
let name_obj :{name? : string} = {name : 'Kane'};
let name_obj2 : OBJ_TYPE = {name : 'Kang'};
let comp_name :MY_TYPE = 'Kang';
comp_name = 1234;

let any_type :any;  //모든 타입을 다 받는 변수 virus type
let unknown_type :unknown;  //unknown type

//number type을 받아서 number type만 리턴해야하는 엄격한 타입
function test_func(arg : number) : number {
    return arg * 2;
}

//tuple type
type TUP_TYPE = [number, boolean];
let school_list : TUP_TYPE = [123, true];

class User {
    name :string; 
    constructor(name : string) {
        this.name = name;
    }
}