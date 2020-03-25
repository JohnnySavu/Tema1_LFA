#include <bits/stdc++.h>
using namespace std;
class Automat
{
private:
    int n, m;
    int nod_init;
    bool is_final[310];
    bool am_fost[310][160];
    int vec[310];
    vector<int> muchie[310][30];
    int n_final_nodes;
    vector<string> word;
public:
    friend ifstream& operator >> (ifstream&, Automat &);
    bool checkWord(string &);
    inline void setMem(int);
    bool generateWords();
    friend ofstream& operator <<(ofstream& , const Automat& );
};
