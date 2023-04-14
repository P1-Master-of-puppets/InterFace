#include "gameSoundPlayer.h"

void GameSoundPlayer::playMainTheme(bool stop)
{
	static QSoundEffect sound;
	sound.setSource(QUrl::fromLocalFile(TETRIS_THEME));
	sound.setLoopCount(QSoundEffect::Infinite);
	sound.setVolume(0.25f);

	if (stop)
		sound.stop();
	else
		sound.play();
	
}

void GameSoundPlayer::playTic()
{
	static QSoundEffect sound;
	sound.setSource(QUrl::fromLocalFile(TICK_SOUND));
	sound.setLoopCount(1);
	sound.setVolume(0.75f);
	sound.play();
}

void GameSoundPlayer::playSelect()
{
	static QSoundEffect sound;
	sound.setSource(QUrl::fromLocalFile(SELECT_SOUND));
	sound.setLoopCount(1);
	sound.setVolume(0.5f);
	sound.play();
}

void GameSoundPlayer::playBoop()
{
	static QSoundEffect sound;
	sound.setSource(QUrl::fromLocalFile(BOOP_SOUND));
	sound.setLoopCount(1);
	sound.setVolume(0.10f);
	sound.play();
}

void GameSoundPlayer::playTetris()
{
	static QSoundEffect sound;
	sound.setSource(QUrl::fromLocalFile(TETRIS_SOUND));
	sound.setLoopCount(1);
	sound.setVolume(1.0f);
	sound.play();
}

void GameSoundPlayer::playDeny()
{
	static QSoundEffect sound;
	sound.setSource(QUrl::fromLocalFile(DENY_SOUND));
	sound.setLoopCount(1);
	sound.setVolume(0.25f);
	sound.play();
}

void GameSoundPlayer::playGameOver()
{
	static QSoundEffect sound;
	sound.setSource(QUrl::fromLocalFile(GAME_OVER_SOUND));
	sound.setLoopCount(1);
	sound.setVolume(0.5f);
	sound.play();
}

void GameSoundPlayer::playLineComplete()
{
	static QSoundEffect sound;
	sound.setSource(QUrl::fromLocalFile(LINE_COMPLETE_SOUND));
	sound.setLoopCount(1);
	sound.setVolume(0.5f);
	sound.play();
}


