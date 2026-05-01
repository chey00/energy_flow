#ifndef VIEWMAIN_HPP
#define VIEWMAIN_HPP

#include <QMainWindow>

class ViewMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    ViewMainWindow(QWidget *parent = nullptr);

private slots:
    void actionSet(void);
    void actionOpen(void);
    void actionSave(void);
    void actionPrint(void);
    void actionExport(void);
};
#endif // VIEWMAIN_HPP
