#ifndef __ZERO_STATIC_MATRIX_H__
#define __ZERO_STATIC_MATRIX_H__

#include <memory>
#include <vector>
#include <stdint.h>

namespace Zero
{
    template<class T>
    class StaticMatrixRow; // forward declaration

    template <class T>
    class StaticMatrix
    {
    public:
        StaticMatrix(size_t rows, size_t columns)
        {
            this->resize(rows, columns);
        }

        StaticMatrixRow<T> &operator[](size_t row)
        {
            StaticMatrixRow<T> ret(&this->_internal, row, this->_columns);
            return ret;
        }

        void push(size_t row, size_t col, T val)
        {
            size_t position = row * this->_columns + col;
            this->_internal[position] = val;
        }

        void resize(size_t rows, size_t columns)
        {
            this->_rows = rows;
            this->_columns = columns;
            this->_internal.resize(rows * columns);
        }

        inline size_t size() const { return this->_internal.size(); }
        inline size_t max_size() const { return this->_internal.max_size(); }
        inline size_t capacity() const { return this->_internal.capacity(); }

        inline typename std::vector<T>::const_iterator begin() const { return this->_internal.begin(); }
        inline typename std::vector<T>::const_iterator end() const { return this->_internal.end(); }
        inline typename std::vector<T>::iterator erase(typename std::vector<T>::iterator position) { return this->_internal.erase(position); }
        inline typename std::vector<T>::iterator erase(typename std::vector<T>::iterator first, typename std::vector<T>::iterator last) { return this->_internal.erase(first, last); }

        inline void clear() { this->_internal.clear(); }

    private:
        std::vector<T> _internal;

        size_t _rows;
        size_t _columns;
    };

    template<class T>
    class StaticMatrixRow
    {
        friend class StaticMatrix<T>;

    public:
        T &operator[](size_t column)
        {
            size_t position = this->_row * this->_columns + column;
            return (*this->_internal)[position];
        }

    protected:
        StaticMatrixRow(std::vector<T>* other, size_t row, size_t total_columns)
        {
            this->_internal = other;
            this->_row = row;
            this->_columns = total_columns;
        }

    private:
        std::vector<T>* _internal;
        size_t _row;
        size_t _columns;
    };


} // namespace Zero

#endif

