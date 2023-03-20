import sys
input = sys.stdin.readline


n = int(input())
words = []
# 기본적으로 단어를 입력 받고, 단어 길이도 추가로 입력
for _ in range(n):
    word = input().strip()
    words.append((word, len(word)))
words = list(set(words))  # 중복 제거
# 단어 기준으로 오름차순 정렬 먼저 한 후, 길이 기준으로 오름차순 하면 문제 조건과 부합
words.sort(key=lambda x: x[0])
words.sort(key=lambda x: x[1])
for word in words:
    print(word[0])
