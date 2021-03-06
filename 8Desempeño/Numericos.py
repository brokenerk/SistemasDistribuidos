import math
import time

def main():
    max = 1757600.0
    calculosNumericos(max)

def calculosNumericos(m):
    max = float(m)
    i = 0.00
    seno = 0.00
    cos = 0.00
    tan = 0.00
    log = 0.00
    raiz = 0.00
    while i < max:
        seno += math.sin(i)
        cos  += math.cos(i)
        tan +=  math.tan(i)
        log += math.log1p(i)
        raiz += math.sqrt(i)
        i +=1

main()