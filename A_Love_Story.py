n = int(input())
while n > 0:
    s = input()
    cnt = 0
    m = "codeforces"
    for i in range(len(s)):
        if s[i] != m[i]: cnt += 1
    print(cnt,end = "\n")
    n = n-1

