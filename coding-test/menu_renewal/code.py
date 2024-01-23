from itertools import combinations
#각각의 주문에 대해 course 의 개수대로 짝지어 조합을 생성
# 생성된 조합에서 두 번 이상 등장하면서 가장 많이 등장하는 주문을 배열에 담아서 리턴
def solution(orders, course):
    orders.sort(key=lambda x:len(x))
    new_course = []   # 최종 선택되는 주문
    build_course = {} # 각각의 주문을 key, 주문횟수를 value
    test_course = [] # 모든 조합의 주문을 담는 배열
    for c in course:
        for order in orders:
            if len(order) > c:
                # 조합 생성
                order = list(combinations(order,c))
                # 조합을 생성하면 리스트 안에 튜플모양으로 생성된다.
                # 각각의 튜플을 하나의 문자열로 만들어서 저장
                # 'WX', 'XW' 와 같은 주문을 다른 것으로 인식하지 않게 미리 정렬하면서 저장
                order = [''.join(sorted(i)) for i in order]
            elif len(order) == c:
                order = [''.join(sorted(order))]
            else:
                continue  # 코스 개수에 미치지 못하는 주문은 패스
            test_course += order
        # 각각의 음식과 그것의 등장횟수를 이용한 build hash
        for food in test_course:
            build_course[food] = build_course.get(food, 0) + 1
        if len(build_course) > 0:
            #sorted(build_course.items(), key=lambda item:item[1], reverse=True)
            max_v = max(list(build_course.values()))
            for key, value in build_course.items():
                if max_v >= 2 and value == max_v:
                    new_course.append(key)
        build_course.clear()
        test_course.clear()
    new_course.sort()
    return new_course
