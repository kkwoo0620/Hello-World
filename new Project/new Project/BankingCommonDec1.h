#ifndef __BACKING_COMMON_H__
#define __BACKING_COMMON_H__

#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>

using std::cout;
using std::endl;
using std::cin;
const int NAME_LEN = 20;


// 프로그램 사용자의 선택 메뉴
enum { MAKE = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT };

//신용 등급
enum { RANK_A = 7, RANK_B = 4, RANK_C = 2 };

// 계좌 종류
enum { Normal = 1, HighCredit };

#endif