QT             = core
QT            -= gui
QT            += QtISO9660

CONFIG(debug, debug|release) {
TARGET         = iso9660toold
} else {
TARGET         = iso9660tool
}

CONFIG        += console

TEMPLATE       = app

SOURCES       += $${PWD}/iso9660tool.cpp

win32 {
RC_FILE        = $${PWD}/iso9660tool.rc
OTHER_FILES   += $${PWD}/iso9660tool.rc
OTHER_FILES   += $${PWD}/*.js
}
