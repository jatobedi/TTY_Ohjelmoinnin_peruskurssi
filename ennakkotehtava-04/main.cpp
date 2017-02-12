// TIE-02200 Ohjelmoinnin peruskurssi
// ennakkotehtava-04
// Janne Aare 235645
// janne.aare@student.tut.fi

#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

using taulukko_type = map<string, map<int, string>>;
using taulukko_iter = map<string, map<int, string>>::iterator;

void lisaa_kilpailija(taulukko_type& taulukko, string laji, int sija, string nimi);
void tulosta( taulukko_type& taulu );

// ----------------------------------------------------------------------

int main()
{
    taulukko_type taulukko;
    lisaa_kilpailija(taulukko, "keihas", 1, "Heimo Heittaja");
    lisaa_kilpailija(taulukko, "keihas", 6, "Kalle Keihänen");
    lisaa_kilpailija(taulukko, "seiväs", 1, "Hilkka Hyppääjä");
    lisaa_kilpailija(taulukko, "Kuula", 1, "Tauno Teräs");
    tulosta(taulukko);

}

// ----------------------------------------------------------------------

void lisaa_kilpailija( taulukko_type& taulukko, string laji, int sija, string nimi ){
    taulukko_iter iter = taulukko.find(laji);
    if ( iter == taulukko.end() ){
        taulukko.insert( { laji, {{ sija, nimi }} } );
    } else {
        iter->second.insert( { sija, nimi } );
    }
}

void tulosta( taulukko_type& taulu ){

    for ( auto pari : taulu ){
        cout << pari.first << endl;
        for ( auto pelaaja : pari.second ) {
            cout << "   " << pelaaja.first << " " << pelaaja.second << endl;
        }
    }
}
