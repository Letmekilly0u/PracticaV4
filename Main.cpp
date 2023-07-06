#include "MainHeader.h"

std::vector<uint8_t> LoadImageToMemory(std::string nameFile)
{
  std::ifstream file(nameFile, std::ios::binary | std::ios::ate);
  size_t size = file.tellg();
  file.seekg(0, std::ios::beg);
  std::vector<char> buffer;
  buffer.resize(size);
  file.read(buffer.data(), size);
  std::vector<uint8_t> outVector;
  outVector.resize(size);

  for(int i = 0; i < outVector.size(); i++)
  {
    outVector[i] = buffer[i];
  }

  return outVector;
}


int main(int argc, char **argv) {
  FreeImageLibHolder init = FreeImageLibHolder();
  std::vector<uint8_t> memoryImg = LoadImageToMemory("two.png");
  //FIBITMAP* image;
  IApcGraphicsHelper GraphicHelper;
  //GraphicHelper.CreatImageBMP(memoryImg.data(), memoryImg.size(), image);
  //GraphicHelper.encodeImageToJPEG(memoryImg.data(), memoryImg.size());
  //GraphicHelper.encodeImageToJPEG(memoryImg.data(), memoryImg.size(), 150, 150);
  //GraphicHelper.rotateImageEncodeToJPEG(memoryImg.data(), memoryImg.size(), 70);
  //GraphicHelper.cutImageMiddle(memoryImg.data(), memoryImg.size(), 60);
  //GraphicHelper.cutImagePoints(memoryImg.data(), memoryImg.size(), 60, 60, 600, 300);
  //GraphicHelper.getImageFormat(memoryImg.data(), memoryImg.size());
  GraphicHelper.encodeImageToBMP(memoryImg.data(), memoryImg.size());

  return 0;
}
