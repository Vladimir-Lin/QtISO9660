NAME         = QtISO9660
TARGET       = $${NAME}
QT           = core
QT          -= gui
CONFIG(static,static|shared) {
# static version does not support Qt Script now
QT          -= script
} else {
QT          += script
}

load(qt_build_config)
load(qt_module)

INCLUDEPATH += $${PWD}/../../include/QtISO9660

HEADERS     += $${PWD}/../../include/QtISO9660/QtISO9660
HEADERS     += $${PWD}/../../include/QtISO9660/qtiso9660.h

SOURCES     += $${PWD}/qtiso9660.cpp

OTHER_FILES += $${PWD}/../../include/$${NAME}/headers.pri

include ($${PWD}/../../doc/Qt/Qt.pri)
