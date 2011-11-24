#ifndef MENU_H
#define MENU_H


#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QProgressBar>
#include <QSlider>
#include <QInputDialog>
#include <QGroupBox>
#include <QtGui>
#include <QMenuBar>
#include <QLineEdit>
#include <QColor>
#include <QGridLayout>


class Menu : public QMainWindow {
    Q_OBJECT

        protected:
        QPushButton *serie;
        QPushButton *tablem;
        QPushButton *grad;
        QPushButton *dedu;
        QPushButton *equation;
        QPushButton *devFac;



        public slots:
        void aserie();
        void atable();
        void adedu();
        void agrad();


        signals:


        public :
            Menu();

};

#endif // MENU_H
