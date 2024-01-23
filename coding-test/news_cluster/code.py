import math
def solution(str1, str2):
    
    defined_v = 65536
    str1 = str1.lower()
    str2 = str2.lower()
    # 문자열로 리스트 만들기
    str1 = list(map(str, str1))
    str2 = list(map(str, str2))
    #str1 = list(filter(str.isalpha, str1))
    #str2 = list(filter(str.isalpha, str2))
    string1 = {}
    string2 = {}
    
    for i in range(len(str1)-1):
        string = str1[i] + str1[i+1]
        if string.isalpha():  # 문자로 이루어진 것만 저장
            string1[string] = string1.get(string, 0) + 1
    for i in range(len(str2)-1):
        string = str2[i] + str2[i+1]
        if string.isalpha():
            string2[string] = string2.get(string, 0) + 1
    intersect_v = 0
    union_v = 0
    # A 문자열에 B 문자열을 해싱하면서 A 문자열의 value를 변경하여 합집합 계산
    for key in string2.keys():
        if key in string1:
            if string1[key] == string2[key]:
                intersect_v += string1[key]
                # 중복값이 있을 경우 더 작은 문자열이 교차집합, 많은 문자열이 합집합(조건)
            elif string1[key] > string2[key]:
                intersect_v += string2[key]
            else: # 교집합은 비교하면서 바로 만들고 합집합은 마지막에 첫번째 문자열로 생성
                intersect_v += string1[key]
                string1[key] = string2[key]
        else:
            string1[key] = string2[key]
    
    union_v = sum(list(string1.values()))
    if union_v == 0:
        return defined_v
    answer = math.trunc(defined_v * (intersect_v/union_v))
    
    return answer
