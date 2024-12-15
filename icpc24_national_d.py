def solve(G, W, R, T):
    c = G + W + R
    time = (T + 0.5) % c

    if time < G:
        return "Guiding Beat"
    elif time < G + W:
        return "Warning Beat"
    else:
        return "Resting Phase"

for _ in range(int(input())):
    G, W, R, T = map(int, input().split())
    print(solve(G, W, R, T))
