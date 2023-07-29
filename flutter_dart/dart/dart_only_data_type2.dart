//int list type definition

typedef INT_LIST = List<int>;

INT_LIST reverseOfNumbers(INT_LIST list) {
  var reversed = list.reversed;
  return reversed.toList();
}

//type definition for map

typedef UserInfo = Map<String, String>;

String get_user_info(UserInfo info) {
  return "Hi ${info['name']}";
}

void main() {
  print(reverseOfNumbers([1, 2, 3, 4, 5]));
  print(get_user_info({"name": "eungchan"}));
}
