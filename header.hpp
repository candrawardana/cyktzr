#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>
#include <iostream>
#include <utility>

using namespace sf;
RenderWindow window(VideoMode(1024, 640), "CYKTZR");
Event event;
CircleShape cursorPos(2);
float coortengahx(float x){
	return (1024-x)/2;
}

Vector2f responsif(Sprite periksa,float x, float y){
	float xxx = x/periksa.getLocalBounds().width;
	float yyy = y/periksa.getLocalBounds().height;
	if(xxx>yyy)
		return Vector2f(yyy,yyy);
	return Vector2f(xxx,xxx);
}

Vector2f pas(Sprite periksa,float x, float y){
	float xxx = x/periksa.getLocalBounds().width;
	float yyy = y/periksa.getLocalBounds().height;
	return Vector2f(xxx,yyy);
}
