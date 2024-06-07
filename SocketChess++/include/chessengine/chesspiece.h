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

#include "piececolor.h"

namespace socketchess{

namespace chesspieces{

class chesspiece{
public:
    explicit chesspiece(const int _x, const int _y, const piececolor &_c) noexcept : x(_x), y(_y), c(_c){}
    virtual ~chesspiece() noexcept = default;
    chesspiece(const chesspiece&) = delete;
    chesspiece& operator=(const chesspiece&) = delete;

    // Inline getters
    [[nodiscard]] int get_x() const noexcept { return x; }
    [[nodiscard]] int get_y() const noexcept { return y; }
    [[nodiscard]] piececolor get_color() const noexcept { return c; }

    // Inline setters
    void set_x(int _x) noexcept { x = _x; }
    void set_y(int _y) noexcept { y = _y; }
    void set_color(const piececolor _c) noexcept { c = _c; }

    // Member functions
    [[nodiscard]] virtual const bool move_to(const int _x, const int _y) const noexcept = 0;


private:
    int x, y;
    piececolor c; // Enum used to define piece color (BLACK | WHITE)
};

} // namespace chesspieces

} // namespace socketchess

#endif