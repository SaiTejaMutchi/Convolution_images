#include<opencv2/imgproc.hpp>
#include<opencv2/highgui.hpp>
#include<iostream>

#include <string>
 
 using namespace cv;
using namespace std;


class Cat{
  public:
 static void readCatImg() {

 cv::Mat catimage = cv::imread("cat.jpg");

    if(catimage.empty()){
        cout<<"can not find image"<<endl;
       
    }

    //set kernel size
    int kernelSize = 3;

    //create a 3x3 kernel with all elements equal to 1. We are use a kernel size of 5x5. To keep things simple, we will 
    //also choose a kernel where all elements are the same. This kernel is often called a Box Kernel. Notice, the sum 
    //of all the elements of the kernel add up to 1. This ensures that the output image has the same brightness level 
  
    Mat kernel = Mat::ones(kernelSize, kernelSize, CV_32F);

    //normalize kernel so that sum of all the elements is equal to 1
    kernel = kernel / (float)(kernelSize * kernelSize);

    
  

    Mat catresult;

    //apply convolution filter. The third parameter (depth) is set to -1, which means the bit-depth of the output image 
    //is the same as the input image. So if the input image is of type CV_8UC3, the output image will also be of the same 
    //type. Later we will see certain kinds of kernels where CV_32F or CV_64F should be used.
    filter2D(catimage, catresult, -1, kernel, Point(-1, -1), 0, BORDER_DEFAULT);

    /* /create windows to display images
    cv::namedWindow("catimage", WINDOW_NORMAL);
    cv::namedWindow("catresult", WINDOW_NORMAL);

    //display images
    cv:: imshow("catimage", catimage);
    cv::imshow("catresult", catresult);
   */

     cv::imwrite("convolutedcat.jpg",catresult);


 	

 
  }


};
class Dog{
   public:
   static void readDogImg() {
  cv::Mat imagedog = cv :: imread("dog.jpg");
  
    if(imagedog.empty()){
        cout<<"can not find image"<<endl;
       
    }

    //set kernel size
    int kernelSize = 3;

    //create a 3x3 kernel with all elements equal to 1. We are use a kernel size of 5x5. To keep things simple, we will 
    //also choose a kernel where all elements are the same. This kernel is often called a Box Kernel. Notice, the sum 
    //of all the elements of the kernel add up to 1. This ensures that the output image has the same brightness level 
    
    Mat kernel = Mat::ones(kernelSize, kernelSize, CV_32F);

    //normalize kernel so that sum of all the elements is equal to 1
    kernel = kernel / (float)(kernelSize * kernelSize);

   
    

    Mat resultdog;

    //apply convolution filter. The third parameter (depth) is set to -1, which means the bit-depth of the output image 
    //is the same as the input image. So if the input image is of type CV_8UC3, the output image will also be of the same 
    //type. Later we will see certain kinds of kernels where CV_32F or CV_64F should be used.
    filter2D(imagedog, resultdog, -1, kernel, Point(-1, -1), 0, BORDER_DEFAULT);

   /* //create windows to display images
    cv::namedWindow("imagedog", WINDOW_NORMAL);
    cv::namedWindow("resultdog", WINDOW_NORMAL);

    //display images
    cv:: imshow("imagedog", imagedog);
    cv::imshow("resultdog", resultdog);
   cv::waitKey();
*/
    cv::imwrite("convoluteddog.jpg",resultdog);
  	
  }


};


class Convolution{
    public:
   static void readCatImg(){
  	Cat::readCatImg();
  }
   static void readDogImg(){
  	Dog::readDogImg();
  }
  

};


int main()
{
     
   	Convolution x;
   	x.readCatImg();
    x.readDogImg();
return 0;

}