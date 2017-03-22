// TIE-02200 Ohjelmoinnin peruskurssi
// ennakkotehtava-09
// Janne Aare 235645
// janne.aare@student.tut.fi

#include <pino.hh>
#include <iostream>
#include <string>
#include <memory>

using namespace std;

int main()
{
    Pino lukupino;
    int luku;

    // syotetaan lukuja ja tallennetaan ne pinoon.
    while ( true ){
        cout << "syota luku: ";
        cin >> luku;
        if ( luku == 0 ){
            break;
        }
        lukupino.push_front(luku);
    }
    // tulostetaan kaikki pinoon tallennetut luvut.
    lukupino.tulosta();


    // tyhjennetään pino.
    while ( lukupino.pop_front(luku) ){
    }

    // tulostaan pino, että saadaan varmistettua sen tyhjyys.
    lukupino.tulosta();
}
