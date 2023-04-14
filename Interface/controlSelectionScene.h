#pragma once
#ifndef CONTROLSELECTIONSCENE_H
#define CONTROLSELECTIONSCENE_H

#include "applicationScene.h"
#include <QGraphicsView>
#include "buttonGroup2D.h"
#include "inputSetting.h"
#include "controlSelectionButton.h"
#include "assets.h"
#include "screenMapper.h"
#include "inputSetting.h"

class ControlSelectionScene : public ApplicationScene
{
	Q_OBJECT
public:
	ControlSelectionScene(QSize windowSize);
	~ControlSelectionScene();

public slots:
	void translateLeftOptionClicked();
	void translateRightOptionClicked();
	void rotateRightOptionClicked();
	void rotateLeftOptionClicked();
	void dropInstantOptionClicked();
	void dropFasterOptionClicked();
	void holdPieceOptionClicked();

	void translateLeftDeleteClicked();
	void translateRightDeleteClicked();
	void rotateRightDeleteClicked();
	void rotateLeftDeleteClicked();
	void dropInstantDeleteClicked();
	void dropFasterDeleteClicked();
	void holdPieceDeleteClicked();

	void exitPage();

private:
	ButtonGroup2D* _buttonGroup;
	InputSetting settings;
	ControlSelectionButton* _translateLeftButton;
	ControlSelectionButton* _translateRightButton;
	ControlSelectionButton* _rotateRightButton;
	ControlSelectionButton* _rotateLeftButton;
	ControlSelectionButton* _dropInstantButton;
	ControlSelectionButton* _dropFasterButton;
	ControlSelectionButton* _holdPieceButton;
	ToggledButton* _saveAndExitButton;

	InputSetting _inputSetting;

	ControllerInputOutput waitForInput();

protected:
	void keyPressEvent(QKeyEvent* event);
};

#endif // CONTROLSELECTIONSCENE_H
