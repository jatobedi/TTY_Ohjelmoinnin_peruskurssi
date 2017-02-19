#include "algoritmit.hh"


bool lue_tiedosto(ketjut_type& ketjut){
    // Lukee tiedostosta "tuotetiedot.txt" rivit,
    // pilkkoo ne Splitterillä ";"  merkin kohdalta ja
    // tallentaa tiedot kaupoista tietorakenteeseen.
    // ketjut ketjut_type: tietorakenne, johon tiedot tallenetaan.
    // return bool: true, jos tiedoston avaus onnistuu false jos ei.

    ifstream tiedosto_olio("tuotetiedot.txt");
    if ( not tiedosto_olio ){
        return false;
    }else{
        string rivi;
        Splitter paloittelija;
        string ketju;
        string kauppa;
        string tuote;
        double hinta;
        while ( getline(tiedosto_olio, rivi) ){
            paloittelija.aseta_paloiteltava_merkkijono(rivi);
            paloittelija.paloittele(';');
            ketju = paloittelija.hae_kentta(0);
            kauppa = paloittelija.hae_kentta(1);
            tuote = paloittelija.hae_kentta(2);
            if ( paloittelija.hae_kentta(3) == "loppu" ){
                hinta = TUOTE_LOPPUNUT;
            }else{
                hinta = stod(paloittelija.hae_kentta(3));
            }

            Tuote tavara = {
                tuote, hinta
            };

            ketjut_type::iterator iter = ketjut.find(ketju);
            // iter etsii nimettyä kauppaketjua.
            if ( iter == ketjut.end() ){
                ketjut.insert({{ketju, {{kauppa,{{tavara}}}}}});
            }else {
                kaupat_type::iterator iter2 = iter->second.find(kauppa);
                // iter2 etsii nimettyä myymälää myymälät sisältävästä mapista.
                if ( iter2 == iter->second.end() ){
                    iter->second.insert({{kauppa, {{tavara}}}});
                }else{
                    bool ei_loytynyt = true;
                    for ( auto& alkio : iter2->second ){

                        if ( alkio.tuotenimi == tavara.tuotenimi ){
                            alkio.hinta = tavara.hinta;
                            ei_loytynyt = false;

                        }
                    }
                    if ( ei_loytynyt ){
                        iter2->second.push_back(tavara);
                    }

                }
            }

        }
        tiedosto_olio.close();


    }
    return true;
}

void tulosta_kauppaketjut(ketjut_type ketjut){
    // tulostaa kauppaketrjut.
    // ketjut ketjut_type: tietorakenne, josta tiedot luetaan.

    for ( auto ketju : ketjut){
        cout << ketju.first << endl;
    }
}

void tulosta_myymalat(ketjut_type ketjut, string ketju){
    // Tulostaa myymälät.
    // ketjut ketjut_type: tietorakenne, josta tiedot luetaan.
    // string ketju: ketju, jonka myymälät tulostetaan.

    ketjut_type::iterator iter = ketjut.find(ketju);
    for ( auto kauppa : iter->second ){
        cout << kauppa.first << endl;
    }
}

void halvin(ketjut_type ketjut, string nimi){
    // Käy kaikkien kauppojen kaikki tuotteet
    // etsien parametrin tuotetta, tulostaa
    // halvimman löytyneen ja kaupat, joista
    // se sillä hinnalla löytyi. Jos ei löydy
    // tulostetaan, "ei kuulu valikoimiin" ja
    // jos loppu kaikkialta tulostetaan
    // "Tuote on tilapäisesti loppu kaikkialta."
    // ketjut ketjut_type: tietorakenne, josta tiedot luetaan.
    // string nimi: haettava tuote.

    bool tuote_loytyy = false;
    set<string> halvimmat_kaupat;
    const double ALKU = 9999999.99;
    double halvin_hinta = ALKU;
    for ( auto ketju : ketjut){
        for ( auto kauppa : ketju.second ){
            for ( auto esine : kauppa.second ){
                if ( esine.tuotenimi == nimi ){
                    tuote_loytyy = true;
                    string halpa_kauppa = ketju.first + " " + kauppa.first;
                    if ( esine.hinta < halvin_hinta and esine.hinta != TUOTE_LOPPUNUT ){
                        halvin_hinta = esine.hinta;
                        halvimmat_kaupat.clear();

                        halvimmat_kaupat.insert(halpa_kauppa);
                    }else if(esine.hinta == halvin_hinta){
                        halvimmat_kaupat.insert(halpa_kauppa);
                    }
                }

            }
        }
    }
    if (tuote_loytyy){
        if ( halvin_hinta == ALKU ){
            cout << "Tuote on tilapäisesti loppu kaikkialta." << endl;
        }else{
            cout << setprecision(2) << fixed
                 << halvin_hinta << " euroa" << endl;
            for ( auto kauppa: halvimmat_kaupat ){
                cout << kauppa << endl;
            }
        }

    }else{
            cout << "Tuote ei kuulu valikoimiin." << endl;
        }
    }

void valikoima(ketjut_type ketjut, string ketju, string kauppa){
    // Etsii tietorakenteesta kaupan ja tulostaa
    // sen jokaisesta tuotteesta tuotenimen ja hinnan.
    // ketjut ketjut_type: tietorakenne, josta tiedot luetaan.
    // string ketju: ketju, jonka kauppaa haetaan.
    // string kauppa: kauppa, jonka valikoima tulostetaan.

    ketjut_type::iterator iter = ketjut.find(ketju);
    kaupat_type::iterator iter2 = iter->second.find(kauppa);
    sort (iter2->second.begin(), iter2->second.end());
    for ( auto tavara : iter2->second ){
        cout << tavara.tuotenimi << " ";

        if ( tavara.hinta == TUOTE_LOPPUNUT ){
            cout << "loppu" << endl;
        }else{
            cout << setprecision(2) << fixed << tavara.hinta
                << endl;
        }
    }
}

void tuotenimet(ketjut_type ketjut){
    // Kerää kaikkien kauppojen tuotenimet settiin
    // ja tulostaa ne yksitelleen.
    // ketjut ketjut_type: tietorakenne, josta tiedot luetaan.

    set<string> tuotteet;
    for ( auto ketju : ketjut){
        for ( auto kauppa : ketju.second ){
            for ( auto esine : kauppa.second ){
                tuotteet.insert(esine.tuotenimi);
            }
        }
    }
    for ( auto esine : tuotteet ){
        cout << esine << endl;
    }
}
