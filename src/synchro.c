#include "synchro.h"
#include "ensitheora.h"
#include <pthread.h>
#include <semaphore.h>


bool fini;

/* les variables pour la synchro, ici */
sem_t cases_vides, cases_pleines;
pthread_mutex_t m_cons, m_dep;

/*	Initialisation ?
pthread_mutex_init(&m_cons, NULL);
pthread_mutex_init(&m_dep, NULL);
sem_init(&cases_vides, 1, NBTEX);
sem_init(&cases_pleines, 1, 0);
*/


/* l'implantation des fonctions de synchro ici */
void envoiTailleFenetre(th_ycbcr_buffer buffer) {
}

void attendreTailleFenetre() {
}

void signalerFenetreEtTexturePrete() {
}

void attendreFenetreTexture() {
}

void debutConsommerTexture() {
	sem_wait(&cases_pleines);
	pthread_mutex_lock(m_cons);
}

void finConsommerTexture() {
	pthread_mutex_unlock(m_cons);
	sem_post(&cases_vides);
}


void debutDeposerTexture() {
	sem_wait(&cases_vides);
	pthread_mutex_lock(m_dep);
}

void finDeposerTexture() {
	pthread_mutex_unlock(m_dep);
	sem_post(&cases_pleines);
}
