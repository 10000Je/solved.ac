import sys
from collections import deque
input = sys.stdin.readline

v = int(input())
tree = {i: {} for i in range(1, v+1)}
for _ in range(v):
    nums = tuple(map(int, input().split()))
    start = nums[0]
    for i in range(1, len(nums)-1):
        if i % 2:
            end = nums[i]
        else:
            tree[start][end] = nums[i]
            tree[end][start] = nums[i]

def bfs(start):
    cur_queue = deque((start,))
    dist = {start: 0}
    while cur_queue:
        root = cur_queue.popleft()
        for child, weight in tree[root].items():
            if child in dist:
                continue
            cur_queue.append(child)
            dist[child] = dist[root]+weight
    return max(dist.items(), key=lambda x:x[1])

a = bfs(1)[0]
b = bfs(a)
print(b[1])