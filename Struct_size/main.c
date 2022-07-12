//
//  main.c
//  Struct_size
//
//  Created by LL on 2022/7/7.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    // insert code here...
    
    struct ss1 {
        char a[17];// 偏移0，大小17。
        int x;// 偏移17 + 3，大小4。
    }s1;// 内对齐后的大小是24，外对齐后的大小是24。
    printf("s1的大小: %zd\n", sizeof(s1));
    printf("变量a地址: %p, 变量x地址: %p\n", &s1.a, &s1.x);
    
    
    struct ss2 {
        char a[17];// 偏移0，大小17。
        int x;// 偏移17 + 3，大小4。
        char b;// 偏移24，大小1。
    }s2;// 内对齐后的大小是25，外对齐后的大小是28。
    printf("s2的大小: %zd\n", sizeof(s2));
    printf("变量a地址: %p, 变量x地址: %p，变量b地址: %p\n", &s2.a, &s2.x, &s2.b);
    
    
    struct ss3 {
        char a[17];// 偏移0，大小17。
        int x;// 偏移17 + 3，大小4。
        double b;// 偏移24，大小8。
        char c;// 偏移32，大小1。
    }s3;// 内对齐后的大小是33，外对齐后的大小是40。
    printf("s3的大小: %zd\n", sizeof(s3));
    printf("变量a地址: %p, 变量x地址: %p，变量b地址: %p，变量c地址: %p\n", &s3.a, &s3.x, &s3.b, &s3.c);
    
    
#pragma pack(push)
#pragma pack(2)
 
    struct ss4 {
        char a[13];// 偏移0，大小13。
        int x;// 偏移13 + 1，大小4。
    }s4;// 内对齐后的大小是18，外对齐后的大小是18。
 
#pragma pack(pop)
    
    printf("s4的大小: %zd\n", sizeof(s4));
    printf("变量a地址: %p, 变量x地址: %p\n", &s4.a, &s4.x);
    
    
#pragma pack(push)
#pragma pack(2)
 
    struct ss5 {
        char a[13];// 偏移0，大小13。
        int x;// 偏移13 + 1，大小4。
        char b;// 偏移18，大小1。
    }s5;// 内对齐后的大小是19，外对齐后的大小是20。
 
#pragma pack(pop)
    
    printf("s5的大小: %zd\n", sizeof(s5));
    printf("变量a地址: %p, 变量x地址: %p, 变量b的地址: %p\n", &s5.a, &s5.x, &s5.b);

    
#pragma pack(push)
#pragma pack(2)
 
    struct ss6 {
        char a[13];// 偏移0，大小13。
        int x;// 偏移13 + 1，大小4。
        double b;// 偏移18，大小8。
        char c;// 偏移26，大小1。
    }s6;// 内对齐后的大小是27，外对齐后的大小是28。
 
#pragma pack(pop)
    
    printf("s6的大小: %zd\n", sizeof(s6));
    printf("变量a地址: %p, 变量x地址: %p, 变量b地址: %p，变量c地址: %p\n", &s6.a, &s6.x, &s6.b, &s6.c);

    
    struct ss7 {
        char a;// 偏移0，大小1。
        struct ss1 b;// 偏移1 + 3，大小24。
        char f;// 偏移28，大小1。
        struct ss2 c;// 偏移29 + 3，大小28。
        char g;// 偏移60，大小1。
        struct ss3 d;// 偏移61 + 3，大小40。
        char e;// 偏移104，大小1。
    }s7;// 内对齐后的大小是105，外对齐后的大小是112。
    printf("s7的大小: %zd\n", sizeof(s7));
    printf("变量a地址: %p, 变量b.a地址: %p, 变量b.x地址: %p\n", &s7.a, &s7.b.a, &s7.b.x);
    printf("变量f地址: %p, 变量c.a地址: %p, 变量c.x地址: %p, 变量c.b地址: %p\n", &s7.f, &s7.c.a, &s7.c.x, &s7.c.b);
    printf("变量g地址: %p, 变量d.a地址: %p, 变量d.x地址: %p, 变量d.b地址: %p, 变量d.c地址: %p\n", &s7.g, &s7.d.a, &s7.d.x, &s7.d.b, &s7.d.c);
    printf("变量e地址: %p\n", &s7.e);
    
    
#pragma pack(push)
#pragma pack(2)

    struct ss8 {
        char a;// 偏移0，大小1。
        struct ss1 b;// 偏移1 + 1，大小24。
        char f;// 偏移26，大小1。
        struct ss2 c;// 偏移27 + 1，大小28。
        char g;// 偏移56，大小1。
        struct ss3 d;// 偏移57 + 1，大小40。
        char e;// 偏移98，大小1。
    }s8;// 内对齐后的大小是99，外对齐后的大小是100。

    struct ss8_1 {
        char a;// 偏移0，大小1
        struct {
            char a[17];// 偏移1 + 1，大小17。
            int x;// 偏移17 + 1，大小4。
        }b;// 内对齐后的大小是22，外对齐后的大小是22。
        char f;// 偏移24，大小1。
        struct {
            char a[17];// 偏移25 + 1，大小17。
            int x;// 偏移17 + 1，大小4。
            char b;// 偏移22，大小1。
        }c;// 内对齐后的大小是23，外对齐后的大小是24。
        char g;// 偏移50，大小1。
        struct {
            char a[17];// 偏移51 + 1，大小17。
            int x;// 偏移17 + 1，大小4。
            double b;// 偏移22，大小8。
            char c;// 偏移30，大小1。
        }d;// 内对齐后的大小是31，外对齐后的大小是32。
        char e;// 偏移84，大小1。
    }s8_1;// 内对齐后的大小是85，外对齐后的大小是86。
    
#pragma pack(pop)

    printf("s8的大小: %zd\n", sizeof(s8));
    printf("变量a地址: %p, 变量b.a地址: %p, 变量b.x地址: %p\n", &s8.a, &s8.b.a, &s8.b.x);
    printf("变量f地址: %p, 变量c.a地址: %p, 变量c.x地址: %p, 变量c.b地址: %p\n", &s8.f, &s8.c.a, &s8.c.x, &s8.c.b);
    printf("变量g地址: %p, 变量d.a地址: %p, 变量d.x地址: %p, 变量d.b地址: %p, 变量d.c地址: %p\n", &s8.g, &s8.d.a, &s8.d.x, &s8.d.b, &s8.d.c);
    printf("变量e地址: %p\n", &s8.e);
    printf("----------------\n");
    printf("s8_1的大小: %zd\n", sizeof(s8_1));
    printf("变量a地址: %p, 变量b.a地址: %p, 变量b.x地址: %p\n", &s8_1.a, &s8_1.b.a, &s8_1.b.x);
    printf("变量f地址: %p, 变量c.a地址: %p, 变量c.x地址: %p, 变量c.b地址: %p\n", &s8_1.f, &s8_1.c.a, &s8_1.c.x, &s8_1.c.b);
    printf("变量g地址: %p, 变量d.a地址: %p, 变量d.x地址: %p, 变量d.b地址: %p, 变量d.c地址: %p\n", &s8_1.g, &s8_1.d.a, &s8_1.d.x, &s8_1.d.b, &s8_1.d.c);
    printf("变量e地址: %p\n", &s8_1.e);
    
    
    union uu1 {
            char a[9];
            double i;
        }u1;// 取最大变量a的值9，外对齐后的大小为16。
        
        printf("u1的大小: %zd\n", sizeof(u1));
        
        union uu2 {
            char a[9];
            int i;
        }u2;// 取最大变量a的值9，外对齐后的大小为12。
        
        printf("u2的大小: %zd\n", sizeof(u2));
        
    #pragma pack(push)
    #pragma pack(2)
        union uu3 {
            char a[9];
            int i;
        }u3;// 取最大变量a的值9，外对齐后的大小为10。
        
        printf("u3的大小: %zd\n", sizeof(u3));
    #pragma pack(pop)
    
    
    enum ee1 {
        red,
        green,
        blue,
    }e1;
    
    enum {
        white = 4294967293,
        black,
        orange,
    }e2;
    
    enum {
        yellow = 4294967294,
        purple,
        gray,
    }e3;
    
    enum {
      white1,
      black1,
      orange1 = 2147483648,
    }e4;
    
    enum {
      white2 = -1,
      black2,
      orange2 = 2147483648,
    }e5;
    
    printf("e1的大小: %zd\n", sizeof(e1));
    printf("e2的大小: %zd\n", sizeof(e2));
    printf("e3的大小: %zd\n", sizeof(e3));
    printf("e4的大小: %zd\n", sizeof(e4));
    printf("e5的大小: %zd\n", sizeof(e5));
    
    
    struct ss9 {
        int i;// 偏移0，大小4。
        union uu1 u;// 偏移4 + 4，大小16。
        char d;// 偏移24，大小1。
        enum ee1 color;// 偏移25 + 3，大小4。
        char e;// 偏移32，大小1。
    }s9;// 内对齐后的大小是33，外对齐后的大小是40。
    printf("s9的大小: %zd\n", sizeof(s9));
    printf("变量i地址: %p, 变量u地址: %p, 变量d地址: %p, 变量color地址: %p, 变量e地址: %p\n", &s9.i, &s9.u, &s9.d, &s9.color, &s9.e);
    
    return 0;
}
