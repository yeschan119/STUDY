var my_name = 'Kang';
var name_list = ['Kang', 'Ko'];
var union_name_list = ['Kane', 35];
var name_obj = { name: 'Kane' };
var name_obj2 = { name: 'Kang' };
var comp_name = 'Kang';
comp_name = 1234;
var any_type; //모든 타입을 다 받는 변수 virus type
var unknown_type; //unknown type
//number type을 받아서 number type만 리턴해야하는 엄격한 타입
function test_func(arg) {
    return arg * 2;
}
var school_list = [123, true];
var User = /** @class */ (function () {
    function User(name) {
        this.name = name;
    }
    return User;
}());
