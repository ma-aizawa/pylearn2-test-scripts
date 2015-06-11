#include <stdio.h>
#include <iostream>
#include <string>
#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"


int main() {
  FILE *fp = fopen("train.csv", "w");

  int numFiles = 20;
  int numFirstClass = 10;

  for (int i = 1; i <= numFiles; i++) {
    char name_c[10];
    sprintf(name_c, "%03d", i);
    std::string name = name_c;
    std::string path =  "data/" + name + ".jpeg";

    IplImage *input = cvLoadImage(path.c_str(), CV_LOAD_IMAGE_GRAYSCALE);

    if (i < numFirstClass) fprintf(fp, "0");
    else fprintf(fp, "1");

    for (int y = 0; y < input->height; y++) {
      for (int x = 0; x < input->width; x++) {
        uchar pixelValue = 0;
        pixelValue = (uchar)input->imageData[y * input->width + x];
        fprintf(fp, ",%d", (int)pixelValue);
      }
    }
    fprintf(fp, "\n");
  }
}

