# Coding-Test
Problems for coding tests

## 문제 출처 : [programmers] : https://programmers.co.kr/learn/courses/30/lessons/43165
             
## 제목 :  타겟넘버

## 풀이
  + numbers에 있는 숫자들을 하나씩 볼 때마다 -, + 계산을 고려해야 하므로
  + 이는 root를 0으로 하는 binary tree와 같다.
  + 즉 결과로 생성되는 값의 개수는 2^len(numbers) 가 된다.
  + DFS로 풀기 - code
  + BFS로 풀기
  ~~~
  BFS로 풀기
  def solution(numbers, target):
      result = [0]
      for n in numbers:
          new_result = []
          while result:
              val = result.pop(0)
              new_result.append(val-n)
              new_result.append(val+n)
          result = new_result[:]
      answer = 0
      for n in result:
          if n == target:
              answer += 1
      return answer
  ~~~
