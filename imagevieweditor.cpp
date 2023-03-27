#include "imagevieweditor.h"
#include <QMouseEvent>

ImageViewEditor::ImageViewEditor(QWidget *parent) :
    QGraphicsView(parent)
{
    imageItem = new QGraphicsPixmapItem();

    QGraphicsScene* scene = new QGraphicsScene();
    scene->addItem(imageItem);

    this->setScene(scene);
}

void ImageViewEditor::updatePixmap(QImage* image) {
    imageItem->setPixmap(QPixmap::fromImage(*image));
}

void ImageViewEditor::mousePressEvent(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton) {
        QPoint pos = mapToScene(event->pos()).toPoint();
        emit mouseDown(pos);
        //qDebug() << "moussPress";
    }
}

void ImageViewEditor::mouseMoveEvent(QMouseEvent *event) {
//    if(pencil == true){
//        QPoint pos = mapToScene(event->pos()).toPoint();
//        emit mouseDown(pos);
//        //qDebug() << pencil;
//    }

    //Andy Tran Edited
    QPoint pos = mapToScene(event->pos()).toPoint();
    emit mouseDown(pos);
    //qDebug() << pencil;


}

void ImageViewEditor::pencilClicked(){
    //Andy Tran Edited
//    pencil = true;
//    eraser = false;
    emit changeTool(PENCIL);
};

void ImageViewEditor::eraserClicked(){
    //Andy Tran Edited
//    pencil = false;
//    eraser = true;
    emit changeTool(ERASER);
    qDebug() << "eraser called";
};

void ImageViewEditor::mouseReleaseEvent(QMouseEvent *) {

}

void ImageViewEditor::wheelEvent(QWheelEvent *event)
{
    // Get the current zoom level

    // Zoom in or out based on the wheel delta
    if (event->angleDelta().y() > 0) {
        scale *= 1.2;
    } else {
        scale /= 1.2;
    }

    // Set the new zoom level
    setTransform(QTransform().scale(scale, scale));
}
