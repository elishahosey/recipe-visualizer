#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QProcess>
#include <QString>
#include <QDir>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

// string recipeUrl;

void MainWindow::on_btnVisualize_clicked()
{
    //when clicked, take the recipe url and scrape the site for food references
    QString recipeUrl = ui->txt_url->toPlainText();

    //TODO: set up your python env
    QString pythonPath = "C:/Anaconda3/envs/personal/python.exe";
    QString script = "D:/PROJECT/RecipeVisualizer/scrape.py";

    // Create a QProcess object
    QProcess process;

    // Prepare the arguments for the script
    QStringList arguments;
    arguments << script << recipeUrl;

    // Start the process
    process.start(pythonPath, arguments);

    // Wait for the process to finish (optional)
    process.waitForFinished();

    // Print output from the script (optional)
    QString output = process.readAllStandardOutput();
    QString errorOutput = process.readAllStandardError();
    qDebug() << "Script Output:" << output;
    qDebug() << "Error Output:" << errorOutput;

}

