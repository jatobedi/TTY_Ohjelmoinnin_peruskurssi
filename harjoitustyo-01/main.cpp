// TIE-02200 Ohjelmoinnin peruskurssi
// Harjoitustyo-01
// Janne Aare 234645
// janne.aare@student.tut.fi


#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include <iomanip>

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
    // Pankkitililuokka toimii kuten pankkitili.
    // Pankkitilillä on tilinumero, saldo ja asiakasnumero.
    // Tilitä voi nostaa rahaa, tehdä talletuksen ja siirron
    // tililtä toiselle.

public:
    Pankkitili();
    Pankkitili(string tilinumero, float saldo, int asiakasnumero);
    void tulosta() const;
    void aseta(string tilinumero, double saldo, int asiakasnumero);
    void pano(double maara);
    bool otto(double maara);
    bool tilisiirto(Pankkitili &tilille, double maara);
    bool saldo_riittaa(double maara) const;
private:
    string tilinumero_;
    float saldo_;
    int asiakasnumero_;

};

// Funktiot.

void tulosta_virhe(){
    // Virhe tulostetaan ilmoitukseksi käyttäjän vääristä
    // syötteistä.
    cout << "Virhe: tuntematon valinta" << endl;
}

void tulosta_virhe_negatiivisesta(){
    // Virhe tulostetaan, jos käyttäjä on syöttänyt negatiivisia
    // arvoja rahasummiin.
    cout << "Virhe: summien on oltava positiivisia." << endl;
}

void aseta(vector<Pankkitili>& tilit, int tilinro);
void pano(vector<Pankkitili>& tilit, int tilinro);
void otto(vector<Pankkitili>& tilit, int tilinro);
void tilisiirto(vector<Pankkitili>& tilit, int tilinro1, int tilinro2);

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
        string valinta = paloittelija.hae_kentta(0);

        if (kenttia == 1 and valinta == "loppu" ){
                jatkuu = false;
                break;
        }

        else if ( kenttia == 2 ){

           int tilinro = stoi( paloittelija.hae_kentta(1) );

           if ( tilinro < 1 or tilinro > 3 ){
               tulosta_virhe();
               continue;
           }

            if ( valinta == "tulosta"){
                tilit.at( tilinro - 1 ).tulosta();
            }

            else if ( valinta == "aseta"){
                aseta(tilit, tilinro);
            }

            else if ( valinta == "pano"){
                pano(tilit, tilinro);

            }

            else if ( valinta == "otto"){
                otto(tilit, tilinro);

            }else{
                tulosta_virhe();
            }
        }

        else if ( kenttia > 2 and valinta == "tilisiirto" ){

            int tilinro1 = stoi(paloittelija.hae_kentta(1));
            int tilinro2 = stoi(paloittelija.hae_kentta(2));

            tilisiirto(tilit, tilinro1, tilinro2);

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
    // Oletusrakentaja.

    tilinumero_("FI0000"), saldo_(0.0), asiakasnumero_(0000000){
}

Pankkitili::Pankkitili(string tilinumero, float saldo, int asiakasnumero):
    // Rakentaja.

    tilinumero_(tilinumero), saldo_(saldo), asiakasnumero_(asiakasnumero){

}
void Pankkitili::tulosta() const {
    // tulostaa näytölle tilinumeron, saldon kahden desimaalin tarkkuudella ja
    // asiakasnumeron.

    cout << "Tilinumero: " << tilinumero_ << endl;
    cout << setprecision(2) << fixed << "Saldo: " << saldo_ << endl;
    cout << "Asiakasnumero: " << asiakasnumero_ << endl;
}

void Pankkitili::aseta(string tilinumero, double saldo, int asiakasnumero){
    // Asettaa tilin tiedot.
    // string tilinumero:   tilin tilinumero.
    // double saldo:        tilillä oleva rahamäärä.
    // int asiakasnumero:   asiakasnumero.

    tilinumero_ = tilinumero;
    saldo_ = saldo;
    asiakasnumero_= asiakasnumero;
}

void Pankkitili::pano(double maara){
    // Lisää tilille rahaa.
    // double määrä: tilille lisättävä määrä.
    saldo_ += maara;
}

bool Pankkitili::otto(double maara){
    // Nostaa tililtä rahaa.
    // double maara: nostettava rahamäärä.
    // return bool: true, jos nosto onnistuu, false epäonnistumisesta.

    if ( saldo_riittaa(maara) ){
        saldo_ -= maara;
        return true;
    }else{
        return false;
    }

}

bool Pankkitili::tilisiirto(Pankkitili& tilille, double maara){
    // Siirtää rahaa tililtä toiselle.
    // Pankkitili: tilille: tili, jolle siirretään.
    // double maara: siirrettävä rahamäärä.
    // return bool: true, jos siirto onnistuu, false epäonnistumisesta.

    if ( saldo_riittaa(maara) ){

        saldo_ -= maara;
        tilille.pano(maara);

        return true;

    } else {
        return false;
    }

}

bool Pankkitili::saldo_riittaa(double maara) const{
    // Tarkistaa, ettei tilin mene miinukselle.
    // double maara: rahamäärä, joka tilitä yritetään nostaa.
    // return bool: true, jos saldo riittää. false jos saldo ei riitä.

    if ( saldo_ - maara >= 0.0){
        return true;
    }else{
        return false;
    }
}

// Funktioiden määrittelyt.

void aseta(vector<Pankkitili>& tilit, int tilinro){
    // Asettaa tilin tiedot käyttäjän syötteiden mukaisiksi
    // Pankkitililuokan metodilla:
    //.aseta(string tilinumero, double saldo, int asiakasnumero).
    // vector<Pankkitili>& tilit:   tilioliot sisältävä säiliö.
    // int tilinro:                 muokattavan tilin numero.

    string syote;
    vector<string> apu;
    cout << "Syötä tilinumero: ";
    getline(cin, syote);
    apu.push_back(syote);

    cout << "Syötä saldo: ";
    getline(cin, syote);
    apu.push_back(syote);

    if ( stod(apu.at(1)) >= 0 ){
        cout << "Syötä asiakasnumero: ";
        getline(cin, syote);
        apu.push_back(syote);


        tilit.at( tilinro - 1 ).aseta( apu.at(0), stod(apu.at(1)), stoi(apu.at(2)) );

        cout << "Tilin " << tilinro << " tiedot asetettu."
             << endl;

    } else {
        tulosta_virhe_negatiivisesta();
    }


}

void pano(vector<Pankkitili>& tilit, int tilinro){
    // Lisää tilille käyttäjän syöttämän määrän rahaa.
    // vector<Pankkitili>& tilit:   tilioliot sisältävä säiliö.
    // int tilinro:                 tilin numero.

    string syote;
    cout << "Syötä rahamäärä: ";
    getline(cin, syote);

    if ( stod(syote) >= 0 ){

        tilit.at( tilinro - 1 ).pano(stod(syote));

        cout << "Pano suoritettu tilille " <<  tilinro << "."
             << endl;
    } else {
        tulosta_virhe_negatiivisesta();
    }


}

void otto(vector<Pankkitili>& tilit, int tilinro){
    // Nostaa tililtä käyttäjän syöttämän määrän rahaa.
    // vector<Pankkitili>& tilit:   tilioliot sisältävä säiliö.
    // int tilinro:                 tilin numero.

    string syote;
    cout << "Syötä rahamäärä: ";
    getline(cin, syote);
    double maara = stod(syote);

    if ( maara >= 0 ){

        if ( tilit.at( tilinro - 1 ).saldo_riittaa(maara) ){

            tilit.at( tilinro - 1 ).otto(maara);
            cout << "Otto suoritettu tililtä " << tilinro << "."
            << endl;

        } else {
            cout << "Virhe: tilin saldo ei riitä."
                 << endl;
        }
    } else {
        tulosta_virhe_negatiivisesta();
    }
}

void tilisiirto(vector<Pankkitili>& tilit, int tilinro1, int tilinro2){
    // Siirtää käyttäjän syöttämän määrän rahaa tililtä toiselle.
    // vector<Pankkitili>& tilit:   tilioliot sisältävä säiliö.
    // int tilinro1:                 tili, jolta nostetaan.
    // int tilinro2:                 tili, jolle pannaan.

    if ( tilinro1 < 1 or tilinro2 < 1 or tilinro1 > 3 or tilinro2 > 3 or
         tilinro1 == tilinro2 ){
        tulosta_virhe();
    } else {
        string syote;
        cout << "Syötä siirtomäärä: ";
        getline(cin, syote);
        double maara = stod(syote);

        if ( maara > 0 ){
            // tilisiirtometodi palauttaa onnistuneesta tilisiirrosta true.
            if ( tilit.at(tilinro1-1).tilisiirto(tilit.at(tilinro2-1), maara) ){
            } else {
                cout << "Virhe: tilisiirto epäonnistui."
                     << endl;
              }
        } else {
            tulosta_virhe_negatiivisesta();
        }
    }
}
