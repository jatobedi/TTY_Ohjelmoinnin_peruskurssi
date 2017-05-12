#ifndef RESEPTI_MAP_HH
#define RESEPTI_MAP_HH


#include <string>
#include <memory>

using namespace std;


class Resepti_map
{
public:
    Resepti_map();
    bool lisaa_esine(string esineen_nimi);
    bool lisaa_materiaali(string esineen_nimi, string materiaalin_nimi);
    void tulosta();
    void tulosta_materiaalit(string esine);
    bool loytyyko_esine(const string &etsittava);
private:
    struct Materiaali_alkio {
        string materiaali;
        shared_ptr<Materiaali_alkio> seuraava_mat;

        bool operator<(const Materiaali_alkio& a){
            return materiaali < a.materiaali;
        }
    };

    struct Esine_alkio {
        string esine;

        shared_ptr<Esine_alkio> seuraava_esine;
        Esine_alkio* edellinen_esine;

        shared_ptr<Materiaali_alkio> eka_materiaali;
        Materiaali_alkio* vika_materiaali;
        int mat_lkm;
    };


    shared_ptr<Esine_alkio> ensimmainen_esine_;
    Esine_alkio* viimeinen_esine_;
    int lkm_;



};

#endif // RESEPTI_MAP_HH


