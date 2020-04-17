#include "../includes/manualscribble.h"

#define PI 3.14159265

#include <QMouseEvent>
#include <QPainter>
#include <qdebug.h>
#if defined(QT_PRINTSUPPORT_LIB)
#include <QtPrintSupport/qtprintsupportglobal.h>
#if QT_CONFIG(printdialog)
#include <QPrinter>
#include <QPrintDialog>
#endif
#endif

//! [0]
ManualScribble::ManualScribble(QWidget* parent)
    : QWidget(parent)
{
    setAttribute(Qt::WA_StaticContents);
}
//! [0]

//! [1]
bool ManualScribble::openImage(const QString& fileName)
//! [1] //! [2]
{
    QImage loadedImage;
    if (!loadedImage.load(fileName))
        return false;

    QSize newSize = loadedImage.size().expandedTo(size());
    resizeImage(&loadedImage, newSize);
    image = loadedImage;
    modified = false;
    update();
    return true;
}
//! [2]

//! [3]
bool ManualScribble::saveImage(const QString& fileName, const char* fileFormat)
//! [3] //! [4]
{
    QImage visibleImage = image;
    resizeImage(&visibleImage, size());

    if (visibleImage.save(fileName, fileFormat))
    {
        modified = false;
        return true;
    }
    return false;
}
//! [4]

//! [5]
void ManualScribble::setPenColor(const QColor& newColor)
//! [5] //! [6]
{
    myPenColor = newColor;
}
//! [6]

//! [7]
void ManualScribble::setPenWidth(int newWidth)
//! [7] //! [8]
{
    myPenWidth = newWidth;
}
//! [8]

//! [9]
void ManualScribble::clearImage()
//! [9] //! [10]
{
    image.fill(qRgb(255, 255, 255));
    modified = true;
    update();
}
//! [10]

//! [11]
void ManualScribble::mousePressEvent(QMouseEvent* event)
//! [11] //! [12]
{
    if (event->button() == Qt::LeftButton)
    {
        lastPoint = event->pos();
        scribbling = true;
    }
}

void ManualScribble::mouseMoveEvent(QMouseEvent* event)
{
    if ((event->buttons() & Qt::LeftButton) && scribbling)
    {
        drawLineTo(event->pos());
        QPoint coordinates = event->pos();
//      qDebug()<<event->pos();
        moveRefFrame(coordinates);
    }
}

void ManualScribble::mouseReleaseEvent(QMouseEvent* event)
{
    if (event->button() == Qt::LeftButton && scribbling)
    {
        drawLineTo(event->pos());
        scribbling = false;
    }
}

//! [12] //! [13]
void ManualScribble::paintEvent(QPaintEvent* event)
//! [13] //! [14]
{
    QPainter painter(this);
    QRect dirtyRect = event->rect();
    painter.drawImage(dirtyRect, image, dirtyRect);
}
//! [14]

//! [15]
void ManualScribble::resizeEvent(QResizeEvent* event)
//! [15] //! [16]
{
    if (width() > image.width() || height() > image.height())
    {
        int newWidth = qMax(width() + 128, image.width());
        int newHeight = qMax(height() + 128, image.height());
        resizeImage(&image, QSize(newWidth, newHeight));
        update();
    }
    QWidget::resizeEvent(event);
}
//! [16]

//! [17]
void ManualScribble::drawLineTo(const QPoint& endPoint)
//! [17] //! [18]
{
    QPainter painter(&image);
    painter.setPen(QPen(myPenColor, myPenWidth, Qt::SolidLine, Qt::RoundCap,
                        Qt::RoundJoin));
    painter.drawLine(lastPoint, endPoint);
    modified = true;

    int rad = (myPenWidth / 2) + 2;
    update(QRect(lastPoint, endPoint).normalized()
           .adjusted(-rad, -rad, +rad, +rad));
    lastPoint = endPoint;
}
//! [18]

//! [19]
void ManualScribble::resizeImage(QImage* image, const QSize& newSize)
//! [19] //! [20]
{
    if (image->size() == newSize)
        return;

    QImage newImage(newSize, QImage::Format_RGB32);
    newImage.fill(qRgb(255, 255, 255));
    QPainter painter(&newImage);
    painter.drawImage(QPoint(0, 0), *image);
    *image = newImage;
}
//! [20]

//! [21]
void ManualScribble::print()
{
#if defined(QT_PRINTSUPPORT_LIB) && QT_CONFIG(printdialog)
    QPrinter printer(QPrinter::HighResolution);

    QPrintDialog printDialog(&printer, this);
    //! [21] //! [22]
    if (printDialog.exec() == QDialog::Accepted)
    {
        QPainter painter(&printer);
        QRect rect = painter.viewport();
        QSize size = image.size();
        size.scale(rect.size(), Qt::KeepAspectRatio);
        painter.setViewport(rect.x(), rect.y(), size.width(), size.height());
        painter.setWindow(image.rect());
        painter.drawImage(0, 0, image);
    }
#endif // QT_CONFIG(printdialog)
}
//! [22]

void ManualScribble::moveRefFrame(QPoint& coordinates)
{

    int Cx = coordinates.x();
    int Cy = coordinates.y();

    QMap<QString, double> angles;
    angles.insert("Az", 0);
    angles.insert("El", 0);

    if (Cx < 500 && Cy < 500 && Cx > 0 && Cy > 0)
    {
        int Bx, By;
        Bx = Cx - 250;
        By = -(Cy - 250);

        if (Bx > 0 && By > 0)
        {
            // First Quadrant
            angles["Az"] = atan2(Bx, By) * 180 / PI;

        }
        else if (Bx < 0 && By > 0)
        {
            // Second Quadrant
            angles["Az"] = (atan2(Bx, By) * 180 / PI) + 360;

        }
        else if (Bx < 0 && By < 0)
        {
            // Third Quadrant
            angles["Az"] = (atan2(Bx, By) * 180 / PI) + 360;

        }
        else if (Bx > 0 && By < 0)
        {
            // First Quadrant
            angles["Az"] = (atan2(Bx, By) * 180 / PI) ;
        }

        angles["El"] = (90 * (250 - sqrt(pow(Bx, 2) + pow(By, 2))) / 250);

        if (angles["Az"] > 360)
        {
            angles["Az"] = 360;
        }
        else if (angles["Az"] < 0)
        {
            angles["Az"] = 0;
        }

        if (angles["El"] > 90)
        {
            angles["El"] = 90;
        }
        else if (angles["El"] < 0)
        {
            angles["El"] = 0;
        }
        else
        {
            //drawLineTo(coordinates);
        }

        //qDebug()<<"Az: "+ QString::number(angles["Az"]) +" El: "+QString::number(angles["El"]);

        emit logAngles(angles);
    }
}
