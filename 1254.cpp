#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    string tag, num, linha, tag2, linha2;
    int var, var2;
    size_t i, j;

    while(getline(cin, tag)){
        getline(cin,num);
        getline(cin,linha);
        tag2 = tag;
        linha2 = linha;

        j = linha.size();

        for(i = 0; i < j; ++i)
            linha[i] = tolower(linha[i]);
        for(i = 0; i < tag.size(); ++i)
            tag[i] = tolower(tag[i]);

        for(i = 0; i < j; ++i){
            if(linha[i] ==  '<'){
                var = linha.find('>', i);
                var2 = linha.find(tag,i);
                while(var2 != string::npos && var2 < var ){
                    linha.replace(var2, tag.size(), num);
                    linha2.replace(var2, tag.size(), num);
                    var = linha.find('>', i);
                    var2 = linha.find(tag,i);
                }
            }
        }

        cout << linha2 << endl;

    }
    return 0;
}