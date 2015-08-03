#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <functional>
#include <thread>
#include <mutex>
#include <condition_variable>

class Mergesort_Thead_Helper {

    const auto MAX_NUM_THREADS = 4;
    std::mutex thread_mutex;
    std::condition_variable threads_available, threads_busy;

    void push(function<void(vector<double>&, int, int)> sort_function);


};
