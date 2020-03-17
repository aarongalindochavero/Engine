#include "GameObject.h"
#include "TextureManager.h"

GameObject::GameObject(const char* texturesheet, int x, int y)
{
	objTexture = TextureManager::LoadTexture(texturesheet);

	xpos = x;
	ypos = y;
}

GameObject::~GameObject()
{
}

void GameObject::update()
{
	xpos++;
	ypos++;

	srcRet.h = 32;
	srcRet.w = 32;
	srcRet.x = 0;
	srcRet.y = 0;

	destRect.x = xpos;
	destRect.y = ypos;
	destRect.w = srcRet.w * 2;
	destRect.h = srcRet.h * 2;

}

void GameObject::Render()
{
	SDL_RenderCopy(Game::renderer, objTexture, &srcRet, &destRect);
}
