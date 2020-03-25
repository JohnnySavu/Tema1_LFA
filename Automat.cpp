#include <bits/stdc++.h>
#include "Automat.h"
using namespace std;

inline void Automat :: setMem(int siz)
{
    for (int i = 0; i<= n; i++)
        for (int j = 0; j <= siz + 1; j++)
            am_fost[i][j] = 0;
}

ifstream& operator >> (ifstream& fin, Automat &obj)
{
    int aux, nods, nodf;
    char c;
    fin >> obj.n >> obj.m >> obj.n_final_nodes;
    fin >> obj.nod_init;
    for (int i = 0 ; i <= obj.n; i++)
    {
        obj.is_final[i] = false;
    }
    for (int i = 1; i<= obj.n_final_nodes; i++)
    {
        fin >> aux;
        obj.is_final[aux] = true;
    }
    for (int i = 1; i<= obj.m; i++)
    {
        fin >> nods >> nodf >> c;
        obj.muchie[nods][c - 'a'].push_back(nodf);
    }
    return fin;
}

bool Automat :: generateWords()
{
    int words = 0;
    unordered_map<string, bool> vizitat;
    queue <string> q_s;
    int nod;
    queue <int> q_n;
    string s = "",aux;
    q_s.push(s);
    q_n.push(nod_init);
    while (words < 100 and !q_n.empty())
    {
        if (q_n.size() > 3000000)
            return 0;
        s = q_s.front();
        nod = q_n.front();
        q_s.pop();
        q_n.pop();
        if (is_final[nod] == true)
            words++, word.push_back(s);
        for (int i = 0; i <= 26; i++)
            if (muchie[nod][i].size()) 
                for (auto next:muchie[nod][i])
            {
                aux  = s + char(i + 'a') + to_string(next);
                if (vizitat[aux] == false)
                {
                    vizitat[aux] = true;
                    aux = s + char(i + 'a');
                    q_s.push(aux);
                    q_n.push(next);
                }
            }

    }
    return (words >= 100);

}

bool Automat::checkWord(string &s)
{
    queue <int> q_n;
    queue <int> q_l;
    int nod, l;
    int siz = s.size();
    q_n.push(nod_init);
    q_l.push(0);
    while (!q_n.empty())
    {
        nod = q_n.front();
        l = q_l.front();
        q_n.pop();
        q_l.pop();
        if (l == siz)
        {
            if (is_final[nod] == 1) return 1;
        }
        else
        {
            for (auto next : muchie[nod][s[l] - 'a'])
                if (!am_fost[next][l + 1])
                    {
                        am_fost[next][l + 1] = true;
                        q_n.push(next);
                        q_l.push(l + 1);
                    }
        }
    }
    return 0;
}

ofstream& operator << (ofstream & g, const Automat &obj)
{
    for (int i = 0; i < 100; i++)
        g << obj.word[i] <<"\n";
    return g;
}