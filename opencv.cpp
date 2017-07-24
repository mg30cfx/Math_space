#include <opencv2\opencv.hpp>
    
using namespace cv;
 
int main ( int argc, char **argv )
{
    Mat dst;
    Mat im_gray;
    Mat im_gray_1;
    
    //Mat im_gray = imread("PCB_no_defect.tif",CV_LOAD_IMAGE_GRAYSCALE);
    Mat im_rgb = imread("PCB_no_defect.tif");
    //Mat im_gray_1 = imread("PCB_defect.tif",CV_LOAD_IMAGE_GRAYSCALE);
    Mat im_rgb_1 = imread("PCB_defect.tif");
    
    cvtColor(im_rgb,im_gray,CV_RGB2GRAY);
    cvtColor(im_rgb_1,im_gray_1,CV_RGB2GRAY);
    
    equalizeHist( im_gray, dst );
    
    Mat img_bw = im_gray > 138;
    Mat img_bw_1 = im_gray_1 > 138;
    Mat result = img_bw_1-img_bw;
    
    namedWindow( "Display window1", WINDOW_AUTOSIZE ); // Create a window for display.
    imshow( "Display window1", result);  // Show 
    
    namedWindow( "Display window2", WINDOW_AUTOSIZE ); // Create a window for display.
    imshow( "Display window2",img_bw );  // Show our image inside it.
    
    namedWindow( "Display window3", WINDOW_AUTOSIZE );// Create a window for display.
    imshow( "Display window3", img_bw_1); 
    
    imwrite("im_gray.jpg", im_gray);
    imwrite("im_gray_1.jpg", im_gray_1);
    imwrite("im_bw.jpg", img_bw);
    imwrite("im_bw_1.jpg", img_bw_1);
    imwrite("Defect.jpg",result);
    
    waitKey(0);  // Wait for a keystroke in the window

    return 0;

    return 0;
}
