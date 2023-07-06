#include <iostream>
#include <FreeImage.h>
#include <string>
#include <algorithm>
#include <fstream>

// Класс для инициализации и уничтожения библиотеки автоматически
class FreeImageLibHolder
{
  public:
    FreeImageLibHolder()
    {
      FreeImage_Initialise();
      std::cout << "Lib is initialise.\n";
    }
    ~FreeImageLibHolder()
    {
      FreeImage_DeInitialise();
      std::cout << "Lib is deInitialise.\n";
    }
};

class IApcGraphicsHelper
{
public:
  //Создание изображения FreeImage (BMP формат)
  static int createFreeImage(unsigned char *memory,
    size_t fileSize,
    FIBITMAP*& image);

  //Декодирование в JPEG
  static int encodeImageToJPEG(unsigned char *memory,
    size_t fileSize);

  //Декодирование в JPEG с учетом размера
  static int encodeImageToJPEG(unsigned char *memory,
    size_t fileSize,
    int anMaxWidth,
    int anMaxHeight);

  //Вращение изображения и декодирование в JPEG
  static int rotateImageEncodeToJPEG(unsigned char *memory,
    size_t fileSize,
    double angle);

 //Вращение изображения (для функций)
  static int rotateImage(FIBITMAP*& image,
    double angle);

  //Обоезает по краям изображение на заданное число пикселей
  static int cutImageMiddle(unsigned char *memory,
    size_t fileSize,
    int pixelCount);

 //Обрезает изображение по зданным точкам
 static int cutImagePoints(unsigned char *memory,
   size_t fileSize,
   const int pointLeft,
   const int pointTop,
   const int pointRight,
   const int pointBottomop);

//Получения размеров изображение (для функций)
static int getImageSize(FIBITMAP*& image);

//Получение формата изображения
static int getImageFormat(unsigned char *memory,
  size_t fileSize);

//Декодирование в BMP
static int encodeImageToBMP(unsigned char *memory,
  size_t fileSize);
};

//Класс (обертка FITBITMAP)
class TFitBitmapHolder
{
public:
  FIBITMAP* m_pBitmap;

  TFitBitmapHolder()
  :m_pBitmap(nullptr){};

  ~TFitBitmapHolder()
  {
    if(m_pBitmap){
    FreeImage_Unload(m_pBitmap);
    }
  }
};

//Класс (обертка FIMEMORY)
class TFiMemoryHolder
{
public:
  FIMEMORY* m_pMemory;

  TFiMemoryHolder()
  :m_pMemory(nullptr){};

  ~TFiMemoryHolder()
  {
    if(m_pMemory){
    FreeImage_CloseMemory(m_pMemory);
    }
  }
};
