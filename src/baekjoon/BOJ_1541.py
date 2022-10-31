# - 연산자가 수식에 제일 많아야 하므로,
# + 연산자가 포함된 수식을 최대한 괄호로 묶는다.

# - 연산자로 분리
input = input().split("-")
print(input)
result = []
for i in input:
    # + 연산자로 분리하고 덧셈을 수행한다.
    parse = i.split("+")
    print(parse)
    to_int = list(map(int, parse))
    result.append(sum(to_int))
print(result)
# 처음 피연산자만 제외하고 나머지는 뺀것이 정답.
print(result[0] * 2 - sum(result))
