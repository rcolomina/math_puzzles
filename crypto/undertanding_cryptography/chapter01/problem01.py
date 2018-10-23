#!/usr/bin/python3

''' 
1.1 The ciphertext below was encrypte using a substitution cipher. Decrypt the ciphertext without knowledge of the key

lrvmnir bpr sumvbwvr jx bpr lmiwv yjeryrkbi jx qmbm wi 
bpr xjvni mkd ymibrut jx irhx wi bpr riirkvr jx
ynbinlmtmipw utn qmumbr dj w ipmhh but bj rhnvwdmbr bpr 
yjeryrkbi jx bpr qmbm mvvjudwko bj yt wkbrusurbmbwjk
lmird jk xjubt trmui jx ibndt

wb wi kjb mk rmit bmiq bj rashmwk rmvp yjeryrkb mkd wbi
iwokwxwvmkvr mkd ijyr ynib urymwk nkrashmwkrd bj ower m
vjyshrbr rashmkmbwkj jkr cjnhd pmer bj lr fnmhwxwrd mkd
wkiswurd bj invp mk rabrkb bpmb pr vjnhd urmvp bpr ibmbr
jx rkhwopbrkrd ywkd vmsmlhr jx urvjokwgwko ijnkdhrii
ijnkd mkd ipmsrhrii ipmsr w dj kjb drry ytirhx bpr xwkmh
mnbpjuwbt lnb yt rasruwrkvr cwbp qmbm pmi hrxb kj djnlb
bpmb bpr xjhhjcwko wi bpr sujsru msshwvmbwjk mkd
wkbrusurbmbwjk w jxxru yt bprjuwri wk bpr pjsr bpmb bpr 
riirkvr jx jqwkmcmk qmumbr cwhh urymwk wkbmvb

1. Compute the relative frequency of all letters A...Z in the ciphertext.
You may want to use a tool such as the open-source program CrypTool [50]
for this task. However, a paper and pencil approach is also still double.

2. Decrypt the ciphertext with the help of the relative letter frequency
of the English language

A 0.0817 B 0.0150 C 0.0278 D 0.0425 E 0.1270 F 0.0223
G 0.0202 H 0.0609 I 0.0697 J 0.0015 K 0.0077 L 0.0403
M 0.0241 N 0.0675 O 0.0751 P 0.0193 Q 0.0010 R 0.0599
S 0.0633 T 0.0906 U 0.0276 V 0.0098 W 0.0236 X 0.0015
Y 0.0197 Z 0.0007

Note that the text is relatively short and that the letter frequenies in it might not perfectly align with that of general English language from the table.

3. Who wrote the text?

'''


# 1. Computing of relatives frequency

class FrequencyAnalysis:
    
    def __init__(self,sentence):
        self.sentence = sentence

        self.alphabet = ['a','b','c','d','e','f', \
                         'g','h','i','j','k','l', \
                         'm','n','o','p','q','r', \
                         's','t','u','v','w','x','y','z']             

    def count(self):
        freqTable = {}

        sentenceNoSpaces = [x for x in self.sentence if x != ' ']        
        totalLetters = len(sentenceNoSpaces)

        #print(totalLetters)
        for letter in self.alphabet:
            countingLetter = list(sentenceNoSpaces).count(letter)
            freqLetter = float(countingLetter) / float(totalLetters)
            freqTable[letter] = freqLetter 
        return freqTable
    

if __name__ == "__main__":

    cypherText = 'lrvmnir bpr sumvbwvr jx bpr lmiwv yjeryrkbi jx qmbm wi bpr xjvni mkd ymibrut jx irhx wi bpr riirkvr jx ynbinlmtmipw utn qmumbr dj w ipmhh but bj rhnvwdmbr bpr yjeryrkbi jx bpr qmbm mvvjudwko bj yt wkbrusurbmbwjk lmird jk xjubt trmui jx ibndt wb wi kjb mk rmit bmiq bj rashmwk rmvp yjeryrkb mkd wbi iwokwxwvmkvr mkd ijyr ynib urymwk nkrashmwkrd bj ower m vjyshrbr rashmkmbwjk jkr cjnhd pmer bj lr fnmhwxwrd mkd wkiswurd bj invp mk rabrkb bpmb pr vjnhd urmvp bpr ibmbr jx rkhwopbrkrd ywkd vmsmlhr jx urvjokwgwko ijnkdhrii ijnkd mkd ipmsrhrii ipmsr w dj kjb drry ytirhx bpr xwkmh mnbpjuwbt lnb yt rasruwrkvr cwbp qmbm pmi hrxb kj djnlb bpmb bpr xjhhjcwko wi bpr sujsru msshwvmbwjk mkd wkbrusurbmbwjk w jxxru yt bprjuwri wk bpr pjsr bpmb bpr riirkvr jx jqwkmcmk qmumbr cwhh urymwk wkbmvb'

    print("Cypher Text")
    print("----")
    print(cypherText)
    print("----")
    f1 = FrequencyAnalysis(cypherText)
    calTableOfFreq = f1.count()

    print("calculated table of frequencies on cypher text")
    #print(calTableOfFreq)
    
    refTableOfFreq = {'a': 0.0817, 'b': 0.0150, 'c': 0.0278, \
                      'd': 0.0425, 'e': 0.1270, 'f': 0.0223, \
                      'g': 0.0202, 'h': 0.0609, 'i': 0.0697, \
                      'j': 0.0015, 'k': 0.0077, 'l': 0.0403, \
                      'm': 0.0241, 'n': 0.0675, 'o': 0.0751, \
                      'p': 0.0193, 'q': 0.0010, 'r': 0.0599, \
                      's': 0.0633, 't': 0.0906, 'u': 0.0276, \
                      'v': 0.0098, 'w': 0.0236, 'x': 0.0015, \
                      'y': 0.0197, 'z': 0.0007}

    print("Reference Table of Frequencies sorted")
    refFreqSorted = sorted(refTableOfFreq.items(), key=lambda kv:kv[1])
    refKeysSorted = [pair[0] for pair in refFreqSorted]
    #print(refFreqSorted)

    print("Calculated Table of Frequencies sorted")
    calFreqSorted = sorted(calTableOfFreq.items(), key=lambda kv:kv[1])
    calKeysSorted = [pair[0] for pair in calFreqSorted] 
    #print(calFreqSorted)
    
    # Create map to decrypt
    mapDecrypt = {}
    for pair in zip(refKeysSorted,calKeysSorted):
        keyClear = pair[0]
        keyCypher= pair[1]                
        mapDecrypt[keyCypher] = keyClear

    print("-------")
    print("Appliying frequency table to try a first attempt to decypher the text")

    def decrypt(mapDecrypt):
        clearText=""
        for char in cypherText:
            if char!=' ':
                clearText+=mapDecrypt[char]
            else:
                clearText+=' '
        return clearText
 
    print("-----")
   
    print(decrypt(mapDecrypt))
    
    # Extra transpositon on mapDecrypt
    print("-----")
    print("After some transpositions interpreting the results")
    print("-----")
    
    mapDecrypt['l']='b'
    mapDecrypt['n']='u'
    mapDecrypt['j']='o'
    mapDecrypt['x']='f'
    mapDecrypt['k']='n'
    mapDecrypt['t']='y'
    mapDecrypt['w']='i'
    mapDecrypt['s']='p'
    mapDecrypt['q']='k'
    mapDecrypt['d']='d'
    mapDecrypt['q']='k'
    mapDecrypt['h']='l'
    mapDecrypt['o']='g'
    mapDecrypt['q']='k'
    mapDecrypt['c']='w'
    mapDecrypt['g']='z'

    
    print(decrypt(mapDecrypt))
    print("-----")


    


    
