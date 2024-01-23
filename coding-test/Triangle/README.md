# Coding-Test
Problems for coding tests

## 문제 출처 : [programmers] : [https://programmers.co.kr/learn/courses/30/lessons/43105]
             
## 제목 :  정수 삼각형

## 문제 핵심
  + DP를 응용한 문제
  + 효율성이 매우 중요한 문제
## 문제 해결 방법
  + 삼각형을 삼각형으로 보지 말고 그냥 2차원 배열로 봐야 함
  + Top - Down 방식으로 풀기
  + Top-down 이다보니 recursive로 구현.
  + 위에서부터 아래로 내려올 때마다 i+1, j : 왼쪽, i+1, j+1 : 오른쪽에서 큰값을 더하면서 memo에 저장


