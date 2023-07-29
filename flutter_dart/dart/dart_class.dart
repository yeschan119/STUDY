//class안에서 선언되는 변수는 반드시 변수 타입을 지정!!
class Class1 {
  final String name = 'chan'; //no changed
  int age = 30;

  void show_info() {
    print(
        "Hi my name is $name, I'm $age years old."); //dart에서만 허용. this.name도 역시 허용
  }
}

class Class2 {
  late final String name;
  late int age;

  Class2(String name, int age) {
    this.name = name;
    this.age = age;
  }

  void show_info() {
    print("Hi my name is $name, I'm $age years old.");
  }
}

class Class3 {
  late final String name;
  late int age;

  Class3(this.name, this.age);

  void show_info() {
    print("Hi my name is $name, I'm $age years old.");
  }
}

class Class4 {
  late final String name;
  late int age;

  Class4({
    required this.name, //required because name can be null
    required this.age,
  });

  void show_info() {
    print("Hi my name is $name, I'm $age years old.");
  }
}

void main() {
  var class1 = Class1();
  class1.show_info();

  var class2 = Class2("chan", 33);
  class2.show_info();

  var class3 = Class3("chan", 34);
  class3.show_info();

  var class4 = Class4(
    name: "chan",
    age: 35,
  );

  class4.show_info();
}
