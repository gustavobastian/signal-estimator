#pragma once

#include <QPointF>
#include <QVector>

#include <cstring>
#include <iostream>
#include <optional>

enum IOType { Input, Output, None };

class PointsBuffer {
public:
    void appendPoint(QPointF);

    QVector<QPointF> getCurrentPoints();
    void clearBuf();

private:
    QList<QPointF> ringbuf_; // see appendPoint() implementation
    const size_t ring_size_ = 1024;
    QVector<QPointF> lastPlottedPoints;
};