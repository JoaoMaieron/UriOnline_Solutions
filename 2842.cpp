#include <iostream>
#include <string>
#define CWC 1000
using namespace std;

int LCS_table[CWC + 1][CWC + 1];

int lcsAlgo(string S1, string S2, int m, int n) {
  // Building the mtrix in bottom-up way
  for (int i = 0; i <= m; i++) {
    for (int j = 0; j <= n; j++) {
      if (i == 0 || j == 0)
        LCS_table[i][j] = 0;
      else if (S1[i - 1] == S2[j - 1])
        LCS_table[i][j] = LCS_table[i - 1][j - 1] + 1;
      else
        LCS_table[i][j] = max(LCS_table[i - 1][j], LCS_table[i][j - 1]);
    }
  }
  return LCS_table[m][n];
}

int main()
{
    string um, dois;
    cin >> um;
    cin >> dois;
    int i = um.size();
    int j = dois.size();
    int resposta = lcsAlgo(um,dois,i,j);
    int ednaldo = i - resposta;
    ednaldo += j - resposta;

    resposta += ednaldo;
    cout << resposta << endl;

}
