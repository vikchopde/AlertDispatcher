cmake_minimum_required(VERSION 3.10)
project(zerotohero)

set(CMAKE_CXX_STANDARD 14)

add_executable(zerotohero main.cpp AlertQueue.hpp IAlert.hpp EmailAlert.hpp IAlertListener.hpp EmailAlertListener.hpp Dispatcher.hpp Dispatcher.cpp SMSAlertListener.hpp)