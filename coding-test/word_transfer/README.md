# Coding-Test
Problems for coding tests

## 문제 출처 : [programmers] : https://programmers.co.kr/learn/courses/30/lessons/43163
             
## 제목 :  단언 변환

## 문제 핵심
  + BFS를 이용한 풀이
  
## 문제 해결 방법
  + 단어 -> 변환어 의 모든 조합을 양방향으로 체크하여 리스트에 담는다.
  + 한쪽 방향만 체크하는 것이 아님에 주의
  + 시작 단어를 큐에 넣고 만들어 놓은 리스트를 BFS로 순회하면서 변환될 수 있는 단어들을 큐에 푸시
  + BFS로 순회하는 이유는 모든 방향으로 체크하면 타겟을 찾는 순간 다른 것은 볼 필요가 없기 때문
  + BFS로 순회할 때 레벨을 체크하는 것이 중요(level이 곧 변환 횟수이기 때문)
  + seen에 값을 넣을 때 똑같이 level 에 값을 넣어주고
  + 큐에서 값을 꺼낼 때 level에 같은 값이 하나라도 있으면 level을 clear한다.
  + level을 clear 할 때마다 레벨이 하나씩 늘어나는 것이기에 쉽게 변환 횟수를 얻을 수 있다.


