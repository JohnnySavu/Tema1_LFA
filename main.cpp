#include <bits/stdc++.h>
#include "Automat.cpp"
using namespace std;
ifstream fin("nfa.in");
ofstream fout("nfa.out");
ofstream g("words.txt");


int main()
{
    Automat aut;
    fin >> aut;
    string s;
    int n;
    fin >> n;
    for (int i = 1 ; i <= n; i++)
    {
        fin >> s;
        aut.setMem(s.size());
        fout << aut.checkWord(s) <<"\n";
    }
    if (aut.generateWords())
    {
        g << aut;
    }
    fin.close();
    fout.close();
    g.close();


    return 0;
}

