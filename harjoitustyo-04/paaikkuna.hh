#ifndef PAAIKKUNA_HH
#define PAAIKKUNA_HH

#include <QMainWindow>

namespace Ui {
class Paaikkuna;
}
class QAction;
class QActionGroup;
class QMenu;

class Paaikkuna : public QMainWindow
{
    Q_OBJECT

public:
    explicit Paaikkuna(QWidget *parent = 0);
    ~Paaikkuna();

public slots:
    void nollaa_kaikki_arvot();
    double laske_bmi(double paino, double pituus);
    void paivita_kentat();
    void tulosta_mies_bmi(double bmi);
    void tulosta_nais_bmi(double bmi);

private:
    Ui::Paaikkuna *ui;
    void luo_actionit();
    void luo_menut();

    QMenu *menu_toimenpide;
    QMenu *menu_sukupuoli;
    QActionGroup *sukupuoliryhma;
    QAction *act_alkutila;
    QAction *act_lopeta;
    QAction *act_nainen;
    QAction *act_mies;

};

#endif // PAAIKKUNA_HH
