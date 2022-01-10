t = int(input())
show = {}

for i in range(t):
    m, n = map(int, input().split())
    for j in range(m):        
        japones = input()
        show[japones] = input()
    for line in range(n):
        linha = input().split()
        lala = len(linha)-1
        for index, word in enumerate(linha):
            if word in show:
                if index == lala:
                    print(show[word], end = '')
                else:
                    print(show[word], end=' ')
            else:
                if index == lala:
                    print(word, end = '')
                else:
                    print(word, end=' ')
        print('')
    print('')
    show.clear()
