#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/info_parser.hpp>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

void MainWindow::SetDalFilePath(){
    const auto path_qstr = QFileDialog::getOpenFileName(this, "open \".dal\" file", "", "Dal file (.dal);;All (.*)");
    if(path_qstr.isEmpty()){
        return;
    }
    this->ui->lineEdit->setText(path_qstr);
    this->dal_file_path = boost::filesystem::path(path_qstr.toStdString());
}

void MainWindow::Integrate(){
    const std::string config_file_name = "config.conf";
    const unsigned int default_intencity_index = 7;
    boost::property_tree::ptree ptree;
    std::ifstream ifs(config_file_name);
    if(!ifs){
        std::ofstream ofs(config_file_name);
        ofs << "intencity_index " << default_intencity_index << std::endl;
        ofs.close();
        ifs.open(config_file_name);
    }
    boost::property_tree::info_parser::read_info(ifs, ptree);
    const auto intencity_index = ptree.get<unsigned int>("intencity_index", default_intencity_index);

    if(this->dal_file_path.empty()){
        this->statusBar()->showMessage("invalid dal file path.", 10000);
        return;
    }

    const auto save_path_str = QFileDialog::getSaveFileName().toStdString();
    if(save_path_str.empty()){
        return;
    }
    std::ofstream save_file(save_path_str.c_str());
    if(!save_file){
        this->statusBar()->showMessage("invalid save file path.", 10000);
        return;
    }

    boost::filesystem::ifstream dal_file(this->dal_file_path);
    if(!dal_file){
        this->statusBar()->showMessage("invalid dal file path.", 10000);
        return;
    }

    intencity_integrator::IntegrateIntencity(intencity_index, dal_file, this->dal_file_path, save_file);
}

MainWindow::~MainWindow()
{
    delete ui;
}
