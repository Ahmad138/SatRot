#ifndef MANUALSCRIBBLE_H
#define MANUALSCRIBBLE_H

#include <math.h>

#include <QColor>
#include <QImage>
#include <QPoint>
#include <QWidget>

//! [0]
class ManualScribble : public QWidget
{
    Q_OBJECT

public:
    ManualScribble(QWidget *parent = nullptr);

    bool openImage(const QString &fileName);
    bool saveImage(const QString &fileName, const char *fileFormat);
    void setPenColor(const QColor &newColor);
    void setPenWidth(int newWidth);

    bool isModified() const { return modified; }
    QColor penColor() const { return myPenColor; }
    int penWidth() const { return myPenWidth; }

public slots:
    void clearImage();
    void print();
    void moveRefFrame(QPoint &coordinates);

protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void paintEvent(QPaintEvent *event) override;
    void resizeEvent(QResizeEvent *event) override;

private:
    void drawLineTo(const QPoint &endPoint);
    void resizeImage(QImage *image, const QSize &newSize);

    bool modified = false;
    bool scribbling = false;
    int myPenWidth = 3;
    QColor myPenColor = Qt::red;
    QImage image;
    QPoint lastPoint;

signals:
    void logAngles(QMap<QString, double> &angles);
};
//! [0]

#endif // MANUALSCRIBBLE_H
