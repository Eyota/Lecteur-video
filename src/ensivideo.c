#include <stdio.h>
#include <unistd.h>
#include <assert.h>
#include <SDL2/SDL.h>
#include <pthread.h>

#include "stream_common.h"
#include "oggstream.h"


int main(int argc, char *argv[]) {
    int res;
	pthread_t theoraThread[1], vorbisThread[1];	//Entre [] = nb threads

    if (argc != 2) {
	fprintf(stderr, "Usage: %s FILE", argv[0]);
	exit(EXIT_FAILURE);
    }
    assert(argc == 2);


    // Initialisation de la SDL
    res = SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO|SDL_INIT_EVENTS);
    atexit(SDL_Quit);
    assert(res == 0);
    
    // start the two stream readers
	//prennent en argument le nom du fichier à lire ?
	pthread_create(&theoraThread[1], NULL, theoraStreamReader, NULL);	//argv[1]?
	pthread_create(&vorbisThread[1], NULL, vorbisStreamReader, NULL);
	//Vérifier création threads
    
    // wait audio thread
	pthread_join(vorbisThread, NULL);

    // 1 seconde de garde pour le son,
    sleep(1);

    // tuer les deux threads videos si ils sont bloqués
	//if (bloqués){
		//pthread_cancel(theoraThread);
		//pthread_cancel(thread affichage);
	//}

    // attendre les 2 threads videos --> utiliser des moniteurs ?
	pthread_join(theoraThread, NULL);
	//pthread_join(thread affichage, NULL);
    
    exit(EXIT_SUCCESS);    
}
