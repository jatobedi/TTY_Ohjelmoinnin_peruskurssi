#include "reppu.hh"
#include "resepti_map.hh"

#include <string>
#include <iostream>
#include <memory>

using namespace std;

Reppu::Reppu(Resepti_map reseptit): ensimmainen_tavara_{nullptr},
    viimeinen_tavara_{nullptr},
    reseptit_{reseptit}
{

}

bool Reppu::lisaa_tavara(const string& tavaran_nimi){
    // Lisää uuden tavaran dynaamisen listan viimeiseksi.
    // Paluuarvo: true onnistuneesta lisäyksestä, muuten false.

    if ( etsi_repusta(tavaran_nimi) or not etsi_resepteista(tavaran_nimi) ) {
        // Tavaran löytyessä repusta, reppu tyhjennetään.
        tyhjenna();
        return false;
    }

    shared_ptr<Reppu_alkio> uuden_osoite(
                new Reppu_alkio{tavaran_nimi, nullptr});


    // ensimmäinen listalla
    if ( viimeinen_tavara_ == nullptr ){
        ensimmainen_tavara_ = uuden_osoite;
    }
/*
    // Loput tavarat.
    else {
        // Laitetaan esimmäinen tavara osoittamaan toiseen.
        if (ensimmainen_tavara_->seuraava_tav == nullptr){
            ensimmainen_tavara_->seuraava_tav = uuden_osoite;
        }

        viimeinen_tavara_->seuraava_tav = uuden_osoite;
    }

    viimeinen_tavara_ = uuden_osoite;
    return true;
*/
    }

bool Reppu::onko_askarreltavissa(const string& tuote){
    cout << tuote << endl;
    return true;
}

bool Reppu::etsi_resepteista(const string& tavara){
    // Etsii tavaraa resepteistä.
    // Paluuarvo: true, jos löytyy, muuten false.

    //return reseptit_.loytyyko_esine(tavara);

}

void Reppu::tulosta(){
    // Tulostaa kaikki repun tavarat lisäysjärjestyksessä.

    shared_ptr<Reppu_alkio> iteraattori = ensimmainen_tavara_;
    while ( iteraattori != nullptr ) {
        cout << iteraattori->tavara << endl;
        iteraattori = iteraattori->seuraava_tav;
    }
}

void Reppu::tyhjenna(){
    // Tyhjentää repun.

    ensimmainen_tavara_ = nullptr;
    viimeinen_tavara_ = nullptr;
}

bool Reppu::etsi_repusta(const string& tavara){
    // Etsii repusta nimettyä tavaraa.
    // Paluuarvo: true, jos nimetty löytyy ja false, jos ei löydy.

    shared_ptr<Reppu_alkio> iteraattori = ensimmainen_tavara_;
    while ( iteraattori != nullptr ) {
        if ( iteraattori->tavara == tavara ){
            return true;
        }
    }
    return false;
}


