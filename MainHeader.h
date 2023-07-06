#include "ObertkaHeader.h"
//Касс тестирования
class Test
{
public:
  Test()
  {};

  ~Test()
  {};
};


//Внешние функции
//Загрузка изображения в память (дя того чтобы тестировать обертку надо что-то поожить в память и это что-то храниться в типе uint8_t и имеет размер size_t)
std::vector<uint8_t> LoadImageToMemory(std::string nameFile);
