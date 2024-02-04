//type alias
//type은 redefinition이 불가

type AnimalTYPE = string | number | undefined;
type OBJECT_TYPE = {name : string, age : number};
type OBJ_TYPE2 = {sex : boolean};
type BR_TYPE = { readonly name : string};


let animal:AnimalTYPE;

//object type extend
type NameTYPE = string;
type ADULT_TYPE = boolean;
type PERSON = NameTYPE | ADULT_TYPE;
type NEW_OBJ_TYPE = OBJECT_TYPE & OBJ_TYPE2;


//const는 원래 값을 수정하지 못하지만 const object의 경우 속성을 바꿀 수 있음
//(const는 재할당 금지이지 오브젝트 안 자료수정은 노상관) 그래서 readonly type 설정해주면 안에 있는 obj도 바꾸지 못함
const birth_region :BR_TYPE = {name : 'seoul'};