import heapq
def solution(operations):
    minheap = []
    maxheap = []
    idx = 0  # 힙이 비었는지 알기 위해
    for op in operations:
        op = op.split()
        if op[0] == 'I':
            n = int(op[1])
            # min-heap, max-heap 에 동시에 넣기
            heapq.heappush(minheap, n)
            heapq.heappush(maxheap, (-n, n))
            idx += 1
        else:
            if idx > 0 and op[1] == '1':
                # max-heap 에서 최대값을 꺼내고 동시에 min-heap에서도 제거
                p = heapq.heappop(maxheap)[1]
                minheap.remove(p)
                idx -= 1
            elif idx > 0 and op[1] =='-1':
                p = heapq.heappop(minheap)
                maxheap.remove((-p, p))
                idx -= 1
    minheap.sort()
    if len(minheap) == 0:
        answer = [0,0]
    else:
        answer = [minheap[-1], minheap[0]]
    return answer