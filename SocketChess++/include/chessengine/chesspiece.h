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
#ifndef CHESSPIECE_H
#define CHESSPIECE_H

#include <set>

#include "piececolor.h"
#include "piecename.h"

namespace socketchess{

namespace chesspieces{

class chesspiece{
public:
    explicit chesspiece(const piececolor &_c, const piecename &_pn) noexcept : c(_c), pname(_pn){}
    virtual ~chesspiece() noexcept = default;
    chesspiece(const chesspiece&) = delete;
    chesspiece& operator=(const chesspiece&) = delete;

    // Inline getters
    [[nodiscard]] piecename get_name() const noexcept { return pname; }
    [[nodiscard]] piececolor get_color() const noexcept { return c; }

    // Inline setters
    void set_name(const piecename _pn) noexcept { pname = _pn; }
    void set_color(const piececolor _c) noexcept { c = _c; }

    // Member functions
    [[nodiscard]] virtual const bool move_to(const char &x1, const char &y1, const char &x2, const char &y2) const noexcept = 0;
    [[nodiscard]] virtual const std::set<std::pair<char,char>> verify_allowed_movements(chesspiece*, const char &x1, const char &y1) const noexcept = 0;

private:
    piecename pname; // Enum used to define piece name ( KING | QUEEN | ROOK |BISHOP | KNIGHT | PAWN )
    piececolor c; // Enum used to define piece color (BLACK | WHITE)
};

} // namespace chesspieces

} // namespace socketchess

#endif