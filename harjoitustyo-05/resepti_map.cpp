#include "resepti_map.hh"

#include <string>
#include <iostream>
#include <memory>
#include <algorithm>

using namespace std;

Resepti_map::Resepti_map():
    reseptit_{nullptr},
    viimeinen_resepti_{nullptr}
{

}

void Resepti_map::lisaa_alkio(const string& lisattava_esine, const string& lisattava_materiaali){
    if ( loytyyko_esine_resepteista(lisattava_esine) ){
        lisaa_materiaali(lisattava_esine, lisattava_materiaali);
    } else {
        lisaa_esine(lisattava_esine);
        lisaa_materiaali(lisattava_esine, lisattava_materiaali);
    }
}

void Resepti_map::lisaa_esine(const string& lisattava_esine){
    shared_ptr<R_alk> uuden_osoite(new R_alk{lisattava_esine, nullptr, 0, nullptr});
    if ( onko_reseptit_tyhja() ){
        reseptit_ = uuden_osoite;
        viimeinen_resepti_ = uuden_osoite;
    } else {
        viimeinen_resepti_->seuraava_esine = uuden_osoite;
        viimeinen_resepti_ = uuden_osoite;
    }
}

void Resepti_map::lisaa_materiaali(const string& haettava_esine, const string& lisattava_materiaali){
    // Haetaan esine resepteistä, että voidaan tarkistaa, onko siinä materiaaleja.
    R_alk* haettavan_osoite = reseptit_.get();
    while ( haettavan_osoite != nullptr ) {
        if ( haettavan_osoite->esine == haettava_esine)
            lisaa_taulukkoon(haettavan_osoite, lisattava_materiaali);
        haettavan_osoite = haettavan_osoite->seuraava_esine.get();
    }
}

void Resepti_map::lisaa_taulukkoon(R_alk* esineen_osoite, const string& lisattava_materiaali){
    int vanha_taulukon_koko = esineen_osoite->mat_lkm;
    int uusi_taulukon_koko = vanha_taulukon_koko + 1;

    if ( onko_materiaalit_tyhja(esineen_osoite) ){
        string* uusi_taulukko = new string[1];
        uusi_taulukko[0] = lisattava_materiaali;
        esineen_osoite->materiaalit = uusi_taulukko;
    } else {
        string* uusi_taulukko = new string[uusi_taulukon_koko];
        string* vanha_taulukko = esineen_osoite->materiaalit;
        for (int i = 0; i < vanha_taulukon_koko; ++i){
            uusi_taulukko[i] = vanha_taulukko[i];
        }
        uusi_taulukko[vanha_taulukon_koko] = lisattava_materiaali;
        esineen_osoite->materiaalit = uusi_taulukko;
        delete [] vanha_taulukko;
    }
    esineen_osoite->mat_lkm = uusi_taulukon_koko;
}

void Resepti_map::tulosta_esineet(){
    R_alk* tulostettavan_osoite = reseptit_.get();
    while (tulostettavan_osoite != nullptr) {
        cout << tulostettavan_osoite->esine << endl;
        tulostettavan_osoite = tulostettavan_osoite->seuraava_esine.get();
    }
}

void Resepti_map::tulosta_materiaalit(const string& etsittava_esine){
    R_alk* etsittavan_osoite = reseptit_.get();
    while ( etsittavan_osoite != nullptr ) {
        if ( etsittavan_osoite->esine == etsittava_esine){
            string* taulukon_osoite = etsittavan_osoite->materiaalit;
            int taulukon_koko = etsittavan_osoite->mat_lkm;

            sort(taulukon_osoite, taulukon_osoite + taulukon_koko);

            for (int i = 0; i < taulukon_koko; ++i){
                cout << taulukon_osoite[i] << endl;
            }
        }
        etsittavan_osoite = etsittavan_osoite->seuraava_esine.get();
    }
}

bool Resepti_map::onko_reseptit_tyhja(){
    if ( reseptit_ == nullptr ){
        return true;
    } else {
        return false;
        }
}

bool Resepti_map::onko_materiaalit_tyhja(R_alk* esineen_osoite){
    if ( esineen_osoite->materiaalit == nullptr ){
        return true;
    } else {
        return false;
        }
}

bool Resepti_map::loytyyko_esine_resepteista(const string& etsittava_esine){
    R_alk* etsittavan_osoite = reseptit_.get();
    while ( etsittavan_osoite != nullptr ) {
        if ( etsittavan_osoite->esine == etsittava_esine)
            return true;
        etsittavan_osoite = etsittavan_osoite->seuraava_esine.get();
    }
    return false;
}

bool Resepti_map::loytyyko_materiaali_esineesta(const string& etsittava_esine, const string& etsittava_materiaali){
    // Haetaan esine resepteistä, että voidaan tarkistaa, onko siinä materiaaleja.
    R_alk* etsittavan_osoite = reseptit_.get();
    while ( etsittavan_osoite != nullptr ) {
        if ( etsittavan_osoite->esine == etsittava_esine){

            // Verrataan jokaista taulukon esinettä etsittävään.
            int taulukon_koko = etsittavan_osoite->mat_lkm;
            string* materiaalin_osoite = etsittavan_osoite->materiaalit;
            for (int i = 0; i < taulukon_koko; ++i){
                if ( materiaalin_osoite[i] == etsittava_materiaali ){
                    return true;
                }
            }
        }
        etsittavan_osoite = etsittavan_osoite->seuraava_esine.get();
    }
    return false;
}
