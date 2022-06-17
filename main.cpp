#include <QCoreApplication>
#include <QDebug>
#include <QTime>

using namespace std;

#include <QUtauData.h>

#include "test.h"

int main(int argc, char *argv[]) {
    // 检测命令行参数
    if (argc < 2) {
        qDebug() << "No input file.";
        return 0;
    }

#ifdef Q_OS_WINDOWS
    QString aInputFile(QString::fromLocal8Bit(argv[1]));
#else
    QString aInputFile(QString::fromUtf8(argv[1]));
#endif

    QUtauData aUtauData;
    bool aSuccess;

    // 第一步：打开文件
    openTempFile(aUtauData, aInputFile, &aSuccess);

    if (!aSuccess) {
        qDebug() << "Open failed.";
        return -1;
    } else {
        qDebug() << "Open success.";
    }
    qDebug() << "";

    // 第二步：检测音符信息
    traverseNotes(aUtauData);
    qDebug() << "";

    // 第三步：批量改变歌词
    modifyLyricBatch(aUtauData);

    // 第四步：反馈
    if (aUtauData.Export(aInputFile)) {
        qDebug() << "Export success.";
    } else {
        qDebug() << "Export failed.";
    }

    return 0;
}
