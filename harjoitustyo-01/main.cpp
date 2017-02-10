// TIE-02200 Ohjelmoinnin peruskurssi
// Harjoitustyo-01
// Janne Aare 234645
// janne.aare@student.tut.fi


#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

using namespace std;

// Mallikoodista kopioitu splitter-luokka.

const unsigned int SPLITTER_VIRHE = 0;

class Splitter {
  public:
    Splitter(const string& paloiteltava_merkkijono = "");
    void aseta_paloiteltava_merkkijono(const string& merkkijono);
    unsigned int paloittele(char erotinmerkki, bool ohita_tyhjat = false);
    unsigned int kenttien_lukumaara() const;
    string hae_kentta(unsigned int kentan_numero) const;
  private:
    string paloiteltava_;
    vector<string> kentat_;
};

// Pankkitili-luokka.

class Pankkitili {

public:
    Pankkitili();
    Pankkitili(string tilinumero, float saldo, int asiakasnumero);
    void tulosta() const;
    void aseta(string tilinumero, float saldo, int asiakasnumero);
    void pano(float maara);
    bool otto(float maara);
    bool tilisiirto(Pankkitili &tilille, float maara);
    bool saldo_riittaa(float maara) const;
private:
    string tilinumero_;
    float saldo_;
    int asiakasnumero_;

};

void tulosta_virhe(){
    cout << "Virhe: tuntematon valinta" << endl;
}

void tulosta_virhe_negatiivisesta(){
    cout << "Virhe: summien on oltava positiivisia." << endl;
}

//void aseta()



// ----------------------------------------------------------
// Paafunktio.
// ----------------------------------------------------------


int main()
{
   // Luodaan tilit ja laitetaan ne sailioon indeksilla hakua varten.
    Pankkitili tili_1;
    Pankkitili tili_2;
    Pankkitili tili_3;
    vector<Pankkitili> tilit= { tili_1, tili_2, tili_3 };

    Splitter paloittelija;

    bool jatkuu = true;

    while ( jatkuu ){

        // Kayttajalta otetaan syote, joka jaetaan Splitter luokan avulla
        // osiin välilyöntien kohdalta. Palautettavan kenttäluvun perusteella
        // valitaan karkeasti sopiva valinta ja jatketaan tarkempaan syötteen
        // tarkasteluun.

        cout << "pankkitilitesti> ";
        string syote;
        getline(cin, syote);

        paloittelija.aseta_paloiteltava_merkkijono(syote);
        unsigned int kenttia = paloittelija.paloittele(' ', true);

       if (kenttia == 1){

            string valinta = paloittelija.hae_kentta(0);

            if ( valinta == "loppu"){
                jatkuu = false;
                break;
            } else {
                tulosta_virhe();
            }
        }

        else if ( kenttia == 2 ){

           string valinta = paloittelija.hae_kentta(0);

           int num = stoi(paloittelija.hae_kentta(1));

           if ( num < 1 or num > 3 ){
               tulosta_virhe();
               continue;
           }

            unsigned int tili_nro_1 = num - 1 ;
            vector<string> apu;

            if ( valinta == "tulosta"){
                tilit.at(tili_nro_1).tulosta();


            }

            else if ( valinta == "aseta"){
                cout << "Syötä tilinumero: ";
                getline(cin, syote);
                apu.push_back(syote);

                cout << "Syötä saldo: ";
                getline(cin, syote);
                apu.push_back(syote);

                if ( stod(apu.at(1)) < 0 ){
                    tulosta_virhe_negatiivisesta();
                    continue;
                }

                cout << "Syötä asiakasnumero: ";
                getline(cin, syote);
                apu.push_back(syote);


                tilit.at(tili_nro_1).aseta(apu.at(0), stod(apu.at(1)), stoi(apu.at(2)));

                cout << "Tilin " << paloittelija.hae_kentta(1) << " tiedot asetettu."
                     << endl;


            }

            else if ( valinta == "pano"){
                cout << "Syötä rahamäärä: ";
                getline(cin, syote);

                if ( stod(syote) < 0 ){
                    tulosta_virhe_negatiivisesta();
                    continue;
                }

                tilit.at(tili_nro_1).pano(stod(syote));

                cout << "Pano suoritettu tilille " << paloittelija.hae_kentta(1) << "."
                     << endl;


            }

            else if ( valinta == "otto"){

                cout << "Syötä rahamäärä: ";
                getline(cin, syote);

                if ( stod(syote) < 0 ){
                    tulosta_virhe_negatiivisesta();
                    continue;
                }

                float maara = stod(syote);


                if ( tilit.at(tili_nro_1).saldo_riittaa(maara) ){

                    tilit.at(tili_nro_1).otto(maara);
                    cout << "Otto suoritettu tililtä " << paloittelija.hae_kentta(1) << "."
                    << endl;

                } else {
                    cout << "Virhe: tilin saldo ei riitä."
                         << endl;
                }

            }else{
                tulosta_virhe();
            }
            }

        else if (kenttia > 2){

            string valinta = paloittelija.hae_kentta(0);

            int num1 = stoi(paloittelija.hae_kentta(1));
            int num2 = stoi(paloittelija.hae_kentta(2));

            if ( num1 < 1 or num2 < 1 or num1 > 3 or num2 > 3 or num1 == num2){
                tulosta_virhe();
                continue;
            }

            int tilin1_ind = num1 - 1;
            int tilin2_ind = num2 - 1;

            if ( valinta == "tilisiirto"){

                cout << "Syötä siirtomäärä: ";
                getline(cin, syote);

                if ( stod(syote) < 0 ){
                    tulosta_virhe_negatiivisesta();
                    continue;
                }

                float maara = stod(syote);

                if ( tilit.at(tilin1_ind).tilisiirto(tilit.at(tilin2_ind), maara) ){

                } else {
                    cout << "Virhe: tilisiirto epäonnistui."
                         << endl;
                }

            }else{
                tulosta_virhe();
            }

        }else{
            tulosta_virhe();
        }

    }

}

// ----------------------------------------------------------
// Metodien maarittelyt.
// ----------------------------------------------------------

// Mallikoodista kopioidut slitter-luokan metodit.

Splitter::Splitter(const string& paloiteltava_merkkijono):
    paloiteltava_(paloiteltava_merkkijono), kentat_( {} ) {
}


void Splitter::aseta_paloiteltava_merkkijono(const string& merkkijono) {
    paloiteltava_ = merkkijono;
    kentat_ = {};
}


unsigned int Splitter::paloittele(char erotinmerkki, bool ohita_tyhjat) {
    kentat_.clear();

    string::size_type alkukohta = 0;
    string kentan_teksti;

    while ( true ) {

        string::size_type loppukohta;

        loppukohta = paloiteltava_.find(erotinmerkki, alkukohta);

        if ( loppukohta == string::npos ) {
            break;
        }

        kentan_teksti = paloiteltava_.substr(alkukohta, loppukohta - alkukohta);

        if ( not (ohita_tyhjat and kentan_teksti.empty()) ) {
            kentat_.push_back(kentan_teksti);
        }


        alkukohta = loppukohta + 1;
    }


    kentan_teksti = paloiteltava_.substr(alkukohta);

    if ( not (ohita_tyhjat and kentan_teksti.empty()) ) {
        kentat_.push_back(kentan_teksti);
    }

    return kentat_.size();
}


unsigned int Splitter::kenttien_lukumaara() const {

    if ( kentat_.size() == 0 ) {
        return SPLITTER_VIRHE;

    } else {

        return kentat_.size();
    }
}


string Splitter::hae_kentta(unsigned int kentan_numero) const {

    if ( kentat_.empty() or kentan_numero >= kentat_.size() ) {
        throw out_of_range("virheellinen kentan_numero");
    }

    return kentat_.at(kentan_numero);
}


// Pankkitili-luokan metodit.

Pankkitili::Pankkitili():
    tilinumero_("FI0000"), saldo_(0.0), asiakasnumero_(0000000){
}

Pankkitili::Pankkitili(string tilinumero, float saldo, int asiakasnumero):
    tilinumero_(tilinumero), saldo_(saldo), asiakasnumero_(asiakasnumero){

}
void Pankkitili::tulosta() const {
    cout << "Tilinumero: " << tilinumero_ << endl;
    cout << "Saldo: " << saldo_ << endl;
    cout << "Asiakasnumero: " << asiakasnumero_ << endl;
}

void Pankkitili::aseta(string tilinumero, float saldo, int asiakasnumero){
    tilinumero_ = tilinumero;
    saldo_ = saldo;
    asiakasnumero_= asiakasnumero;
}

void Pankkitili::pano(float maara){
    saldo_ += maara;
}

bool Pankkitili::otto(float maara){
    if ( saldo_riittaa(maara) ){
        saldo_ -= maara;
        return true;
    }else{
        return false;
    }

}

bool Pankkitili::tilisiirto(Pankkitili& tilille, float maara){
    if ( saldo_riittaa(maara) ){

        saldo_ -= maara;
        tilille.pano(maara);

        return true;

    } else {
        return false;
    }

}

bool Pankkitili::saldo_riittaa(float maara) const{
    if ( saldo_ - maara >= 0.0){
        return true;
    }else{
        return false;
    }
}
