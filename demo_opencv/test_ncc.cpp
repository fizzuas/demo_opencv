#include <opencv2/imgcodecs.hpp>
#include <iostream>
#include <opencv2/highgui.hpp>
using namespace std;
using namespace cv;

void test_ncc(string path1, string path2) {
	Mat image1 = imread(path1, IMREAD_GRAYSCALE);
	Mat image2 = imread(path2, IMREAD_GRAYSCALE);

	imshow("image1", image1);
	imshow("image2", image2);


	std::cout << "image1宽度 "<< image1.cols << ",image1高度" << image1.rows << endl;
	std::cout << "image2宽度 "<< image2.cols << ",image2高度" << image1.rows << endl;

	int overlap = image1.cols/10;
	int overlap_max = image1.cols;
	float pearsonCorrelationCoefficientMax = 0;
	int overlapMaxCorrelationCoefficient = 0;
	for ( overlap ; overlap < overlap_max; overlap += overlap)
	{
		//****************************************//
		Mat imageTemp = image2(Rect(0, 0, overlap, image1.rows));
		long double tempTotalcount = 0;
		long double tempTotalPixel = 0;
		for (int i = 0; i < overlap; i++)
		{
			for (int j = 0; j < image1.rows; j++)
			{
				tempTotalcount += 1;
				cout << i<<","<<j<<"："<<int(imageTemp.at<uchar>(j,i)) << ",";
				tempTotalPixel += float(imageTemp.at<uchar>(j, i));
			}
			cout << endl;
		}
		float tempAvg = tempTotalPixel / tempTotalcount;
		//**************************************//	
		long double tempSubstract = 0;
		for (int i = 0; i < overlap; i++)
		{
			for (int j = 0; j < image1.rows; j++)
			{
				long double tempSquare = (long double(imageTemp.at<uchar>(j, i)) - tempAvg) * (long double(imageTemp.at<uchar>(j, i)) - tempAvg);
				tempSubstract = tempSubstract + tempSquare;
			}
			cout << endl;
		}
		float tempVariance = sqrt(tempSubstract / tempTotalcount);
		//***********************************************//
		Mat imageBase = image1(Rect(image1.cols - overlap, 0, overlap, image1.rows));
		int baseTotalcount = 0;
		int baseTotalPixel = 0;
		for (int i = 0; i < overlap; i++)
		{
			for (int j = 0; j < image1.rows; j++)
			{
				baseTotalcount += 1;
				cout << i<<","<<j<<"："<<int(imageTemp.at<uchar>(j,i)) << ",";
				baseTotalPixel += float(imageBase.at<uchar>(j, i));
			}
			cout << endl;
		}
		float baseAvg = baseTotalPixel / baseTotalcount;

		//*****************************************//	
		long double baseSubstract = 0;
		for (int i = 0; i < overlap; i++)
		{
			for (int j = 0; j < image1.rows; j++)
			{
				long double baseSquare = (long double(imageBase.at<uchar>(j, i)) - baseAvg) * (long double(imageBase.at<uchar>(j, i)) - baseAvg);
				baseSubstract = baseSubstract + baseSquare;
			}
			cout << endl;
		}
		float baseVariance = sqrt(baseSubstract / baseTotalcount);
		//***************************************//
		long double dotMul = 0;
		for (int i = 0; i < overlap; i++)
		{
			for (int j = 0; j < image1.rows; j++)
			{
				dotMul += abs((long double(imageBase.at<uchar>(j, i)) - baseAvg) * (long double(imageTemp.at<uchar>(j, i)) - tempAvg));
			}
			cout << endl;
		}
		float dotMulAvg = dotMul / baseTotalcount;

		float pearsonCorrelationCoefficient = dotMulAvg / (baseVariance * tempVariance);
		if (pearsonCorrelationCoefficientMax < pearsonCorrelationCoefficient)
		{
			pearsonCorrelationCoefficientMax = pearsonCorrelationCoefficient;
			overlapMaxCorrelationCoefficient = overlap;
		}

	}
	cout << "最大相关系数" << pearsonCorrelationCoefficientMax << endl;
	cout << "最大相关系数时重叠区域" << overlapMaxCorrelationCoefficient << endl;


}