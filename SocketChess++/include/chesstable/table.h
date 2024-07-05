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
#ifndef TABLE_H
#define TABLE_H

#include <memory>

#include "../chessengine/piececolor.h"
#include "../chessengine/chesspiece.h"
#include "../chessengine/piecename.h"

namespace socketchess{

class chesstable{
public:
    explicit chesstable() noexcept;
    virtual ~chesstable() = default;
    [[nodiscard]] chesspieces::chesspiece* get_piece(const int &x, const int &y) const noexcept { return board[x][y].get(); } /// Inline
    void instance_new_table() noexcept;
    std::string enum_to_string(chesspieces::piecename name); 
private:
    std::unique_ptr<chesspieces::chesspiece> board[8][8];
};

} // END OF NAMESPACE socketchess


#endif