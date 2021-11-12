
#pragma once

// includes
#include <iostream>
#include <vector>
#include <array>
#include <string>
#include <cstring>
#include <sstream>
#include <cassert>
#include <math.h>

// Typedef for short form
typedef unsigned long long U64;

// constant size
const int BOARD_SQ_NUM = 120;

// enum
enum { EMPTY = 0, wP , wN , wB , wR , wQ , wK , bP , bN , bB , bR , bQ , bK };
enum { FILE_A = 1 , FILE_B , FILE_C , FILE_D , FILE_E , FILE_F , FILE_G , FILE_H  };
enum { RANK_1 = 1 , RANK_2 , RANK_3 , RANK_4 , RANK_5 , RANK_6 , RANK_7 , RANK_8  };
enum { WHITE , BLACK , BOTH };
enum { FALSE , TRUE };

enum {
    A1 = 21  , B1 , C1 , D1 , E1 , F1 , G1 , H1 ,
    A2 = 31  , B2 , C2 , D2 , E2 , F2 , G2 , H2 ,
    A3 = 41 , B3 , C3 , D3 , E3 , F3 , G3 , H3 ,
    A4 = 51 , B4 , C4 , D4 , E4 , F4 , G4 , H4 ,
    A5 = 61 , B5 , C5 , D5 , E5 , F5 , G5 , H5 ,
    A6 = 71 , B6 , C6 , D6 , E6 , F6 , G6 , H6 ,
    A7 = 81 , B7 , C7 , D7 , E7 , F7 , G7 , H7 ,
    A8 = 91 , B8 , C8 , D8 , E8 , F8 , G8 , H8 , NO_SQ
};


// constant starting square of pieces in sq120

const std::array<int,8> wPawnStart = {A2,B2,C2,D2,E2,F2,G2,H2};
const std::array<int,8> bPawnStart = {A7,B7,C7,D7,E7,F7,G7,H7};

const std::array<int,2> wKnightStart = {B1,G1};
const std::array<int,2> bKnightStart = {B8,G8};

const std::array<int,2> wBishopStart = {C1,F1};
const std::array<int,2> bBishopStart = {C8,F8};

const std::array<int,2> wRookStart = {A1,H1};
const std::array<int,2> bRookStart = {A8,H8};

const std::array<int,1> wQueenStart = {D1};
const std::array<int,1> bQueenStart = {D8};

const std::array<int,1> wKingStart = {E1};
const std::array<int,1> bKingStart = {E8};

// direction for 64-based squares
const std::array<int,4> diagonal_direction = { +9, -9, +11, -11};
const std::array<int,4> horizontal_direction = {-1, -10, 1, 10};
const std::array<int,8> knight_direction = {-8, -19, -21, -12, 8, 19, 21, 12};
const std::array<int,8> king_direction = { -1, 1, -10, 10, -9, 9, -11, 11};

const std::array<int,1> w_pawn_moves_direction = {};
const std::array<int,1> b_pawn_moves_direction = {};
const std::array<int,2> w_pawn_atk_direction = {-11,-9};
const std::array<int,2> b_pawn_atk_direction = {+11,+9};

// extern for init.h
// direct convert between sq64 with sq120 with array
extern std::array<int,BOARD_SQ_NUM+1> Sq120_to_Sq64;
extern std::array<int,65> Sq64_to_Sq120;

