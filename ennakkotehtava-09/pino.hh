#ifndef PINO_HH
#define PINO_HH

class Pino {
      public:
        Pino();
        ~Pino();

        // empty palauttaa true vain, jos rakenteeseen (private-osan
        // linkitetty lista) ei sisällä yhtään alkiota.
        bool empty() const;

        // push_front lisää parametrina saamansa kokonaisluvun
        // private-osan linkitetyn listan alkuun.
        void push_front(int lisattava_arvo);


        // pop_front poistaa listan alusta yhden luvun ja tallentaa
        // sen viiteprametriinsa.  Jos lista on tyhjä, parametrin arvo
        // ei muutu, ja funktio palauttaa false.  Jos listasta saatiin
        // poistettua arvo, paluuarvo on true.
        bool pop_front(int& poistettu_arvo);

        void tulosta() const;

      private:
        struct Pinon_alkio {
            int kokonaisluku;
            Pinon_alkio* seuraavan_osoite;
        };

        Pinon_alkio* ensimmaisen_osoite_;
        Pinon_alkio* viimeisen_osoite_;

    };

#endif // PINO_HH
