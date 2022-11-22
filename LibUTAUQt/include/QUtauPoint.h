#ifndef __QUTAUPOINT_H__
#define __QUTAUPOINT_H__

#include <QUtauGlobal.h>

//===========================================================================
// UTAU 控制点类
class LIBUTAUQT_API QUtauPoint {
public:
    enum PointType {
        sType,
        lineType,
        rType,
        jType,
    };

    QUtauPoint();
    QUtauPoint(const QUtauPoint &oRHS);

    QUtauPoint(double oX, double oY);
    QUtauPoint(double oX, double oY, PointType oP);

    QUtauPoint &operator=(const QUtauPoint &oRHS);

    QUtauPoint operator+(const QUtauPoint &oRHS) const;
    QUtauPoint &operator+=(const QUtauPoint &oRHS);

    QUtauPoint operator-() const;

    QUtauPoint operator-(const QUtauPoint &oRHS) const;
    QUtauPoint &operator-=(const QUtauPoint &oRHS);

    friend QDebug operator<<(QDebug debug, const QUtauPoint &oRHS);

    double mX;
    double mY;
    PointType mP;

    // 控制点类型转换
    static QString pointTypeToString(const PointType &oType);
    static PointType stringToPointType(const QString &oString);
};

//===========================================================================

#endif // __QUTAUPOINT_H__