def check_rule(p, place, flag):
    cnt = 0
    if p[0] > 0 and place[p[0]-1][p[1]] == 'P':
        cnt += 1
    if p[0] < len(place)-1 and place[p[0]+1][p[1]] == 'P':
        cnt += 1
    if p[1] > 0 and place[p[0]][p[1]-1] == 'P':
        cnt += 1
    if p[1] < len(place[0])-1 and place[p[0]][p[1]+1] == 'P':
        cnt += 1
    if flag == 'P' and cnt > 0:
        return False
    elif flag == 'O' and cnt > 1:
        return False
    return True
def solution(places):
    answer = []
    for idx, place in enumerate(places):
        rule = True
        for i in range(len(place)):
            for j in range(len(place[0])):
                if place[i][j] == 'P':
                    if not check_rule([i,j], place,'P'):
                        rule = False
                        break
                elif place[i][j] == 'O':
                    if not check_rule([i,j], place,'O'):
                        rule = False
                        break
            if rule == False:
                answer.append(0)
                break
        else:
            answer.append(1)
    
    
    return answer
