#include "Face2dCreator.h"
#include "ui_Face2dCreator.h"
#include "CCEGLView.h"

using namespace cocos2d;

Face2dCreator::Face2dCreator(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Face2dCreator)
{
    ui->setupUi(this);
}

Face2dCreator::~Face2dCreator()
{
    delete ui;
}

void Face2dCreator::closeEvent(QCloseEvent *v)
{
    QWidget::closeEvent(v);
    CCEGLView::sharedOpenGLView()->getWindow()->close();
}
