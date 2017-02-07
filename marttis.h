#ifndef MARTTIS_H
#define MARTTIS_H

#include <QMainWindow>

namespace Ui {
class marttis;
}

class marttis : public QMainWindow
{
    Q_OBJECT

public:
    explicit marttis(QWidget *parent = 0);
    ~marttis();

private slots:
    void on_aloitaButton_clicked();
    void on_pelaajiaInput_textChanged(const QString &arg1);
    void on_kierroksiaInput_textChanged(const QString &arg1);

private:
    Ui::marttis *ui;
    QString pelaajiaInput;
    QString kierroksiaInput;
    QString tulosOutput;
};

#endif // MARTTIS_H
