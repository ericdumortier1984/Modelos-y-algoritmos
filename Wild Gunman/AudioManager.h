#pragma once
#include "Include&using.h"

class AudioManager
{
private:
	// Declaración de los objetos de sonido y música
	Sound gunShotSound;

	SoundBuffer gunShotBuffer;

	Music music;
public:

	void InitAudio(); // Función para inicializar los recursos de audio
	
	// Funciones para reproducir los diferentes sonidos
	void PlayGunShot();
};