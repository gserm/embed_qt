#include <QApplication>
#include <QWinWidget>
#include <QLayout>

#include "com_foo_test_handlers_FooHandler.h"
#include "my_widget.h"

int argc = 1;
const char *argv[] = {"example"};

JNIEXPORT void JNICALL Java_com_foo_test_handlers_FooHandler_embedQtWidget
  (JNIEnv *, jobject, jlong parentHandle) {

	if(!qApp) new QApplication(argc, (char**)argv);

	auto* host = new QWinWidget((HWND)parentHandle);
	auto* myWindow = new Widget(host);
	myWindow->setFixedHeight(600);
	myWindow->setFixedWidth(600);

	auto* layout = new QHBoxLayout(host);
	layout->addWidget(myWindow);

	host->show();
	//qApp->exec();
}
