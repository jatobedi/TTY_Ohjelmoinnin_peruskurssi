// TIE-02200 Ohjelmoinnin peruskurssi
// ennakkotehtava-08
// Janne Aare 235645
// janne.aare@student.tut.fi

#include "paaikkuna.hh"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Paaikkuna w;
    w.show();

    return a.exec();
}
