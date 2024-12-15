ntest = int(input())
for _ in range(ntest):
    n = int(input())
    a = map(int, input().split())
    cnt1, cnt2 = 0, 0
    for x in a:
        if x == 1:
            cnt1 += 1
        else:
            cnt2 += 1
            cnt1 += x - 2
    print(cnt1 // 2 + cnt2 // 2)
