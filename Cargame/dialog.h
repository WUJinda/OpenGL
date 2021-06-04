#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>


namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();

    bool getQuit() {return quit_;}//Vérifiez si l'utilisateur souhaite se déconnecter
    bool getRestart() {return restart_;}//Vérifiez si l'utilisateur souhaite recommencer
    void setRandT(int record, QString time);//Le temps et le score sont affichés dans la boîte de dialogue.
private:
    Ui::Dialog *ui;
    bool quit_ = false;
    bool restart_ = false;

private slots:
    void on_Restart_clicked();
    void on_Quit_clicked();
};

#endif // DIALOG_H
