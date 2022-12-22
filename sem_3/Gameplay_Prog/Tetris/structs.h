#include <cassert>

struct Vector3
{
	Vector3(float _x, float _y, float _z)
	{
		x = _x;
		y = _y;
		z = _z;
	}

	float x;
	float y;
	float z;

	float& operator[](int index)
	{
		switch (index)
		{
		case 0:
			return x;
			break;

		case 1:
			return y;
			break;

		case 2:
			return z;
			break;

		default:
			assert("invalid index used for operator[] with a Vector3\n");
			break;
		}
	}

	float operator[](int index) const
	{
		switch (index)
		{
		case 0:
			return x;
			break;

		case 1:
			return y;
			break;

		case 2:
			return z;
			break;

		default:
			assert("invalid index used for operator[] with a Vector3\n");
			break;
		}
	}
};

struct Vector4
{
	Vector4(float _x, float _y, float _z, float _w)
	{
		x = _x;
		y = _y;
		z = _z;
		w = _w;
	}

	float x;
	float y;
	float z;
	float w;

	float& operator[](int index)
	{
		switch (index)
		{
		case 0:
			return x;
			break;
			
		case 1:
			return y;
			break;

		case 2:
			return z;
			break;
			
		case 3:
			return w;
			break;

		default:
			assert("invalid index used for operator[] with a Vector 4\n");
			break;
		}
	}

	float operator[](int index) const
	{
		switch (index)
		{
		case 0:
			return x;
			break;

		case 1:
			return y;
			break;

		case 2:
			return z;
			break;

		case 3:
			return w;
			break;

		default:
			assert("invalid index used for operator[] with a Vector 4\n");
			break;
		}
	}
};

struct Matrix
{
	virtual const Matrix& Transpose() = 0;

	virtual const Matrix& InverseRows() = 0;

	virtual const Matrix& InverseCollumns() = 0;

	virtual const float GetValue(int rowIndex, int columnIndex) = 0;
};

struct Matrix4X4 : public Matrix
{
	Matrix4X4() = default;

	Matrix4X4
	(
		const Vector4& row1,
		const Vector4& row2,
		const Vector4& row3,
		const Vector4& row4
	)
	{
		data[0] = row1;
		data[1] = row2;
		data[2] = row3;
		data[3] = row4;
	}

	const Matrix4X4& Transpose()
	{
		Matrix4X4 result{};

		for (int rowNr{}; rowNr < 4; ++rowNr)
		{
			for (int colNr{}; colNr < 4; ++colNr)
			{
				result[rowNr][colNr] = data[colNr][rowNr];
			}
		}

		data[0] = result[0];
		data[1] = result[1];
		data[2] = result[2];
		data[3] = result[3];

		return *this;
	}

	const Matrix4X4& InverseRows()
	{
		Matrix4X4 result{};
		for (int rowIndex{}; rowIndex < 4; ++rowIndex)
		{
			for (int colIndex{}; colIndex < 4; ++colIndex)
			{
				result[rowIndex][colIndex] = data[rowIndex][3 - colIndex];
			}
		}

		data[0] = result[0];
		data[1] = result[1];
		data[2] = result[2];
		data[3] = result[3];

		return *this;
	}

	const Matrix4X4& InverseCollumns()
	{
		Matrix4X4 result{};
		for (int rowIndex{}; rowIndex < 4; ++rowIndex)
		{
			for (int colIndex{}; colIndex < 4; ++colIndex)
			{
				result[rowIndex][colIndex] = data[3 - rowIndex][colIndex];
			}
		}

		data[0] = result[0];
		data[1] = result[1];
		data[2] = result[2];
		data[3] = result[3];

		return *this;
	}

	const float GetValue(int rowIndex, int columnIndex)
	{
		return data[rowIndex][columnIndex];
	}

	static Matrix4X4 Transpose(const Matrix& matrix)
	{
		Matrix4X4 result{};
		result.Transpose();

		return result;
	}

	static Matrix4X4 InverseRows(const Matrix& matrix)
	{
		Matrix4X4 result{};
		result.InverseRows();

		return result;
	}

	Vector4 data[4]
	{
		{0, 0, 0, 0},
		{0, 0, 0, 0},
		{0, 0, 0, 0},
		{0, 0, 0, 0}
	};

	Vector4& operator[](int index)
	{
		return data[index];
	}

	Vector4 operator[](int index) const
	{
		return data[index];
	}
};

struct Matrix3X3 : public Matrix
{
	Matrix3X3() = default;

	Matrix3X3
	(
		const Vector3& row1,
		const Vector3& row2,
		const Vector3& row3
	)
	{
		data[0] = row1;
		data[1] = row2;
		data[2] = row3;
	}

	const Matrix3X3& Transpose()
	{
		Matrix3X3 result{};

		for (int rowNr{}; rowNr < 3; ++rowNr)
		{
			for (int colNr{}; colNr < 3; ++colNr)
			{
				result[rowNr][colNr] = data[colNr][rowNr];
			}
		}

		data[0] = result[0];
		data[1] = result[1];
		data[2] = result[2];

		return *this;
	}

	const Matrix3X3& InverseRows()
	{
		Matrix3X3 result{};
		for (int rowIndex{}; rowIndex < 3; ++rowIndex)
		{
			for (int colIndex{}; colIndex < 3; ++colIndex)
			{
				result[rowIndex][colIndex] = data[rowIndex][2 - colIndex];
			}
		}

		data[0] = result[0];
		data[1] = result[1];
		data[2] = result[2];

		return *this;
	}

	const Matrix3X3& InverseCollumns()
	{
		Matrix3X3 result{};
		for (int rowIndex{}; rowIndex < 3; ++rowIndex)
		{
			for (int colIndex{}; colIndex < 3; ++colIndex)
			{
				result[rowIndex][colIndex] = data[2 - rowIndex][colIndex];
			}
		}

		data[0] = result[0];
		data[1] = result[1];
		data[2] = result[2];

		return *this;
	}

	const float GetValue(int rowIndex, int columnIndex)
	{
		return data[rowIndex][columnIndex];
	}

	static Matrix3X3 Transpose(const Matrix& matrix)
	{
		Matrix3X3 result{};
		result.Transpose();

		return result;
	}

	static Matrix3X3 InverseRows(const Matrix& matrix)
	{
		Matrix3X3 result{};
		result.InverseRows();

		return result;
	}

	Vector3 data[3]
	{
		{0, 0, 0},
		{0, 0, 0},
		{0, 0, 0}
	};

	Vector3& operator[](int index)
	{
		return data[index];
	}

	Vector3 operator[](int index) const
	{
		return data[index];
	}
};