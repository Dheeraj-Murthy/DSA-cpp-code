#include<bits/stdc++.h>
using namespace std;

#define d 256
#define p 131

void patternSearch(char pat[], char txt[])
{
    int h = 1;
    int plen = strlen(pat);
    int tlen = strlen(txt);
    int phash = 0;
    int thash = 0;


    for (int i = 0; i < plen -1; i++) h = ( h * d ) % p;
    for (int i = 0; i < plen; i++) {
        phash = ( phash*d + pat[i] )%p;
        thash = ( thash*d + txt[i] )%p;
    }

    for (int i = 0; i <= tlen - plen; i++)
    {
        if (phash == thash)
        {
            int j;
            for(j = 0; j < plen; j++){
                if (pat[j]!=txt[i+j]) break;
            }
            if (j == plen) cout << "found the pattern at index : " << i << endl;
        }

        if (i < tlen - plen)
        {
            thash = ( d*(thash - txt[i]*h) + txt[i+plen] )%p;

            if (thash < 0) thash = (thash+p);
        }
    }


}

int main()
{ 
    char pat[] = "Geeks";
    char txt[] = "GeeksforGeeks";
    patternSearch(pat, txt);

}