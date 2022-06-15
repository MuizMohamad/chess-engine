#include "makemove.hpp"

void clearPiece(const int sq120, Board b){

    assert(checkInsideBoard(sq120));

    int piece = b.pieces[sq120];
    
    assert(checkPieceValid(piece));

    // color / side
    int color = getPieceColor(piece);
    
    int t_pieceNum = -1;

    b.position_key = hash_piece(b,piece,sq120);

    b.pieces[sq120] = EMPTY;
    b.piecesInSq64[Sq120_to_Sq64[sq120]] = EMPTY;
    
    // reduce material value of the side
    b.materialValue[color] -= pieceValue[piece];

    // one of the square in pieceList should be equal to sq120 (pieceExits)
    for (int index = 0; index < b.pieceNum[piece]; ++index){
        if(b.pieceList[piece][index] == sq120){
            t_pieceNum = index;
            break;
        }
    }

    assert(t_pieceNum != -1);

    b.pieceNum[piece]--;
    b.pieceList[piece][t_pieceNum] = b.pieceList[piece][b.pieceNum[piece]];
    b.pieceListInSq64[piece][t_pieceNum] = b.pieceListInSq64[piece][b.pieceNum[piece]];
}

void addPiece(const int sq120, Board b,int piece){

    assert(checkInsideBoard(sq120));
    assert(checkPieceValid(piece));

    int color = getPieceColor(piece);
    
    //int t_pieceNum = -1;

    b.position_key = hash_piece(b,piece,sq120);

    b.pieces[sq120] = piece;
    b.piecesInSq64[Sq120_to_Sq64[sq120]] = piece;
    
    // add material value to the side
    b.materialValue[color] += pieceValue[piece];

    b.pieceList[piece][b.pieceNum[piece]] = sq120;
    b.pieceListInSq64[piece][b.pieceNum[piece]] = Sq120_to_Sq64[sq120];
    b.pieceNum[piece]++;
}

void movePiece(const int from, const int to, Board b){

    assert(checkInsideBoard(from));
    assert(checkInsideBoard(to));

    int piece = b.pieces[from];
    int piece_color = getPieceColor(piece);

    int piece_exist_from = false;

    // unhash the piece from the position key
    b.position_key = hash_piece(b,piece,from);
    b.pieces[from] = EMPTY;

    // hash the new piece location to the position key
    b.position_key = hash_piece(b,piece,to);
    b.pieces[to] = piece;

    for (int index = 0 ; index < b.pieceNum[piece]; ++index){
        if (b.pieceList[piece][index] == from){
            b.pieceList[piece][index] = to;
            piece_exist_from = true;
        }
    }

    assert(piece_exist_from);
}