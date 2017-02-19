#ifndef ALGORITMIT_HH
#define ALGORITMIT_HH

#include "splitter.hh"
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <set>
#include <iomanip>
#include <algorithm>

const double TUOTE_LOPPUNUT = 0.0;

struct Tuote {
    // Tuotteen nimen ja hinnan sisältävä tietorakenne.
        string tuotenimi;
        double hinta;

    // Määrätään tuotteiden välinen suuruusjärjestys
    // määräytymään tuotenimen perusteella
    // .sort() algoritmia varten.

        bool operator<(const Tuote& a)
        {
            return tuotenimi < a.tuotenimi;
        }
    };

using kaupat_type = map<string, vector<Tuote>>;
using ketjut_type = map<string, kaupat_type>;


bool lue_tiedosto(ketjut_type& ketjut);

void tulosta_kauppaketjut(ketjut_type ketjut);
void tulosta_myymalat(ketjut_type ketjut, string ketju);
void halvin(ketjut_type ketjut, string nimi);
void valikoima(ketjut_type ketjut, string ketju, string kauppa);
void tuotenimet(ketjut_type ketjut);

#endif // ALGORITMIT_HH
