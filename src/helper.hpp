
#pragma once

#include "defs.hpp"

// get nth bit 1-based index
// and goes from right to left
// eg 100 , 1st bit is 0 , 2nd bit is 0 and 3rd bit is 1
int getNthBitFromNumber(int_fast64_t num,int n);

// set nth bit to 1 (1-based index, start from n = 1)
void setNthBitFromNumber(int* num,int n);

// set nth bit to 0 (1-based index, start from n = 1)
void clearNthBitFromNumber(int* num,int n);

char pieceToChar(int piece);
int charToPiece(char ch);

std::vector<std::string> split_string(std::string string,std::string delimiter);

std::string sq64ToSqStr(int sq);
int sqStrToSq64(std::string sq);

int getPieceColor(int piece);
std::string combineFileRankStr(char file,char rank);

int getRankFromSq120(int sq120);

// from https://chess.stackexchange.com/questions/1482/how-do-you-know-when-a-fen-position-is-legal
// bool is_valid_fen(const std::string &fen);

// helper function for search
