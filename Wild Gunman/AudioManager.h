#pragma once
#include "Include&using.h"

class AudioManager
{
private:
	// Declaraci�n de los objetos de sonido y m�sica
	Sound gunShotSound;
	Sound menuSound;
	Sound youWinSound;
	Sound youLoseSound;

	SoundBuffer gunShotBuffer;
	SoundBuffer menuSoundBuffer;
	SoundBuffer youWinBuffer;
	SoundBuffer youLoseBuffer;

	Music music;
public:

	void InitAudio(); // Funci�n para inicializar los recursos de audio
	
	// Funciones para reproducir los diferentes sonidos
	void PlayGunShot();
	void PlayMenuMusic();
	void PlayWin();
	void PlayLose();
};