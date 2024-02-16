//protected
class User10 {
    protected x = 10;
}

class NewUser extends User10 {
    y = this.x;
}

let person = new NewUser()
console.log(person.y)

//static 키워드가 있으면 부모만 쓸 수 있음. 자식한테 안물려줌, object 복사 방지용

class UserStatic {
    static x = 10;
    y = 20;
    public static z = 50;   //public과 같이 사용
}

let son =new UserStatic()

//이렇게 부모에서만 접근
console.log(UserStatic.x)

class StaticUse {
    static skill = 'JS'
    intro = StaticUse.skill + ' expert'
}

let chan = new StaticUse()
console.log(chan.intro)

StaticUse.skill = 'C#'
let Kane = new StaticUse()
console.log(Kane.intro)