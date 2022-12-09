

#include "opencv2/opencv.hpp"
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <iostream>

using namespace cv;
using namespace std;

int main(int argc, char **argv)
{

    //--------------------------------------------------------
    // networking stuff: socket , connect
    //--------------------------------------------------------
    int sokt;
    char *serverIP;
    int serverPort;

    if (argc < 3)
    {
        serverIP = "10.0.0.210";
        serverPort = 1235;
    }
    else
    {
        serverIP = argv[1];
        serverPort = atoi(argv[2]);
    }

    struct sockaddr_in serverAddr;
    socklen_t addrLen = sizeof(struct sockaddr_in);

    if ((sokt = socket(PF_INET, SOCK_STREAM, 0)) < 0)
    {
        std::cerr << "socket() failed" << std::endl;
    }

    serverAddr.sin_family = PF_INET;
    serverAddr.sin_addr.s_addr = inet_addr(serverIP);
    serverAddr.sin_port = htons(serverPort);

    if (connect(sokt, (sockaddr *)&serverAddr, addrLen) < 0)
    {
        std::cerr << "connect() failed!" << std::endl;
    }

    //----------------------------------------------------------
    // OpenCV Code
    //----------------------------------------------------------

    Mat img;
    img = Mat::zeros(1024, 1280, CV_8UC1);
    int imgSize = img.total() * img.elemSize();
    uchar *iptr = img.data;
    int bytes = 0;
    int key;
    int thickness = 2;
    int posX = 5;
    int posY = 50;
    stringstream ss;
    ss << "Connection time out , please wait ...";
    Point textOrg(posX, posY);
    int fontFace = FONT_HERSHEY_SIMPLEX;
    double fontScale = 0.7;

    // make img continuos
    if (!img.isContinuous())
    {
        img = img.clone();
    }

    std::cout << "Image Size:" << imgSize << std::endl;

    namedWindow("TSL FireView Spaceborne", 1);

    while (key != 'q')
    {

        if ((bytes = recv(sokt, iptr, imgSize, MSG_WAITALL)) < 1)
        {
            std::cerr << "recv failed, received bytes = " << bytes << std::endl;

            close(sokt);
            if ((sokt = socket(PF_INET, SOCK_STREAM, 0)) < 0)
            {
                std::cerr << "socket() failed" << std::endl;
            }

            serverAddr.sin_family = PF_INET;
            serverAddr.sin_addr.s_addr = inet_addr(serverIP);
            serverAddr.sin_port = htons(serverPort);

            if (connect(sokt, (sockaddr *)&serverAddr, addrLen) < 0)
            {
                std::cerr << "connect() failed!" << std::endl;
            }

            putText(img, ss.str(), textOrg, fontFace, fontScale, CV_RGB(250, 0, 0), thickness);
            cv::imshow("TSL FireView Spaceborne", img);
        }
        else
        {
            cv::imshow("TSL FireView Spaceborne", img);
        }

        if (key = cv::waitKey(10) >= 0)
            break;
    }

    close(sokt);

    return 0;
}
