#pragma once
#include "Include&using.h"

class AudioManager
{
private:
	// Declaraci�n de los objetos de sonido y m�sica
	Sound gunShotSound;

	SoundBuffer gunShotBuffer;

	Music music;
public:

	void InitAudio(); // Funci�n para inicializar los recursos de audio
	
	// Funciones para reproducir los diferentes sonidos
	void PlayGunShot();
};