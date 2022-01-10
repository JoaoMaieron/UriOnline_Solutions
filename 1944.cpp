# -*- coding: utf-8 -*-

painel = ['F', 'A', 'C', 'E']
entrada = []
N = int(input())
i = 0
j = 0
brindes = 0

for i in range(N):
    if not painel:
        painel = ['F', 'A', 'C', 'E']
        
    entrada = input().split()    
    
    if i % 2 == 0:        
        painel = painel + entrada
    else:        
        painel = entrada + painel

        
    tamanho = len(painel) - 1
    iguais = 0
    for j in range(4):
        if painel[j] == painel[tamanho-j]:
            iguais += 1
    if iguais == 4:
        brindes += 1        
        for j in range(4):            
            painel.pop(0)
            painel.pop(len(painel)-1)            
    
print(brindes)