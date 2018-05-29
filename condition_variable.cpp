#include <stdlib.h>  
#include <string>  
#include <iostream>  
#include <mutex>  
#include <thread>  
#include <condition_variable>  
//----------------------------------------------------------  
std::mutex g_mutexWait;                 // 互斥锁  
std::condition_variable g_condWait;     // 条件变量  
//----------------------------------------------------------  
///< 输入数据线程函数  
void InputThread()  
{  
    std::cout << "请在10秒内输入任意字符：" << std::endl;  
    // 等待手工输入  
    std::string strInputData = "";  
    std::cin >> strInputData;  
    // 输入了字符，则发出通知  
    if (strInputData != "")  
    {  
        g_condWait.notify_one();  
    }  
}  
//----------------------------------------------------------  
///< 主函数  
int main(int argc, char* argv[])  
{  
    try  
    {  
        // 启动线程输入数据  
        std::thread threadInput(InputThread);  
        // 取得当前时间  
        time_t tmInputStart = time(NULL);  
  
        // 使用条件变量，等待输入数据  
        std::unique_lock<std::mutex> lockWait(g_mutexWait);  
        std::cv_status cvsts = g_condWait.wait_for(lockWait, std::chrono::seconds(3));  
        // 消息接收超时  
        if (cvsts == std::cv_status::timeout)  
        {  
            std::cout << "您输入的太慢了！请输入任意字符退出程序！" << std::endl;  
        }  
        else // 接收到条件变量信号，未超时  
        {  
            time_t tmInputEnd = time(NULL);  
            std::cout << "您输入的太快了！只用了" << (tmInputEnd - tmInputStart) << "秒！" << std::endl;  
        }  
        // 等待线程退出  
        threadInput.join();  
    }  
    catch (std::exception &ex)  
    {  
        std::cout << ex.what() << std::endl;  
    }  
    system("PAUSE");  
    return 0;  
} 
