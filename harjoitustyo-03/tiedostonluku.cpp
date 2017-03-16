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
    // Lukee tehtävätiedoston ja tallentaa sen sisällön tietorakenteeseen.
    // ifstream virta: tiedoston tietovirta.
    // Todo tehtavarakenne: tietorakenne, johon tietovirran tieto tallennetaan.
    // return virheetön: jos tiedoston tiedot ovat virheettömät palautetaan true,
    // muuten palautetaan false.

    bool virheeton = true;
    lue_rivi(virta, tehtavarakenne, virheeton);
    return virheeton;
}

bool tarkista_kentat(const int& kiireellisyys,  const string& kaskykentta){
    // Tarkistaa, että tiedostosta luetun rivin arvot ovat sallittuja.
    // int kiireellisyys: numeroarvoinen kenttä, jonka arvon on oltava välillä 1-5.
    // string kaskykentta: käskykenttä, joka ei saa olla tyhjä tai koostua välilyönneistä.
    // return: jos kentät ovat ehtojen mukaisia palautetaan true, muuten false.

    if ( kaskykentta.length()==0 or kiireellisyys < 1 or kiireellisyys > 5){
        return false;
    }

    else if ( kaskykentta.find_first_not_of(' ') == string::npos )
    {
        return false;
    }else{
        return true;
    }
}

void lue_rivi(ifstream& virta, Todo& tehtavarakenne, bool& virheeton){
    // Lukee rekursiivisesti kaikki tietovirran rivit.
    // ifstream virta: luettava tietovirta.
    // Todo tehtavarakenne: tietorakenne, johon virran tiedot tallennetaan.
    // bool virheeton: jos virran tiedot ovat virheettömiä palautetaan true,
    // muuten palautetaan false.

    string rivi;
    string numerokentta;
    int kiireellisyys = 0;
    string::size_type pilkun_paikka = 0;
    string tehtavakentta;
    if ( getline(virta, rivi) ){
        pilkun_paikka = rivi.find(";");

        if ( pilkun_paikka == string::npos ){
            virheeton = false;

        }else{
            numerokentta = rivi.substr(0,pilkun_paikka);
            muuta_string_intiksi(numerokentta, kiireellisyys);
            tehtavakentta = rivi.substr(pilkun_paikka+1);

            virheeton = tarkista_kentat(kiireellisyys, tehtavakentta);

            if ( virheeton ){
                tehtavarakenne.lisaa_tehtava(kiireellisyys, tehtavakentta);
                lue_rivi(virta, tehtavarakenne, virheeton);

            }
        }

    }
}
