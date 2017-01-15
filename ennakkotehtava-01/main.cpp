// TIE-02200 Ohjelmoinnin peruskurssi K2017
// Ennakkotehtava 01
// Janne Aare 235645
// janne.aare@student.tut.fi

#include <iostream>
#include <string>

using namespace std;

void tulosta_riveja(int rivien_maara) {
    // tulostaa valitun maaran tyhjia riveja.
    while (rivien_maara > 0){
        cout << endl;
        rivien_maara --;
    }
}

int main()
{
    // arvattava- ja arvattu sana
    const string sana = "kellopeliappelsiini";
    string arvattusana = "___________________";

    // kirjanpito virheista
    const int sallitut_virheet = 5;
    int virheet = 0;

    // Kerrotaan pelaajalle arvatun sanan pituus.
    string::size_type mitta = 0;
    mitta = sana.length();
    cout << "Sanassa on " << mitta << " kirjainta." << endl;

    // Paalooppi, joka kyselee pelaajalta kirjaimia
    // kunnes sana on arvattu tai virheiden maara ylittyy
    while (sana != arvattusana and
            virheet < sallitut_virheet){
        // Alustetaan arvattu kirjain.
        string kirjain = "";

        tulosta_riveja(1);
        cout << "voit erehtya viela " << sallitut_virheet - virheet
             << " kertaa" << endl;
        tulosta_riveja(1);

        // Otetaan pelaajalta syote.
        cout << "Arvaa kirjain: ";
        getline(cin, kirjain);
        if (kirjain == ""){
            kirjain = ' ';
        } else {
            kirjain = kirjain.at(0);
        }

        // Tarkastetaan loytyyko kirjain sanasta.
        // Oikeat kirjaimet vaihdetaan arvattuun sanaan.
        string::size_type kirjaimen_indeksi = sana.find(kirjain);
        if ( kirjaimen_indeksi == string::npos ){
            cout << "kirjainta ei löytynyt" << endl;
            virheet ++;
        } else {
            int i = 0;
            while (i < 19){
                if (sana.at(i) == kirjain.at(0)){
                    arvattusana.at(i) = kirjain.at(0);
                }
                i++;
            }
        }

        cout << arvattusana << endl;

    }

    // Lopputekstit pelaajalle.
    tulosta_riveja(2);
    if ( sana == arvattusana ) {
        cout << "Onneksi olkoon, arvasit sanan oikein!" << endl;
    } else {
            cout << "Voi harmin paikka, arvaukset loppuivat kesken!" << endl;
    }

}
