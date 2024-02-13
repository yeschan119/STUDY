class OOP {
    public name : string //public은 default이므로 안붙여도 됨
    private age : number;
    constructor (name) {
        this.name = name
        this.age = 30
    }

    change_age(age:number) : void {
        this.age = age
    }
}

let user = new OOP('Kane');
user.change_age(20)
console.log(user);

//public키워드를 이용하면 아래처럼 name을 따로 선언하지 않아도 됨
class OOP2 {
    constructor (public name) {
        this.name = name;
    }
}

let user2 = new OOP2('Kang')