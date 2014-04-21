#ifndef FACE2DCREATOR_H
#define FACE2DCREATOR_H

#include <QWidget>

namespace Ui {
class Face2dCreator;
}

class Face2dCreator : public QWidget
{
    Q_OBJECT

public:
    explicit Face2dCreator(QWidget *parent = 0);
    ~Face2dCreator();
    void closeEvent(QCloseEvent *);
private:
    Ui::Face2dCreator *ui;
};

#endif // FACE2DCREATOR_H
