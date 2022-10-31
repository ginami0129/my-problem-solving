from itertools import combinations

L, C = map(int, input().split(" "))
# 패스워드는 정렬되어 있으므로 미리 정렬한다.
input_str = sorted(list(input().split(" ")))
# 가능한 모든 패스워드 조합을 구한다.
for passwd in combinations(input_str, L):
    consonant = vowel = 0
    # 자음 모음의 개수를 카운트
    for letter in passwd:
        if (
            letter == "a"
            or letter == "e"
            or letter == "i"
            or letter == "o"
            or letter == "u"
        ):
            vowel += 1
        else:
            consonant += 1
    # 자음 2개, 모음 1개 이상인 경우 출력한다.
    if vowel >= 1 and consonant >= 2:
        print("".join(passwd))

# # 만들수 있는 암호를 사전순으로 구한다.
# # 그 중 모음의 개수를 cnt 변수에 저장한다.
# def dfs(passwd, length, cnt):
#     # 원하는 길이의 암호를 구하면 종료
#     if length == L:
#         passwords.append([passwd, cnt])
#     # 만들수 있는 암호를 구한다.
#     for i in range(C):
#         # 사전순인지 판단한다.
#         if len(passwd) == 0 or ord(passwd[-1]) < ord(str[i]):
#             passwd += str[i]
#             # 모음의 개수를 카운트
#             if (
#                 str[i] == "a"
#                 or str[i] == "e"
#                 or str[i] == "i"
#                 or str[i] == "o"
#                 or str[i] == "u"
#             ):
#                 dfs(passwd, length + 1, cnt + 1)
#             else:
#                 dfs(passwd, length + 1, cnt)
#             passwd = passwd[:-1]


# if __name__ == "__main__":
#     L, C = map(int, input().split(" "))
#     str = list(input().split(" "))
#     passwords = []
#     # 만들 수 있는 암호를 구한다.
#     dfs("", 0, 0)
#     # 사전순 출력을 위해 정렬한다.
#     passwords.sort()
#     for password, cnt in passwords:
#         # 모음 최소 한개, 자음 최소 2개인 암호만 출력한다.
#         if cnt >= 1 and len(password) - cnt >= 2:
#             print(password)
