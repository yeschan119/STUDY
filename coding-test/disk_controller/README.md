## 문제 출처 : [programmers] : [https://programmers.co.kr/learn/courses/30/lessons/42627]
## 제목 :  디스크 컨트롤러

## 문제 핵심
  + Heap 문제
  + 어렵진 않은데 좀 귀찮은 문제

## 문제 풀이 방법
  + 전체 job을 힙(priority queue)에 넣기
  + 하드가 비어 있을 때는 heappop(jobs) 해서 하드에 넣기
  + 해당 작업의 끝나는 시간이 하드의 작업 완료시간보다 늦은 경우 그냥 하드에 넣기
  + 아닐 때는 그 시간 대에 들어갈 수 있는 작업들을 모아서 그중 젤 빨리 끝나는 작업을 하드에 넣고 나머지는 다시 jobs에 푸시
  + 이런 식으로 jobs에 작업이 안 남을 때까지 loop
