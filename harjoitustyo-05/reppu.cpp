// TIE-02200 Ohjelmoinnin peruskurssi
// harjoitustyo-05
// Janne Aare 235645
// janne.aare@student.tut.fi
// Reppu on tietosäiliö,
// johon käyttäjä voi lisätä esineitä.

#include "reppu.hh"
#include "resepti_map.hh"

#include <string>
#include <iostream>
#include <memory>

using namespace std;

Reppu::Reppu(Resepti_map reseptit): ensimmainen_tavara_{nullptr},
    // Rakentaja.
    // Resepti_map reseptit: Lähdetietorakenne.

    viimeinen_tavara_{nullptr},
    reseptit_{reseptit}
{

}

bool Reppu::lisaa_tavara(const string& tavaran_nimi){
    // Lisää uuden tavaran dynaamisen listan viimeiseksi.
    // const string& tavaran_nimi: Lisättävän tavaran nimi.
    // Paluuarvo: true onnistuneesta lisäyksestä, muuten false.

    if ( etsi_repusta(tavaran_nimi) or not etsi_resepteista(tavaran_nimi) ) {
        // Tavaran löytyessä repusta, reppu tyhjennetään.
        lisaysvirheilmoitus();
        tyhjenna();
        return false;
    }

    shared_ptr<Reppu_alkio> uuden_osoite(
                new Reppu_alkio{tavaran_nimi, nullptr});


    // ensimmäinen listalla
    if ( onko_tyhja() ){
        ensimmainen_tavara_ = uuden_osoite;
        viimeinen_tavara_ = uuden_osoite;
    }

    // Loput tavarat.
    else {
        // Laitetaan esimmäinen tavara osoittamaan toiseen.
        viimeinen_tavara_->seuraava_tav = uuden_osoite;
        viimeinen_tavara_ = uuden_osoite;
    }
    return true;
}

bool Reppu::onko_askarreltavissa(const string& tuote){
    // Tarkistaa löytyykö repusta kysytyn tuotteen
    // valmistamiseen tarvitut tavarat.
    // const string& tuote: kysytty tuote.
    // return: true, jos askarreltavissa, muuten false.

    if ( onko_tyhja() ){
        return false;
    }
    else if ( etsi_repusta(tuote) ){
        return true;
    } else {
        string* materiaalit = reseptit_.esineen_materiaalitaulukko(tuote);
        int taulukon_koko = reseptit_.esineen_materiaalimaara(tuote);

        // Materiaalittomat tuotteet on löydyttävä repusta.
        if ( taulukon_koko == 0 ){
            return false;
        }

        for (int i = 0; i < taulukon_koko;++i){
            if ( not etsi_repusta(materiaalit[i]) ){
                return false;
            }
        }
    }
    return true;
}

bool Reppu::etsi_resepteista(const string& tavara){
    // Etsii tavaraa resepteistä.
    // const string& tavara: etsittävä tavara.
    // Paluuarvo: true, jos löytyy, muuten false.

    return reseptit_.loytyyko_esine_resepteista(tavara);

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
    // const string& tavara: etsittävä tavara.
    // Paluuarvo: true, jos nimetty löytyy ja false, jos ei löydy.

    if ( onko_tyhja() ){
        return false;
    }

    Reppu_alkio* iteraattori = ensimmainen_tavara_.get();
    while ( iteraattori != nullptr ) {
        if ( iteraattori->tavara == tavara ){
            return true;
        }
        iteraattori = iteraattori->seuraava_tav.get();
    }
    return false;
}

bool Reppu::onko_tyhja()const{
    // Tarkistaa onko reppu tyhjä.
    // return: true, jos on, muuten false.

    if ( ensimmainen_tavara_ == nullptr ){
        return true;
    } else {
        return false;
    }
}
void Reppu::lisaysvirheilmoitus(){
    // tulostaa virheilmoitusen.

    cout << "Virhe: tavaraa ei voi lisata reppuun." << endl;
}
