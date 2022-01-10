while True:
    try:
        dicionario = {}
        n, m = map(int, input().split())
        pedro_ernesto = input().split()
        for i in range(n):
            pedro_ernesto[i] = int(pedro_ernesto[i])
            if pedro_ernesto[i] not in dicionario:
                listao = [i+1]
                dicionario[pedro_ernesto[i]] = listao
            else:
                dicionario[pedro_ernesto[i]].append(i+1)

        for i in range(m):
            k, v = map(int, input().split())
            if v in dicionario:
                if len(dicionario[v]) >= k:
                    print(dicionario[v][k-1])
                else:
                    print(0)
            else:
                print(0)
        
    except EOFError:
        break
