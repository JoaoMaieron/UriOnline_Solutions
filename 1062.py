while True:
    try:
        n = int(input())
        if input == 0:
            break
        else:
            while True:                
                entrada = []
                for i in range(n,0,-1):
                    entrada.append(str(i))
                desejada = input().split()
                if len(desejada) == 1:
                    print()
                    break
                else:                
                    pilha = [entrada.pop()]
                    i = 0
                    while i < len(desejada):
                        if pilha:
                            if pilha[-1] != desejada[i]:
                                if entrada:
                                    numero = entrada.pop()
                                    pilha.append(numero)
                                else:
                                    print("No")
                                    break
                            if pilha[-1] == desejada[i]:
                                numero = pilha.pop()
                                i += 1
                        else:
                            if entrada:
                                numero = entrada.pop()
                                pilha.append(numero)
                            else:
                                break
                    if not pilha and not entrada:
                        print("Yes")                        
    except EOFError:
        break