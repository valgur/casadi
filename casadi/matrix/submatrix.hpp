/*
 *    This file is part of CasADi.
 *
 *    CasADi -- A symbolic framework for dynamic optimization.
 *    Copyright (C) 2010 by Joel Andersson, Moritz Diehl, K.U.Leuven. All rights reserved.
 *
 *    CasADi is free software; you can redistribute it and/or
 *    modify it under the terms of the GNU Lesser General Public
 *    License as published by the Free Software Foundation; either
 *    version 3 of the License, or (at your option) any later version.
 *
 *    CasADi is distributed in the hope that it will be useful,
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *    Lesser General Public License for more details.
 *
 *    You should have received a copy of the GNU Lesser General Public
 *    License along with CasADi; if not, write to the Free Software
 *    Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 *
 */

#ifndef SUBMATRIX_HPP
#define SUBMATRIX_HPP

namespace CasADi{


/** SubMatrix class for Matrix 
  SubMatrix is the return type for operator() of the Matrix class, it allows access to the value as well as changing the parent object
  \author Joel Andersson 
  \date 2011
*/

/// submatrix - move to a new file
template<typename M>
class SubMatrix : public M{
  public:
    /// Constructor
    SubMatrix(M& mat, const std::vector<int>& ii, const std::vector<int>& jj) : mat_(mat), ii_(ii), jj_(jj), M(mat.getSub(ii,jj)){}

    //@{
    /// Methods that modify a part of the parent obejct (A[i] = ?, A[i] += ?, etc.)
    M& operator=(const M &y) { mat_.setSub(ii_,jj_,y); return mat_;}
    M& operator+=(const M &y){ mat_.setSub(ii_,jj_,*this+y); return mat_;}
    M& operator-=(const M &y){ mat_.setSub(ii_,jj_,*this-y); return mat_;}
    M& operator*=(const M &y){ mat_.setSub(ii_,jj_,*this*y); return mat_;}
    M& operator/=(const M &y){ mat_.setSub(ii_,jj_,*this/y); return mat_;}
    //@}

  private:
    /// A reference to the matrix that is allowed to be modified
    M& mat_;
    
    /// The element of the matrix that is allowed to be modified
    std::vector<int> ii_, jj_;
};

// Implementation


} // namespace CasADi


#endif // SUBMATRIX_HPP
