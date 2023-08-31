#pragma once

#include <QtWidgets/QMainWindow>
#include <QFileDialog>
#include <QMessageBox>
#include "ui_app.h"
#include <QTextEdit>
#include <QLineEdit>
#include <QFileDialog>
#include <QLabel>
#include <QVBoxLayout>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <QDebug>
#include <QPrintDialog>
#include <QPrinter>
#include <QGuiApplication>

class App : public QMainWindow
{
    Q_OBJECT

public:
    App(QWidget* parent = nullptr);
    ~App();


private slots:
    void pushButton_clicked();
    void pushButton1_clicked();
    void pushButton2_clicked();
    void pushButton3_clicked();
    void pushButton4_clicked();
    void pushButtonImport_clicked();
    void onFileImported(const QString& filePath);
    void onTabChanged(int index);
    void pushButton9_clicked();

    //void onConfirmationButtonClicked();
    //void changeLanguage(QAction* action); // Îáúÿâëÿåì íîâûé ñëîò

private:
    Ui::App ui;
    QLabel* label; // Äîáàâëÿåì QLabel äëÿ îòîáðàæåíèÿ èçîáðàæåíèÿ
    //QLineEdit* inputField;
    //QPushButton* confirmationButton;
};
