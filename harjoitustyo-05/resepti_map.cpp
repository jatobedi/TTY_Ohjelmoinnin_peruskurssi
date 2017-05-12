#include "resepti_map.hh"

#include <string>
#include <iostream>
#include <memory>
#include <algorithm>

using namespace std;

Resepti_map::Resepti_map():
    ensimmainen_esine_{nullptr},
    viimeinen_esine_{nullptr},
    lkm_{0}
{

}

bool Resepti_map::loytyyko_esine(const string& etsittava) {
    // Käy reseptin esinestructit läpi hakien etsittävää esinettä.
    // Paluuarvo: löytyneestä true, muuten false.

    shared_ptr<Esine_alkio> iteraattori = ensimmainen_esine_;
    while ( iteraattori != nullptr ) {
        if ( ensimmainen_esine_->esine == etsittava ){
            return true;
        }
        iteraattori = iteraattori->seuraava_esine;
    }
    return false;

}

bool Resepti_map::lisaa_esine(string esineen_nimi) {

    if ( loytyyko_esine(esineen_nimi) ) {
        return false;
    }

    shared_ptr<Esine_alkio> uuden_osoite{new Esine_alkio};
    uuden_osoite->esine = esineen_nimi;
    uuden_osoite->eka_materiaali = nullptr;
    uuden_osoite->vika_materiaali = nullptr;
    uuden_osoite->seuraava_esine = nullptr;

    // ensimmäinen listalla
    if ( lkm_ == 0 ){
        uuden_osoite->edellinen_esine = nullptr;
        ensimmainen_esine_ = uuden_osoite;

    } else {
        uuden_osoite->edellinen_esine = viimeinen_esine_;
        viimeinen_esine_->seuraava_esine = uuden_osoite;
    }

    viimeinen_esine_ = uuden_osoite.get();
    ++lkm_;

    return true;

}

bool Resepti_map::lisaa_materiaali(string esineen_nimi, string materiaalin_nimi){
    // tarkistetaan ensin onko esine jo olemassa,
    // ja lisätään se jos, se puuttuu.
    lisaa_esine(esineen_nimi);


    // haetaan esineen osoite.
    shared_ptr<Esine_alkio> esineen_os = ensimmainen_esine_;
    while ( esineen_os != nullptr ) {
        if ( esineen_os->esine == esineen_nimi ){
            break;
        }
        esineen_os = esineen_os->seuraava_esine;
    }



    shared_ptr<Materiaali_alkio> iteraattori = esineen_os->eka_materiaali;

    // tarkistetaan onko materiaali jo lisätty.
    while (iteraattori != nullptr){
        if ( iteraattori->materiaali == materiaalin_nimi ){
            return false;
        }
        iteraattori = iteraattori->seuraava_mat;
    }

    shared_ptr<Materiaali_alkio> uuden_osoite{new Materiaali_alkio};
    uuden_osoite->materiaali = materiaalin_nimi;
    uuden_osoite->seuraava_mat = nullptr;

    // Esnimmäiselle materiaalille.
    if ( esineen_os->mat_lkm == 0 ){
        esineen_os->eka_materiaali = uuden_osoite;
    }
    // Muille materiaaleille.
    else {
        esineen_os->vika_materiaali->seuraava_mat = uuden_osoite;
    }

    esineen_os->vika_materiaali = uuden_osoite.get();
    ++esineen_os->mat_lkm;
    return true;
}

void Resepti_map::tulosta(){
    shared_ptr<Esine_alkio> iteraattori = ensimmainen_esine_;
    while ( iteraattori != nullptr ) {
        cout << iteraattori->esine << endl;
        iteraattori = iteraattori->seuraava_esine;
    }
}

void Resepti_map::tulosta_materiaalit(string esine){

    // Etsitään esine resepteistä.
    shared_ptr<Esine_alkio> esineen_os = ensimmainen_esine_;
    while ( esineen_os != nullptr ) {
        if ( esineen_os->esine == esine ){
            break;
        }
        esineen_os = esineen_os->seuraava_esine;
    }
    if ( esineen_os == nullptr ){
        return;
    }


    // Syötetään esineen materiaalit taulukkoon.
    else {
        int materiaalien_maara = esineen_os->mat_lkm;
        shared_ptr<Materiaali_alkio> iteraattori = esineen_os->eka_materiaali;
        string* taulukko = new string[materiaalien_maara];
        int laskuri = 0;

        while ( iteraattori != nullptr ){
            taulukko[laskuri] = iteraattori->materiaali;
            iteraattori = iteraattori->seuraava_mat;
            ++laskuri;
        }

        // Järjestetään taulukko.
        sort(taulukko, taulukko + materiaalien_maara);

        // Tulostetaan taulukon tiedot.
        laskuri = 0;
        while (laskuri < materiaalien_maara){
            cout << taulukko[laskuri] << endl;
            ++laskuri;
        }

        // Poistetaan taulukko.
        delete [] taulukko;
    }
}
