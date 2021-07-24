#ifndef QTC_MAINWINDOW_H
#define QTC_MAINWINDOW_H

#include <QMainWindow>

class QTC_MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    QTC_MainWindow(QWidget *parent = nullptr);
    ~QTC_MainWindow();
};
#endif // QTC_MAINWINDOW_H
