#include "QUtauPoint.h"

//===========================================================================
QUtauPoint::QUtauPoint() {
    mX = 0.0;
    mY = 0.0;
    mP = sType;
}

QUtauPoint::QUtauPoint(const QUtauPoint &oRHS) {
    mX = oRHS.mX;
    mY = oRHS.mY;
    mP = oRHS.mP;
}

QUtauPoint::QUtauPoint(double oX, double oY) {
    mX = oX;
    mY = oY;
    mP = sType;
}

QUtauPoint::QUtauPoint(double oX, double oY, PointType oP) {
    mX = oX;
    mY = oY;
    mP = oP;
}

QUtauPoint &QUtauPoint::operator=(const QUtauPoint &oRHS) {
    mX = oRHS.mX;
    mY = oRHS.mY;
    mP = oRHS.mP;

    return *this;
}

QUtauPoint QUtauPoint::operator+(const QUtauPoint &oRHS) const {
    QUtauPoint aResult;
    aResult.mX = mX + oRHS.mX;
    aResult.mY = mY + oRHS.mY;

    return aResult;
}

QUtauPoint &QUtauPoint::operator+=(const QUtauPoint &oRHS) {
    mX += oRHS.mX;
    mY += oRHS.mY;

    return *this;
}

QUtauPoint QUtauPoint::operator-() const {
    QUtauPoint aResult(-mX, -mY, mP);
    return aResult;
}

QUtauPoint QUtauPoint::operator-(const QUtauPoint &oRHS) const {
    QUtauPoint aResult;
    aResult.mX = mX - oRHS.mX;
    aResult.mY = mY - oRHS.mY;

    return aResult;
}

QUtauPoint &QUtauPoint::operator-=(const QUtauPoint &oRHS) {
    mX -= oRHS.mX;
    mY -= oRHS.mY;

    return *this;
}

QDebug operator<<(QDebug debug, const QUtauPoint &oRHS) {
    QString info =
        QString("QUtauPoint(mX:%1; mY:%2; mP:%3)").arg(oRHS.mX).arg(oRHS.mY).arg(oRHS.mP);
    debug << info;
    return debug;
}

QString QUtauPoint::pointTypeToString(const PointType &oType) {
    QString aResult;
    switch (oType) {
    case sType:
        aResult = "";
        break;
    case lineType:
        aResult = "s";
    case rType:
        aResult = "r";
        break;
    case jType:
        aResult = "j";
        break;
    }

    return aResult;
}

QUtauPoint::PointType QUtauPoint::stringToPointType(const QString &oString) {
    PointType aResult;

    if (oString == "s") {
        aResult = lineType;
    } else if (oString == "r") {
        aResult = rType;
    } else if (oString == "j") {
        aResult = jType;
    } else {
        aResult = sType;
    }

    return aResult;
}