#include <iostream>
#include <map>
#include <iterator>
#include <string>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    map<string, float> arvores;
    string aux;
    int n, total;

    scanf("%d", &n);
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    getline(cin,aux);
    for(int i = 0; i < n; ++i){
        total = 0;
        while(true){
            getline(cin,aux);
            if(aux.size() == 0)
                break;
            else{
                ++total;
                if(arvores.count(aux))
                    arvores[aux] += 1;
                else
                    arvores.insert(pair<string,float>(aux,1));
            }
        }
        map<string, float>::iterator itr;
        for(itr = arvores.begin(); itr != arvores.end(); ++itr){
            cout << itr->first;
            printf(" %.4f\n", (itr->second*100) / total);
        }
        if(i < n-1)
            printf("\n");
            
        arvores.clear();
    }



    return 0;
}