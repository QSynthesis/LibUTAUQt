#ifndef TEST_H
#define TEST_H

#include "LibUTAUQt/QUtauData.h"
#include <QDebug>

// 打开文件
int openTempFile(QUtauData &oData, const QString &oFileName, bool *oSuccess = NULL);

// 遍历音符
int traverseNotes(const QUtauData &oData);

// 在所有音符后添加 1
int modifyLyricBatch(QUtauData &oData);

#endif // TEST_H
