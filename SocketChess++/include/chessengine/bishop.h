/**
 * MIT License
 * 
 * Copyright (c) 2024 Guilherme Martinelli Taglietti
 *                    Dalton Oberdan Adiers
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */
#ifndef BISHOP_H
#define BISHOP_H

#include <set>

#include "chesspiece.h"

namespace socketchess{

namespace chesspieces{

class bishop : public chesspiece{
public:
    explicit bishop(const piececolor &_c) : chesspiece(_c, piecename::BISHOP){}

    // Overriding "chesspiece" class virtual member function
    [[nodiscard]] const bool move_to(const char &x1, const char &y1, const char &x2, const char &y2) const noexcept override;
    [[nodiscard]] const std::set<std::pair<char,char>> verify_allowed_movements(chesspiece*, const char &x1, const char &y1) const noexcept override;
};


} // namespace chesspieces

} // namespace socketchess

#endif
