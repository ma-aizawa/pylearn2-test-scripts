#include <stdio.h>
#include <iostream>
#include <string>
#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"

int main () {
  FILE *fp = fopen("test.csv", "w");

  int n = 2;

  for (int i = 1; i <= n; i++) {
    char name_c[10];
    sprintf(name_c, "%02d", i);
    std::string name = name_c;
    std::string path = "data/" + name + ".jpeg";

    IplImage *input = cvLoadImage(path.c_str(), CV_LOAD_IMAGE_GRAYSCALE);

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

