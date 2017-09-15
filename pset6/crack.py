#!/usr/bin/env python3
import cs50
import crypt
import sys

letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"

def main():
    if len(sys.argv) != 2:
        print("Usage: ./crack hash")
        return 1

    my_hash = sys.argv[1]
    my_pass = ''

    for i in range(4):
        loopy(my_hash, my_pass, i)

def crack(my_hash, my_pass):
    res = 0
    ash = ''.join(my_pass)
    print(ash)
    result = crypt.crypt(ash, "50")
    my_len = len(result)

    for i in range(my_len):
        if result[i] == my_hash[i] :
            res = 1
        else :
            res = 0
            break

    if res == 1 :
        print(my_pass)
        exit(0)

def loopy(my_hash, my_pass, my_round):
    if my_round == 0 :
        for a in range(52):
            my_pass[my_round] = letters[a]
            crack(my_hash, my_pass)
    else :
        for c in range(52):
            my_pass[my_round] = letters[c]
            loopy(my_hash, my_pass, (my_round -1) )

if __name__ == "__main__":
    main()

