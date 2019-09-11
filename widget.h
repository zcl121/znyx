#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QString>
#include <QPushButton>
#include <QLabel>
#include <QSlider>
#include <QPixmap>
#include <QPalette>
#include <QIcon>
#include <QSize>
#include <QTextEdit>
#include <QFont>
#include <QDebug>
#include <QString>
#include <QVector>

#include <QTimer>
#include <QTextCharFormat>
#include <QColor>
#include <QLineEdit>

#include <stdio.h>
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <pthread.h>
#include <errno.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>
#include <string.h>

class Widget : public QWidget
{
    Q_OBJECT
    
public:
    Widget(QWidget *parent = 0);
    void main();
    void qg();
    void readLrc();
    void readMp3();

   // int msg_deal(char *msg_src,char *msg_done[],char *str);
  //  void mousePressEvent(QMouseEvent *ev);

    ~Widget();
public slots:
    void on_pushButtonConnect_clicked();
    void on_pushButtonConnect_clicked1();
    void on_pushButtonConnect_clicked2();
    void kuaijin();
    void houtui();
    void update();

    void setValue(int value);
    void onCurrentLineHighLight();

};
class lrc{
public:
    lrc()
    {
    }
    lrc(int m_time,QString lrc_buf)
    {
        this->m_time = m_time;
        this->lrc_buf = lrc_buf;
    }

    int m_time;
    QString lrc_buf;

};



//typedef  struct lrc{
//    int m_time;
//    char lrc_buf[800];
//    struct lrc *front;
//    struct lrc *next;
//}LRC;
//void link_print(LRC *head);
//LRC *link_find(LRC *head,int m_time);
//LRC *link_insert(LRC *head,LRC *pnew);
#endif // WIDGET_H
