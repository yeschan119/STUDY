def solution(triangle):
    depth = len(triangle)
    answer = 0
    memo = [[0]*len(t) for t in triangle]
    def dp_search(i, j):
        if i == depth:
            return 0
        if memo[i][j] > 0:
            return memo[i][j]
        memo[i][j] = triangle[i][j] + max(dp_search(i+1, j), dp_search(i+1, j+1))
        return memo[i][j]
    dp_search(0,0)
    answer = max(memo)[0]
    return answer