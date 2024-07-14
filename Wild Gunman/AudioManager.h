#pragma once
#include "Include&using.h"

class AudioManager
{
private:
	// Declaración de los objetos de sonido y música
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

	void InitAudio(); // Función para inicializar los recursos de audio
	
	// Funciones para reproducir los diferentes sonidos
	void PlayGunShot();
	void PlayMenuMusic();
	void PlayWin();
	void PlayLose();
};