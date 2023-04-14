#include <sceneManager.h>

QGameController* SceneManager::controller = nullptr;

SceneManager::SceneManager(QGraphicsView* mainView) : _mainView(mainView)
{

	_eventHandler = new ControllerEventHandler();
	SceneManager::controller = new QGameController(7, 115200);
	if (!SceneManager::controller->getIsRunning())
	{
		delete SceneManager::controller;
		SceneManager::controller = nullptr;
	}
	else
	{
		controller->setSceneManager(_eventHandler);
		_eventHandler->setGraphicsView(mainView);
		SceneManager::controller->enableKeyBoardEvent();
	}
	_currentScene = nullptr;
	goToSplashScreen();
}

SceneManager::~SceneManager()
{
	delete _eventHandler;
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

