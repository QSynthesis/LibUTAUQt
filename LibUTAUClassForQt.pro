QT -= gui

CONFIG += c++11 console
CONFIG -= app_bundle

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        LibUTAUQt/QGenonSettings.cpp \
        LibUTAUQt/QOtoIni.cpp \
        LibUTAUQt/QPrefixMap.cpp \
        LibUTAUQt/QUtauConstants.cpp \
        LibUTAUQt/QUtauData.cpp \
        LibUTAUQt/QUtauSection.cpp \
        LibUTAUQt/QUtauSectionNote.cpp \
        LibUTAUQt/QUtauSectionSettings.cpp \
        LibUTAUQt/QUtauSectionVersion.cpp \
        LibUTAUQt/QUtauUtils.cpp \
        main.cpp \
        test.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    LibUTAUQt/QPrefixMap.h \
    LibUTAUQt/QUtauSectionNote.h \
    LibUTAUQt/QUtauSectionSettings.h \
    LibUTAUQt/QUtauSectionVersion.h \
    LibUTAUQt/QUtauStrings.h \
    LibUTAUQt/QGenonSettings.h \
    LibUTAUQt/QOtoIni.h \
    LibUTAUQt/QUtauConstants.h \
    LibUTAUQt/QUtauData.h \
    LibUTAUQt/QUtauGlobal.h \
    LibUTAUQt/QUtauSection.h \
    LibUTAUQt/QUtauUtils.h \
    test.h
