import sys
input = sys.stdin.readline


# 한 체스판은 8x8 = 64, n과 m은 8~50 -> 최대 43x43x64 = 118,336 개 탐색
n, m = map(int, input().split())
graph = [list(input().strip()) for _ in range(n)]
answer = 64
for i in range(len(graph)-7):
    for j in range(len(graph[0])-7):
        count = 0  # 제대로 위치한 체스판 개수
        for x in range(8):
            for y in range(8):
                # (0, 0)부터 (7, 7)까지, x와 y의 합이 짝수일 때 'W', 홀수일 때 'B'가 맞는 것으로 계산
                if (x+y) % 2 == 0 and graph[i+x][j+y] == 'W':
                    count += 1
                elif (x+y) % 2 == 1 and graph[i+x][j+y] == 'B':
                    count += 1
        # print(f'({i}, {j})에서 count={count}')  결과 확인 코드
        answer = min(answer, count, 64-count)  # 짝수 'W', 홀수 'B' 고정한 것의 반대 case도 계산
sys.stdout.write(str(answer))
