#include <QApplication>
#include "widget.h"
#include <QTextCodec>
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








int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTextCodec *codec = QTextCodec::codecForName("UTF-8");       //UTF-8
    QTextCodec::setCodecForTr(codec);
    QTextCodec::setCodecForLocale(codec);
    QTextCodec::setCodecForCStrings(codec);

    Widget w;

    w.show();





    return a.exec();
}
