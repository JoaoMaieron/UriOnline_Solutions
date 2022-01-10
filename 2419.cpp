#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main()
{
    int n, m, i;
    int costa = 0;
    string aux;
    string peloamordedeus = "";
    vector<string> mapa;
    size_t as;

    scanf("%d %d", &n, &m);

    // Cria um grafo pro mapa
    int var2 = n*m;
    vector<vector<int>> grafo(var2);
    for (i=0;i<var2;++i){
        grafo[i].push_back(i-m);
        grafo[i].push_back(i+1);
        grafo[i].push_back(i+m);
        grafo[i].push_back(i-1);
    }

    // Pega as string tudo num vetor
    for (i=0;i<n;++i){
        cin >> aux;
        peloamordedeus += aux;
    }

    for(i=0;i<var2;++i){
        if(peloamordedeus[i] =='#'){
            for(as=0;as<grafo[i].size();++as){
                if(grafo[i][as] < 0 || grafo[i][as] > var2 - 1
                   || i % m == 0 || (i+1) % m == 0 ){//se ta na fronteira do mapa, conta como costa
                    ++costa;
                    break;
                }
                else if(peloamordedeus[grafo[i][as]] == '.'){
                    ++costa;
                    break;
                }
            }
        }
    }

    cout << costa << endl;

    return 0;
}