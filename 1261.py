M, N = input().split()
M = int(M)
N = int(N)
dicionario = {}
i = 0
salario = 0
descricao = ''

for i in range(M):
    palavra, valor = input().split()
    valor = int(valor)
    dicionario[palavra] = valor

for i in range(N):        
    salario = 0
    while descricao != ['.']:
        descricao = input().split()        
        for x in descricao:
            if x in dicionario:
                salario += dicionario[x]
    print(salario)
    descricao = '' 