from math import gcd
def solution(w,h):
    num_of_pattern = gcd(w,h)   # gcd 구하기
    a = w/num_of_pattern  # 첫 패턴(2,3)은 패턴의 가로 세로가 되기에..
    b = h/num_of_pattern
    
    num_of_wasted_block = a + b - 1
    answer = (w * h) - (num_of_pattern * num_of_wasted_block)
    return answer