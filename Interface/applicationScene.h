#pragma once
#ifndef APPLICATIONSCENE_H
#define APPLICATIONSCENE_H

#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QSize>
#include <QPixmap>

class ApplicationScene : public QGraphicsScene
{
	Q_OBJECT
public:
	ApplicationScene(QSize size, QObject* parent = nullptr);
	virtual ~ApplicationScene();
	void setBackground(QPixmap image);
public slots:
signals:
	void exitApplication();
	void goToSplashScreen();
	void goToMainMenu();
	void goToControlSetup();
	void goToMainGame();

protected:
	QGraphicsView* _applicationView;
	QSize _sceneSize;
private:
	QGraphicsPixmapItem* _background;

};
#endif // !APPLICATIONSCENE_H

