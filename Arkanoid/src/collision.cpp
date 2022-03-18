#include "collision.h"
#include "engine.h"

bool AABBIntersect(const AABB& a, const AABB& b)
{
	return a.xMin < b.xMax && b.xMin < a.xMax && a.yMin < b.yMax && b.yMin < a.yMax;
}

bool AABBCircleIntersect(const AABB& a, const Circle& b)
{
	float clamped_x = clamp(b.posX, a.xMin, a.xMax);
	float clamped_y = clamp(b.posY, a.yMin, a.yMax);

	float dx = b.posX - clamped_x;
	float dy = b.posY - clamped_y;

	float dist_sqrd = dx * dx + dy * dy;
	float dist = sqrt(dist_sqrd);

	return dist < b.radius;
}