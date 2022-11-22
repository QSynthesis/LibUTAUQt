#ifndef TEST_H
#define TEST_H

#include <QDebug>

#include "QUtauUst.h"

// 打开文件
int openTempFile(QUtauUst &oData, const QString &oFileName, bool *oSuccess = NULL);

// 遍历音符
int traverseNotes(const QUtauUst &oData);

// 在所有音符后添加 1
int modifyLyricBatch(QUtauUst &oData);

#endif // TEST_H
