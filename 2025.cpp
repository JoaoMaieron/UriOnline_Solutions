#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, aux;
    string linha, linha2;
    string var = "Joulupukki";
    string var2 = "oulupukk";
    size_t j;

    scanf("%d", &n);
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    for(int i = 0; i < n; ++i){
        linha.clear();
        linha2.clear();
        getline(cin,linha);
        linha2 = linha;

        for(j = 0; j < linha.size(); ++j)
            linha2 += tolower(linha[i]);

        for(j = 0; j < linha.size(); ++j){
            aux = linha.find(var2,j);
            if(aux > 0 && aux != string::npos){
                if( aux + 8 <= linha.size() - 1){
                    linha.replace(aux-1,10,var);
                    linha2.replace(aux-1,10,var);
                }
            }
        }

        cout << linha << endl;
    }

    return 0;
}