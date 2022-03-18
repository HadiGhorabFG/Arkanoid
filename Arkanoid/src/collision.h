 #pragma once
#include "circle.h"

struct AABB
{
	float xMin;
	float xMax;
	float yMin;
	float yMax;
};

bool AABBIntersect(const AABB& a, const AABB& b);
bool AABBCircleIntersect(const AABB& a, const Circle& b);