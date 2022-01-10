areas = int(input())

for area in range(areas):
    tam_grid = int(input())
    area_bacterias = 0
    matriz = [0]*tam_grid
    flag_area = 0
    flag2 = 0
    
    for i in range(tam_grid):
        matriz[i] = input().replace(" ",'')
    
    for i in range(tam_grid):
        matriz[i] = list(matriz[i])
        flag_area = 0
        flag2 = 0
        if i == 0 or i == tam_grid - 1:
            for j in range(tam_grid):
                if matriz[i][j] == '1':
                    area_bacterias += 1
        else:
            for j in range(tam_grid):
                if matriz[i][j] == '1':
                    area_bacterias += 1
                    if flag_area == 0:
                        flag_area = 1
                elif matriz[i][j] == '0':
                    if flag_area == 1 and matriz[i-1][j] == '1':
                        flag2 = 0
                        for k in range(j+1,tam_grid):
                            if matriz[i][k] == '1':
                                flag2 = 1
                        if flag2 > 0:
                            matriz[i][j] = '1'
                            area_bacterias += 1
                        else:
                            flag_area = 0
    
    area_bacterias = float(area_bacterias)
    area_bacterias = area_bacterias / 2
    print("{:.2f}".format(area_bacterias))