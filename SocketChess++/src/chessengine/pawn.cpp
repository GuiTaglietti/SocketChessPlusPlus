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

#include "../../include/chessengine/pawn.h"
#include "../../include/chessengine/piececolor.h"
#include "../../include/chesstable/table.h"

namespace socketchess{

[[nodiscard]] const std::set<std::pair<char,char>> chesspieces::pawn::verify_allowed_movements(chesspiece* piece, const char &x1, const char &y1) const noexcept {
    std::set<std::pair<char,char>> allowed_movements;
    short int posI = x1 - 97, posJ = y1 - 49, move = 1;
    if(piece->get_color() == piececolor::BLACK)
        move *= -1;
    short int front_move = posI + move;
    if(front_move < 8 && front_move > 0 && 1) // && 1 --> Verificar se a casa da frente está vazia (Em caso de first move, verificar se as duas da frente estão)
        allowed_movements.insert({front_move + 97, posJ});
    return allowed_movements;
}
 [[nodiscard]] const bool chesspieces::pawn::move_to(const char &x1, const char &y1, const char &x2, const char &y2) const noexcept{
    return true;
 }


} // namespace socketchess