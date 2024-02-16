var __extends = (this && this.__extends) || (function () {
    var extendStatics = function (d, b) {
        extendStatics = Object.setPrototypeOf ||
            ({ __proto__: [] } instanceof Array && function (d, b) { d.__proto__ = b; }) ||
            function (d, b) { for (var p in b) if (Object.prototype.hasOwnProperty.call(b, p)) d[p] = b[p]; };
        return extendStatics(d, b);
    };
    return function (d, b) {
        if (typeof b !== "function" && b !== null)
            throw new TypeError("Class extends value " + String(b) + " is not a constructor or null");
        extendStatics(d, b);
        function __() { this.constructor = d; }
        d.prototype = b === null ? Object.create(b) : (__.prototype = b.prototype, new __());
    };
})();
//protected
var User10 = /** @class */ (function () {
    function User10() {
        this.x = 10;
    }
    return User10;
}());
var NewUser = /** @class */ (function (_super) {
    __extends(NewUser, _super);
    function NewUser() {
        var _this = _super !== null && _super.apply(this, arguments) || this;
        _this.y = _this.x;
        return _this;
    }
    return NewUser;
}(User10));
var person = new NewUser();
console.log(person.y);
//static 키워드가 있으면 부모만 쓸 수 있음. 자식한테 안물려줌, object 복사 방지용
var UserStatic = /** @class */ (function () {
    function UserStatic() {
        this.y = 20;
    }
    UserStatic.x = 10;
    UserStatic.z = 50; //public과 같이 사용
    return UserStatic;
}());
var son = new UserStatic();
//이렇게 부모에서만 접근
console.log(UserStatic.x);
var StaticUse = /** @class */ (function () {
    function StaticUse() {
        this.intro = StaticUse.skill + ' expert';
    }
    StaticUse.skill = 'JS';
    return StaticUse;
}());
var chan = new StaticUse();
console.log(chan.intro);
StaticUse.skill = 'C#';
var Kane = new StaticUse();
console.log(Kane.intro);
