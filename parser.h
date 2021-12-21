#ifndef __PARSER_H__
#define __PARSER_H__

#include <string.h>
#include <string>
#include <ctype.h>        // ��� ������� isdigit, ������������ �������� �� ������ ������

#include "polynom.h"

// + - = ^ x 0..9

enum State {
  START,
  NUMBER,
  END                    // �����?
};

// �������: �����, ��������, ����������
enum LexType {
  LEX_NULL,              // ��� ��� �������������� ������

  LEX_NUMBER,            // �����
  LEX_DELIM,             // �����������, �������� �� ������������ ��������
  LEX_VAR                // ����������
};

// �����������
enum LexDelims {
  LEX_DEL_NULL,          // ��� ������

  LEX_DEL_ADD,           // �������� "+"
  LEX_DEL_SUB,           // �������� "-", �������� ��� �������
  LEX_DEL_POW,           // ���������� � �������
  LEX_DEL_EQUALS         // ���� ���������
};

const char* LEX_DELIMS[] = {
    "",
    "+",
    "-",
    "^",
    "=",
    0                 // �������� ��� ����������� ����� ������
};

class Lexem {
public:
  int type;           // ��� ������� (���������, �����������, ������)
  int index;          // ���������� ������ �������

  int value;          // �������� ������� (��� �������� ��������)

  std::string buf;    // �������� ����� �������

  Lexem(int type = LEX_NULL, int index = LEX_NULL, int value = 0) :
    type(type),
    index(index),
    value(value) {};

};

class Parser
{
private:
  std::string polynomStr;        // c�������� ������������� ��������
  int len;                       // ����� ������
  int pos;                       // ������� ������� �������
  Polynom polynom;               // �������

  Lexem currentLex;              // ������� �������

public:
  // ������������
  Parser(const std::string& _polynomStr) : polynomStr(_polynomStr), len(polynomStr.length()), pos(0), polynom() { };

  // ����������
  ~Parser();

  // �������� ������
  Lexem getNextLexem() {
    State currentState = START;
    char currentChar;

    std::string buf = "";

    while (true) {
      currentChar = polynomStr[pos];

      switch (currentState) {
       case START:
        if (currentChar == ' ') {                  // ���� ��� ������
          pos++;                                   // ����������, ��� � ���������� �������
          currentState = START;                    // ������� � ��� �� ���������
        }
        else if (isdigit(currentChar)) {           // ���� ������� ������ - �����,
          buf += currentChar;                      // ��������� �� � �����-���������� �������,
          pos++;                                   // ���������� �� ��������� ������,
          currentState = NUMBER;                   // � ��������� � ��������� ��� �������� ��������
        }
        else if (currentChar == 'x') {             // ���� ������� ������ ����������
          pos++;
          return Lexem(LEX_VAR);           // ���������� �������
        }
        else {                                     // ����� ���� ��� �������������� �����������?
          buf += currentChar;
          pos++;
          const char* tmp = buf.c_str();
          int index = 0;
          for (int i = 0; i < 6 || !index; i++) index = strcmp(tmp, LEX_DELIMS[i]);   // ���� ������ � ������� ������������
          if (index != 0) return Lexem(LEX_DELIM, index);                        // ���������� ��������������� �������
          else return Lexem(LEX_NULL, LEX_NULL);                                 // ��� ������ ����������� - ������
        }
        break;

       case NUMBER:                              // c�������� ������������� �������� ��������
        if (isdigit(currentChar)) {             // ���� ������ - �����
          buf += currentChar;                   // ��������� ��� � ������-�����
          pos++;                                // ��������� � ���������� �������
          currentState = NUMBER;                // � �������� � ��� �� ���������
        }
        else {                                  // ������ ������ - ������ ����� ��� �����������
          return Lexem(LEX_NUMBER, LEX_NULL, atoi(buf.c_str()));          //  ���������� ��������������� �������
        }
        break;
      }
    }
  };

  Polynom parse() {
    polynom = NULL;

    currentLex = getNextLexem();                // ��������� ������ �������
    // 
    //-ax^b+4x=
    while (currentLex.index != LEX_DEL_EQUALS) {
      int coef = 1, deg = 0;
      if (currentLex.type == LEX_DELIM && currentLex.index == LEX_DEL_SUB) {
        coef = -1;
        currentLex = getNextLexem();
      }
      if (currentLex.type == LEX_NUMBER) {
        coef *= currentLex.value;
        currentLex = getNextLexem();
      }
      if (currentLex.type == LEX_VAR) {
        deg = 1;
        currentLex = getNextLexem();
      }
      if (currentLex.type == LEX_DELIM && currentLex.index == LEX_DEL_POW) {
        currentLex = getNextLexem();
        /* ������������� �������? */
        if (currentLex.type == LEX_NUMBER) {
          deg = currentLex.value;
          currentLex = getNextLexem();
        } else {
          throw logic_error("Error in expression");
        }
      }
      if (currentLex.type == LEX_DELIM && (currentLex.index == LEX_DEL_ADD || currentLex.index == LEX_DEL_SUB || currentLex.index == LEX_DEL_EQUALS)) {
        Monom cur_monom(coef, deg);        // -4x^3, 5x^4, x^2, x, 456      // x^^ x^x x^+
        polynom += cur_monom;
      }
      if (currentLex.index == LEX_DEL_ADD || currentLex.index == LEX_DEL_SUB) {
        currentLex = getNextLexem();
      }
    }
    return polynom;
  };

};

#endif  // __PARSER_H__
