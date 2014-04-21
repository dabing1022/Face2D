#ifndef FACE2DCREATOR_FILELISTITEM_H
#define FACE2DCREATOR_FILELISTITEM_H

#include <QWidget>

namespace Ui {
class Face2dCreator_FileListItem;
}

class Face2dCreator_FileListItem : public QWidget
{
    Q_OBJECT

public:
    explicit Face2dCreator_FileListItem(QWidget *parent = 0);
    ~Face2dCreator_FileListItem();

private:
    Ui::Face2dCreator_FileListItem *ui;
};

#endif // FACE2DCREATOR_FILELISTITEM_H
