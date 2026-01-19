#include <iostream>
#include <memory>
#include <algorithm>
#include <arpa/inet.h>  // 用于 htonl/ntohl


int BigTranLittle(uint inet)
{   
    return(
    (0xFF000000 & inet) >>  24|
    (0x00FF0000 & inet) >>  8|
    (0x0000FF00 & inet) <<  8|
    (0x000000FF & inet) <<  24
    );
}

int main()
{
    int number = 0x12345678;
    int ret = BigTranLittle(number);
    std::cout << "ret = " << std::hex << ret << std::endl;
    int ret2 = htonl(number);  // 如果当前是小端，htonl会转换
    std::cout << "ret2 = " << std::hex << ret2 << std::endl;

    return 0;
}