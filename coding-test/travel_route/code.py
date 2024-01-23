def solution(tickets):
    answer = ["ICN"]  # 출발점
    remained_list = []  # 더는 갈 수 없는 공항을 담는 리스트
    # 재귀함수로 해결
    # 함수를 호출할 때마다 시작 공항과 현재 남아 있는 경로 리스트를 전달하고
    # 위의 1~3번 작업을 수행
    def dfs_search(start, tickets):
        if not tickets:
            return
        # 선택되는 공항과 그 공항의 인덱스를 같이 담기 위해 사용
        # 인덱스를 저장하는 이유는 tickets에서 선택된 공항을 제거하기 위함
        temp_list = {}
        for i, ticket in enumerate(tickets):
            if ticket[0] == start:
                temp_list[ticket[1]] = i
        # 만일 start에서 갈 수 있는 공항을 찾지 못한 경우
        if len(temp_list) == 0:
            remained_list.append(answer.pop())
            dfs_search(answer[-1], tickets)
        else: # 목적지들을 정렬. 알파벳 순이 높은 것만 하나 뽑기 위해
            temp_list = sorted(temp_list.items(), key=lambda item:item[0])
            ticket = temp_list[0][0]
            answer.append(ticket)
            idx = temp_list[0][1]
            del tickets[idx]   # 선택된 목적지를 tickets에서 제거
            dfs_search(ticket, tickets)
    dfs_search('ICN', tickets)
    # 더 이상 갈 수 없었던 공항들을 다시 합치기
    if len(remained_list) > 0:
        while remained_list:
            answer.append(remained_list.pop())
    return answer
