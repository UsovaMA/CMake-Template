#ifndef __PARSER_H__
#define __PARSER_H__

#include <string.h>
#include <string>
#include <ctype.h>        // для функции isdigit, определяющей является ли символ цифрой

#include "polynom.h"

// + - = ^ x 0..9

enum State {
  START,
  NUMBER,
  END                    // нужно?
};

// Лексемы: числа, операции, переменные
enum LexType {
  LEX_NULL,              // тип для нераспознанных лексем

  LEX_NUMBER,            // числа
  LEX_DELIM,             // разделители, состояще из неалфавитных символов
  LEX_VAR                // переменная
};

// Разделители
enum LexDelims {
  LEX_DEL_NULL,          // для ошибки

  LEX_DEL_ADD,           // операция "+"
  LEX_DEL_SUB,           // операция "-", бинарный или унарный
  LEX_DEL_POW,           // возведение в степень
  LEX_DEL_EQUALS         // знак равенства
};

const char* LEX_DELIMS[] = {
    "",
    "+",
    "-",
    "^",
    "=",
    0                 // заглушка для определения конца списка
};

class Lexem {
public:
  int type;           // тип лексемы (константа, разделитель, ошибка)
  int index;          // конкретный индекс лексемы

  int value;          // значение лексемы (для числовых констант)

  std::string buf;    // хранение самой лексемы

  Lexem(int type = LEX_NULL, int index = LEX_NULL, int value = 0) :
    type(type),
    index(index),
    value(value) {};

};

class Parser
{
private:
  std::string polynomStr;        // cтроковое представление полинома
  int len;                       // длина строки
  int pos;                       // текущия позиция парсера
  Polynom polynom;               // полином

  Lexem currentLex;              // текущая лексема

public:
  // конструкторы
  Parser(const std::string& _polynomStr) : polynomStr(_polynomStr), len(polynomStr.length()), pos(0), polynom() { };

  // деструктор
  ~Parser();

  // основные методы
  Lexem getNextLexem() {
    State currentState = START;
    char currentChar;

    std::string buf = "";

    while (true) {
      currentChar = polynomStr[pos];

      switch (currentState) {
       case START:
        if (currentChar == ' ') {                  // если это пробел
          pos++;                                   // пропускаем, идём к следующему символу
          currentState = START;                    // остаёмся в том же состоянии
        }
        else if (isdigit(currentChar)) {           // если текущий символ - цифра,
          buf += currentChar;                      // добавляем ее в буфер-накопитель лексемы,
          pos++;                                   // сдвигаемся на следующий символ,
          currentState = NUMBER;                   // и переходим в состояние для числовых констант
        }
        else if (currentChar == 'x') {             // если текущий символ переменная
          pos++;
          return Lexem(LEX_VAR);           // возвращаем лексему
        }
        else {                                     // может быть это односимвольный разделитель?
          buf += currentChar;
          pos++;
          const char* tmp = buf.c_str();
          int index = 0;
          for (int i = 0; i < 6 || !index; i++) index = strcmp(tmp, LEX_DELIMS[i]);   // ищим символ в таблице разделителей
          if (index != 0) return Lexem(LEX_DELIM, index);                        // возвращаем соответствующую лексему
          else return Lexem(LEX_NULL, LEX_NULL);                                 // нет такого разделителя - ошибка
        }
        break;

       case NUMBER:                              // cостояние распознавания числовых констант
        if (isdigit(currentChar)) {             // если символ - цифра
          buf += currentChar;                   // добавляем его в строку-буфер
          pos++;                                // переходим к следующему символу
          currentState = NUMBER;                // и остаемся в том же состоянии
        }
        else {                                  // другой символ - значит число уже закончилось
          return Lexem(LEX_NUMBER, LEX_NULL, atoi(buf.c_str()));          //  возвращаем соответствующую лексему
        }
        break;
      }
    }
  };

  Polynom parse() {
    polynom = NULL;

    currentLex = getNextLexem();                // Считываем первую лексему
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
        /* отрицательная степень? */
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
