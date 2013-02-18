#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "IntencityIntegrator/IntensityIntegrator.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void SetDalFilePath();
    void Integrate();
    
private:
    Ui::MainWindow *ui;

    boost::filesystem::path dal_file_path;
};

#endif // MAINWINDOW_H
