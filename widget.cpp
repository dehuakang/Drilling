﻿#include "widget.h"
#include "renderer.h"

Widget::Widget(QWidget *parent)
    : QMainWindow(parent)
{
    this->setWindowTitle("Drilling");
    this->resize(600,400);

    //菜单项实例化
    drillingView = new QMenu(this);//this指当前窗口
    lithologyView = new QMenu(this);
    drillingCode = new QMenu(this);
    drillingTest = new QMenu(this);
    drillingEdit = new QMenu(this);

    drillingView = menuBar()->addMenu("钻孔显示");
    lithologyView = menuBar()->addMenu("分层显示");
    drillingCode = menuBar()->addMenu("钻孔编码");
    drillingTest = menuBar()->addMenu("钻孔检测");
    drillingEdit = menuBar()->addMenu("编辑钻孔");

    viewDrilling = new QAction("显示钻孔",this);
    viewDrilling->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_V));
    viewDrilling->setStatusTip("Drilling view");

    hideDrilling = new QAction("隐藏钻孔",this);
    hideDrilling->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_H));
    hideDrilling->setStatusTip("Drilling hide");

    lithologyDrilling = new QAction("钻孔分层显示",this);
    lithologyDrilling->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_L));
    lithologyDrilling->setStatusTip("Drilling lithoLogy view");

    viewCode = new QAction("显示编码",this);
    viewCode->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_C));
    viewCode->setStatusTip("Drilling code view");

    hideCode = new QAction("隐藏编码",this);
    hideCode->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_U));
    hideCode->setStatusTip("Drilling code hide");

    testDrilling = new QAction("钻孔检测",this);
    testDrilling->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_T));
    testDrilling->setStatusTip("Drilling Test");

    addDrilling = new QAction("添加钻孔",this);
    addDrilling->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_A));
    addDrilling->setStatusTip("Drilling add");

    removeDrilling = new QAction("删除钻孔",this);
    removeDrilling->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_D));
    removeDrilling->setStatusTip("Drilling remove");

    drillingView->addAction(viewDrilling);
    drillingView->addAction(hideDrilling);

    lithologyView->addAction(lithologyDrilling);

    drillingCode->addAction(viewCode);
    drillingCode->addAction(hideCode);
    \
    drillingTest->addAction(testDrilling);

    drillingEdit->addAction(addDrilling);
    drillingEdit->addAction(removeDrilling);

    menuBar()->hide();

    enterSys = new QPushButton(this);
    enterSys->setText("进入系统");
    enterSys->setGeometry(200,150,200,100);
    connect(enterSys,SIGNAL(clicked()),this,SLOT(enterSystem()));
}

Widget::~Widget()
{

}

void Widget::enterSystem()
{
    menuBar()->show();
    Renderer renderer;
    QVTKWidget *a;
    a = new QVTKWidget(this);
    a->GetRenderWindow()->AddRenderer(renderer.renderer);
    delete enterSys;
    setCentralWidget(a);
}
