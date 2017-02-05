// TIE-02200 Ohjelmoinnin peruskurssi
// ennakkotehtava-03
// Janne Aare 235645
// janne.aare@student.tut.fi


#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>

using namespace std;


const unsigned int SPLITTER_VIRHE = 0;

class Splitter {
public:
  Splitter(const string& paloiteltava_merkkijono = "");
  void aseta_paloiteltava_merkkijono(const string& merkkijono);
  unsigned int paloittele(char erotinmerkki, bool ohita_tyhjat = false);
  unsigned int kenttien_lukumaara() const;
  string hae_kentta(unsigned int kentan_numero) const;

private:
   vector<string> kentat_;
   string merkkijono_;
   unsigned int kenttien_lkm_;
};

// --------------------------
// paafunktio
// --------------------------


int main()
{
    Splitter paloittelija("a::bc:def::hijlkm");

    paloittelija.paloittele(':');  // Huomaa heittomerkit

    cout << "kenttia: " << paloittelija.kenttien_lukumaara() << endl;  // 6

    cout << paloittelija.hae_kentta(0) << endl;  // a
    cout << paloittelija.hae_kentta(4) << endl;  // (tyhjä)
    cout << paloittelija.hae_kentta(5) << endl;  // hijlkm

    for ( unsigned int i = 0; i < paloittelija.kenttien_lukumaara(); ++i ) {
      string kasiteltava_kentta = paloittelija.hae_kentta(i);
      cout << i << ": [" << kasiteltava_kentta << "]" << endl;
    }

   paloittelija.aseta_paloiteltava_merkkijono(" A B  C   D    E     ");
    unsigned int kenttia = paloittelija.paloittele(' ', true);

    cout << "kenttia: " << kenttia << endl;  // 5

    for ( unsigned int i = 0; i < kenttia; ++i ) {
      string kasiteltava_kentta = paloittelija.hae_kentta(i);
      cout << i << ": [" << kasiteltava_kentta << "]" << endl;
    }

    cout << paloittelija.hae_kentta(5) << endl;  // out_of_range


}

// --------------------------
// Metodien maarittelyt
// --------------------------

Splitter::Splitter(const string& paloiteltava_merkkijono):
    merkkijono_(paloiteltava_merkkijono), kenttien_lkm_(SPLITTER_VIRHE){

}
    

void Splitter::aseta_paloiteltava_merkkijono(const string& merkkijono){
    kentat_ = {};
    merkkijono_ = merkkijono;
    kenttien_lkm_ = SPLITTER_VIRHE;
}

unsigned int Splitter::paloittele(char erotinmerkki, bool ohita_tyhjat){
    string::size_type alkukohta = 0;
    string::size_type loppukohta;
    string kentan_sisalto;

    while (true){
        loppukohta = merkkijono_.find(erotinmerkki, alkukohta);
        if (loppukohta != string::npos){
            kentan_sisalto = merkkijono_.substr(alkukohta,(loppukohta-alkukohta));
        }else{
            kentan_sisalto = merkkijono_.substr(alkukohta);
            kentat_.push_back(kentan_sisalto);
            alkukohta = loppukohta+1;
            kenttien_lkm_ += 1;
            break;
        }

        if (not(kentan_sisalto == "" and ohita_tyhjat)){
            kentat_.push_back(kentan_sisalto);
            kenttien_lkm_ += 1;
        }

        alkukohta = loppukohta+1;

        }
    if (kentat_.back() == "" and kentat_.size() != 0 and ohita_tyhjat){

         kentat_.pop_back();
         kenttien_lkm_ -= 1;
    }
    return kenttien_lkm_;
}
    


unsigned int Splitter::kenttien_lukumaara() const{
    return kenttien_lkm_;
}

string Splitter::hae_kentta(unsigned int kentan_numero) const{
    if (kentan_numero > (kenttien_lkm_-1)){
         throw out_of_range("virheellinen kentan_numero");
    }else{
        return kentat_.at(kentan_numero);
    }
}

