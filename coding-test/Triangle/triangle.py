def solution(n):
    result = []
    while n != 0:
        remain = n % 3
        if remain == 0:
            remain = 4
            n -= 1
        result.append(str(remain))
        n //= 3
    answer = ''.join(result[::-1])
    return answer