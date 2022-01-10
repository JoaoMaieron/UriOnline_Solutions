while True:
    
    N, K = input().split()
    N = int(N)
    K = int(K)
    if N == 0 and K == 0:
        break
    else:
        numeros = [0]*(K+1)
        numeros[K] = N
        i = 0
    
        while i < K:
            decimal = 0
            aux = 0
            A, B = input().split()
            A = int(A)
            B = int(B)
            N = '{0:032b}'.format(N) 
            N = list(N)
            N[31-A], N[31-B] = N[31-B], N[31-A]
            N = ''.join(N)
            decimal = int(N,2)
            numeros[i] = decimal
            N = decimal
            i += 1

        menor = numeros[0]
        maior = numeros[0]    
        for i in range(len(numeros)):
            if numeros[i] > maior:
                maior = numeros[i]
            if numeros[i] < menor:
                menor = numeros[i]
        print(str(N) + " " + str(maior) + " " + str(menor))


