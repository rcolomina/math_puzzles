import itertools

def getSplits(myciphers):
    comb=[]    
    for split in [p for p in itertools.product([0,1], repeat=4)]:            
        tsplit=[]
        tsplit.append(myciphers[0])
        for c,s in zip(myciphers[1:],split):      
            if s == 1:
                tsplit.append("-")
            tsplit.append(c)

        comb.append("".join(tsplit))
    return comb

# Test Case 1
myciphers="12345"
print(getSplits(myciphers))

# Test Case 2
myciphers="ABCD"
print(getSplits(myciphers))
