#ifndef MODELMAINWINDOW_HPP
#define MODELMAINWINDOW_HPP

#include <QObject>

class ModelMainWindow : public QObject
{
    Q_OBJECT
public:
    explicit ModelMainWindow(QObject *parent = nullptr);

    void saveToXML(const QString fileName);
    void loadFromXML(const QString fileName);

signals:


};

#endif // MODELMAINWINDOW_HPP
