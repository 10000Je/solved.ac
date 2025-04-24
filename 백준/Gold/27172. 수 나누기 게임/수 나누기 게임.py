# no. 27172: 수 나누기 게임
# x1, x2, x3, ..., xn
# 만약 xi가 xj로 나누어 떨어지면,
# xi -= 1, xj += 1
# 만약 xj가 xi로 나누어 떨어지면,
# xi += 1, xj -= 1
# 둘다 아니라면, 변화 없음
# 에라토스테네스의 체 응용

from sys import stdin
input = stdin.readline

n = int(input())
nums = {num: 0 for num in map(int, input().split())}

for num in nums.keys():
    tmp = num*2
    while tmp <= 1_000_000:
        if tmp in nums:
            nums[num] += 1
            nums[tmp] -= 1
        tmp += num

print(*nums.values())