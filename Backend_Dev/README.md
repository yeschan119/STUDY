# 책 읽기
## 목적
### 회사일은 너~무 깊고 좁다. 1년에 한 번씩 이직하지 않는 한 개발에 대한 전체적인 이해와 지식을 얻기 힘듬.
### 아는 것들은 다시 한번 정리하면서 기록, 몰랐던 것들은 새롭게 기록
## Title of Book
### Backend Develop in 30 days.(By Pedro Marquez-Soto)
## Web Server 구현
+ IP + Port = Socket 이라고 함
+ client가 요청을 보내면 Server가 응답하는데, 이때 동적/정적 응답 가능
  + 정적 : Apache, nginx와 같은 서버의 동작
  + 동적 : Jave Servlet, PHP와 같은 웹 애플리케이션 기술이 동작하는 방식
+ web server의 endpoint를 확인하기 위해서는 브라우저를 통해 확인할 수도 있고 terminal/bash에서 <code>CURL</code>을 통해서 확인할 수 있음
  + <code>curl localhost:8080/index.html</code>
  + <code>curl localhost:8080/dynamic.html</code>
  + curl은 이렇게 동시에 여러 리소스를 요청할 수 있음
+ Multi Threading
  + 일반적으로 서버에는 동시 접속이 진행되기 때문에 multi threading으로 구현되어야 함
  + 서버의 응답을 받아서 동작하는 함수를 클래스로 따로 구현하고 호출을 받을 때마다 new server_action() 할 수 있는데, 이렇게 하면 thread 제한에 걸릴 수 있기 때문에, Java의 경우 ThreadPoolExecutor() 기능 사용
    + ThreadPoolExecutor()는 요청할 때마다 new thread를 성하는 대신, 정해진 개수 안에서 thread 재사용이 가능
