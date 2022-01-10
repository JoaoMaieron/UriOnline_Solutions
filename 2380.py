def constroi():
    for i in range(n+1):
        ednaldo_pereira.append(i)
        nro.append(1)    

def busca(i):
    if i != ednaldo_pereira[i]:
        ednaldo_pereira[i] = busca(ednaldo_pereira[i])
    return ednaldo_pereira[i]

def une(i, j):
    cade_i = busca(i)
    cade_j = busca(j)
    if cade_i != cade_j:
        if nro[cade_i] >= nro[cade_j]:
            nro[cade_i] += nro[cade_j]
            ednaldo_pereira[cade_j] = cade_i
        else:
            nro[cade_i] += nro[cade_j]
            ednaldo_pereira[cade_i] = cade_j

n, k = map(int, input().split())
ednaldo_pereira = []
nro = [1]
constroi()

for i in range(k):
    haha = input().split()
    haha[1] = int(haha[1])
    haha[2] = int(haha[2])
    if haha[0] == 'F':
        une(haha[1], haha[2])
    elif haha[0] == 'C':
        if busca(haha[1]) == busca(haha[2]):
            print('S')
        else:
            print('N')
