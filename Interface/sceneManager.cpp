#include <sceneManager.h>

SceneManager::SceneManager(QGraphicsView* mainView) : _mainView(mainView)
{
	_currentScene = nullptr;
	goToSplashScreen();
}

QSize SceneManager::getSize()
{
	return QSize(_mainView->width(), _mainView->height());
}

void SceneManager::goToSplashScreen() {
	changeView(new GameStartScene(getSize(), _mainView));
}

void SceneManager::goToMainMenu() {
	changeView(new GameMenuScene(getSize()));
}

void SceneManager::goToControlSetup() {
	changeView(new ControlSelectionScene(getSize()));
}

void SceneManager::goToMainGame() {
	GameSoundPlayer::playMainTheme();
	MainGameScene* scene = new MainGameScene(getSize(), _mainView);
	changeView(scene);
	scene->startGame();
}

void SceneManager::exitApplication() {
	changeView(new GameStartScene(getSize(), _mainView));
}

void SceneManager::changeView(ApplicationScene* newScene)
{
	ApplicationScene* temp = _currentScene;


	_currentScene = newScene;
	_mainView->setScene(newScene);
	QObject::connect(newScene, &ApplicationScene::exitApplication, this, &SceneManager::exitApplication);
	QObject::connect(newScene, &ApplicationScene::goToSplashScreen, this, &SceneManager::goToSplashScreen);
	QObject::connect(newScene, &ApplicationScene::goToMainMenu, this, &SceneManager::goToMainMenu);
	QObject::connect(newScene, &ApplicationScene::goToControlSetup, this, &SceneManager::goToControlSetup);
	QObject::connect(newScene, &ApplicationScene::goToMainGame, this, &SceneManager::goToMainGame);

	if (_currentScene != nullptr)
		delete temp;
}

