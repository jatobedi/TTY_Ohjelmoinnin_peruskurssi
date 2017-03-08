// TIE-02200 Ohjelmoinnin peruskurssi
// ennakkotehtava-07
// Janne Aare 235645
// janne.aare@student.tut.fi


#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;


struct Opiskelija {
    string nimi;
    unsigned int opnum;
};


// ***** TODO *****************************************************************
// Toteuta tÃ¤hÃ¤n kohtaan vertailufunktio algorithm-kirjaston
// sort-funktiota varten.  Funktion on osattava vertailla kahta
// Opiskelija-tyyppistÃ¤ struct:ia siten, ettÃ¤ aakkosissa aiemmin
// oleva nimi-kenttÃ¤ tulkitaan pienemmÃ¤ksi struct:iksi.
// ****************************************************************************
bool vertaa_tyyppia(const Opiskelija& a, const Opiskelija& b)
{
    return a.nimi < b.nimi;
}


// ***** TODO *****************************************************************
// Toteuta tÃ¤hÃ¤n kohtaan vertailufunktio algorithm-kirjaston
// sort-funktiota varten.  Funktion on osattava vertailla kahta
// Opiskelija-tyyppiseen struct:iin osoittavaa osoitinta siten,
// ettÃ¤ pienemmÃ¤ksi tulkitaan se niistÃ¤, joka osoittaa opiskelija-
// numeroltaan pienempÃ¤Ã¤n opiskelijaan.
// ****************************************************************************
bool vertaa_osoitinta(const Opiskelija* a, const Opiskelija* b)
{
    return a->opnum < b->opnum;
}

int main() {
    vector<Opiskelija> oprek = {
        { "Teekkari, Tiina",           52401 },
        { "Ylikuuskajaskari, Jaska",  186112 },
        { "Repolainen, Reijo",        117118 },
        { "Teekkari, Teemu",          196196 },
        { "Santaholma, Santtu",       173421 },
    };

    vector<Opiskelija*> opiskelijaosoittimet = { };

    // Laitetaan opiskelijaosoittimet-vektoriin kaikkien oprek:iin
    // talletettujen opiskelijoiden muistiosoitteet.
    for ( vector<Opiskelija>::size_type i = 0; i < oprek.size(); ++i ) {
        opiskelijaosoittimet.push_back( &oprek.at(i) );
    }



    // ***** TODO *************************************************************
    // KÃ¤ytÃ¤ tÃ¤ssÃ¤ kohdassa algorithm-kirjaston sort-funktiota siten,
    // ettÃ¤ saat oprek-vektorissa olevat opiskelijat jÃ¤rjestetty
    // nimi-kentÃ¤n mukaiseen kasvavaan aakkosjÃ¤rjestykseen.
    // ************************************************************************
    sort(oprek.begin(), oprek.end(), vertaa_tyyppia);


    // ***** TODO *************************************************************
    // KÃ¤ytÃ¤ tÃ¤ssÃ¤ kohdassa algorithm-kirjaston sort-funktiota siten,
    // ettÃ¤ saat opiskelijaosoittimet-vektorissa olevat osoittimet
    // jÃ¤rjestettyÃ¤ siten, ettÃ¤ ne ovat osoittamiensa opiskelijoiden
    // mukaisessa kasvavassa opiskelijanumerojÃ¤rjestyksessÃ¤.
    // ************************************************************************
    sort(opiskelijaosoittimet.begin(), opiskelijaosoittimet.end(), vertaa_osoitinta);


    //------------------------------------------------------------------//
    // TÃ¤ssÃ¤ kohdassa kumpikin vektori on jÃ¤rjestetty oman vertailu-    //
    // kriteerinsÃ¤ perusteella kasvavaan jÃ¤rjestykseen. TÃ¤tÃ¤ tilannetta //
    // havainnollistetaan tehtÃ¤vÃ¤nannon kuvassa, joka esittÃ¤Ã¤           //
    // lajittelun jÃ¤lkeistÃ¤ lopputilannetta.                            //
    //------------------------------------------------------------------//



    // Tulostetaan opiskelijoiden tiedot nÃ¤ytÃ¶lle kuumankin edellÃ¤
    // lajitellun vektorin avulla, jotta nÃ¤hdÃ¤Ã¤n onko lajittelu onnistunut.

    cout << "Opiskelijat nimen mukaisessa jÃ¤rjestyksessa:" << endl
         << "--------------------------------------------" << endl;
    for ( Opiskelija opisk : oprek ) {
        cout << setw(24) << left << opisk.nimi
             << setw(6) << right << opisk.opnum << endl;
    }

    cout << endl;

    cout << "Opiskelijat numeron mukaisessa jÃ¤rjestyksessa:" << endl
         << "----------------------------------------------" << endl;
    for ( Opiskelija* opisk_ptr : opiskelijaosoittimet ) {
        cout << setw(24) << left << opisk_ptr->nimi
             << setw(6) << right << opisk_ptr->opnum << endl;
    }
}
