void main() {
  String? name = "chan"; //null safefy

  name = null;

  if (name != null) {
    name.isNotEmpty;
  }

  dynamic name2;

  name2 = "eungchan";
  if (name2 is String) {
    //위에서 string check를 했기 때문에 함수 안에서는 String으로 동작, 함수를 벗어나면 다시 dynamic!! what a function
    print(name2.length);
  }

  final name3 = "eungchan"; //costant value of run-time
  print(name3);

  late final String name4; //do something later
  //print(name4);  // output error because of late keyword
  name4 = 'eungchan';
  print(name4);

  const const_var = 100; // constant value of compile-time
}
