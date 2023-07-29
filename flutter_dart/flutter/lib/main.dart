import 'package:flutter/material.dart';

//runApp은 root widget이고 root widget은 둘 중 하나를 리턴
// return material application or cupertino application
// material is a design system of Google. cupertino is a design system of Apple.
void main() {
  runApp(App());
}

//runApp은 class를 실행시켜서 앱으로 보여주는 것이고
//flutter에서 class는 widget역할을 한다. flutter는 widget들의 모음
//class가 widget역할을 하려면 flutter가 가지고 있는 3개의 core widget을 상속받아야 하는데
//아래가 가장 기본적인 widget이다.
//상속 받고 나서 build method를 override 해줘야 한다. that's rule.
//그 이유는 flutter가 뭔가를 화면에 출력할 때 항상 build method를 찾아 build method가 return하는 것을(무엇이든) 출력해줌.
class App extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    // TODO: implement build

    return MaterialApp(
      //scaffold is a structture of your screen for app.
      home: Scaffold(
        appBar: AppBar(
          title: Text('Webtoon Flix'),
        ),
        body: Center(
          child: Text('Start Building Webtoon Flix Application!'),
        ),
      ),
    );
    //throw UnimplementedError();
  }
}
