#include "AudioManager.h"

void AudioManager::InitAudio()
{

    // Cargar los archivos de sonido
    if (!menuSoundBuffer.loadFromFile("Assets/sound/menu_sound.ogg"))
    {
        // Error al cargar el archivo de disparo
        cout << "Error al cargar el archivo de menu_sound.ogg" << std::endl;
        return;
    }
    menuSound.setBuffer(menuSoundBuffer); // Asignar el buffer de sonido a la fuente de sonido

    if (!gunShotBuffer.loadFromFile("Assets/sound/gun_shot.ogg"))
    {
        // Error al cargar el archivo de disparo
        cout << "Error al cargar el archivo de sonido de disparo" << std::endl;
        return;
    }
    gunShotSound.setBuffer(gunShotBuffer); // Asignar el buffer de sonido a la fuente de sonido

    if (!youWinBuffer.loadFromFile("Assets/sound/you_win.ogg"))
    {
        // Error al cargar el archivo de disparo
        cout << "Error al cargar el archivo de sonido you_win.ogg" << std::endl;
        return;
    }
    youWinSound.setBuffer(youWinBuffer); // Asignar el buffer de sonido a la fuente de sonido

    if (!youLoseBuffer.loadFromFile("Assets/sound/you_lose.ogg"))
    {
        // Error al cargar el archivo de disparo
        cout << "Error al cargar el archivo de sonido you_lose.ogg" << std::endl;
        return;
    }
    youLoseSound.setBuffer(youLoseBuffer); // Asignar el buffer de sonido a la fuente de sonido

}

void AudioManager::PlayMenuMusic()
{

    menuSound.setVolume(50);
    menuSound.play();
}

void AudioManager::PlayGunShot()
{

    gunShotSound.setVolume(50);
    gunShotSound.play();
}

void AudioManager::PlayWin()
{

    youWinSound.setVolume(50);
    youWinSound.play();
}

void AudioManager::PlayLose()
{

    youLoseSound.setVolume(50);
    youLoseSound.play();
}