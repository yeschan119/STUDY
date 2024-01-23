import heapq
def solution(jobs):
    heapq.heapify(jobs)
    disk = []
    while jobs:
        if not disk:
            temp = heapq.heappop(jobs)  # 하드가 비었을 때
            temp[1] = temp[0] + temp[1]
            disk.append(temp)
        elif jobs[0][0] >= disk[-1][1]:  # 시작시간이 충분히 느릴 때
            temp = heapq.heappop(jobs)
            temp[1] = temp[0] + temp[1]
            disk.append(temp)
        else:
            pivot = disk[-1][1]
            temp_work = []
            while jobs and jobs[0][0] <= pivot:  # 그 시간 대에 들어갈 수 있는 작업들 찾아서
                temp_work.append(heapq.heappop(jobs))
            temp_work = sorted(temp_work, key = lambda x:x[1])  # 완료시간이 가장 짧은 것으로 정렬
            temp = temp_work.pop(0)
            temp[1] = temp[1] + pivot
            disk.append(temp)
            for temp in temp_work:  # 나머지는 다시 푸시
                heapq.heappush(jobs, temp)
            
    disk = [work[1]-work[0] for work in disk]
    answer = sum(disk) // len(disk)
    return answer