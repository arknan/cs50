#!/usr/bin/env python3

import cs50

def main():
    print("Input the half-pyramid's height, a non-negative integer, no greater than 23")
    height = cs50.get_int()
    while True:
        if height < 0 or height > 23:
            print("Retry")
            height = cs50.get_int()
        else:
            break

    for i in range(height):
        for j in range (height-1-i):
            print(" ", end="")
        for k in range(1+i):
            print("#", end="")
        print(" ", end="")
        for l in range(1+i):
            print("#", end="")
        print()

if __name__ == "__main__":
    main()
