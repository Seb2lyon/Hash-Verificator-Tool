QT += widgets

SOURCES += \
    hashThread.cpp \
    helpWindow.cpp \
    main.cpp \
    mainWindow.cpp \
    searchFileWindow.cpp \
    waitHashWindow.cpp

HEADERS += \
    hashThread.h \
    helpWindow.h \
    mainWindow.h \
    searchFileWindow.h \
    waitHashWindow.h

OTHER_FILES += \
    ressources.rc

RC_FILE = ressources.rc

TRANSLATIONS = Hash-Verificator-Tool_en.ts
