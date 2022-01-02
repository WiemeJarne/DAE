#pragma once
#include "structs.h"
#include <vector>

namespace utils
{

	const float g_Pi{ 3.1415926535f };

#pragma region OpenGLDrawFunctionality
	void ClearBackground(float r, float g, float b);
	void ClearBackground();
	// Choose a floating point value for each color component between 0.0f and 1.0f. The a (alpha) is optional.
	// Usage: SetColor(1.0f, 0.0f, 0.0f); set the drawing color to red
	void SetColor(float r, float g, float b, float a = 1);
	// Pass a Color4f object to the function
	void SetColor(const Color4f& color);

	// Draws a line by connecting the two points specified by (x1,y1) and (x2,y2)
	void DrawLine(float x1, float y1, float x2, float y2, float lineWidth = 1.0f);
	// Draws a line by connecting the two points specified by p1 and p1
	void DrawLine(const Point2f& p1, const Point2f& p2, float lineWidth = 1.0f);

	void DrawTriangle(const Point2f& p1, const Point2f& p2, const Point2f& p3, float lineWidth = 1);
	void FillTriangle(const Point2f& p1, const Point2f& p2, const Point2f& p3);
	void DrawRect(float left, float bottom, float width, float height, float lineWidth = 1.0f);
	void DrawRect(const Point2f& bottomLeft, float width, float height, float lineWidth = 1.0f);
	void DrawRect(const Rectf& rect, float lineWidth = 1.0f);
	void FillRect(float left, float bottom, float width, float height);
	void FillRect(const Point2f& bottomLeft, float width, float height);
	void FillRect(const Rectf& rect);

	void DrawCircle(const Circlef& circle, float lineWidth = 1.0f);
	void DrawEllipse(float centerX, float centerY, float radX, float radY, float lineWidth = 1.0f);
	void DrawEllipse(const Point2f& center, float radX, float radY, float lineWidth = 1.0f);
	void DrawEllipse(const Ellipsef& ellipse, float lineWidth = 1.0f);
	void FillCircle(const Circlef& circle);
	void FillEllipse(float centerX, float centerY, float radX, float radY);
	void FillEllipse(const Ellipsef& ellipse);
	void FillEllipse(const Point2f& center, float radX, float radY);

	// Draws an arc. The angle parameters are in radians, not in degrees.
	void DrawArc(float centerX, float centerY, float radX, float radY, float fromAngle, float tillAngle, float lineWidth = 1.0f);
	// Draws an arc. The angle parameters are in radians, not in degrees.
	void DrawArc(const Point2f& center, float radX, float radY, float fromAngle, float tillAngle, float lineWidth = 1.0f);
	// Fills an arc. The angle parameters are in radians, not in degrees.
	void FillArc(float centerX, float centerY, float radX, float radY, float fromAngle, float tillAngle);
	// Fills an arc. The angle parameters are in radians, not in degrees.
	void FillArc(const Point2f& center, float radX, float radY, float fromAngle, float tillAngle);

	void DrawPolygon(const std::vector<Point2f>& vertices, bool closed = true, float lineWidth = 1.0f);
	void DrawPolygon(const Point2f* pVertices, size_t nrVertices, bool closed = true, float lineWidth = 1.0f);
	void FillPolygon(const std::vector<Point2f>& vertices);
	void FillPolygon(const Point2f* pVertices, size_t nrVertices);

	void DrawVector(Vector2f& vector, Point2f startingPoint = Point2f{ 0, 0 });

#pragma endregion OpenGLDrawFunctionality

#pragma region TextureFunctionality

	struct Texture
	{
		GLuint id;
		float width;
		float height;
	};
	bool TextureFromFile(const std::string& path, Texture& texture);
	bool TextureFromString(const std::string& text, TTF_Font* pFont, const Color4f& textColor, Texture& texture);
	bool TextureFromString(const std::string& text, const std::string& fontPath, int ptSize, const Color4f& textColor, Texture& texture);
	void TextureFromSurface(const SDL_Surface* pSurface, Texture& textureData);
	void DrawTexture(const Texture& texture, const Point2f& dstBottomLeft, const Rectf& srcRect = {});
	void DrawTexture(const Texture& texture, const Rectf& dstRect, const Rectf& srcRect = {});
	void DeleteTexture(Texture& texture);
#pragma endregion TextureFunctionality

#pragma region CollisionFunctionality

	float GetDistance(const Point2f& rPointA, const Point2f& rPointB);
	float GetDistance(float pointAX, float pointAY, float pointBX, float pointBY);

	bool IsPointInCircle(const Circlef& rCircle, const Point2f& rPoint);
	bool IsPointInRectangle(const Rectf& rRectangle, const Point2f& rPoint);

	bool IsOverlapping(const Rectf& rRectangleA, const Rectf& rRectangleB);
	bool IsOverlapping(const Circlef& rCircleA, const Circlef& rCircleB);

	bool IsIntersecting(const Circlef& rCircle, const Rectf& rRectangle);

	Point2f GetCenterRectangle(const Rectf& rRectangle);

#pragma endregion CollisionFunctionality

#pragma region VectorFunctionality

	Vector2f Add(Vector2f& rVectorA, Vector2f& rVectorB);
	Vector2f Subtract(Vector2f& rVectorA, Vector2f& rVectorB);
	float DotProduct(Vector2f& rVectorA, Vector2f& rVectorB);
	float CrossProduct(Vector2f& rVectorA, Vector2f& rVectorB);
	std::string ToString(Vector2f& rVector);
	Vector2f Scale(Vector2f& rVector, float scale);
	float Length(Vector2f& rVector);
	Vector2f Normalise(Vector2f& rVector);
	float AngleBetween(Vector2f& rVectorA, Vector2f& rVectorB);
	bool IsEqual(Vector2f& rVectorA, Vector2f& rVectorB);

#pragma endregion VectorFunctionality

#pragma region GeneralUtils

	Point2f GetMiddle(const Point2f& RPointA, const Point2f& pointB);
	float ConvertDegreesToRadians(float degrees);
	float ConvertRadiansToDegrees(float radians);
	Point2f GetCoordinates(float radius, float radians, Point2f startLocation = Point2f{ 0.0f, 0.0f });
	Vector2f GetVectorToDirectionWithForce(float angle, float force);
	Color4f GetRandomColor();
	float GetRandomNr(int min, int max);
	int GetGridIndex(int rowIndex, int columnIndex, int nrOfColumns);
	int GetGridIndex(IndexGrid index, int nrOfColumns);

#pragma endregion GeneralUtils
}