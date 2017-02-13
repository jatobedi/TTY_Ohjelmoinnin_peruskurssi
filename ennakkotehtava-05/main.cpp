// TIE-02200 Ohjelmoinnin peruskurssi.
// ennakkotehtava-05
// Janne Aare 235645
// janne.aare@student.tut.fi

#include "splitter.hh"
#include "laskutoimitukset.hh"
#include <iostream>
#include <string>

using namespace std;

void laske(double nro_1, string merkki, double nro_2){
    if ( merkki == "+"){
        cout << summa(nro_1, nro_2) << endl;
    }
    else if ( merkki == "-"){
        cout << erotus(nro_1, nro_2) << endl;
    }
    else if ( merkki == "*"){
        cout << tulo(nro_1, nro_2) << endl;
    }
    else if ( merkki == "/"){
        cout << osamaara(nro_1, nro_2) << endl;
    }
}

int main() {

    string syote;
    Splitter laskutoimitus;

    while (true){
        cout << "laskin> ";
        getline(cin, syote);
        laskutoimitus.aseta_paloiteltava_merkkijono(syote);
        int kentat = laskutoimitus.paloittele(' ');

        if ( kentat == 3 ){
            double nro_1 = stod(laskutoimitus.hae_kentta(0));
            double nro_2 = stod(laskutoimitus.hae_kentta(2));
            string merkki = laskutoimitus.hae_kentta(1);
            laske(nro_1, merkki, nro_2);
        }else{
            cout << "Kiitos ja näkemiin!" << endl;
            break;
        }
    }
}

