void main() {
  bool test = true;
  num number; //name is the base class of int, double..
  number = 10;
  number = 10.99;
  //list
  var numbers = [
    1,
    2,
    3,
    4,
  ];
  List<int> num_list = [1, 2, 3];
  numbers.add(10);
  print(numbers);

  //collection if 기능

  var five = true;
  var five_list = [
    1,
    2,
    3,
    4,
    if (five) 5,
  ];

//string interpolation
  var name5 = 'eungchan';
  var age = 30;
  var greeting = 'Hello my name is $name5 and ${age + 2} years old';
  print(greeting);

//collection for
  var oldFriends = ['nico', 'lynn'];
  var newFriends = [
    'lewis',
    'ralph',
    'darren',
    for (var friend in oldFriends) "**$friend**",
  ];
  print(newFriends);

  //map
  var player = {
    'name': 'chan',
    'age': '33',
    'superpower': false,
  };
  print(player);

  Map<int, bool> player2 = {
    1: true,
    2: false,
    3: false,
  };
  print(player2);

  Map<List<int>, bool> player3 = {
    [1, 2]: true,
    [3, 4]: false,
  };
  print(player3);

  //set
  //set과 list가 다른 점은 set에 속한 목록은 모두 유니크하다는 거
  var set_ex = {1, 2, 3};
  set_ex.add(1);
  set_ex.add(1);
  print(set_ex); //중복되는 숫자는 추가 안되었음

  //typde def
}
