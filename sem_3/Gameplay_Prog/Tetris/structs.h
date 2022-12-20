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
		}
	}
};

struct Matrix
{
	Matrix() = default;

	Matrix
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

	const Matrix& Transpose()
	{
		Matrix result{};

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
	}

	static Matrix Transpose(const Matrix& matrix)
	{
		Matrix result{};
		result.Transpose();

		return result;
	}

	static Matrix InverseRows(const Matrix& matrix)
	{
		Matrix result{};
		//row 1
		result[0][0] = matrix[0][3];
		result[0][1] = matrix[0][2];
		result[0][2] = matrix[0][1];
		result[0][3] = matrix[0][0];

		//row 2
		result[1][0] = matrix[1][3];
		result[1][1] = matrix[1][2];
		result[1][2] = matrix[1][1];
		result[1][3] = matrix[1][0];

		//row 3
		result[2][0] = matrix[2][3];
		result[2][1] = matrix[2][2];
		result[2][2] = matrix[2][1];
		result[2][3] = matrix[2][0];

		//row 4
		result[3][0] = matrix[3][3];
		result[3][1] = matrix[3][2];
		result[3][2] = matrix[3][1];
		result[3][3] = matrix[3][0];

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