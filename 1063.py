# -*- coding: utf-8 -*-

while True:
    try:
        
        N = input()
        if N == 0:
            break
        else:
            entrada = input().split()
            entrada.reverse()
            desejada = input().split()
            pilha = [entrada.pop()]
            saida = ['I']
            contagem_saida = 0
            i = 0

            while i < len(desejada):
                if pilha:                
                    if pilha[-1] != desejada[i]:
                        if entrada:
                            letra = entrada.pop()
                            pilha.extend(letra)
                            saida.append('I')                    
                        else:
                            saida.append(" Impossible")
                            break

                    if pilha [-1] == desejada[i]:                
                        letra = pilha.pop()
                        saida.append('R')                
                        i += 1
                else:
                    if entrada:
                        letra = entrada.pop()
                        pilha.extend(letra)
                        saida.append('I')
                    else:
                        break

            frase = ''.join(saida)
            print(frase)
    except EOFError:
        break