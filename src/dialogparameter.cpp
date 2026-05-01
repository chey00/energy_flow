#include "dialogparameter.hpp"

#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QDialogButtonBox>
#include <QGridLayout>
#include <QLabel>
#include <QIcon>
#include <QToolButton>
#include <QComboBox>
#include <QLineEdit>
#include <QCalendarWidget>
#include <QTimeEdit>
#include <QTime>
#include <QSlider>
#include <QString>
#include <QTextEdit>

DialogParameter::DialogParameter(QWidget *parent) : QDialog(parent)
{
    this->setWindowTitle(tr("Metadaten"));

    QVBoxLayout *vBoxLayout = new QVBoxLayout(this);

    //Add QHBoxLayouts to QVBoxLayout
    {
        //1. Line
        {
            QHBoxLayout *hBoxLayout = new QHBoxLayout();

            QComboBox *comboBox = new QComboBox(this);

            comboBox->addItem(tr("Herr"));
            comboBox->addItem(tr("Frau"));
            comboBox->addItem(tr("Divers"));

            QLineEdit *lineEdit = new QLineEdit(this);

            hBoxLayout->addWidget(new QLabel(tr("Lehrkraft "), this));
            hBoxLayout->addWidget(comboBox);
            hBoxLayout->addWidget(lineEdit);

            vBoxLayout->addItem(hBoxLayout);
        }

        //2. Line
        {
            QCalendarWidget *calendarWidget = new QCalendarWidget();

            vBoxLayout->addWidget(calendarWidget);
        }

        //3. Line
        {
            QHBoxLayout *hBoxLayout = new QHBoxLayout();

            hBoxLayout->addWidget(new QLabel(tr("Uhrzeit "), this), 0, Qt::AlignRight);

            QTimeEdit *timeEditTime = new QTimeEdit(QTime::currentTime(), this);

            hBoxLayout->addWidget(timeEditTime);

            hBoxLayout->addWidget(new QLabel(tr("Dauer "), this), 0, Qt::AlignRight);

            QTimeEdit *timeEditDuration = new QTimeEdit(QTime(0, 45), this);

            hBoxLayout->addWidget(timeEditDuration);

            vBoxLayout->addItem(hBoxLayout);
        }

        //4. Line
        {
            QGridLayout *gridLayout = new QGridLayout();

            QLineEdit *lineEditSubject = new QLineEdit(this);
            QLineEdit *lineEditClass = new QLineEdit(this);

            QTextEdit *textEditComment = new QTextEdit(this);

            gridLayout->addWidget(new QLabel(tr("Fach"), this), 0, 0, Qt::AlignRight);
            gridLayout->addWidget(new QLabel(tr("Klasse"), this), 1, 0, Qt::AlignRight);
            gridLayout->addWidget(new QLabel(tr("Kommentar"),this), 2, 0, Qt::AlignRight | Qt::AlignTop);

            gridLayout->addWidget(lineEditSubject, 0, 1);
            gridLayout->addWidget(lineEditClass, 1, 1);
            gridLayout->addWidget(textEditComment, 2, 1);

            vBoxLayout->addItem(gridLayout);
        }

        //Last Line
        {
            QDialogButtonBox *buttonBox = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel);

            connect(buttonBox, &QDialogButtonBox::accepted, this, &QDialog::accept);
            connect(buttonBox, &QDialogButtonBox::rejected, this, &QDialog::reject);

            vBoxLayout->addWidget(buttonBox);
        }
    }

    this->setLayout(vBoxLayout);
}
