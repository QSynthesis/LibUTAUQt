#include "test.h"

// 打开文件
int openTempFile(QUtauData &oData, const QString &oFileName, bool *oSuccess) {
    int tmpOpenCode = oData.LoadFromFile(oFileName);
    bool aSuccess = true;

    qDebug() << "# Open Temp File";

    switch (tmpOpenCode) {
    case ERROR_INVALID_INPUT_FILE_PATH:
        qDebug() << "Input file not found.";
        aSuccess = false;
        break;
    case ERROR_INVALID_FORMAT:
        qDebug() << "Input file format error.";
        aSuccess = false;
        break;

    // 以下错误发生了也能被允许
    case ERROR_INVALID_VOICE_DIR_PATH:
        qDebug() << "Voice dir not found.";
        break;
    case ERROR_NO_SETTING_INI:
        qDebug() << "setting.ini not found.";
        break;
    case ERROR_NO_TOOLS_IN_SETTING_INI:
        qDebug() << "Invalid project file.";
        break;
    case ERROR_INVALID_TOOLS_IN_SETTING_INI:
        qDebug() << "Invalid tool path in setting.ini.";
        break;
    case ERROR_INVALID_TOOLS_IN_PROJECT_UST:
        qDebug() << "Invalid tool path in project file.";
        break;

    // 没有错误
    default:
        qDebug() << "No error in input file.";
        break;
    }

    if (oSuccess) {
        *oSuccess = aSuccess;
    }
    return tmpOpenCode;
}

// 遍历音符
int traverseNotes(const QUtauData &oData) {
    const QUtauSectionNote *aNote;
    QVector<QUtauSectionNote>::size_type i;

    const QUtauSectionSettings *aSettings = oData.SectionSettings();

    QString aLyric, aFlags;
    int aNoteNum, aLength;

    double aPreUtterance, aVoiceOverlap, aStartPoint;
    int aPreStatus, aOveStatus, aStpStatus;

    double aTempo;
    int aTempoStatus;

    double aSettingTempo;
    int aSettingTempoStatus;

    qDebug() << "# Get Settings";

    aSettings->GetValue(KEY_NAME_TEMPO, &aSettingTempo, &aSettingTempoStatus);
    qDebug() << aSettingTempo << aSettingTempoStatus;
    qDebug() << "";

    qDebug() << "# Traverse Notes";

    for (i = oData.SectionNotesNormalBegin(); i < oData.SectionNotesNormalEnd(); ++i) {

        aNote = oData.SectionNoteAt(i);

        // 歌词、音阶、长度
        aLyric = "";
        aFlags = "";
        aNoteNum = 60;
        aLength = 480;

        aNote->GetValue(KEY_NAME_LYRIC, &aLyric);
        aNote->GetValue(KEY_NAME_NOTE_NUM, &aNoteNum);
        aNote->GetValue(KEY_NAME_LENGTH, &aLength);

        // 先行、重叠、STP
        aPreUtterance = aVoiceOverlap = aStartPoint = 0;
        aPreStatus = aOveStatus = aStpStatus = MFM_OMITTED; // 设为省略的

        aNote->GetValue(KEY_NAME_PRE_UTTERANCE, &aPreUtterance, &aPreStatus);
        aNote->GetValue(KEY_NAME_VOICE_OVERLAP, &aVoiceOverlap, &aOveStatus);
        aNote->GetValue(KEY_NAME_START_POINT, &aStartPoint, &aStpStatus);

        // Flags
        if (aNote->GetValue(KEY_NAME_FLAGS, &aFlags)) {
            // Flags 在此音符上被设定了
        }

        // 曲速
        aTempo = 0;
        aTempoStatus = MFM_OMITTED; // 设为省略的

        aNote->GetValue(KEY_NAME_TEMPO, &aTempo, &aTempoStatus);

        qDebug() << i << aLyric << "notenum" << aNoteNum << "len" << aLength << "pre"
                 << aPreUtterance << "ove" << aVoiceOverlap << "stp" << aStartPoint << "tempo"
                 << aTempo << aFlags;
    }

    return 1;
}

int modifyLyricBatch(QUtauData &oData) {
    QUtauSectionNote *aNote;
    QVector<QUtauSectionNote>::size_type i;

    QString aLyric;

    qDebug() << "# Change Lyrics";

    for (i = oData.SectionNotesNormalBegin(); i < oData.SectionNotesNormalEnd(); ++i) {
        aNote = oData.SectionNoteAt(i);

        aNote->GetValue(KEY_NAME_LYRIC, &aLyric);
        aNote->SetValue(KEY_NAME_LYRIC, aLyric + "1");
    }

    qDebug() << "1 is appended to all lyrics.";

    return 1;
}
