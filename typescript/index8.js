var OOP = /** @class */ (function () {
    function OOP(name) {
        this.name = name;
        this.age = 30;
    }
    OOP.prototype.change_age = function (age) {
        this.age = age;
    };
    return OOP;
}());
var user = new OOP('Kane');
user.change_age(20);
console.log(user);
//public키워드를 이용하면 아래처럼 name을 따로 선언하지 않아도 됨
var OOP2 = /** @class */ (function () {
    function OOP2(name) {
        this.name = name;
        this.name = name;
    }
    return OOP2;
}());
var user2 = new OOP2('Kang');
var env = "IMS-Prod";
function test(env) {
    console.log(env);
    try {
        if (env == 'IMS') {
            console.log('IMS');
        }
        else {
            console.log('here');
            throw new Error('ERROR BBB');
        }
    }
    catch (error) {
        throw new Error(error.message);
    }
}
test(env);
