#include "Face2dCreator.h"
#include "ui_Face2dCreator.h"
#include "CCEGLView.h"
#include "Face2dCreator_FileListItem.h"

using namespace cocos2d;

Face2dCreator::Face2dCreator(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Face2dCreator)
{
    ui->setupUi(this);
    for(int i = 0 ; i < 4 ; ++i)
    {
        QListWidgetItem* item = new QListWidgetItem();
        ui->listWidget->addItem(item);

        Face2dCreator_FileListItem* widget = new Face2dCreator_FileListItem(ui->listWidget);
        widget->setBackgroundRole(QPalette::Button);
        widget->show();
        ui->listWidget->setItemWidget(item,widget);
        item->setSizeHint(QSize(widget->geometry().size()));
    }
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
