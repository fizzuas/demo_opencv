#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>
using namespace std;
using namespace cv;
void test_mad(string img_path1, string img_path2);
int test_phash(string ImageName1, string ImageName2);
void test_ncc(string path1, string path2);

int main(int argc, char** argv)
{
	std::string path1 = ".\\images\\test_mei_1.jpg";
	std::string path2 = ".\\images\\test_mei_2.jpg";
	std::string path3 = ".\\images\\test1.png";
	std::string path4 = ".\\images\\test2.png";
	test_phash(path1,path2);
	//test_ncc(path2, path2);
	//test_mad(path1, path2);

	waitKey(0);
	return 0;
}
