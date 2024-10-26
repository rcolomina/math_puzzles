#!/usr/bin/python

# Try to find out what are A,B and C
#
#   AAA
#   BBB
#  +CCC
# -----
#  BAAC
#
# Where A,B and C are distinct and positive

# The smallest solution will be (A,B,C) = (1,2,3)
# and the bigest (A,B,C = (9,8,7)

listPosSol = [[a,b,c] for a in range(1,10) for b in range(1,10) for c in range(1,10) if a!=b and a!=c and b!=c]


for item in listPosSol:
    
    a = item[0]
    b = item[1]
    c = item[2]

    if ( 111 * (a+b+c) ) == ( b * 1000 + a * 110 + c ):
        print item," Condition OK"



