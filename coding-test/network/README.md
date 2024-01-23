## 문제 출처 : [programmers] : [https://programmers.co.kr/learn/courses/30/lessons/43162]
## 제목 :  네트워크

## 문제 핵심
  + 전형적인 DFS문제

## 문제 풀이 방법
  + computers를 행렬로 보고 [i,j]가 1인 것들만 따로 저장
  + [i,j]가 1이라는 것은 i와 j가 연결되었다는 것
  + 0번째 컴부터 따로 저장된 네트워크를 탐색하면서 연결되어 있는 것들을 모조리 탐색
