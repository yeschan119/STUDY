from collections import deque
def solution(begin, target, words):
    word_net = []
    words = [begin] + words
    # 데이터 준비
    for i in range(len(words)):
        for j in range(len(words)):
            cnt = 0
            for b, t in zip(words[i], words[j]):
                if b != t:
                    cnt += 1
            if cnt == 1:
                word_net.append([words[i], words[j]])
    # BFS 탐색 시작
    queue = deque()
    queue.append(begin)
    answer = 0
    found = False
    seen = {begin}
    level = []  # level을 체크하기 위해
    while queue:
        word = queue.popleft()
        if word in level:  # level이 하나씩 늘어나는 것
            level.clear()
            answer += 1
        for changed_word in word_net:
            if word == changed_word[0] and changed_word[1] not in seen:
                queue.append(changed_word[1])
                seen.add(changed_word[1])
                level += [changed_word[1]] # append 가 아니라 add 해준다.
        if target in seen:
            answer += 1
            found = True
            break
    # target을 못 찾았을 경우
    if found == False:
        answer = 0
    
    return answer
