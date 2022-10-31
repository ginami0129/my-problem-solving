word = input()
alphabet = [0] * (ord("z") - ord("a") + 1)
for char in word:
    alphabet[ord(char) - ord("a")] += 1
print(*alphabet, sep=" ")
