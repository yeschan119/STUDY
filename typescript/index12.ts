export type NAME = string;
export var name = 'Kang';

//type을 object로 감싸서 감춘다.
//import 할 때 이름이 겸칠 수 있기 때문에 namespace를 만들어 export
export namespace NEW_NAME {
    export type NEWNAME = string | number;
}

var age:NEW_NAME.NEWNAME = 30