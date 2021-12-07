#include "pch.h"
#include "MyUtils.h"

void DrawSquares(const int numberOfSquares, float pointX, float pointY, int sideLenght)
{
	SetColor(0.f, 0.f, 0.f);

	const int spaceBetweenLines{ sideLenght / (numberOfSquares * 2) };

	Point2f point{ pointX, pointY };
	Point2f point2{ pointX + sideLenght, pointY };

	for (int loopNumber{ 1 }; loopNumber <= numberOfSquares; ++loopNumber)
	{
		DrawLine(point, point2);

		point = point2;
		point2.y = pointY + sideLenght;

		DrawLine(point, point2);

		point = point2;
		point2.x = pointX;

		DrawLine(point, point2);

		point = point2;
		point2.y = pointY;

		DrawLine(point, point2);

		pointX += spaceBetweenLines;
		pointY += spaceBetweenLines;
		sideLenght -= 2 * spaceBetweenLines;

		point.x = pointX;
		point.y = pointY;

		point2.x = pointX + sideLenght;
		point2.y = pointY;
	}
}

void DrawSquares(int numberOfSquares, Point2f point1, int sideLenght)
{
	SetColor(0.f, 0.f, 0.f);

	const int spaceBetweenLines{ sideLenght / (numberOfSquares * 2) };

	Point2f point2{ point1.x + sideLenght, point1.y };

	for (int loopNumber{ 1 }; loopNumber <= numberOfSquares; ++loopNumber)
	{
		DrawLine(point1, point2);

		point1 = point2;
		point2.y = point1.y + sideLenght;

		DrawLine(point1, point2);

		point1 = point2;
		point2.x = point1.x;

		DrawLine(point1, point2);

		point1 = point2;
		point2.y = point1.y;

		DrawLine(point1, point2);

		point1.x += spaceBetweenLines;
		point1.y += spaceBetweenLines;
		sideLenght -= 2 * spaceBetweenLines;

		point1.x = point1.x;
		point1.y = point1.y;

		point2.x = point1.x + sideLenght;
		point2.y = point1.y;
	}
}

void DrawEquilateralTriangle(const float bottomLeftPointX, const float bottomLeftPointY, const float sideLenght, const bool filled, const Color4f color)
{
	const Point2f bottomLeftPoint{ bottomLeftPointX, bottomLeftPointY };
	const Point2f bottomRightPoint{ bottomLeftPointX + sideLenght, bottomLeftPointY };
	const Point2f topPoint{ bottomLeftPointX + sideLenght / 2, bottomLeftPointY + sqrtf(powf(sideLenght, 2) - powf(sideLenght / 2, 2)) };

	SetColor(color);

	if (filled)
	{
		FillTriangle(bottomLeftPoint, bottomRightPoint, topPoint);
	}
	else
	{
		DrawTriangle(bottomLeftPoint, bottomRightPoint, topPoint);
	}

}

void DrawEquilateralTriangle(const Point2f bottomLeftPoint, const float sideLenght, const bool filled, const Color4f color)
{
	const Point2f bottomRightPoint{ bottomLeftPoint.x + sideLenght, bottomLeftPoint.y };
	const Point2f topPoint{ bottomLeftPoint.x + sideLenght / 2, bottomLeftPoint.y + sqrtf(powf(sideLenght, 2) - powf(sideLenght / 2, 2)) };

	SetColor(color);

	if (filled)
	{
		FillTriangle(bottomLeftPoint, bottomRightPoint, topPoint);
	}
	else
	{
		DrawTriangle(bottomLeftPoint, bottomRightPoint, topPoint);
	}
}

void DrawPentagram(const float middlePointX, const float middlePointY, const float radius, const float lineWidth, const Color4f color)
{
	const float angle = { 1.25663706f };

	SetColor(color);

	DrawLine(middlePointX + radius * cosf(angle), middlePointY + radius * sinf(angle), middlePointX + radius * cosf(angle * 4), middlePointY + radius * sinf(angle * 4), lineWidth);
	DrawLine(middlePointX + radius * cosf(angle * 4), middlePointY + radius * sinf(angle * 4), middlePointX + radius * cosf(angle * 2), middlePointY + radius * sinf(angle * 2), lineWidth);
	DrawLine(middlePointX + radius * cosf(angle * 2), middlePointY + radius * sinf(angle * 2), middlePointX + radius, middlePointY, lineWidth);
	DrawLine(middlePointX + radius, middlePointY, middlePointX + radius * cosf(angle * 3), middlePointY + radius * sinf(angle * 3), lineWidth);
	DrawLine(middlePointX + radius * cosf(angle * 3), middlePointY + radius * sinf(angle * 3), middlePointX + radius * cosf(angle), middlePointY + radius * sinf(angle), lineWidth);
}

void DrawPentagram(const Point2f middlePoint, const float radius, float rotationAngle, const float lineWidth, const Color4f color)
{
	const float angle = { 1.25663706f };

	SetColor(color);

	DrawLine(middlePoint.x + radius * cosf(angle + rotationAngle), middlePoint.y + radius * sinf(angle + rotationAngle), middlePoint.x + radius * cosf(angle * 4 + rotationAngle), middlePoint.y + radius * sinf(angle * 4 + rotationAngle), lineWidth);
	DrawLine(middlePoint.x + radius * cosf(angle * 4 + rotationAngle), middlePoint.y + radius * sinf(angle * 4 + rotationAngle), middlePoint.x + radius * cosf(angle * 2 + rotationAngle), middlePoint.y + radius * sinf(angle * 2 + rotationAngle), lineWidth);
	DrawLine(middlePoint.x + radius * cosf(angle * 2 + rotationAngle), middlePoint.y + radius * sinf(angle * 2 + rotationAngle), middlePoint.x + radius * cosf(rotationAngle), middlePoint.y + radius * sinf(rotationAngle), lineWidth);
	DrawLine(middlePoint.x + radius * cosf(rotationAngle), middlePoint.y + radius * sinf(rotationAngle), middlePoint.x + radius * cosf(angle * 3 + rotationAngle), middlePoint.y + radius * sinf(angle * 3 + rotationAngle), lineWidth);
	DrawLine(middlePoint.x + radius * cosf(angle * 3 + rotationAngle), middlePoint.y + radius * sinf(angle * 3 + rotationAngle), middlePoint.x + radius * cosf(angle + rotationAngle), middlePoint.y + radius * sinf(angle + rotationAngle), lineWidth);
}

void DrawLinearGradient(const Rectf rectangle, Color4f startColor, Color4f endColor)
{
	const float rectangleWidth{ 1 };

	Color4f color1{ startColor };
	Color4f color2{ endColor };
	Color4f rectangleColor{ startColor };

	for (float rectangleLeft{ rectangle.left }; rectangleLeft <= rectangle.width; rectangleLeft += rectangleWidth)
	{
		SetColor(rectangleColor);

		FillRect(rectangleLeft, rectangle.bottom, rectangleWidth, rectangle.height);

		if (startColor.r > 0)
		{
			color1.r = (((rectangleLeft - rectangle.left) / rectangle.width) - 1.f) * (-1);
			rectangleColor.r = color1.r;
		}

		if (startColor.g > 0)
		{
			color1.g = (((rectangleLeft - rectangle.left) / rectangle.width) - 1.f) * (-1);
			rectangleColor.g = color1.g;
		}

		if (startColor.b > 0)
		{
			color1.b = (((rectangleLeft - rectangle.left) / rectangle.width) - 1.f) * (-1);
			rectangleColor.b = color1.b;
		}

		if (endColor.r > 0)
		{
			color2.r = ((rectangleLeft - rectangle.left) / rectangle.width);
			rectangleColor.r = color2.r;
		}

		if (endColor.g > 0)
		{
			color2.g = ((rectangleLeft - rectangle.left) / rectangle.width);
			rectangleColor.g = color2.g;
		}

		if (endColor.b > 0)
		{
			color2.b = ((rectangleLeft - rectangle.left) / rectangle.width);
			rectangleColor.b = color2.b;
		}
		rectangleColor.r = color1.r + color2.r;
		rectangleColor.g = color1.g + color2.g;
		rectangleColor.b = color1.b + color2.b;
	}
}

void DrawDotGrid(Point2f middlePointBottomLeftDot, float dotRadius, float spaceBetweenDots, int numberOfRows, int numberOfColumns, Color4f dotColor)
{
	Point2f middlePoint{ middlePointBottomLeftDot };

	SetColor(dotColor);

	for (int rowNumber{ 1 }; rowNumber <= numberOfColumns; ++rowNumber)
	{
		for (int columnNumber{ 1 }; columnNumber <= numberOfRows; ++columnNumber)
		{
			FillEllipse(middlePoint, dotRadius, dotRadius);

			middlePoint.y += dotRadius * 2 + spaceBetweenDots;
		}
		middlePoint.y = middlePointBottomLeftDot.y;
		middlePoint.x += dotRadius * 2 + spaceBetweenDots;
	}
}