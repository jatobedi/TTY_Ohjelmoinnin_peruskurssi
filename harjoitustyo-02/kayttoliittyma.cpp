#include "kayttoliittyma.hh"

void tulosta_virhe(){
    // Käyttäjän virheellisistä syötteistä
    // tulostetaan tämä virheilmoitus.

    cout << "Virhe: tuntematon syöte." << endl;
}

void lue_syote(vector<string>& syotteet){
    // Lukee käyttäjän syötteen ja käsittelee
    // sen käyttöliittymää varten.
    // syotteet vector<string>: Säiliö
    // käyttäjän syötteitä varten.

    Splitter paloittelija;
    string rivi;
    syotteet.clear();
    while ( rivi.length() < 1){
        cout << "tuotehaku> ";
        getline(cin, rivi);
        if ( rivi.length() > 0){
            paloittelija.aseta_paloiteltava_merkkijono(rivi);
            int kentat = paloittelija.paloittele(' ',1);

            if ( kentat >= 1 ){
            syotteet.push_back(paloittelija.hae_kentta(0));
            }
            if ( kentat >= 2 ){

            syotteet.push_back(paloittelija.hae_kentta(1));
            }
            if ( kentat == 3 ){

             syotteet.push_back(paloittelija.hae_kentta(2));
            }
        }else{
            tulosta_virhe();
        }
    }
}

void kayttoliittyma(ketjut_type& ketjut){
    // Tekee toimintoja käyttäjän syötteiden perusteella.
    // ketjut ketjut_type: tietorakenne, josta tiedot luetaan.

    vector<string> syotteet(3);

    // Käyttäjältä hyväksytyt käskyt.
    set<string> kaskyt = {
            "lopeta", "kauppaketjut", "myymalat",
            "halvin", "tuotevalikoima", "tuotenimet"};

    // Lista tietorakenteen ketjuista tarkistuksia varten.
    set<string> lista_ketjuista;
    for ( auto ketju : ketjut){
        lista_ketjuista.insert(ketju.first);
    }

    // Lista tietorakenteen myymälöistä tarkistuksia varten.
    set<string> lista_myymaloista;
    for ( auto ketju : ketjut ){
       for ( auto kauppa : ketju.second ){
           lista_myymaloista.insert(kauppa.first);
        }

    }
    while ( true ) {
        lue_syote(syotteet);

        if ( kaskyt.find(syotteet.at(0)) != kaskyt.end() ){
            if ( syotteet.at(0) == "lopeta" and syotteet.size() == 1 ){
                break;
            }
            if ( syotteet.at(0) == "kauppaketjut" and syotteet.size() == 1 ){
                tulosta_kauppaketjut(ketjut);
            }
            else if ( syotteet.at(0) == "tuotenimet" and syotteet.size() == 1 ){
                tuotenimet(ketjut);
            }
            else if ( syotteet.at(0) == "halvin" and syotteet.size() == 2 ){
                halvin(ketjut, syotteet.at(1));

            }
            else if ( syotteet.at(0) == "myymalat" and syotteet.size() == 2 and
                      (lista_ketjuista.find(syotteet.at(1)) != lista_ketjuista.end())){
                    tulosta_myymalat(ketjut, syotteet.at(1));
            }

            else if ( syotteet.at(0) == "tuotevalikoima" and syotteet.size() == 3 and
                      (lista_ketjuista.find(syotteet.at(1)) != lista_ketjuista.end()) and
                      (lista_myymaloista.find(syotteet.at(2)) != lista_myymaloista.end())){
                    valikoima(ketjut, syotteet.at(1), syotteet.at(2));

            }else{
                tulosta_virhe();
                }


        }else{
            tulosta_virhe();
        }
    }
}
