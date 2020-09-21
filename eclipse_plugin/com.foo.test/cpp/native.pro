TEMPLATE = lib

TARGET = native

CONFIG += dll migrate

#ensure you've set the env variable JAVA_HOME
INCLUDEPATH += $$(JAVA_HOME)/include \
				$$(JAVA_HOME)/include/win32

CONFIG(migrate) {
	
	INCLUDEPATH += D:/development/qtwinmigrate/5/src
	DEFINES += QT_QTWINMIGRATE_IMPORT QTWINMIGRATE
	
	# change these paths accordingly
	CONFIG(debug, debug|release):LIBS += D:/development/qtwinmigrate/5/lib/QtSolutions_MFCMigrationFramework-headd.lib
	CONFIG(release, debug|release):LIBS += D:/development/qtwinmigrate/5/lib/QtSolutions_MFCMigrationFramework-head.lib
}

greaterThan(QT_MAJOR_VERSION, 4) {
    QT += widgets
}

HEADERS += my_widget.h

SOURCES +=  embed.cpp

