#include "pino.hh"
#include <iostream>
#include <string>

Pino::Pino(): ensimmaisen_osoite_(nullptr),
    viimeisen_osoite_(nullptr){
}
Pino::~Pino(){
    Pinon_alkio* vapautettavan_osoite;
    while ( ensimmaisen_osoite_ != nullptr ){
        vapautettavan_osoite = ensimmaisen_osoite_;
        ensimmaisen_osoite_ = ensimmaisen_osoite_->seuraavan_osoite;

        delete vapautettavan_osoite;
    }
}

// empty palauttaa true vain, jos rakenteeseen (private-osan
// linkitetty lista) ei sisällä yhtään alkiota.
bool Pino::empty() const{
    if ( ensimmaisen_osoite_ == nullptr ) {
        return true;
    }else{
        return false;
    }

}

// push_front lisää parametrina saamansa kokonaisluvun
// private-osan linkitetyn listan alkuun.
void Pino::push_front(int lisattava_arvo){
    Pinon_alkio* uuden_osoite = new Pinon_alkio{lisattava_arvo, nullptr};

    if ( ensimmaisen_osoite_ == nullptr ) {
        ensimmaisen_osoite_ = uuden_osoite;
        viimeisen_osoite_ = uuden_osoite;
    }else{
        viimeisen_osoite_->seuraavan_osoite = uuden_osoite;
        viimeisen_osoite_ = uuden_osoite;
    }

}


// pop_front poistaa listan alusta yhden luvun ja tallentaa
// sen viiteprametriinsa.  Jos lista on tyhjä, parametrin arvo
// ei muutu, ja funktio palauttaa false.  Jos listasta saatiin
// poistettua arvo, paluuarvo on true.
bool Pino::pop_front(int& poistettu_arvo){
    if ( empty() ) {
        return false;
    }

    Pinon_alkio* poistettavan_osoite = ensimmaisen_osoite_;

    poistettu_arvo = ensimmaisen_osoite_->kokonaisluku;

    if ( ensimmaisen_osoite_ == viimeisen_osoite_ ) {
        ensimmaisen_osoite_ = nullptr;
        viimeisen_osoite_ = nullptr;
    }else{
        ensimmaisen_osoite_ = ensimmaisen_osoite_->seuraavan_osoite;
    }

    delete poistettavan_osoite;

    return true;
}

void Pino::tulosta() const{
    Pinon_alkio* tulostettavan_osoite = ensimmaisen_osoite_;
    if (tulostettavan_osoite == nullptr ){
        std::cout << "Ei tulostettavaa." << std::endl;
    }

    while ( tulostettavan_osoite != nullptr ) {
        std::cout << tulostettavan_osoite->kokonaisluku << std::endl;
        tulostettavan_osoite = tulostettavan_osoite->seuraavan_osoite;
    }
}
