#include <sceneManager.h>

SceneManager::SceneManager(QGraphicsView* setView): mainView(setView)
{
	viewSize = QSize(mainView->width(), mainView->height());
	goToSplashScreen();
}

void SceneManager::exitApplication() {

}

void SceneManager::goToSplashScreen() {
	splashScreen = new GameStartScene(viewSize);
	splashScreen->setSceneRect(mainView->rect());
	mainView->setScene(splashScreen);
	connect(splashScreen, &GameStartScene::goToMainGame, this, &SceneManager::goToMainGame);
}

void SceneManager::goToMainMenu() {

}

void SceneManager::goToControlSetup() {

}

void SceneManager::goToMainGame() {
	mainGame = new MainGameScene(viewSize);
	mainGame->setSceneRect(mainView->rect());
	mainView->setScene(mainGame);
}

