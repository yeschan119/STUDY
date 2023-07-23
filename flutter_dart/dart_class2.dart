//named constructor
//enum
//abstract class
//Mixin : mixin is a class that does not have a constructor.

enum Team { Red, Blue }

abstract class Place {
  void show_place_info();
}

mixin Rich {
  int property = 30000000000;
}

mixin class Welfare {
  int bonus = 10000;
  String vacation = "1 month per year";
}

class Class5 extends Place {
  late String name;
  late int age;
  late Team team;

  Class5.Blueteam({
    required String name,
    required int age,
  })  : this.name = name,
        this.age = age,
        this.team = Team.Blue;

  Class5.Redteam(String name, int age)
      : this.name = name,
        this.age = age,
        this.team = Team.Red;

  void show_info() {
    print("Hi m name is $name. I'm $age years old.");
  }

  void show_place_info() {
    //abstrace class member initialization
    print("This team is in Seoul.");
  }
}

class Company with Rich, Welfare {
  late final String name;
  late final int sales;

  Company.A({
    required String name,
    required int sales,
  })  : this.name = name,
        this.sales = sales;
  void show_info() {
    print("Name : $name, Sales : $sales, Property $property");
    print("Bonus : $bonus, Vacation : $vacation");
  }
}

void main() {
  var blueteam = Class5.Blueteam(name: "blue name", age: 30);
  var redteam = Class5.Redteam("red name", 31);
  blueteam.show_info();
  redteam.show_info();

  var anyteam = Class5.Blueteam(name: "chan", age: 33)
    ..team = Team.Blue; //cascade operator
  anyteam.show_info();

  var company = Company.A(name: "Tmax", sales: 5000000);
  company.show_info();
}
