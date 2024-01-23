import heapq
def solution(scoville, K):
    answer = 0
    if K == 0:
        return 0
    # heapify를 통해 heap 생성
    heapq.heapify(scoville)
    while len(scoville) > 1:
        if scoville[0] < K:
            s1 = heapq.heappop(scoville)
            s2 = heapq.heappop(scoville)
            new_s = s1 + (s2*2)
            heapq.heappush(scoville, new_s)
            answer += 1
        else:
            break
    # 모든 음식의 스코빌 지수를 K 이상으로 만들 수 없을 경우
    if len(scoville) == 1 and scoville[0] < K:
        return -1
    return answer
