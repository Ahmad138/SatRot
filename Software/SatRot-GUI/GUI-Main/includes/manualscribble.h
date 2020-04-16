#ifndef MANUALSCRIBBLE_H
#define MANUALSCRIBBLE_H

#include <math.h>

#include <QColor>
#include <QImage>
#include <QPoint>
#include <QWidget>

//! [0]
/**
 * @brief
 *
 */
class ManualScribble : public QWidget
{
    Q_OBJECT

public:
    /**
     * @brief
     *
     * @param parent
     */
    ManualScribble(QWidget* parent = nullptr);

    /**
     * @brief
     *
     * @param fileName
     * @return bool
     */
    bool openImage(const QString& fileName);
    /**
     * @brief
     *
     * @param fileName
     * @param fileFormat
     * @return bool
     */
    bool saveImage(const QString& fileName, const char* fileFormat);
    /**
     * @brief
     *
     * @param newColor
     */
    void setPenColor(const QColor& newColor);
    /**
     * @brief
     *
     * @param newWidth
     */
    void setPenWidth(int newWidth);

    /**
     * @brief
     *
     * @return bool
     */
    bool isModified() const { return modified; }
    /**
     * @brief
     *
     * @return QColor
     */
    QColor penColor() const { return myPenColor; }
    /**
     * @brief
     *
     * @return int
     */
    int penWidth() const { return myPenWidth; }

public slots:
    /**
     * @brief
     *
     */
    void clearImage();
    /**
     * @brief
     *
     */
    void print();
    /**
     * @brief
     *
     * @param coordinates
     */
    void moveRefFrame(QPoint& coordinates);

protected:
    /**
     * @brief
     *
     * @param event
     */
    void mousePressEvent(QMouseEvent* event) override;
    /**
     * @brief
     *
     * @param event
     */
    void mouseMoveEvent(QMouseEvent* event) override;
    /**
     * @brief
     *
     * @param event
     */
    void mouseReleaseEvent(QMouseEvent* event) override;
    /**
     * @brief
     *
     * @param event
     */
    void paintEvent(QPaintEvent* event) override;
    /**
     * @brief
     *
     * @param event
     */
    void resizeEvent(QResizeEvent* event) override;

private:
    /**
     * @brief
     *
     * @param endPoint
     */
    void drawLineTo(const QPoint& endPoint);
    /**
     * @brief
     *
     * @param image
     * @param newSize
     */
    void resizeImage(QImage* image, const QSize& newSize);

    bool modified = false; /**< TODO: describe */
    bool scribbling = false; /**< TODO: describe */
    int myPenWidth = 3; /**< TODO: describe */
    QColor myPenColor = Qt::red; /**< TODO: describe */
    QImage image; /**< TODO: describe */
    QPoint lastPoint; /**< TODO: describe */

signals:
    /**
     * @brief
     *
     * @param QMap<QString
     * @param angles
     */
    void logAngles(QMap<QString, double>& angles);
};
//! [0]

#endif // MANUALSCRIBBLE_H
