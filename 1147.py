letras = [(1,'a'),(2,'b'),(3,'c'),(4,'d'),(5,'e'),(6,'f'),(7,'g'),(8,'h')]
iteracao = 0
while True:
    posicao_cavalo = input()
    if posicao_cavalo == '0':
        break
    else:
        posicao_cavalo = list(posicao_cavalo)
        contagem = 0
        posicao_cavalo[0] = int(posicao_cavalo[0])
        posicao_cavalo[1] = posicao_cavalo[1].lower()
        mov_cavalo = [0]*8
        posicao_peoes = [0]*8
        mov_peoes = [0]*16
    
        for i in range(len(letras)):
            if posicao_cavalo[1] == letras[i][1]:
                posicao_cavalo[1] = letras[i][0]
    
        for i in range(len(posicao_peoes)):
            posicao_peoes[i] = list(input())
            posicao_peoes[i][0] = int(posicao_peoes[i][0])
            posicao_peoes[i][1] = posicao_peoes[i][1].lower()
            for j in range(len(letras)):
                if posicao_peoes[i][1] == letras[j][1]:
                    posicao_peoes[i][1] = letras[j][0]
        
        for i in range(len(posicao_peoes)):
            mov_peoes[i+i] = [posicao_peoes[i][0] - 1, posicao_peoes[i][1] - 1]
            mov_peoes[i+i+1] = [posicao_peoes[i][0] - 1, posicao_peoes[i][1] + 1]
        
        mov_cavalo[0] = [posicao_cavalo[0] - 2, posicao_cavalo[1] - 1]
        mov_cavalo[1] = [posicao_cavalo[0] - 2, posicao_cavalo[1] + 1]
        mov_cavalo[2] = [posicao_cavalo[0] + 2, posicao_cavalo[1] - 1]
        mov_cavalo[3] = [posicao_cavalo[0] + 2, posicao_cavalo[1] + 1]
        mov_cavalo[4] = [posicao_cavalo[0] - 1, posicao_cavalo[1] + 2]
        mov_cavalo[5] = [posicao_cavalo[0] + 1, posicao_cavalo[1] + 2]
        mov_cavalo[6] = [posicao_cavalo[0] - 1, posicao_cavalo[1] - 2]
        mov_cavalo[7] = [posicao_cavalo[0] + 1, posicao_cavalo[1] - 2]
        
        for movimento in mov_cavalo:
            if movimento[0] in range(1,9) and movimento[1] in range(1,9):
                flag = 0
                for i in range(len(mov_peoes)):
                    if movimento == mov_peoes[i]:
                        if mov_peoes[i][0] in range(1,8) and mov_peoes[i][1] in range(1,9):
                            flag = 1
                if flag == 0:
                    contagem += 1
        
        iteracao += 1
        print("Caso de Teste #" + str(iteracao) +": " + str(contagem) + " movimento(s).")