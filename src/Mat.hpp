#include <array>

template<class T, size_t ROWS, size_t COLS>
struct Mat
{
	static constexpr size_t N_ELEM = ROWS * COLS;

	template<class... Args>
	Mat(Args... data) :
		data{data...}
	{
	}

	T& operator()(size_t i, size_t j)
	{
		return data[i * COLS + j];
	}

	const T& operator()(size_t i, size_t j) const
	{
		return data[i * COLS + j];
	}

	template<size_t OTHER_COLS>
	Mat<T, ROWS, OTHER_COLS> operator*(const Mat<T, COLS, OTHER_COLS>& other)
	{
		Mat<T, ROWS, OTHER_COLS> ret;

		for (size_t row = 0; row != ROWS; row++)
			for (size_t col = 0; col != OTHER_COLS; col++)
			{
				auto& elem = ret(row, col) = 0;
				for (size_t k = 0; k != COLS; k++)
					elem += (*this)(row, k) * other(k, col);
			}
		return ret;
	}

	bool operator==(const Mat& other) const
	{
		for (size_t i = 0; i != N_ELEM; i++)
			if (data[i] != other.data[i])
				return false;
		return true;
	}

	bool operator!=(const Mat& other) const
	{
		return !(*this == other);
	}

	T data[N_ELEM];
};