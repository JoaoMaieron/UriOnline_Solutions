show = "Let me try!"
nao_show = "Don't make fun of me!"
while True:
    try:        
        n, m = map(int, input().split())
        if n == 0 and m == 0:
            break
        else:
            if m <= n:                    
                if m > 34:
                    print(show)
                else:
                    posicao = 1
                    i = 2
                    DEU = False
                    while posicao > 0 and posicao <= n:
                        if posicao == m:
                            DEU =  True
                            break
                        else:
                            if posicao < m:
                                if posicao + (2*i-1) < n+1:
                                    posicao += 2*i-1
                                else:
                                    posicao -= 2*i-1
                                i += 1
                            else:
                                if posicao - (2*i-1) > 0:
                                    posicao -= 2*i-1
                                else:
                                    posicao += 2*i-1
                                i += 1
                    if DEU:
                        print(show)
                    else:
                        print(nao_show)
            else:
                print(nao_show)

    except EOFError:
        break
