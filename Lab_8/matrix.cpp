#include <algorithm>

struct Matrix
{
    int** data_ = nullptr;
    size_t n_ = 0u;
    size_t m_ = 0u;
};

void Destruct(Matrix& in) //удаление
{
    if (in.data_ != nullptr)
    {
        for (size_t i = 0; i < in.m_; ++i)
        {
            delete[] in.data_[i];
        }
        delete[] in.data_;
        in.data_ = nullptr;
    }
    in.n_ = 0;
    in.m_ = 0;
}

void Construct(Matrix& out, size_t n, size_t m) //создание матрицы
{
    Destruct(out);

    out.n_ = n;
    out.m_ = m;

    if (n > 0 && m > 0)
    {
        out.data_ = new int*[m];
        for (size_t i = 0; i < m; ++i)
        {
            out.data_[i] = new int[n]();
        }
    }
}

Matrix Copy(const Matrix& matrix) //копирование
{
    Matrix result;
    Construct(result, matrix.n_, matrix.m_);

    for (size_t i = 0; i < matrix.m_; ++i)
    {
        for (size_t j = 0; j < matrix.n_; ++j)
        {
            result.data_[i][j] = matrix.data_[i][j];
        }
    }

    return result;
}

Matrix Add(const Matrix& a, const Matrix& b) //сложение
{
    if (a.n_ != b.n_ || a.m_ != b.m_)
    {
        return Matrix{};
    }

    Matrix result;
    Construct(result, a.n_, a.m_);

    for (size_t i = 0; i < a.m_; ++i)
    {
        for (size_t j = 0; j < a.n_; ++j)
        {
            result.data_[i][j] = a.data_[i][j] + b.data_[i][j];
        }
    }

    return result;
}

Matrix Sub(const Matrix& a, const Matrix& b) //вычитание
{
    if (a.n_ != b.n_ || a.m_ != b.m_)
    {
        return Matrix{};
    }

    Matrix result;
    Construct(result, a.n_, a.m_);

    for (size_t i = 0; i < a.m_; ++i)
    {
        for (size_t j = 0; j < a.n_; ++j)
        {
            result.data_[i][j] = a.data_[i][j] - b.data_[i][j];
        }
    }

    return result;
}

Matrix Mult(const Matrix& a, const Matrix& b) //умножение
{
    if (a.n_ != b.m_)
    {
        return Matrix{};
    }

    Matrix result;
    Construct(result, b.n_, a.m_);

    for (size_t i = 0; i < a.m_; ++i)
    {
        for (size_t j = 0; j < b.n_; ++j)
        {
            result.data_[i][j] = 0;
            for (size_t k = 0; k < a.n_; ++k)
            {
                result.data_[i][j] += a.data_[i][k] * b.data_[k][j];
            }
        }
    }

    return result;
}

void Transposition(Matrix& matrix) //транспонирование
{
    if (matrix.data_ == nullptr || matrix.n_ == 0 || matrix.m_ == 0)
    {
        return;
    }

    Matrix temp;
    Construct(temp, matrix.m_, matrix.n_);

    for (size_t i = 0; i < matrix.m_; ++i)
    {
        for (size_t j = 0; j < matrix.n_; ++j)
        {
            temp.data_[j][i] = matrix.data_[i][j];
        }
    }

    Destruct(matrix);
    matrix = temp;
}

bool operator==(const Matrix& a, const Matrix& b) //сравнение
{
    if (a.n_ != b.n_ || a.m_ != b.m_)
    {
        return false;
    }

    for (size_t i = 0; i < a.m_; ++i)
    {
        for (size_t j = 0; j < a.n_; ++j)
        {
            if (a.data_[i][j] != b.data_[i][j])
            {
                return false;
            }
        }
    }

    return true;
}