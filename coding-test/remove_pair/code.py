def solution(s):
    temp = []
    for ch in s:
        if len(temp) != 0 and ch == temp[-1]:
            temp.pop()
            continue
        else:
            temp.append(ch)
    if len(temp) == 0:
        return 1
    elif len(temp) == 1:
        return 0
    for i in range(len(temp)-1):
        if temp[i] != temp[i+1]:
            return 0
        
    answer = 1


    return answer
