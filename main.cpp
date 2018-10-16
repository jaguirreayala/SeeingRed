#include "Bitmap/bitmap.h"
#include <iostream>
#include <vector>

using namespace std;

//argc - number of arguments in command
//argv - each argument word, stored in an array
int main(int argc, char* argv[])
{
  string filename;
  Bitmap image;

  if(argc != 2)
  {
    cout << "Please specify one image file!\n";
  }
  else if(argc == 2)
  {
    filename = argv[1];

    image.open(filename);

    if(image.isImage())
    {
      vector <vector <Pixel> > imagePixels = image.toPixelMatrix();

      cout << filename << " is " << imagePixels.size() << " pixels high and " << imagePixels[0].size() << " pixels wide\n";
    }
    else if(!image.isImage())
    {
      cout << "Image file must be a bitmap with 24-bit color depth. \n"; 
    }
  }
  return 0;
}
