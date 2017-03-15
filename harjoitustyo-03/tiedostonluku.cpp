// TIE-02200 Ohjelmoinnin peruskurssi
// harjoitustyo-03
// Janne Aare 235645
// janne.aare@student.tut.fi

#include "todo_rakenne.hh"
#include "tiedostonluku.hh"
#include "apufunktiot.hh"
#include <fstream>
#include <string>

using namespace std;


// ----------------------------------------------------------------------------
// lue_tehtavatiedosto
// -------------------
// Funktio lukee parametrina saamansa tietovirran avulla tehtävälistatiedoston
// ja lisää sieltä saamansa tiedot tehtavarakenteeseen.  Jos tiedostossa
// on virheellisiä rivejä, funktion on palautettava false.  Jos tiedosto on
// virheetön, paluuarvon oltava true.  Tiedoston lukemin tämän funktion
// avulla EI SAA TULOSTAA NÄYTÖLLE MITÄÄN, sillä virheilmoitusten tulostuksesta
// on huolehdittu pääohjelmassa.
//
// KOKO TIEDOSTON LUKEMINEN ON TOTEUTETTAVA REKURSION AVULLA.  Tämä funktio,
// eikä sen avuksi itse toteutetut apufunktiot saa sisältää yhtään silmukka-
// rakennetta.  Silmukkarakenteet ovat tässä yhteydessä työn hylkäämisperuste.
//
// Funktion paluuarvo ja parametrien tyypit ja määrä on säilytettävä.
// ET SIIS SAA MUUTTAA LUE_TEHTAVATIEDOSTO-FUNKTION RAJAPINTAA.
// ----------------------------------------------------------------------------
bool lue_tehtavatiedosto(ifstream& virta, Todo& tehtavarakenne) {
    bool virheeton = true;
    lue_rivi(virta, tehtavarakenne, virheeton);
    return virheeton;
}

string::size_type laskuri(string& rivi, string::iterator iter){

    if (iter != rivi.end()) {
        if (*iter == ' '){
            return 1 + laskuri(rivi, iter+1);
        }
    }
    return 0;
}

bool tarkista_kentta(string& rivi){
    if (rivi.length()==0){
        return false;
    }
    string::iterator iter = rivi.begin();
    string::size_type tyhjat = 0;
    tyhjat = laskuri(rivi, iter);

    if (rivi.length() == tyhjat){

        return false;
    }else{
        return true;
    }
}

void lue_rivi(ifstream& virta, Todo& tehtavarakenne, bool& virheeton){
    string rivi;
    string kentta_1;
    string::size_type pilkun_paikka;
    int k_taso = 0;
    string tehtava;
    if ( getline(virta, rivi) ){
        pilkun_paikka = rivi.find(";");

        if ( pilkun_paikka == string::npos ){
            virheeton = false;

        }else{
            kentta_1 = rivi.substr(0,pilkun_paikka);
            virheeton = muuta_string_intiksi(kentta_1, k_taso);

            tehtava = rivi.substr(pilkun_paikka+1);
            virheeton = tarkista_kentta(tehtava);
            virheeton = tehtavarakenne.lisaa_tehtava(k_taso, tehtava);

            if ( virheeton ){
                lue_rivi(virta, tehtavarakenne, virheeton);

            }
        }

    }
}
