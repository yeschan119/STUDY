def solution(n, computers):
    network = []
    answer = 0
    if n == 1:
        return 1
    for i in range(n):
        for j in range(n):
            if computers[i][j] == 1:
                network.append([i,j])
    seen = set()
    visited = [0 for _ in range(n)]
    for i in range(n):
        if visited[i] == 1:
            continue

        stack = [i]
        seen.add(i)
        answer += 1
        while stack:
            com = stack.pop()
            visited[com] = 1

            for net in network:
                if com == net[0] and net[1] not in seen:
                    stack.append(net[1])
                    seen.add(net[1])
    return answer