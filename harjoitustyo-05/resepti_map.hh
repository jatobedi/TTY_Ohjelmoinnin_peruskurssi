// TIE-02200 Ohjelmoinnin peruskurssi
// harjoitustyo-05
// Janne Aare 235645
// janne.aare@student.tut.fi
// Resepti_map on lähdetietosäiliö,
// johon syötetään tiedot vain ohjelman
// alussa ja sen jälkeen sitä käytetään
// vain tietolähteenä.

#ifndef RESEPTI_MAP_HH
#define RESEPTI_MAP_HH
#include <string>
#include <memory>

using namespace std;

class Resepti_map
{
private:
    // Reseptilistan alkio = R_alk.

    struct R_alk {
        string esine;
        string* materiaalit; // taulukko
        int mat_lkm;

        shared_ptr<R_alk> seuraava_esine;
    };

    shared_ptr<R_alk> reseptit_;
    shared_ptr<R_alk> viimeinen_resepti_;

    void lisaa_esine(const string& esine);
    void lisaa_materiaali(const string& esine,
                          const string& lisattava_materiaali);
    void lisaa_taulukkoon(R_alk* esineen_osoite,
                          const string& lisattava_materiaali);
    bool onko_reseptit_tyhja()const;
    bool onko_materiaalit_tyhja(R_alk* esineen_osoite)const;


public:
    Resepti_map();

    void lisaa_alkio(const string& lisattava_esine,
                     const string& lisattava_materiaali);
    bool loytyyko_esine_resepteista(const string& esine)const;
    bool loytyyko_materiaali_esineesta(const string& etsittava_esine,
                                       const string& etsittava_materiaali)const;
    void tulosta_materiaalit(const string& etsittava_esine)const;
    string* esineen_materiaalitaulukko(const string& etsittava_esine)const;
    int esineen_materiaalimaara(const string& etsittava_esine)const;
    void tuhoa_taulukot();
};

#endif // RESEPTI_MAP_HH
