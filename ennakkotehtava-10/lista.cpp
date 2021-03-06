#include "lista.hh"
#include <iostream>
#include <string>

using namespace std;

Lista::Lista(): ensimmaisen_osoite_(nullptr),
    viimeisen_osoite_(nullptr){

}

Lista::~Lista() {
    Listan_alkio* vapautettavan_osoite;
    while ( ensimmaisen_osoite_ != nullptr ){
        vapautettavan_osoite = ensimmaisen_osoite_;
        ensimmaisen_osoite_ = ensimmaisen_osoite_->seuraavan_osoite;

        delete vapautettavan_osoite;
    }
}

void Lista::tulosta() const {
    Listan_alkio* tulostettavan_osoite = ensimmaisen_osoite_;
    int jarjestysnumero = 1;

    while ( tulostettavan_osoite != nullptr ) {
        cout << jarjestysnumero << ". "
             << tulostettavan_osoite->tehtava << endl;
        ++jarjestysnumero;
        tulostettavan_osoite = tulostettavan_osoite->seuraavan_osoite;
    }
}

void Lista::lisaa_alkio_loppuun(const string &lisattava_tehtava) {
    Listan_alkio* uuden_osoite = new Listan_alkio;

    uuden_osoite->tehtava = lisattava_tehtava;
    uuden_osoite->seuraavan_osoite = nullptr;

    if ( ensimmaisen_osoite_ == nullptr ) {
        ensimmaisen_osoite_ = uuden_osoite;
        viimeisen_osoite_ = uuden_osoite;
    } else {

    }
}

bool Lista::poista_alkio_alusta(string &poistettu_tehtava) {
    if ( onko_tyhja() ) {
        return false;
    }

    Listan_alkio* poistettavan_osoite = ensimmaisen_osoite_;

    poistettu_tehtava = poistettavan_osoite->tehtava;

    if ( ensimmaisen_osoite_ == viimeisen_osoite_ ) {
        ensimmaisen_osoite_ = nullptr;
        viimeisen_osoite_ = nullptr;
    } else {
        ensimmaisen_osoite_ = ensimmaisen_osoite_->seuraavan_osoite;
    }

    delete poistettavan_osoite;

    return true;
}

bool Lista::poista_alkio(string poistettava, string& poistettu_tehtava){
    if ( onko_tyhja() ) {
        return false;
    }

    Listan_alkio* poistettavan_osoite = ensimmaisen_osoite_;



    while ( poistettavan_osoite != nullptr ) {
        poistettu_tehtava = poistettavan_osoite->tehtava;

        if (poistettu_tehtava == poistettava ){
            if ( ensimmaisen_osoite_ == viimeisen_osoite_ ) {
                ensimmaisen_osoite_ = nullptr;
                viimeisen_osoite_ = nullptr;
            } else {
                ensimmaisen_osoite_ = ensimmaisen_osoite_->seuraavan_osoite;
            }

            delete poistettavan_osoite;
            return true;

        } else {
            ensimmaisen_osoite_ = ensimmaisen_osoite_->seuraavan_osoite;
        }
    }


    return false;

}

bool Lista::onko_tyhja() const {
    if ( ensimmaisen_osoite_ == nullptr ) {
        return true;
    } else {
        return false;
    }
}
