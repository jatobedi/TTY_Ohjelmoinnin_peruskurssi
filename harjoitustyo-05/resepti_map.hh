#ifndef RESEPTI_MAP_HH
#define RESEPTI_MAP_HH


#include <string>
#include <memory>

using namespace std;


class Resepti_map
{
public:
    Resepti_map();
    bool lisaa(string esineen_nimi, string materiaalin_nimi);
    void tulosta_esineet()const;
    void tulosta_materiaalit(const string& esine)const;
    bool loytyyko_esine(const string &etsittava)const;
    bool loytyyko_materiaali(const string& etsittava)const;
    bool onko_esineet_tyhja()const;
    bool onko_materiaalit_tyhja(const string& esine)const;
private:
    struct Materiaali_alkio {
        string materiaali;
        shared_ptr<Materiaali_alkio> seuraava_mat;
    };

    struct Esine_alkio {
        string esine;
        shared_ptr<Esine_alkio> seuraava_esine;
        shared_ptr<Materiaali_alkio> eka_materiaali;
        shared_ptr<Materiaali_alkio> vika_materiaali;
        int mat_lkm;
    };

    shared_ptr<Esine_alkio> eka_esine_;
    shared_ptr<Esine_alkio> vika_esine_;
};

#endif // RESEPTI_MAP_HH
