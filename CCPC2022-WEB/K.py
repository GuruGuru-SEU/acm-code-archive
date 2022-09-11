import sys

y, q, seed = map(int, input().split())

while True:
    print(y)
    state = int(input())
    if state == 2:
        break
    sys.stdout.flush()
    y = y * 2
