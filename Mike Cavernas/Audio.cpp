#include "Audio.h"

Audio::Audio() {
	music.openFromFile("Asset/Audio/Musica_principal.ogg");
}

Audio::~Audio() {

}

void Audio::PlayMusicGame() {
	music.setLoop(true);
	return music.play();
}

void Audio::StopMusicGame() {
	return music.stop();
}






