//??, ??=
//아래 3개 함수는 같은 일을 한다.
String upperCase(String? name) {
  if (name != null)
    return name.toUpperCase();
  else
    return "Annon";
}

String upperCase2(String? name) => name != null ? name.toUpperCase() : "Annon";

//name이 null이면 오른쪽 수행, 아니면 왼쪽 수행
String upperCase3(String? name) => name?.toUpperCase() ?? "Annon";

void main() {
  print(upperCase("eungchan"));
  print(upperCase2("eungchan"));
  print(upperCase3("eungchan"));

  //??=

  String? name;
  name ??= 'eungchan'; //name이 null이면 값을 입력
  print(name);
}
