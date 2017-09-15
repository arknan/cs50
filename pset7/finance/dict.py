#!/usr/bin/env python3

"""final = dict(a=[],b=[])
temp = list()
temp.append(final)

final["a"].append("ash")
final["a"].append("bsh")

for key in temp[0]:
    print (key)"""

my_list = [0,1,2,3,4,5,6]

for i in range(0, len(my_list), 2):
    share_name = my_list[i]
    if my_list[i+1] < len(my_list) :
        share_q = my_list[i+1]
        print(share_name,share_q)
