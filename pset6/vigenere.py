#!/usr/bin/env python3

import sys
import cs50

def main():
    if len(sys.argv) > 2 or len(sys.argv) == 1 :
        sys.exit("Usage: ./vigenere key")

    key = sys.argv[1]
    keylen = len(key)
    temp = []
    cipher = []

    for c in key:
        if c >= 'a' and c <='z':
            temp.append(ord(c) - ord('a'))
        elif c >= 'A' and c <= 'Z' :
            temp.append(ord(c) - ord('A'))
        else :
            sys.exit("Fatal error: We do not accept non-alphabetical characters in the key")


    print("plaintext:", end='')
    plain = cs50.get_string()
    plen = len(plain)
    print("ciphertext:", end='')

    kcount = 0

    for i in range(plen):
        if plain[i] >= 'a' and plain[i] <= 'z' :
            if kcount < keylen :
               lower_convert(i, kcount, 'l', plain, temp)
               kcount += 1
            else :
                kcount = 0
                lower_convert(i, kcount, 'l', plain, temp)
                kcount += 1
        elif plain[i] >= 'A' and plain[i] <= 'Z' :
            if kcount < keylen :
                lower_convert(i, kcount, 'u', plain, temp)
                kcount += 1
            else :
                kcount = 0
                lower_convert(i, kcount, 'u', plain, temp)
                kcount += 1
        else :
            print(plain[i], end='')

    print()
    return 0

def lower_convert(pi, ki, casetype, plain, k):
    if casetype == 'l' :
        if ord(plain[pi]) + (k[ki]) >= ord('a') and ord(plain[pi]) + (k[ki]) <= ord('z') :
            print( chr( ord(plain[pi]) + (k[ki])), end='' )
        else :
            print( chr( ord(plain[pi]) + (k[ki]) - 26 ), end='' )
    elif  casetype == 'u' :
        if ord(plain[pi]) + (k[ki]) >= ord('A') and ord(plain[pi]) + (k[ki]) <= ord('Z') :
             print( chr( ord(plain[pi]) + ( k[ki] ) ), end='' )
        else :
             print(chr( ord(plain[pi]) + (k[ki]) - 26 ), end='')
    else :
        sys.exit("Fatal Error : You should have never landed in this place, its an internal bug, contact the developer")



if __name__ == "__main__":
    main()
