#include "viewmainwindow.hpp"
#include "dialogparameter.hpp"

#include <QMenuBar>
#include <QStyle>
#include <QFileDialog>
#include <QPrinter>
#include <QPrintDialog>
#include <QDockWidget>
#include <QGridLayout>
#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QTabWidget>
#include <QPixmap>

ViewMainWindow::ViewMainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    //Setup menuBarWidget
    {
        QMenuBar *menuBar = new QMenuBar(this);

        QSize sizeIconMenuBar(16, 16);

        //Setup menuWidget
        {
            QMenu *menuFile = menuBar->addMenu(QIcon(tr(":/icons/icon27.png")).pixmap(sizeIconMenuBar),
                                               tr("&Datei")
                                               );

            menuFile->addAction(QIcon(tr(":/icons/icon28.png")).pixmap(sizeIconMenuBar),
                                tr("&Parameter ..."),
                                this,
                                &ViewMainWindow::actionSet,
                                QKeySequence::New
                                );

            menuFile->addSeparator();

            menuFile->addAction(QIcon(tr(":/icons/icon33.png")).pixmap(sizeIconMenuBar),
                                tr("&Speichern ..."),
                                this,
                                &ViewMainWindow::actionSave,
                                QKeySequence::Save
                                );

            menuFile->addAction(QIcon(tr(":/icons/icon36.png")).pixmap(sizeIconMenuBar),
                                tr("&Öffnen ..."),
                                this,
                                &ViewMainWindow::actionOpen,
                                QKeySequence::Open
                                );

            menuFile->addSeparator();

            menuFile->addAction(QIcon(tr(":/icons/icon34.png")).pixmap(sizeIconMenuBar),
                                tr("&Drucken ..."),
                                this,
                                &ViewMainWindow::actionPrint,
                                QKeySequence::Print
                                );

            menuFile->addAction(QIcon(tr(":/icons/icon35.png")).pixmap(sizeIconMenuBar),
                                tr("&Exportieren ..."),
                                this,
                                &ViewMainWindow::actionPrint,
                                QKeySequence::Cut
                                );

            menuFile->addSeparator();

            menuFile->addAction(QIcon(tr(":/icons/icon38.png")).pixmap(sizeIconMenuBar),
                                tr("Beenden"),
                                this,
                                &ViewMainWindow::close,
                                QKeySequence::Close
                                );
        }

        this->setMenuBar(menuBar);
    }

    //Setup dockWidgets
    {
        QSize sizeIconDockedWidgets(50, 50);

        //Setup dockWidget Grundmodul
        {
            QDockWidget *dockWidget = new QDockWidget(tr("Grundmodul"));

            {
                QGridLayout *gridLayout = new QGridLayout();

                //Hinfuehrung
                {
                    QPushButton *pushButton = new QPushButton(this);

                    pushButton->setIcon(QIcon(tr(":/icons/image16.png")));
                    pushButton->setIconSize(sizeIconDockedWidgets);
                    pushButton->setToolTip(tr("Hinführung"));

                    gridLayout->addWidget(pushButton, 0, 0);
                }

                //Link
                {
                    QPushButton *pushButton = new QPushButton(this);

                    pushButton->setIcon(QIcon(tr(":/icons/image2.png")));
                    pushButton->setIconSize(sizeIconDockedWidgets);
                    pushButton->setToolTip(tr("Link"));

                    gridLayout->addWidget(pushButton, 0, 1);
                }

                //Erarbeitung
                {
                    QPushButton *pushButton = new QPushButton(this);

                    pushButton->setIcon(QIcon(tr(":/icons/image19.png")));
                    pushButton->setIconSize(sizeIconDockedWidgets);
                    pushButton->setToolTip(tr("Erarbeitung"));

                    gridLayout->addWidget(pushButton, 1, 0);
                }

                //Hausaufgabe
                {
                    QPushButton *pushButton = new QPushButton(this);

                    pushButton->setIcon(QIcon(tr(":/icons/image10.png")));
                    pushButton->setIconSize(sizeIconDockedWidgets);
                    pushButton->setToolTip(tr("Hausaufgabe"));

                    gridLayout->addWidget(pushButton, 1, 1);
                }

                //UEbung
                {
                    QPushButton *pushButton = new QPushButton(this);

                    pushButton->setIcon(QIcon(tr(":/icons/image9.png")));
                    pushButton->setIconSize(sizeIconDockedWidgets);
                    pushButton->setToolTip(tr("Übung"));

                    gridLayout->addWidget(pushButton, 2, 0);
                }

                //Erkenntnis ueber UEbung
                {
                    QPushButton *pushButton = new QPushButton(this);

                    pushButton->setIcon(QIcon(tr(":/icons/image14.png")));
                    pushButton->setIconSize(sizeIconDockedWidgets);
                    pushButton->setToolTip(tr("Erkenntnis über Übung"));

                    gridLayout->addWidget(pushButton, 2, 1);
                }

                QWidget *widget = new QWidget(this);

                widget->setLayout(gridLayout);

                dockWidget->setWidget(widget);
            }

            this->addDockWidget(Qt::LeftDockWidgetArea, dockWidget);
        }

        //Setup dockWidget method 1
        {
            QDockWidget *dockWidget = new QDockWidget(tr("Methoden 1"));

            {
                QGridLayout *gridLayout = new QGridLayout();

                //Frage / Impuls
                {
                    QPushButton *pushButton = new QPushButton(this);

                    pushButton->setIcon(QIcon(tr(":/icons/image17.png")));
                    pushButton->setIconSize(sizeIconDockedWidgets);
                    pushButton->setToolTip(tr("Fragen / Impulse"));

                    gridLayout->addWidget(pushButton, 0, 0);
                }

                //Kaertchenabfragen
                {
                    QPushButton *pushButton = new QPushButton(this);

                    pushButton->setIcon(QIcon(tr(":/icons/image11.png")));
                    pushButton->setIconSize(sizeIconDockedWidgets);
                    pushButton->setToolTip(tr("Kärtchenabfragen"));

                    gridLayout->addWidget(pushButton, 0, 1);
                }

                //Partnerarbeit
                {
                    QPushButton *pushButton = new QPushButton(this);

                    pushButton->setIcon(QIcon(tr(":/icons/image15.png")));
                    pushButton->setIconSize(sizeIconDockedWidgets);
                    pushButton->setToolTip(tr("Partnerarbeit"));

                    gridLayout->addWidget(pushButton, 1, 0);
                }

                //Lernzirkel / Kugellager / Stationenlernen
                {
                    QPushButton *pushButton = new QPushButton(this);

                    pushButton->setIcon(QIcon(tr(":/icons/image20.png")));
                    pushButton->setIconSize(sizeIconDockedWidgets);
                    pushButton->setToolTip(tr("Lernzirkel / Kugellager / Stationenlernen"));

                    gridLayout->addWidget(pushButton, 1, 1);
                }

                //Gruppenarbeit
                {
                    QPushButton *pushButton = new QPushButton(this);

                    pushButton->setIcon(QIcon(tr(":/icons/image7.png")));
                    pushButton->setIconSize(sizeIconDockedWidgets);
                    pushButton->setToolTip(tr("Gruppenarbeit"));

                    gridLayout->addWidget(pushButton, 2, 0);
                }

                //Informationstext
                {
                    QPushButton *pushButton = new QPushButton(this);

                    pushButton->setIcon(QIcon(tr(":/icons/image8.png")));
                    pushButton->setIconSize(sizeIconDockedWidgets);
                    pushButton->setToolTip(tr("Informationstext"));

                    gridLayout->addWidget(pushButton, 2, 1);
                }

                //Einzelarbeit
                {
                    QPushButton *pushButton = new QPushButton(this);

                    pushButton->setIcon(QIcon(tr(":/icons/image13.png")));
                    pushButton->setIconSize(sizeIconDockedWidgets);
                    pushButton->setToolTip(tr("Einzelarbeit"));

                    gridLayout->addWidget(pushButton, 3, 0);
                }

                //Praesentation
                {
                    QPushButton *pushButton = new QPushButton(this);

                    pushButton->setIcon(QIcon(tr(":/icons/image18.png")));
                    pushButton->setIconSize(sizeIconDockedWidgets);
                    pushButton->setToolTip(tr("Präsentation"));

                    gridLayout->addWidget(pushButton, 3, 1);
                }

                QWidget *widget = new QWidget(this);

                widget->setLayout(gridLayout);

                dockWidget->setWidget(widget);
            }

            this->addDockWidget(Qt::LeftDockWidgetArea, dockWidget);
        }

        //Setup dockWidget method 2
        {
            QDockWidget *dockWidget = new QDockWidget(tr("Methoden 2"));

            {
                QGridLayout *gridLayout = new QGridLayout();

                //Tafelanschrieb
                {
                    QPushButton *pushButton = new QPushButton(this);

                    pushButton->setIcon(QIcon(tr(":/icons/image5.png")));
                    pushButton->setIconSize(sizeIconDockedWidgets);
                    pushButton->setToolTip(tr("Tafelanschrieb"));

                    gridLayout->addWidget(pushButton, 0, 0);
                }

                //UEberprüfung der Schuelertaetigkeit
                {
                    QPushButton *pushButton = new QPushButton(this);

                    pushButton->setIcon(QIcon(tr(":/icons/image1.png")));
                    pushButton->setIconSize(sizeIconDockedWidgets);
                    pushButton->setToolTip(tr("Überprüfung der Schülertätigkeit"));

                    gridLayout->addWidget(pushButton, 0, 1);
                }

                //einzelne Fragen klaeren (mit einem Schueler)
                {
                    QPushButton *pushButton = new QPushButton(this);

                    pushButton->setIcon(QIcon(tr(":/icons/image3.png")));
                    pushButton->setIconSize(sizeIconDockedWidgets);
                    pushButton->setToolTip(tr("einzelne Fragen klären (mit einem Schüler)"));

                    gridLayout->addWidget(pushButton, 1, 0);
                }

                //Erklaerung / Vortrag des Lehrers
                {
                    QPushButton *pushButton = new QPushButton(this);

                    pushButton->setIcon(QIcon(tr(":/icons/image4.png")));
                    pushButton->setIconSize(sizeIconDockedWidgets);
                    pushButton->setToolTip(tr("Erklärung / Vortrag des Lehrers"));

                    gridLayout->addWidget(pushButton, 1, 1);
                }

                //einzelne Fragen klaeren (mit mehreren Schülern)
                {
                    QPushButton *pushButton = new QPushButton(this);

                    pushButton->setIcon(QIcon(tr(":/icons/image12.png")));
                    pushButton->setIconSize(sizeIconDockedWidgets);
                    pushButton->setToolTip(tr("einzelne Fragen klären (mit mehreren Schülern)"));

                    gridLayout->addWidget(pushButton, 2, 0);
                }

                //Eroerterungs- / Klaerungsdiskussion
                {
                    QPushButton *pushButton = new QPushButton(this);

                    pushButton->setIcon(QIcon(tr(":/icons/image6.png")));
                    pushButton->setIconSize(sizeIconDockedWidgets);
                    pushButton->setToolTip(tr("Erörterungs- / Klärungsdiskussion"));

                    gridLayout->addWidget(pushButton, 2, 1);
                }

                QWidget *widget = new QWidget(this);

                widget->setLayout(gridLayout);

                dockWidget->setWidget(widget);
            }

            this->addDockWidget(Qt::LeftDockWidgetArea, dockWidget);
        }
    }

    //Setup centralWidget
    {
        QTabWidget *tabWidget = new QTabWidget(this);

        QSize sizeIconTabWidget(16, 16);

        //First tab: Energiefluss
        {
            QLabel *label = new QLabel(this);

            label->setPixmap(QPixmap(tr(":/icons/image21.png")));

            tabWidget->addTab(label, QIcon(tr(":/icons/icon31.png")).pixmap(sizeIconTabWidget), tr("Energiefluss"));
        }

        //Second tab: Ablaufplan
        {
            QLabel *label = new QLabel(this);

            label->setPixmap(QPixmap(tr(":/icons/image26.png")));

            tabWidget->addTab(label, QIcon(tr(":/icons/icon37.png")).pixmap(sizeIconTabWidget), tr("Ablaufplan"));
        }

        this->setCentralWidget(tabWidget);
    }

    this->setWindowTitle(tr("Energy Flow"));
}

void ViewMainWindow::actionSet(void)
{
    DialogParameter dialogParameter(this);

    dialogParameter.exec();
    //TODO Activate Buttons
}

void ViewMainWindow::actionOpen(void)
{
    QString fileName = QFileDialog::getOpenFileName(this,
                                                    tr("Aufzeichnungen speichern"),
                                                    "",
                                                    tr("XML-Dateien (*.xml);;Alle Dateien (*)"));
}

void ViewMainWindow::actionSave(void)
{
    QString fileName = QFileDialog::getSaveFileName(this,
                                                    tr("Aufzeichnungen speichern"),
                                                    "",
                                                    tr("XML-Dateien (*.xml);;Alle Dateien (*)"));
}

void ViewMainWindow::actionPrint(void)
{
    QPrinter *qPrinter = new QPrinter(QPrinter::PrinterResolution);
    QPrintDialog printDialog(qPrinter, this);

    if (printDialog.exec() == QDialog::Accepted) {
        //TODO Add exportModel
    }

    delete qPrinter;
}

void ViewMainWindow::actionExport(void)
{
    QString fileName = QFileDialog::getSaveFileName(this,
                                                    tr("Aufzeichnungen exportieren"),
                                                    "",
                                                    tr("PDF-Dateien (*.pdf);;Alle Dateien (*)"));
}

