def pow(A, B, C):
    # A^1 = A
    if B == 1:
        return A % C
    ans = pow(A, B // 2, C) % C
    # A^100 = A^50 * A^50
    # A^101 = A^50 * A^50 * A
    return [(ans * ans) % C, (ans * ans * A) % C][B % 2]


if __name__ == "__main__":
    A, B, C = map(int, input().split())
    print(pow(A, B, C))
