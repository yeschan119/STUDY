from collections import deque
def solution(n, edge):
    Limit = 500000
    # 노드간 거리를 저장
    Nodes = [Limit for i in range(n+1)]  # 1번 ~ n번까지 수행해야 하므로 n+1
    # 모든  edge롤 포함(양방향으로))
    vertex = [[] for i in range(n+1)]
    for path in edge:
        if path[1] not in vertex[path[0]]:
            vertex[path[0]].append(path[1])
        if path[0] not in vertex[path[1]]:
            vertex[path[1]].append(path[0])
    Nodes[1] = 0
    queue = deque([1])
    while queue:
        node = queue.popleft()
        for path in vertex[node]:
            if Nodes[path] > Nodes[node] + 1:
                queue.append(path)
                Nodes[path] = Nodes[node] + 1
            
    answer = 0
    Nodes.pop(0)  # 0번째 노드는 없으므로 빼기
    Nodes.sort(reverse=True)
    
    max_node = Nodes[0]
    for node in Nodes:
        if node == max_node:
            answer += 1
        else:
            break
    return answer