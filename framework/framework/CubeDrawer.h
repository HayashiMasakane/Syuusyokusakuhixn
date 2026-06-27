#pragma once
#include "CommonTypes.h"

void BoxDrawerInit();
void BoxDrawerDraw(
	float width, float height, float depth,
	Color col, float posx, float posy, float posz);
void BoxDrawerDraw(Matrix4x4 _mtx, Color _col);

