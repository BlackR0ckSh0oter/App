#include "app.h"
#include "Pid.h"

App::App(QWidget* parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    ui.tabWidget->setCurrentIndex(0);

    QString imagePathLabel1 = "/home/vlad/Загрузки/1614846257_72-p-fon-flag-rossii-88.jpg";
    QPixmap pixmapLabel1(imagePathLabel1);

    // Ñîçäàåì è óñòàíàâëèâàåì èçîáðàæåíèå äëÿ label
    label = new QLabel(this);
    label->setPixmap(pixmapLabel1);
    label->setGeometry(0, 0, pixmapLabel1.width(), pixmapLabel1.height());
    label->setAlignment(Qt::AlignCenter);
    label->show();

    // Óñòàíàâëèâàåì òàéìåð äëÿ ñêðûòèÿ èçîáðàæåíèÿ ÷åðåç 4 ñåêóíäû
    QTimer::singleShot(4000, [this]() {
        label->setVisible(false);
        show();
        });

    // Îñòàëüíîé êîä âàøåãî ïðèëîæåíèÿ áåç èçìåíåíèé
    for (int i = 0; i < ui.tabWidget->count(); ++i) {
        ui.tabWidget->setTabText(i, "");
    }

    //QString imagePath = "C:\\Users\\Vlad\\Desktop\\pngtree-watercolor-or-torn-flag-of-russia-png-image_3626955.jpg"; // Ïóòü ê èçîáðàæåíèþ
    //QPixmap pixmap(imagePath);
    //if (!pixmap.isNull())
    //{
    //    QLabel* label_2 = new QLabel(ui.centralWidget); // Ïðîâåðüòå, ÷òî ui.centralWidget - ýòî ïðàâèëüíûé ðîäèòåëüñêèé âèäæåò
    //    label_2->setPixmap(pixmap);
    //    label_2->setAlignment(Qt::AlignCenter);

    //    // Óñòàíîâêà ðàçìåðîâ ìåòêè ðàâíûìè ðàçìåðàì èçîáðàæåíèÿ
    //    label_2->setFixedSize(pixmap.size());
    //}

    connect(ui.pushButton, &QPushButton::clicked, this, &App::pushButton_clicked);
    connect(ui.pushButton_2, &QPushButton::clicked, this, &App::pushButton1_clicked);
    connect(ui.pushButton_3, &QPushButton::clicked, this, &App::pushButton2_clicked);
    connect(ui.pushButton_4, &QPushButton::clicked, this, &App::pushButton3_clicked);
    connect(ui.pushButton_5, &QPushButton::clicked, this, &App::pushButton4_clicked);
    connect(ui.pushButton_10, &QPushButton::clicked, this, &App::pushButtonImport_clicked);
    connect(ui.pushButton_9, &QPushButton::clicked, this, &App::pushButton9_clicked);
    connect(ui.tabWidget, &QTabWidget::currentChanged, this, &App::onTabChanged);




    //inputField = new QLineEdit(ui.tabWidget->widget(0));
    //inputField->setPlaceholderText("Ââåäèòå öåëîå ÷èñëî");
    //inputField->setAlignment(Qt::AlignCenter);

    //confirmationButton = new QPushButton("Ïîäòâåðäèòü", ui.pushButton_15);
    //connect(confirmationButton, &QPushButton::clicked, this, &App::onConfirmationButtonClicked);

    //QVBoxLayout* layout = new QVBoxLayout(ui.pushButton_6);
    //layout->addWidget(inputField);
    //layout->addWidget(confirmationButton);
    //ui.tabWidget->widget(0)->setLayout(layout);


}

App::~App()
{

}

void App::pushButton_clicked()
{
    ui.tabWidget->setCurrentIndex(1); // Ïåðåêëþ÷åíèå íà ïåðâóþ âêëàäêó
}

void App::pushButton1_clicked()
{
    ui.tabWidget->setCurrentIndex(2); // Ïåðåêëþ÷åíèå íà âòîðóþ âêëàäêó
}

void App::pushButton2_clicked()
{
    ui.tabWidget->setCurrentIndex(3); // Ïåðåêëþ÷åíèå íà òðåòüþ âêëàäêó
}

void App::pushButton3_clicked()
{
    ui.tabWidget->setCurrentIndex(4); // Ïåðåêëþ÷åíèå íà ÷åòâåðòóþ âêëàäêó
}

void App::pushButton4_clicked()
{
    ui.tabWidget->setCurrentIndex(5); // Ïåðåêëþ÷åíèå íà ïÿòóþ âêëàäêó
}

void App::pushButtonImport_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"), "C:\\Users\\Vlad\\Desktop", tr("Images (*.png *.xpm *.jpg)"));
}

void App::onFileImported(const QString& filePath)
{
    QStringList fileNames = QFileDialog::getOpenFileNames(this, tr("Âûáåðèòå ôàéëû"), "", tr("Âñå ôàéëû (*.*);;Èçîáðàæåíèÿ (*.png *.xpm *.jpg)"));
    if (!fileNames.isEmpty())
    {
        // Îáðàáîòêà âûáðàííûõ ôàéëîâ
        foreach(QString fileName, fileNames)
        {
            // Âàø êîä äëÿ îáðàáîòêè ôàéëà
            // Íàïðèìåð, ìîæíî âûâåñòè èìÿ ôàéëà â êîíñîëü
            qDebug() << "Âûáðàí ôàéë:" << fileName;
        }
    }
}

//void App::Text()
//{
//    // ×àñòü óïðàâëåíèÿ Òýíîì
//    PID pid = PID(0.1, 100, -100, 0.1, 0.01, 0.5);

//    double val = 20;
//    QString outputText;
//    for (int i = 0; i < 100; i++) {
//        double inc = pid.calculate(0, val);
//        outputText += QString("val:% 7.3f inc:% 7.3f\n").arg(val).arg(inc);
//        val += inc;
//    }

//    ui.textEdit_4->setPlainText(outputText); // Óñòàíîâèòü òåêñò â QTextEdit
//}


void App::onTabChanged(int index)
{
    if (index == 1)
    {
        // Èçìåíåíèå ñòèëÿ êíîïêè äëÿ âòîðîé âêëàäêè,
        ui.pushButton->setStyleSheet("QPushButton{border-radius: 10px; background-color: rgb(38, 162, 105); color: rgb(255, 168, 80); font-size: 20px;}");
        ui.pushButton_2->setStyleSheet("QPushButton{border-radius: 10px; background-color: rgb(0, 0, 127); color: rgb(255, 168, 80); font-size: 20px;}");
        ui.pushButton_3->setStyleSheet("QPushButton{border-radius: 10px; background-color: rgb(0, 0, 127); color: rgb(255, 168, 80); font-size: 20px;}");
        ui.pushButton_4->setStyleSheet("QPushButton{border-radius: 10px; background-color: rgb(0, 0, 127); color: rgb(255, 168, 80); font-size: 20px;}");
        ui.pushButton_5->setStyleSheet("QPushButton{border-radius: 10px; background-color: rgb(0, 0, 127); color: rgb(255, 168, 80); font-size: 20px;}");
        ui.pushButton_10->setStyleSheet("QPushButton{border-radius: 10px; background-color: rgb(0, 0, 127); color: rgb(255, 168, 80); font-size: 20px;}");

    }
    else if (index == 2)
    {
        // Èçìåíåíèå ñòèëÿ êíîïêè äëÿ òðåòüåé âêëàäêè
        ui.pushButton_2->setStyleSheet("QPushButton{border-radius: 10px; background-color: rgb(38, 162, 105); color: rgb(255, 168, 80); font-size: 20px;}");
        ui.pushButton->setStyleSheet("QPushButton{border-radius: 10px; background-color: rgb(0, 0, 127); color: rgb(255, 168, 80); font-size: 20px;}");
        ui.pushButton_3->setStyleSheet("QPushButton{border-radius: 10px; background-color: rgb(0, 0, 127); color: rgb(255, 168, 80); font-size: 20px;}");
        ui.pushButton_4->setStyleSheet("QPushButton{border-radius: 10px; background-color: rgb(0, 0, 127); color: rgb(255, 168, 80); font-size: 20px;}");
        ui.pushButton_5->setStyleSheet("QPushButton{border-radius: 10px; background-color: rgb(0, 0, 127); color: rgb(255, 168, 80); font-size: 20px;}");
        ui.pushButton_10->setStyleSheet("QPushButton{border-radius: 10px; background-color: rgb(0, 0, 127); color: rgb(255, 168, 80); font-size: 20px;}");



    }
    else if (index == 3)
    {
        // Èçìåíåíèå ñòèëÿ êíîïêè äëÿ ÷åòâåðòîé âêëàäêè
        ui.pushButton_3->setStyleSheet("QPushButton{border-radius: 10px; background-color: rgb(38, 162, 105); color: rgb(255, 168, 80); font-size: 20px;}");
        ui.pushButton_2->setStyleSheet("QPushButton{border-radius: 10px; background-color: rgb(0, 0, 127); color: rgb(255, 168, 80); font-size: 20px;}");
        ui.pushButton->setStyleSheet("QPushButton{border-radius: 10px; background-color: rgb(0, 0, 127); color: rgb(255, 168, 80); font-size: 20px;}");
        ui.pushButton_4->setStyleSheet("QPushButton{border-radius: 10px; background-color: rgb(0, 0, 127); color: rgb(255, 168, 80); font-size: 20px;}");
        ui.pushButton_5->setStyleSheet("QPushButton{border-radius: 10px; background-color: rgb(0, 0, 127); color: rgb(255, 168, 80); font-size: 20px;}");
        ui.pushButton_10->setStyleSheet("QPushButton{border-radius: 10px; background-color: rgb(0, 0, 127); color: rgb(255, 168, 80); font-size: 20px;}");


    }
    else if (index == 4)
    {
        // Èçìåíåíèå ñòèëÿ êíîïêè äëÿ ïÿòîé âêëàäêè
        ui.pushButton_4->setStyleSheet("QPushButton{border-radius: 10px; background-color: rgb(38, 162, 105); color: rgb(255, 168, 80); font-size: 20px;}");
        ui.pushButton->setStyleSheet("QPushButton{border-radius: 10px; background-color: rgb(0, 0, 127); color: rgb(255, 168, 80); font-size: 20px;}");
        ui.pushButton_2->setStyleSheet("QPushButton{border-radius: 10px; background-color: rgb(0, 0, 127); color: rgb(255, 168, 80); font-size: 20px;}");
        ui.pushButton_3->setStyleSheet("QPushButton{border-radius: 10px; background-color: rgb(0, 0, 127); color: rgb(255, 168, 80); font-size: 20px;}");
        ui.pushButton_5->setStyleSheet("QPushButton{border-radius: 10px; background-color: rgb(0, 0, 127); color: rgb(255, 168, 80); font-size: 20px;}");
        ui.pushButton_10->setStyleSheet("QPushButton{border-radius: 10px; background-color: rgb(0, 0, 127); color: rgb(255, 168, 80); font-size: 20px;}");


    }
    else if (index == 5)
    {
        // Èçìåíåíèå ñòèëÿ êíîïêè äëÿ øåñòîé âêëàäêè
        ui.pushButton_5->setStyleSheet("QPushButton{border-radius: 10px; background-color: rgb(38, 162, 105); color: rgb(255, 168, 80); font-size: 20px;}");
        ui.pushButton->setStyleSheet("QPushButton{border-radius: 10px; background-color: rgb(0, 0, 127); color: rgb(255, 168, 80); font-size: 20px;}");
        ui.pushButton_2->setStyleSheet("QPushButton{border-radius: 10px; background-color: rgb(0, 0, 127); color: rgb(255, 168, 80); font-size: 20px;}");
        ui.pushButton_3->setStyleSheet("QPushButton{border-radius: 10px; background-color: rgb(0, 0, 127); color: rgb(255, 168, 80); font-size: 20px;}");
        ui.pushButton_4->setStyleSheet("QPushButton{border-radius: 10px; background-color: rgb(0, 0, 127); color: rgb(255, 168, 80); font-size: 20px;}");
        ui.pushButton_10->setStyleSheet("QPushButton{border-radius: 10px; background-color: rgb(0, 0, 127); color: rgb(255, 168, 80); font-size: 20px;}");
    }
    else if (index == 6)
    {
        // Èçìåíåíèå ñòèëÿ êíîïêè äëÿ ñåäüìîé âêëàäêè
        ui.pushButton_10->setStyleSheet("QPushButton{border-radius: 10px; background-color: rgb(38, 162, 105); color: rgb(255, 168, 80); font-size: 20px;}");
        ui.pushButton->setStyleSheet("QPushButton{border-radius: 10px; background-color: rgb(0, 0, 127); color: rgb(255, 168, 80); font-size: 20px;}");
        ui.pushButton_2->setStyleSheet("QPushButton{border-radius: 10px; background-color: rgb(0, 0, 127); color: rgb(255, 168, 80); font-size: 20px;}");
        ui.pushButton_3->setStyleSheet("QPushButton{border-radius: 10px; background-color: rgb(0, 0, 127); color: rgb(255, 168, 80); font-size: 20px;}");
        ui.pushButton_5->setStyleSheet("QPushButton{border-radius: 10px; background-color: rgb(0, 0, 127); color: rgb(255, 168, 80); font-size: 20px;}");
        ui.pushButton_4->setStyleSheet("QPushButton{border-radius: 10px; background-color: rgb(0, 0, 127); color: rgb(255, 168, 80); font-size: 20px;}");
    }
}


void App::pushButton9_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Select File to Print"), "", tr("Text Files (*.txt);;All Files (*)"));
    if (fileName.isEmpty()) {
        return;
    }

    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::warning(this, tr("Error"), tr("Could not open the selected file."));
        return;
    }

    QTextStream in(&file);
    QString textToPrint = in.readAll();

    QPrinter printer;
    printer.setPrinterName("Your_Printer_Name"); // Укажите имя принтера

    QTextDocument doc;
    doc.setPlainText(textToPrint);
    doc.print(&printer);

    file.close();
}


//void App::onConfirmationButtonClicked()
//{
//    bool ok;
//    int inputValue = inputField->text().toInt(&ok);
//    if (ok)
//    {
//        // Äåéñòâèÿ ñ ïîëó÷åííûì öåëûì ÷èñëîì inputValue
//        // Íàïðèìåð, ìîæíî âûâåñòè åãî â QTextEdit
//        ui.textEdit->append(QString("Ââåäåííîå ÷èñëî: %1").arg(inputValue));
//    }
//    else
//    {
//        // Â ñëó÷àå, åñëè ââåäåííîå çíà÷åíèå íå ÿâëÿåòñÿ öåëûì÷èñëîì
//        QMessageBox::warning(this, "Îøèáêà", "Íåêîððåêòíûé ââîä. Ââåäèòå öåëîå ÷èñëî.");
//    }
//}




