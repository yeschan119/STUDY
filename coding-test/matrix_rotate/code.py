def solution(rows, columns, queries):
    matrix = []
    row = []
    i = 1
    # rows X columns 행렬 만들기
    for r in range(rows):
        temp = []
        for c in range(columns):
            temp.append(i)
            i += 1
        matrix.append(temp)
    
    answer = []
    for q in queries:
        # x,y 부터 x1,y1 까지 회전
        x, y = q[0]-1, q[1]-1
        x1, y1 = q[2]-1, q[3]-1
        min_v = [] # 바뀌는 숫자들을 담는 배열
        regist = 0 # 바뀌는 값들 임시 저장
        flag = False # x와 x1의 차이가 1인 경우를 위한 flag
        for r in range(rows):
            if r == x:  # 위쪽 회전
                regist = matrix[x][y]
                for c in range(y, y1+1):
                    temp = matrix[r][c]
                    matrix[r][c] = regist  # 마지막 값을 담아두기
                    regist = temp
                    min_v.append(regist)
            elif r > x and r <= x1:  # 왼쪽과 오른쪽 회전
                if r == x1:
                    # 왼쪽, 오른쪽이자 아래쪽이라는 것을 표시
                    # 즉 [1,1,2,2] 와 같은 경우를 말함
                    flag = True
                for c in range(y, y1+1):
                    if c == y:  # 왼쪽 회전
                        matrix[r-1][c] = matrix[r][c]
                        min_v.append(matrix[r][c])
                    elif c == y1: # 오른 쪽 회전
                        temp = matrix[r][c]
                        matrix[r][c] = regist
                        regist = temp
                        min_v.append(regist)
            if r == x1:  # 아래쪽 회전
                if flag == True: # 이미 오른쪽 회전 시 마지막 값이 변경되었기에 그것을 제외
                    a,b = y1-1, y-1
                else:
                    a,b = y1, y-1
                for c in range(a, b, -1):
                    temp = matrix[r][c]
                    matrix[r][c] = regist
                    regist = temp
                    min_v.append(regist)
        answer.append(min(min_v))  # 변경된 값 중 가장 작은 값만 리스트에 추가
    return answer
