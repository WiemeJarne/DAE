#pragma once
#include "utils.h"
using namespace utils;

void DrawSquares(const int numberOfSquares, float pointX, float pointY, int sideLenght);
void DrawSquares(int numberOfSquares, Point2f point2, int sideLenght);

void DrawEquilateralTriangle(const float bottomLeftPointX, const float bottomLeftPointY, const float sideLenght, const bool filled, const Color4f color);
void DrawEquilateralTriangle(const Point2f bottomLeftPoint, const float sideLenght, const bool filled, const Color4f color);

void DrawPentagram(const float middlePointX, const float middlePointY, const float radius, const float lineWidth, const Color4f color);
void DrawPentagram(const Point2f middlePoint, const float radius, const float lineWidth, const Color4f color);

void DrawLinearGradient(const Rectf rectangle, Color4f startColor, Color4f endColor);

void DrawDotGrid(Point2f positionBottomLeftDot, float dotRadius, float spaceBetweenDots, int numberOfRows, int numberOfColumns, Color4f dotColor);