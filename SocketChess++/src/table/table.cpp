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

#include <iostream>
#include "../../include/chesstable/table.h"
#include "../../include/chessengine/pawn.h"
#include "../../include/chessengine/rook.h"
#include "../../include/chessengine/queen.h"
#include "../../include/chessengine/king.h"
#include "../../include/chessengine/bishop.h"
#include "../../include/chessengine/knight.h"
#include "../../include/chessengine/nullpiece.h"
#include "../../include/chessengine/piecename.h"

namespace socketchess{

chesstable::chesstable() noexcept{}
void chesstable::instance_new_table() noexcept{
    //------------------------------WHITE PIECES -------------------------------------//
    //board[0][0]=std::make_unique<chesspieces::rook>(chesspieces::piececolor::WHITE);
    //board[0][1]=std::make_unique<chesspieces::knight>(chesspieces::piececolor::WHITE);
    //board[0][2]=std::make_unique<chesspieces::bishop>(chesspieces::piececolor::WHITE);
    //board[0][3]=std::make_unique<chesspieces::king>(chesspieces::piececolor::WHITE);
    //board[0][4]=std::make_unique<chesspieces::queen>(chesspieces::piececolor::WHITE);
    //board[0][5]=std::make_unique<chesspieces::bishop>(chesspieces::piececolor::WHITE);
    //board[0][6]=std::make_unique<chesspieces::knight>(chesspieces::piececolor::WHITE);
    //board[0][7]=std::make_unique<chesspieces::rook>(chesspieces::piececolor::WHITE);
    board[1][0]=std::make_unique<chesspieces::pawn>(chesspieces::piececolor::WHITE);
    board[1][1]=std::make_unique<chesspieces::pawn>(chesspieces::piececolor::WHITE);
    board[1][2]=std::make_unique<chesspieces::pawn>(chesspieces::piececolor::WHITE);
    board[1][3]=std::make_unique<chesspieces::pawn>(chesspieces::piececolor::WHITE);
    board[1][4]=std::make_unique<chesspieces::pawn>(chesspieces::piececolor::WHITE);
    board[1][5]=std::make_unique<chesspieces::pawn>(chesspieces::piececolor::WHITE);
    board[1][6]=std::make_unique<chesspieces::pawn>(chesspieces::piececolor::WHITE);
    board[1][7]=std::make_unique<chesspieces::pawn>(chesspieces::piececolor::WHITE);
    //----------------------------END OF WHITE PIECES --------------------------------//
    //------------------------------BLACK PIECES -------------------------------------//
    //board[7][0]=std::make_unique<chesspieces::rook>(chesspieces::piececolor::BLACK);
    //board[7][1]=std::make_unique<chesspieces::knight>(chesspieces::piececolor::BLACK);
    //board[7][2]=std::make_unique<chesspieces::bishop>(chesspieces::piececolor::BLACK);
    //board[7][3]=std::make_unique<chesspieces::king>(chesspieces::piececolor::BLACK);
    //board[7][4]=std::make_unique<chesspieces::queen>(chesspieces::piececolor::BLACK);
    //board[7][5]=std::make_unique<chesspieces::bishop>(chesspieces::piececolor::BLACK);
    //board[7][6]=std::make_unique<chesspieces::knight>(chesspieces::piececolor::BLACK);
    //board[7][7]=std::make_unique<chesspieces::rook>(chesspieces::piececolor::BLACK);
    board[6][0]=std::make_unique<chesspieces::pawn>(chesspieces::piececolor::BLACK);
    board[6][1]=std::make_unique<chesspieces::pawn>(chesspieces::piececolor::BLACK);
    board[6][2]=std::make_unique<chesspieces::pawn>(chesspieces::piececolor::BLACK);
    board[6][3]=std::make_unique<chesspieces::pawn>(chesspieces::piececolor::BLACK);
    board[6][4]=std::make_unique<chesspieces::pawn>(chesspieces::piececolor::BLACK);
    board[6][5]=std::make_unique<chesspieces::pawn>(chesspieces::piececolor::BLACK);
    board[6][6]=std::make_unique<chesspieces::pawn>(chesspieces::piececolor::BLACK);
    board[6][7]=std::make_unique<chesspieces::pawn>(chesspieces::piececolor::BLACK);
    //----------------------------END OF BLACK PIECES --------------------------------//
    //-----------------------------INSTANCE OF NULL SPACES ----------------------------//
    for(int i=3; i<6; i++)
        for(int j=0; j<=7; j++)
            board[i][j]=std::make_unique<chesspieces::pawn>(chesspieces::piececolor::BLACK);
    std::cout << "\n\n IMPRESSAO DO TABULEIRO\n\n";
    int counter = 0; // FOR DEBUG
    for(int i=0; i<=7; i++){
        for(int j=0; j<=7; j++){
            counter++;
            std::cout << " cheguei " << counter << " vezes.\n"; // FOR DEBUG
            std::cout << teste_impressao( board[i][j]->get_name()) << " ";
        }
        std::cout << "\n";
    }

}
std::string chesstable::teste_impressao(chesspieces::piecename name){
    switch (name) {
        case chesspieces::piecename::KING: return "KING";
        case chesspieces::piecename::QUEEN: return "QUEEN";
        case chesspieces::piecename::ROOK: return "ROOK";
        case chesspieces::piecename::BISHOP: return "BISHOP";
        case chesspieces::piecename::KNIGHT: return "KNIGHT";
        case chesspieces::piecename::PAWN: return "PAWN";
        default: return "UNKNOWN";
    }
}

} // namespace socketchess
