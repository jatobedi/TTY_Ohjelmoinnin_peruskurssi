//------------------------------------------------
//  TIE-02200 Ohjelmoinnin peruskurssi -mallikoodi
//  Copyright © 2017  opersk@tut.fi
//------------------------------------------------

#include "apufunktiot.hh"
#include "todo_rakenne.hh"
#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <string>

using namespace std;


void suorita_lisaa(Todo& tehtavat, const vector<string>& kentat);
void suorita_listaa(Todo& tehtavat, const vector<string>& kentat);
void suorita_talleta(Todo& tehtavat, const vector<string>& kentat);
void suorita_suorita(Todo& tehtavat, const vector<string>& kentat);


using Funktiotyyppi = decltype(&suorita_lisaa);
using Kaskyrakenne = map<string, Funktiotyyppi>;


const Kaskyrakenne TUNNETUT_KASKYT = {
    { "lisaa",   suorita_lisaa  },
    { "listaa",  suorita_listaa },
    { "talleta", suorita_talleta },
    { "suorita", suorita_suorita }
};


void kayttoliittyma(Todo& tehtavarakenne) {
    // rekursiivisesti toimiva käyttöliittymä.
    // rekursio loppuu, jos syötetään lopeta, loppu tai
    // ei syötetä mitään.

    cout << "tehtavalista> ";
    string rivi;
    if ( not getline(cin, rivi) ) {
        return;
    }

    vector<string> kentat = paloittele_sanoiksi(rivi);

    if ( kentat.empty()
           or kentat.at(0) == "lopeta"
           or kentat.at(0) == "loppu" ) {

        return;

    // virheellinen syöte.
    } else if ( TUNNETUT_KASKYT.find(kentat.at(0)) == TUNNETUT_KASKYT.end()) {
        virheilmoitus(kentat.at(0) + " on tuntematon kasky.");
        kayttoliittyma(tehtavarakenne);

    } else {

        // Sulkeet heti perässä suorittavat löytyvän funktion.
        TUNNETUT_KASKYT.at(kentat.at(0))(tehtavarakenne, kentat);
        kayttoliittyma(tehtavarakenne);
    }
}

//////////////////////////////////////////////////////////////////////////////
// parametri Todo tehtavat kierrätetään käyttöliittymän kautta ja
// vector<string> kentat tulee käyttöliittymästä.

void suorita_listaa(Todo& tehtavat, const vector<string>& kentat) {
    if ( kentat.size() != 1 ) {
        virheilmoitus("listaa: vaara maara sanoja syoterivilla.");

    } else {

        tehtavat.listaa_tehtavat(); // todo_rakenne.
    }
}


void suorita_lisaa(Todo& tehtavat, const vector<string>& kentat) {
    int taso = 0;

    if ( kentat.size() < 3 ) {
        virheilmoitus("lisaa: liian vahan sanoja syoterivilla.");
        return;

    } else if ( not muuta_string_intiksi(kentat.at(1), taso) ) {

        virheilmoitus("lisaa: kiireellisyystaso ei ole numero.");
        return;
    }

    string kuvaus = yhdista_valilyonneilla(kentat.begin() + 2, kentat.end()); // apufunktiot.

    if ( not tehtavat.lisaa_tehtava(taso, kuvaus) ) {   // todo_rakenne.

        virheilmoitus("lisaa: sopimaton kiireellisyystaso.");
    }
}


void suorita_talleta(Todo& tehtavat, const vector<string>& kentat) {
    if ( kentat.size() != 2 ) {
        virheilmoitus("talleta: vaara maara sanoja syoterivilla.");
        return;
    }

    ofstream talletusvirta(kentat.at(1));
    if ( not talletusvirta
           or not tehtavat.talleta_tiedostoon(talletusvirta) ) {

        virheilmoitus("talleta: tiedostoon kirjoittaminen epaonnistui.");
    } else {

        cout << "Tiedosto talletettu." << endl;
    }
}

void suorita_suorita(Todo& tehtavat, const vector<string>& kentat){
    if ( kentat.size() != 1 ){
        cout << "Virhe: vaara maara sanoja syoterivilla." << endl;
    }
    else if ( not tehtavat.poista_tehtava() ){
        cout << "Virhe: Tehtavalista on tyhja." << endl;
    }
}
