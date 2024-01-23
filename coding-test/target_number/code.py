def solution(numbers, target):
    n = len(numbers)
    answer = 0
    def DFS(level, result):
        if level == n:
            if result == target:
                nonlocal answer
                answer += 1
            return
        else:
            # 다음 수로 넘어갈 때마다 + 인 경우와 - 인 경우를 모두 고려
            DFS(level+1, result+numbers[level])
            DFS(level+1, result-numbers[level])
    DFS(0,0)
    return answer
'''
# BFS로 풀기
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
'''
