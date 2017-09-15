#!/usr/bin/env python3

import cs50

def main():
    print("Enter a credit card number")
    ccn = cs50.get_int()
    even = 0 ; odd = 0 ; hundred = 0 ; temp =0 ; count = 0
    temp_ccn = (int) (ccn) ; temp_ccn_2 = ccn

    while temp_ccn > 0 :
        count += 1
        temp_ccn = temp_ccn // 10

    while ccn > 0:
        odd = odd +  (int)(ccn % 10)
        hundred = ccn % 100
        temp = 2 * (hundred // 10)
        if temp > 9 :
            lhs = temp % 10
            rhs = temp // 10
            even = even + (int)( lhs + rhs )
        else :
            even = even + (int)( temp )
        ccn /= 100

    verify = (even + odd) % 10
    if verify == 0:
        if count == 15 :
            print("AMEX")
        elif count == 13 :
            print("VISA")
        elif count == 16 :
            if (temp_ccn_2 // (10 ** 15) ) == 4 :
                print("VISA")
            elif ( temp_ccn_2 // (10**15) ) == 5 :
                print("MASTERCARD")
            else:
                print("INVALID")
    else:
        print("INVALID")

if __name__ == "__main__":
    main()
