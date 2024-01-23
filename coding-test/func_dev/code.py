def solution(progresses, speeds):
    result = []
    answer = []
    if len(progresses) == 0:
        return []
    for p, s in zip(progresses, speeds):
        day = 0
        while p < 100:
            p += s
            day += 1
        result.append(day)  # 각각의 progress 들의 끝나는 날짜를 계산하여 저장
    print(result)
    #count = 1
    i = 0
    while i < len(result):
        count = 1
        if result[i] == 0:  # 미리 계산한 작업은 패스
            i += 1
            continue
        temp = result[i]
        result[i] = 0 # 해당 작업 완료
        for j in range(i+1, len(result)):
            if temp >= result[j]:   # 완료된 작업 보다 늦게 시작했지만 일찍 끝나는 작업은
                result[j] = 0       # 완료 표시
                count += 1
            else:
                break
        answer.append(count)  # 같은 시기에 몇 개의 작업이 끝났는지 확인
        i += 1
    return answer
