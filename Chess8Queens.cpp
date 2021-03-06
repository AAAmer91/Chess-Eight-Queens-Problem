// Chess8Queens.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

void prohibitSquare(char [8][8],int ,int);
void findNext(char[8][8], int*, int* ,int ,int);
void printBoard(char[8][8]);

char chessBoard[8][8];
int queensNum;

int main()
{
	int initialRow;
	int initialColumn;
	int counter = 0;
	int solutionNum = 0;
	
	for (int disp1 = 0; disp1 < 16; disp1++) {
		for (int disp2 = 0; disp2 < 16; disp2++) {
			int row = 0;
			int col = 0;
			int* prow = &row;
			int* pcol = &col;
			initialRow = 0;
			initialColumn = 0;
			while (initialRow < 8) {

				for (int i = 0; i < 8; i++)
					for (int j = 0; j < 8; j++)
						chessBoard[i][j] = '0';

				chessBoard[initialRow][initialColumn] = 'M';
				queensNum++;
				prohibitSquare(chessBoard, initialRow, initialColumn);

				for (int N = 0; N < 8; N++) {

					findNext(chessBoard, prow, pcol, disp1, disp2);
					prohibitSquare(chessBoard, row, col);
				}
				if (queensNum == 8) {
					printBoard(chessBoard);
					cout << '\n';
					solutionNum++;
				}
				queensNum = 0;
				initialColumn++;
				counter++;
				if (initialColumn == 8) {
					initialRow++;
					initialColumn = 0;
				}
			}
		}
	}
	cout << "found " << solutionNum << " solutions \n";

    return 0;
}

void prohibitSquare(char  chessBoard[8][8] ,int row ,int col) {
	for (int i = 0; i < 8; i++) {
		if (chessBoard[row][i] != 'Q' && chessBoard[row][i] != 'M')
			chessBoard[row][i] = '-';
	}
	for (int i = 0; i < 8; i++) {
		if (chessBoard[i][col] != 'Q' && chessBoard[i][col] != 'M')
			chessBoard[i][col] = '-';
	}
	for (int i = -7; i < 8; i++) {
		if (0 <= row + i && row + i < 8 && 0 <= col + i && col + i < 8 && chessBoard[row + i][col + i] != 'Q' && chessBoard[row + i][col + i] != 'M')
			chessBoard[row + i][col + i] = '-';
	}
	for (int i = -7; i < 8; i++) {
		if (0 <= row + i && row + i < 8 && 0 <= col - i && col - i < 8 && chessBoard[row + i][col - i] != 'Q' && chessBoard[row + i][col - i] != 'M')
			chessBoard[row + i][col - i] = '-';
	}
}

void findNext(char chessBoard[8][8], int* row, int* col, int disp1, int disp2 ) {
	bool foundNext = false;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {

			if (disp1 + disp2 > 0 && disp1 > 0) {
				disp1--;
			}

			else if (chessBoard[i][j] == '0') {
				chessBoard[i][j] = 'Q';
				*row = i;
				*col = j;
				foundNext = true;
				queensNum++;
				break;
			}
		}
		if (foundNext)
			break;
	}
}

void printBoard(char chessBoard[8][8]) {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++)
			cout << chessBoard[i][j] << ' ';
		cout << '\n';
	}
}