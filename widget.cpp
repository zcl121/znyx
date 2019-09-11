#include "widget.h"

#include <QFile>


QLabel *labe_time;
QSlider *slider;
static int num=0;
int flag=0;
QTextEdit *te;
QTimer *timer;
QPushButton *bt_pause;
QPushButton *bt_next;
QPushButton *bt_last;
QPushButton *bt_kuaijin;
QPushButton *bt_houtui;

QLabel *labe_time2;
QLabel *labe_11;
QLabel *labe_22;
QLabel *labe_33;
QString gc[10];   //读歌词目录数据
QString gc2[20];  //切割后的目录
int g,t;            //目录总数，打印目录for循环的

QString gq[10]; //读歌曲目录数据
QString gq2[20]; //切割后的目录
int g1,t1;          //目录总数，打印目录for循环的

QString cgc[10];
QString cgq[10];


QVector<lrc>::Iterator it;
QVector<lrc> v;
int j,i,k=0,t_end;
int a=0;

int fd_w;
int pause_gq=0;

int m;

int dd;
Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    main();



    if(mkfifo("myfifo",0664)==-1)
    {
        if(errno != EEXIST)
        {
            perror("fail to mkdifo");
            exit(1);
        }
    }

    pid_t pid;
    pid=fork();
    if(pid>0)
    {
        //让起始的歌曲播放暂停
        if(pause_gq == 0)
        {
            fd_w= open("myfifo",O_WRONLY);
            write(fd_w,"pause\n",6);
            pause_gq = 1;
        }
    }
    else if(pid==0)
    {
        execlp("mplayer",
               " mplayer ",
               "-slave", "-quiet","-idle",
               "-input", "file=./myfifo",
               gq2[m].toAscii().data(), NULL);

    }


}

void Widget::main()
{
    this->move(0,0);
    this->setFixedSize(800,500);

    QPixmap pix1;
    QPalette pal = this->palette();
    pix1.load("./6.jpg");
    pix1 = pix1.scaled(800, 600, Qt::KeepAspectRatio);
    pal.setBrush(QPalette::Background, QBrush(pix1));
    setPalette(pal);

        bt_last=new QPushButton(this);
        bt_last->move(250,390);

        bt_pause=new QPushButton(this);
        bt_pause->move(450,390);
        QPixmap pix3;
        pix3.load("./image/button_style/play1.png");
        bt_pause->setIcon(QIcon(pix3));
        bt_pause->setIconSize(QSize(70,30));

        bt_kuaijin=new QPushButton(this);
        bt_kuaijin->move(150,390);
        bt_kuaijin->setFixedSize(70,30);
        QPixmap pix6;
        pix6.load("./image/style/forward.png");
        bt_kuaijin->setIcon(QIcon(pix6));

        bt_houtui =new QPushButton(this);
        bt_houtui->move(50,390);
        bt_houtui->setFixedSize(70,30);
        QPixmap pix5;
        pix5.load("./image/style/backward.png");
        bt_houtui->setIcon(QIcon(pix5));



        bt_next=new QPushButton(this);
        bt_next->move(650,390);


        QLabel *labe_1=new QLabel("歌曲:",this);
        labe_1->move(250,40);
        labe_1->setFixedSize(400,30);


                labe_11=new QLabel(this);
        labe_11->move(310,40);
        labe_11->setFixedSize(400,30);


        QLabel *labe_2=new QLabel("歌手:",this);
        labe_2->move(250,80);
        labe_2->setFixedSize(400,30);


        labe_22=new QLabel(this);
        labe_22->move(310,80);
        labe_22->setFixedSize(400,30);

        QLabel *labe_3=new QLabel("专辑:",this);
        labe_3->move(460,80);
        labe_3->setFixedSize(400,30);


        labe_33=new QLabel(this);
        labe_33->move(520,80);
        labe_33->setFixedSize(400,30);

        labe_time=new QLabel;
        labe_time->setParent(this);
        labe_time->move(200,350);
        labe_time->setFixedSize(60,30);


        labe_time2=new QLabel(this);
        labe_time2->move(755,350);
        labe_time2->setFixedSize(60,30);






        te=new QTextEdit;
        te->setParent(this);
        te->move(250,140);
        te->setFixedSize(500,200);



        QLabel *labe5_p=new QLabel("this is a label_p",this);
        labe5_p->move(50,80);
        labe5_p->setFixedSize(150,200);




        slider=new QSlider;
        slider->setParent(this);
        slider->setOrientation(Qt::Horizontal);
        slider->setFixedSize(500,30);
        slider->move(250,350);

        //give label setbackground
        QPixmap pix;
        pix.load("./image/background/7.jpg");
        labe5_p->setScaledContents(true);
        labe5_p->setPixmap(pix);

           QPixmap pix2;
           pix2.load("./image/button_style/back1.png");
           bt_last->setIcon(QIcon(pix2));
           bt_last->setIconSize(QSize(70,30));



           QPixmap pix4;
           pix4.load("./image/button_style/front1.png");
           bt_next->setIcon(QIcon(pix4));
           bt_next->setIconSize(QSize(70,30));



        //give label_font_setcolor
        QPalette pe;
        pe.setColor(QPalette::WindowText,Qt::white);

        QFont font("SimSun",9,75);
        labe_time->setFont(font);
        labe_time2->setFont(font);

        QFont font1("SimHei",12,75);

        labe_1->setFont(font1);
        labe_2->setFont(font1);
        labe_3->setFont(font1);
        labe_11->setFont(font1);
        labe_22->setFont(font1);
        labe_33->setFont(font1);
         te->setFont(font1);


        labe_1->setPalette(pe);
        labe_2->setPalette(pe);
        labe_3->setPalette(pe);
        labe_11->setPalette(pe);
        labe_22->setPalette(pe);
        labe_33->setPalette(pe);
        labe5_p->setPalette(pe);
       labe_time->setPalette(pe);
        labe_time2->setPalette(pe);
        te->setPalette(pe);

        readLrc();
        readMp3();
        qg();
        //设置5个按钮的点击事件
        connect(bt_pause,SIGNAL(clicked(bool)),this,SLOT(on_pushButtonConnect_clicked()));
        connect(bt_next,SIGNAL(clicked(bool)),this,SLOT(on_pushButtonConnect_clicked2()));
        connect(bt_last,SIGNAL(clicked(bool)),this,SLOT(on_pushButtonConnect_clicked1()));

        connect(bt_kuaijin,SIGNAL(clicked(bool)),this,SLOT(kuaijin()));
        connect(bt_houtui,SIGNAL(clicked(bool)),this,SLOT(houtui()));


                //设置timer将时间和歌词显示在行编辑里
                timer = new QTimer(this);
                connect(timer, SIGNAL(timeout()), this, SLOT(update()));
                //设置进度条和时间的关系
                connect(slider, SIGNAL(valueChanged(int)),this,SLOT(setValue(int)));
                //改变行编辑里光标的属性
                connect(te,SIGNAL(cursorPositionChanged()),this,SLOT(onCurrentLineHighLight()));

}

//使用容器保存并切割歌词
void Widget::qg()
{
    //打开歌词文件
    QFile file(gc2[k]);
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream in(&file);


    int min,sec;
    QString str,src[3];
    for(int b =0 ; b < 3 ; b ++)
    {
        str = in.readLine();
        src[b] = str.mid(4,(str.length()-5));
    }
    labe_11->setText(src[0]);
    labe_22->setText(src[1]);
    labe_33->setText(src[2]);
    while(!in.atEnd())
    {
        str = in.readLine();
        while(str.mid(0,1) == "[")
        {
            min = str.mid(1,2).toInt();
            sec = str.mid(4,2).toInt();
            t_end = min*60 + sec;
            str = str.mid(10);
        }
        v.push_back(lrc(t_end,str));
    }
    file.close();
    QString minutes,seconds,time_text;
    minutes = minutes.setNum(((v.end() - 1)->m_time +5)/60);
    seconds = seconds.setNum(((v.end() - 1)->m_time +5)%60);
    time_text = minutes + ":" +seconds;


    labe_time2->setText(time_text);


    slider->setMinimum(0);
    slider->setMaximum(t_end);

    te->setAlignment(Qt::AlignCenter);
    for(it = v.begin();it < v.end();it++)
    {
        te->textCursor().insertText(it->lrc_buf +"\n");
    }
    te->moveCursor(QTextCursor::Start,QTextCursor::MoveAnchor);

    for(m=0;m < g;m++)
    {
        if(cgq[m]==cgc[k])
        {
            qDebug()<<"cgc[m]"<<cgc[k];
            qDebug()<<"cgq[k]"<<cgq[m];
            break;
        }
    }







}
//读取歌词目录
void Widget::readLrc()
{

    DIR *dirp;
   if((dirp = opendir("./lyrics")) == NULL)
   {
       perror("fail to opendir");
       exit(1);
   }

   struct dirent *mydir;
   while((mydir = readdir(dirp)) != NULL)
   {
       if(mydir->d_name[0] == '.')
       {
           continue;
       }
       QString str = "./lyrics/" ;
       QString str1=".mp3";
       gc[g]=mydir->d_name;

       cgc[g]=gc[g].mid(0,gc[g].length()-4);
       qDebug() << "cgc="<<cgc[g];
       str +=gc[g];
       gc2[g]=str;
       g++;
   }




}
 //读取歌曲目录
void Widget::readMp3()
{

   DIR *dirp1;
   if((dirp1 = opendir("./song")) == NULL)
   {
       perror("fail to opendir");
       exit(1);
   }

   struct dirent *mydir1;
   while((mydir1 = readdir(dirp1)) != NULL)
   {
       if(mydir1->d_name[0] == '.')
       {
           continue;
       }
       QString str = "./song/" ;
       QString str1=".mp3";
       gq[g1]=mydir1->d_name;

       cgq[g1]=gq[g1].mid(0,gq[g1].length()-4);
       qDebug() << "cgq="<<cgq[g1];

       str +=gq[g1];
       gq2[g1]=str;
       qDebug() << "1111111111111111111==="<<gq2[g1];
       g1++;
   }



}

//上一首
void Widget::on_pushButtonConnect_clicked1()
{

        v.clear();
        te->clear();
        num = 0;

        if(k == 0)
        {
          k = g - 1;
          qg();
        }
        else
        {
            k--;
            qg();
        }
        fd_w=open("./myfifo",O_WRONLY);
        write(fd_w,"loadfile ",9);
        QString str="\n";
        qDebug()<< "m="<<m;
        gq2[m]+=str;
        write(fd_w,gq2[m].toAscii().data(),strlen(gq2[m].toAscii().data()));

}
//暂停
void Widget::on_pushButtonConnect_clicked()
{


    qDebug()<<"pause";
       if(flag==0)
       {

           timer->start(1000);
           QPixmap pix3;
           pix3.load("./image/button_style/pause1.png");
           bt_pause->setIcon(QIcon(pix3));
           bt_pause->setIconSize(QSize(70,30));

           flag=1;
       }
       else
       {

           timer->stop();

           QPixmap pix3;
           pix3.load("./image/button_style/play1.png");
           bt_pause->setIcon(QIcon(pix3));
           bt_pause->setIconSize(QSize(70,30));

           flag=0;
       }
       fd_w=open("./myfifo",O_WRONLY);
       write(fd_w,"pause\n",6);


}


//下一首
void Widget::on_pushButtonConnect_clicked2()
{


       v.clear();
       te->clear();
       num = 0;
       if(k < (g - 1))
       {
           k++;
           qg();


       }
       else
       {
           k = 0;
           qg();

       }
       fd_w=open("./myfifo",O_WRONLY);
       write(fd_w,"loadfile ",9);
       QString str="\n";
       qDebug()<< "m="<<m;
       gq2[m]+=str;
       write(fd_w,gq2[m].toAscii().data(),strlen(gq2[m].toAscii().data()));

}
//前进9秒
void Widget::kuaijin()
{
    fd_w=open("./myfifo",O_WRONLY);
    write(fd_w,"seek ",5);
    write(fd_w,"9\n",2);
     num=num+9;



}
//后退9秒
void Widget::houtui()
{

    qDebug()<<"num============="<<num;

    fd_w=open("./myfifo",O_WRONLY);
    write(fd_w,"seek ",5);
    write(fd_w,"-9\n",3);
    num=num-9;
    if(num<0)
       num=0;




}
//timer的槽函数
void Widget::update()
{
    //时间累加

    int minutes,seconds;

    num++;
    char buf[128];
    minutes = num/60;
    seconds = num%60;
    sprintf(buf, "%02d:%02d", minutes,seconds);
    labe_time->setText(buf);

    slider->setValue(num);

    //判断时间来确定光标位置
    for(it = v.begin() + 1;it < v.end();it++)
    {
        if(it -> m_time == num)
        {

            te->find(it->lrc_buf,QTextDocument::FindWholeWords);
            QTextCursor cursor = te->textCursor();
            cursor.movePosition(QTextCursor::Down);
            te->setTextCursor(cursor);

         }
        if(num== (t_end+5))
        {
            on_pushButtonConnect_clicked2();
        }


    }


}

void Widget::setValue(int value)
{
    num = slider->value();



}

void Widget::onCurrentLineHighLight()
{

     QList<QTextEdit::ExtraSelection> extraSelection;
     QTextEdit::ExtraSelection selection;
     QColor lineColor = QColor(Qt::green).lighter(150);
     selection.format.setForeground(lineColor);
     selection.format.setProperty(QTextFormat::FullWidthSelection,true);
     selection.cursor = te->textCursor();
     selection.cursor.movePosition(QTextCursor::Up);

     extraSelection.append(selection);
     te->setExtraSelections(extraSelection);
}

Widget::~Widget()
{


}
