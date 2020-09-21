#include <QDialog>
#include <QDebug>
#include <QString>
#include <QMenu>
#include <QMenuBar>
#include <QAction>
#include <QMainWindow>
#include <QPushButton>
#include <QLayout>
#include <QPaintEvent>
#include <QPainter>
#include <QBrush>
#include <QMessagebox>
#include <iostream>

class Dialog : public QDialog
{
	Q_OBJECT

public:

	Dialog(QWidget* parent = nullptr)
		: QDialog(parent)
	{
		auto ok = new QPushButton("OK");
		auto layout = new QHBoxLayout(this);
		layout->addWidget(ok);
		connect(ok, SIGNAL(clicked(bool)), this, SLOT(accept()));
	}
};

class Widget : public QWidget
{
	Q_OBJECT

public:

	Widget(QWidget* parent = nullptr): QWidget(parent){}

protected:

	void paintEvent(QPaintEvent* event)
	{
		QPainter p(this);
		p.fillRect(0,0,600,600, Qt::black);
	}

	void mousePressEvent(QMouseEvent* event)
	{
		Dialog d(this);
		int r = d.exec();

//		auto* d = new Dialog(this);
//		d->setModal(false);
//		d->setAttribute(Qt::WA_DeleteOnClose);
//		d->show();
	}
};

class Window : public QMainWindow
{
	Q_OBJECT

public:
	Window(QWidget* parent = nullptr)
		: QMainWindow(parent)
	{
		auto* fileMenu = menuBar()->addMenu("File");
		auto* action = fileMenu->addAction("Open");
		connect(action, SIGNAL(triggered()), this, SLOT(showDialog()));

		setContextMenuPolicy(Qt::CustomContextMenu);
		connect(this, SIGNAL(customContextMenuRequested(QPoint)), this, SLOT(popupMenu(QPoint)));
	}

public slots:

	void showDialog() {
		Dialog d;
		d.exec();

		/*auto* d = new Dialog(this);
		d->show();*/
	}

	void popupMenu(QPoint /*point*/)
	{
		auto pos = QCursor::pos();
		QMenu menu;
		auto* action1 = menu.addAction("Action1");
		connect(action1, SIGNAL(triggered(bool)), this, SLOT(handleAction1()));
		menu.addAction("Action2");
		menu.addAction("Action3");
		menu.addAction("Action4");
		menu.exec(pos);

		/*auto* menu = new QMenu(this);
		auto* action1 = menu->addAction("Action1");
		connect(action1, SIGNAL(triggered(bool)), this, SLOT(handleAction1()));
		menu->addAction("Action2");
		menu->addAction("Action3");
		menu->addAction("Action4");
		menu->popup(pos);*/
	}

	void handleAction1()
	{
		std::cerr << "Handled Action1\n";
	}
};
