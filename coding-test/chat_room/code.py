def solution(record):
    kakao = {}
    
    for ID in record:
        temp = ID.split()
        if temp[0] == 'Enter' or temp[0] == 'Change':
            kakao[temp[1]] = temp[2]
    answer = []
    for room in record:
        temp = room.split()
        if temp[0] == 'Enter':
            answer.append(str(kakao[temp[1]])+"님이" +" " +"들어왔습니다.")
        elif temp[0] == 'Leave':
            answer.append(str(kakao[temp[1]]) + "님이" + " " + "나갔습니다.")
    
    
    return answer
