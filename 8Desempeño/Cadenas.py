import random

def randomString():
	alfabeto = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
	palabra = ""

	for i in range(0, 3):
		aleat = random.randint(0, 25)
		palabra = palabra + alfabeto[aleat]

	return palabra + " "


def search(cad, pat):
	veces = 0
	pos = cad.find(pat)

	while(pos != -1):
		pos = cad.find(pat, pos + 1)
		veces += 1

	return veces

random.seed(0)
#n = input("Teclea n: ")
n = 1757600
cadenota = ""
for i in range(0, n):
	cadenota = cadenota + randomString()

#print(cadenota)

sub = "IPN"
print("Encontrado: " + str(search(cadenota, sub)))