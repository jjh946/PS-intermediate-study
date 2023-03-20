import sys
input = sys.stdin.readline


n = int(input())
nums = list(map(int, input().split()))
nums.sort()  # 이분 탐색을 위한 정렬
m = int(input())
finds = list(map(int, input().split()))
for find in finds:
    lt, rt = 0, n-1
    while lt <= rt:
        pivot = (lt + rt) // 2  # 피벗은 중간지점으로
        if find == nums[pivot]:  # 타겟 넘버 발견 시
            sys.stdout.write('1\n')  # 1 출력
            break  # 반복문 탈출
        elif find > nums[pivot]:  # 피벗 값보다 크면
            lt = pivot + 1  # 피벗 위로 재탐색
        else:  # 피벗 값보다 작으면
            rt = pivot - 1  # 피벗 아래로 재탐색
    else:
        sys.stdout.write('0\n')
