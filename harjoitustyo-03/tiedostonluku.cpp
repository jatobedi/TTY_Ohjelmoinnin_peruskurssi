//------------------------------------------------
//  TIE-02200 Ohjelmoinnin peruskurssi -mallikoodi
//  Copyright © 2017  opersk@tut.fi
//------------------------------------------------

#include "todo_rakenne.hh"
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
    return true;
}
