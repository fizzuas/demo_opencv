#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;
using namespace cv;

/// Global Variables
Mat img1; Mat img2; 
const char* image_window = "Source Image";
const char* result_window = "Result window";
//边长
const int sideLength = 100;

Mat getTargetImg(Mat img) {

	//缩放图片
	Mat resizedImg;
	resize(img,resizedImg,Size(sideLength,sideLength));

	//灰度图
	Mat greyImg;
	cvtColor(resizedImg,greyImg,COLOR_BGR2GRAY);
	return greyImg;
}

//取每行像素点平均值
void getDiff(Mat img){
	vector <unsigned int> v;
	int rows = img.rows;
	for (int i=0; i < rows;i++) {
		
		
	}
}


void test_mad(string img_path1,string img_path2) {
	/// Load image and template
	img1 = imread(img_path1, 1);
	img2 = imread(img_path2, 1);

	imshow("source img", img1);
	imshow("resize img", getTargetImg(img1));

}



