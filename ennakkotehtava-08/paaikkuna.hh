#ifndef PAAIKKUNA_HH
#define PAAIKKUNA_HH

#include <QMainWindow>

namespace Ui {
class Paaikkuna;
}

class Paaikkuna : public QMainWindow
{
    Q_OBJECT

public:
    explicit Paaikkuna(QWidget *parent = 0);
    ~Paaikkuna();

public slots:
    void nollaa_kaikki_arvot();
    void aseta_mailit();

private:
    Ui::Paaikkuna *ui;
};

#endif // PAAIKKUNA_HH
