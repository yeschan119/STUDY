//fat arrow(=>)를 사용할 수 있음

String sayHello(String name) => "Hello $name, Nice to meet you";

//named argument function with default value
void show_info(
    {String name = 'anon', int age = 0, String country = 'galapagos'}) {
  print("My name is $name and Age is $age and country is $country");
}

//일반적인 파라미터는 positional parameter, here is named parameter
//named argument function with required keyword
void show_info2({
  required String name,
  required int age,
  required String country,
}) {
  print("hello $name, you are $age, and you come from $country");
}

//optional positional parameter, country must be a named parameter and others don't matter
//country가 null일 수도 있음(String?) 만일 null이면 cuba로 대체
String show_info3(String name, int age, [String? country = 'cuba']) =>
    "Hello $name, $age, $country are all your information.";

void main() {
  print(sayHello("eungchan"));
  show_info(
    name: 'chan',
    age: 30,
    country: 'cuba',
  );

  show_info2(
    name: 'eung',
    age: 30,
    country: "Korea",
  );

  print(show_info3("eungchan", 30));
}
