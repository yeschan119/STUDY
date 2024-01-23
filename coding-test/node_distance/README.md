# Coding-Test
Problems for coding tests

## 문제 출처 : programmers
## 문제 제목 : 가장 먼 노드 : [https://programmers.co.kr/learn/courses/30/lessons/49189]
## 문제 이해 : BFS로 풀면 무난한 문제
## 주의할 점 :  bidirectional graph 이기 때문에 양방향으로 체크해줘야 한다.
## 문제 해결  :
  + edge에 있는 모든 패스와 그 반대 패스(양방향)를 모두 배열에 저장하고
  + BFS로 1번 노드부터 돌면서 거리를 계산하여 입력한다.
  + BFS로 돌기 때문에 먼저 가는 노드가 항상 빨리 도착하는 노드이고 그것이 결국 1번에서 가장 가까운 거리이다.
  + BFS로 마지막 노드까지 다 돌면 거리가 나오고 거기서 max 개수를 
