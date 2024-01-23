# Coding-Test
Problems for coding tests

## 문제 출처 : [programmers] : https://programmers.co.kr/learn/courses/30/lessons/43164
             
## 제목 :  여행 경로

## 문제 핵심
  + DFS를 살짝 응용해서 푸는 문제
  
## 문제 해결 방법
  + ICN을 먼저 스택에 넣기
  +  스택 top을 보고 거기서부터 갈 수 있는 공항들을 tickets에서 검색.
  +  ** 스택에서 꺼내지 않음. 즉 pop이 아니고 top
  +  여러 개 있을 경우 알파벳 순서가 높은 것을 하나 넣기(ex: ATL, SOF 라면 ATL을 선택)
  +  스택에 넣은 경로(ex: ICN-ATL)는 tickets에서 제거
  +  tickets의 경로가 모두 제거될 때까지 1 ~ 3번을 반복
  +  tickets의 모든 경로가 제거되면, stack을 출력.


