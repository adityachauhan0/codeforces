def solve():
    s = input()
    if len(s) <= 3:
        print("NO")
    else:
        li = sorted(s)
        h = {}
        for i in li:
            h[i] = 0
        for i in li:
            h[i] += 1

        sett = [i for i in li if h[i] > 1]
        settt = set(sett)
        if (len(settt) <= 1 or len(li) - len(sett) > 1): print("NO")
        else: print("YES")
        



t = int(input())
for i in range(t):
    solve()