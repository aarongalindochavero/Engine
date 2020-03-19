#pragma once
#include "Components.h"
#include "Vector2D.h"

class TransformComponent :public Component {
public:
	Vector2D position;
	Vector2D velocity;

	int height = 32;
	int width = 32;
	int scale = 1;

	int speed = 3;

	TransformComponent() {
		position.Zero();
	}

	TransformComponent(int sc) {
		position.Zero();
		scale = sc;
	}

	TransformComponent(float x, float y) {
		position.x = x;
		position.y = y;
	}

	TransformComponent(float x, float y, int h, int w, int sc) {
		position.x = x;
		position.y = y;
		height = h;
		width = w;
		scale = sc;
	}

	void init() override {
		velocity.x = 0;
		velocity.y = 0;
	}

	void update() override {
		position.x += velocity.x * speed;
		position.y += velocity.y * speed;
	}

	/*int x() { return xpos; }
	int x(int x) { xpos = x; }
	int y() { return ypos; }
	int y(int y) { ypos = y; }
	void setPos(int x, int y) {	xpos = x; ypos = y; }*/
};
