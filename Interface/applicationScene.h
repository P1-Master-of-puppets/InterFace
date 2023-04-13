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

private:
	QGraphicsPixmapItem* _background;
	QSize _sceneSize;

};
#endif // !APPLICATIONSCENE_H

