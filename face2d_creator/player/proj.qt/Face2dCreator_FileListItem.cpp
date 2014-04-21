#include "Face2dCreator_FileListItem.h"
#include "ui_Face2dCreator_FileListItem.h"

Face2dCreator_FileListItem::Face2dCreator_FileListItem(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Face2dCreator_FileListItem)
{
    ui->setupUi(this);
}

Face2dCreator_FileListItem::~Face2dCreator_FileListItem()
{
    delete ui;
}
