#include "AudioManager.h"

void AudioManager::InitAudio()
{

    // Cargar los archivos de sonido
    if (!gunShotBuffer.loadFromFile("Assets/sound/gun_shot.ogg"))
    {
        // Error al cargar el archivo de disparo
        cout << "Error al cargar el archivo de sonido de disparo" << std::endl;
        return;
    }
    gunShotSound.setBuffer(gunShotBuffer);  // Asignar el buffer de sonido a la fuente de sonido
}

void AudioManager::PlayGunShot()
{

    gunShotSound.setVolume(50);
    gunShotSound.play();
}