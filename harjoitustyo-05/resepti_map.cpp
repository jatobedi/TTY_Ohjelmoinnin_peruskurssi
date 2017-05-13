#include "resepti_map.hh"

#include <string>
#include <iostream>
#include <memory>
#include <algorithm>

using namespace std;

Resepti_map::Resepti_map():
    eka_esine_{nullptr},
    vika_esine_{nullptr}
{

}

bool Resepti_map::lisaa(string esineen_nimi, string materiaalin_nimi){
    // Lisää esineen ja siihen liittyviä materiaaleja reseptiin.
    // Palauttaa onnistuneesta lisäyksestä true, muuten false.

    shared_ptr<Esine_alkio> uuden_osoite(new Esine_alkio{esineen_nimi, nullptr,nullptr,nullptr,0});


    if ( onko_esineet_tyhja() ){
        eka_esine_ = uuden_osoite;
        vika_esine_ = uuden_osoite;
        lisaa(esineen_nimi, materiaalin_nimi);
        return true;
    }
    else if ( loytyyko_esine(esineen_nimi) ){

        // Haetaan esineen osoite.
        shared_ptr<Esine_alkio> esineen_osoite = eka_esine_;
        while (esineen_osoite != nullptr) {
            if ( esineen_osoite->esine == esineen_nimi ){

                // Lisätään materiaali listaan.
                shared_ptr<Materiaali_alkio> uuden_mat_osoite(new Materiaali_alkio{materiaalin_nimi, nullptr});
                if ( onko_materiaalit_tyhja(esineen_osoite->esine) ){
                    esineen_osoite->eka_materiaali = uuden_mat_osoite;
                    esineen_osoite->vika_materiaali = uuden_mat_osoite;
                } else {
                    esineen_osoite->vika_materiaali->seuraava_mat = uuden_mat_osoite;
                    esineen_osoite->vika_materiaali = uuden_mat_osoite;
                }
            }
        }
        ++esineen_osoite->mat_lkm;
        return true;
    } else {
        vika_esine_->seuraava_esine = uuden_osoite;
        vika_esine_ = uuden_osoite;
        lisaa(esineen_nimi, materiaalin_nimi);
        return true;
    }
}

bool Resepti_map::loytyyko_esine(const string& etsittava) const {
    // etsii esinettä resepteistä.
    // palauttaa: true jos löytyy, muuten false.

    shared_ptr<Esine_alkio> iteraattori = eka_esine_;
    while (iteraattori != nullptr) {
        if ( iteraattori->esine == etsittava ){
            return true;
        }
    }
    return false;
}

bool Resepti_map::loytyyko_materiaali(const string& etsittava) const{
    // käy materiaalilistan läpi.
    // apu_osoite_esine on osoitettava esineeseen, jonka materiaalit
    // käydään läpi.


}



void Resepti_map::tulosta_esineet()const{
    shared_ptr<Esine_alkio> iteraattori = eka_esine_;
    while ( iteraattori != nullptr ) {
        cout << iteraattori->esine << endl;
        iteraattori = iteraattori->seuraava_esine;
    }
}

void Resepti_map::tulosta_materiaalit(const string &esine) const{

    // Etsitään esine resepteistä.
    shared_ptr<Esine_alkio> esineen_os = eka_esine_;
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

bool Resepti_map::onko_esineet_tyhja()const{
    if  ( eka_esine_ == nullptr ){
        return true;
    } else {
        return false;
    }
}
bool Resepti_map::onko_materiaalit_tyhja(const string& esine)const{
    shared_ptr<Esine_alkio> esineen_osoite = eka_esine_;
    while ( esineen_osoite != nullptr ){
        if ( (esineen_osoite->esine == esine) and (esineen_osoite->eka_materiaali == nullptr) ){
            return false;
        }
    }
    return true;
}
