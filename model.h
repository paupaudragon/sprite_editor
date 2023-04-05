#ifndef MODEL_H
#define MODEL_H

#include "qimage.h"
#include <QObject>

//Duong
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QFile>

//AndyTran
#include <QPixmap>
#include <QGraphicsPixmapItem>

//tzhou
#include<QGraphicsView>
#include<QMap>

//Ruini Tong
#include <QCursor>

using std::vector;

//Enum Global Declaration
enum Tool {
    PENCIL,
    PICKER,
    ERASER,
    BUCKET
};
enum Action{
    UPDATE,
    DELETE_FRAME,
    OPEN_FILE,
    CREATE_NEW,
    RESIZE
};

class Model : public QObject
{
    Q_OBJECT

public:
    explicit Model(QObject *parent = nullptr);

    //Main canvas
    QImage canvas;
    QImage mergeCanvas;

    //Shared variable
    static int frameIndex;

public slots:
    void mouseDown(QPoint);
    void mouseMove(QPoint);
    void mouseRelease(QPoint);

    //Andy Tran
    void changeTool(Tool currentTool);
    void mouseClicked(QGraphicsPixmapItem*, int);
    void initializeModel();
    void onAddFrame();
    void deletePressed(int);
    void resizeFrameList(int);

    //Tzhou: this should be combined with setToolColor, but need Renee's consent.
    /**
     * @brief Sets the paint color to a given color.
     *        This new color comes from a sinal in View.
     *        It emits a signal to view to update color picker panel.
     * @param newColor The new color to set to.
     */
    void paintColorChanged(const QColor newColor);//Tzhou, Ruini Tong
    void updateAlpha(int newAlphaSliderValue);
    void updateCustomColor(QGraphicsView* view);
    void customColorIsSelected(QGraphicsView* view);

    //Duong
    void createNewCanvas(int);
    bool saveFile(const QString &filename);
    bool openFile(const QString &filename);


    //Ruini Tong
    void setPenSize(int size);
    void fillColor(QColor currentColor, QPoint pos);

private:
    Tool tool = PENCIL;
    QColor paintColor; //It is initialized in the constructor, uniform convention with the UI.

    // Jeff
    void drawLine(QPoint, QPoint, QImage*, QPainter::CompositionMode);

    //Ruini Tong
    QPoint pixelCurrent;
    int penSize = 1;
    QRect canvasRect;

    //Andy Tran
    vector<QImage> frameList;
    int currentFrame = 0;
    int canvasSize;

    //tzhou
    QMap <QGraphicsView*, QColor> customColors;

    //Duong
    int canvasWidth;
    int canvasHeight;

signals:
    /**
     * @brief Sends canvas to View
     *
     * Sends the canvas to the View, usually after an update has occured to
     * the canvas. The View should update so the user can see the changes
     * the Model has made.
     *
     * @param QImage        the canvas
     */
    void updateCanvas(QImage* canvas, vector<QImage>* list, int currentFrame, Action action, int newSize, int deletedIndex = -1);
    void updatePreviewCanvas(QImage* canvas);

    //Renee, Tzhou
    void updatePaintColor(QColor newColor);

    //Tzhou
    void updateAlphaSliderLabel(QString alphaSliderReading);
    void resetAlphaSlider(int max);

    //Ruini Tong
    void newPosition(QPoint pos);

    //Andy Tran
    void deleteFrameWidget(int);

    //Duong
    void centerAndAutoZoom(int, int);
};

#endif // MODEL_H
