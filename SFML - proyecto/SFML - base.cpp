// Una plantilla para la creacion de programas con SFML
// Programacion I
// Tecnicatura Universitaria de Programacion
// Universidad Tecnológica Nacional
// Desarroladores: Antunez Agustin, Canclini Camilo

#include<SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include "personaje.h"
#include "enemigo.h"
#include "powerUps.h"
#include "vidas.h"
#include <ctime>
#include <stdlib.h>
using namespace sf; 
using namespace std;


int main()
{
	srand(time_t(NULL));


	//inicio de la ventana
	VideoMode vm(800, 600);
	RenderWindow ventana(vm, "Coppo in the Python's Den");
	ventana.setFramerateLimit(60);

	//Fuentes

	Font fuente;
	fuente.loadFromFile("Roboto.ttf");
	Text textVidas;
	textVidas.setFont(fuente);
	textVidas.setPosition({ 0,30 });
	textVidas.setScale(0.8f, 0.8f);
	
	Text puntaje;
	puntaje.setFont(fuente);
	puntaje.setPosition({ 0,5 });
	puntaje.setScale(0.8f, 0.8f);



	//Clases
	personaje Coppo;
	enemigo python;
	powerUps item;
	vidas vitalidad;
	int vida = 3;
	int puntos = 0;


	//imagen de fondo
	Sprite imagen;
	Texture txt_imagen;
	txt_imagen.loadFromFile("recursos/cueva.jpg");
	imagen.setTexture(txt_imagen);

	//Audio
	SoundBuffer buffer;
	buffer.loadFromFile("recursos/oof.wav");
	Sound dolor;
	dolor.setVolume(100.f);
	dolor.setBuffer(buffer);
	SoundBuffer buffer2;
	buffer2.loadFromFile("recursos/coin.wav");
	Sound punto;
	punto.setBuffer(buffer2);
	SoundBuffer buffer3;
	buffer3.loadFromFile("recursos/vamo.wav");
	Sound vidas;
	vidas.setBuffer(buffer3);


	//Inicio de reloj
	Clock clock;
	//GAME LOOP
	while (ventana.isOpen())
	{

		//Actualiza los estados de los perifericos de entrada
		Event cerrar;
		while (ventana.pollEvent(cerrar))
		{
			if (cerrar.type == Event::Closed or Keyboard::isKeyPressed(Keyboard::Escape))
				ventana.close(); //.close() es la funcion necesaria para cerrar la ventana
		}

		//Updates - actualiza los estados del juego
		vitalidad.update();
		python.update();
		Coppo.update();
		item.update();


		//Colisiones 
		Time elapsed = clock.getElapsedTime();
		int tiempo = elapsed.asSeconds();
		cout << tiempo << endl;


		if (Coppo.isCollision(item)) 
		{
			puntos++;
			punto.play();
			item.respawn();
		}

		if (Coppo.isCollision(vitalidad))
		{
			vida++;
			vidas.play();
			vitalidad.respawn();
		}

		if (Coppo.isCollision(python))
		{
			python.golpe();
			dolor.play();
			vida--;
			python.respawn();
			if (vida == 0)
			{
				break;
			}
		}

		textVidas.setString("Vidas:" + to_string(vida));
		puntaje.setString("Puntaje:" + to_string(puntos));
		ventana.clear();


		//Dibuja por la pantalla el objeto 

		ventana.draw(imagen);
		ventana.draw(Coppo);
		ventana.draw(python);
		ventana.draw(textVidas);
		ventana.draw(puntaje);
		ventana.draw(item);
		ventana.draw(vitalidad);
		
		//Display - Flip
		ventana.display();
	}

	//liberacion del juego

	return  0;
}


