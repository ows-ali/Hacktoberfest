#URL: https://www.hackerrank.com/challenges/caesar-cipher-1/problem


def caesarCipher(n, s, k):
    ans = ""
    for i in range(n):
        ch = s[i]
        if ch>="A" and ch<="Z":
            start = ord("A")
            chord = ord(ch)+k
            if chord>ord("Z"):
                chord = start + (chord-ord("A"))%26
            ch = chr(chord)
            
        elif ch>="a" and ch<="z":
            start = ord("a")
            chord = ord(ch)+k
            if chord>ord("z"):
                chord = start + (chord-ord("a"))%26
            ch = chr(chord)

        ans+=ch
    return ans
