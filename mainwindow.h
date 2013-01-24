#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
private:
    void init();

    Ui::MainWindow *ui;

public slots:
    void openPreferencesDialog();

private slots:
    void exchangeRateUpdate(const float rate);

};

#endif // MAINWINDOW_H
