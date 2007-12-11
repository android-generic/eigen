// This file is part of Eigen, a lightweight C++ template library
// for linear algebra. Eigen itself is part of the KDE project.
//
// Copyright (C) 2006-2007 Benoit Jacob <jacob@math.jussieu.fr>
//
// Eigen is free software; you can redistribute it and/or modify it under the
// terms of the GNU General Public License as published by the Free Software
// Foundation; either version 2 or (at your option) any later version.
//
// Eigen is distributed in the hope that it will be useful, but WITHOUT ANY
// WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
// FOR A PARTICULAR PURPOSE. See the GNU General Public License for more
// details.
//
// You should have received a copy of the GNU General Public License along
// with Eigen; if not, write to the Free Software Foundation, Inc., 51
// Franklin St, Fifth Floor, Boston, MA 02110-1301 USA.
//
// As a special exception, if other files instantiate templates or use macros
// or functions from this file, or you compile this file and link it
// with other works to produce a work based on this file, this file does not
// by itself cause the resulting work to be covered by the GNU General Public
// License. This exception does not invalidate any other reasons why a work
// based on this file might be covered by the GNU General Public License.

#ifndef EIGEN_UTIL_H
#define EIGEN_UTIL_H

#ifdef EIGEN_DONT_USE_UNROLLED_LOOPS
#define EIGEN_UNROLLED_LOOPS (false)
#else
#define EIGEN_UNROLLED_LOOPS (true)
#endif

#undef minor

#define USING_EIGEN_DATA_TYPES \
EIGEN_USING_MATRIX_TYPEDEFS \
using Eigen::Matrix;

#ifdef EIGEN_INTERNAL_DEBUGGING
#define EIGEN_ASSERT_LEVEL 2
#else
#define EIGEN_ASSERT_LEVEL 1
#endif

#define eigen_assert(assertLevel, x) if(assertLevel <= EIGEN_ASSERT_LEVEL) assert(x);

#ifdef NDEBUG
#define EIGEN_ONLY_USED_FOR_DEBUG(x) (void)x
#else
#define EIGEN_ONLY_USED_FOR_DEBUG(x)
#endif

#ifdef __GNUC__
# define EIGEN_ALWAYS_INLINE __attribute__((always_inline))
#else
# define EIGEN_ALWAYS_INLINE
#endif

#define EIGEN_INHERIT_ASSIGNMENT_OPERATOR(Derived, Op) \
template<typename OtherScalar, typename OtherDerived> \
Derived& operator Op(const MatrixBase<OtherScalar, OtherDerived>& other) \
{ \
  return MatrixBase<Scalar, Derived>::operator Op(other); \
} \
Derived& operator Op(const Derived& other) \
{ \
  return MatrixBase<Scalar, Derived>::operator Op(other); \
}

#define EIGEN_INHERIT_SCALAR_ASSIGNMENT_OPERATOR(Derived, Op) \
template<typename Other> \
Derived& operator Op(const Other& scalar) \
{ \
  return MatrixBase<Scalar, Derived>::operator Op(scalar); \
}

#define EIGEN_INHERIT_ASSIGNMENT_OPERATORS(Derived) \
EIGEN_INHERIT_ASSIGNMENT_OPERATOR(Derived, =) \
EIGEN_INHERIT_ASSIGNMENT_OPERATOR(Derived, +=) \
EIGEN_INHERIT_ASSIGNMENT_OPERATOR(Derived, -=) \
EIGEN_INHERIT_SCALAR_ASSIGNMENT_OPERATOR(Derived, *=) \
EIGEN_INHERIT_SCALAR_ASSIGNMENT_OPERATOR(Derived, /=)

//forward declarations
template<typename _Scalar, int _Rows, int _Cols> class Matrix;
template<typename MatrixType> class MatrixRef;
template<typename NewScalar, typename MatrixType> class Cast;
template<typename MatrixType> class Row;
template<typename MatrixType> class Column;
template<typename MatrixType> class Minor;
template<typename MatrixType> class DynBlock;
template<typename MatrixType, int BlockRows, int BlockCols> class Block;
template<typename MatrixType> class Transpose;
template<typename MatrixType> class Conjugate;
template<typename MatrixType> class Opposite;
template<typename Lhs, typename Rhs> class Sum;
template<typename Lhs, typename Rhs> class Difference;
template<typename Lhs, typename Rhs> class Product;
template<typename MatrixType> class ScalarMultiple;
template<typename MatrixType> class Random;
template<typename MatrixType> class Zero;
template<typename MatrixType> class Identity;
template<typename ExpressionType> class Eval;
template<typename MatrixType> class FromArray;

template<typename T> struct ForwardDecl
{
  typedef T Ref;
};

template<typename _Scalar, int _Rows, int _Cols>
struct ForwardDecl<Matrix<_Scalar, _Rows, _Cols> >
{
  typedef MatrixRef<Matrix<_Scalar, _Rows, _Cols> > Ref;
};

const int Dynamic = -1;

enum AssertLevel
{
  UserDebugging = 1,
  InternalDebugging = 2
};

#endif // EIGEN_UTIL_H
