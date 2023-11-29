#include <iostream>
#include <cstring>

int main(){
    int num;
    std::cout << "This program will help you calculate ¡Æ(1,n,i!). To calculate ¡Æ(1,n,i!), you should give the computer 'n' first.\n";
    std::cout << "n=";
    std::cin >> num;
    int num2 = num;                                     //n!
    int num3 = num;
    int count = 1;
    while (num2 /= 10) {
        count++;
    }
    int x[9999] = {0};
    int l = count;
    for(int i = 1; i <= count; i++) {
        x[i] = num3 % 10;
        num3 /= 10;
    }

    int numb = num - 1;
    num2 = numb;
    num3 = numb;
    count = 1;
    while (num2 /= 10) {
        count++;
    }
    int y[9999] = {0};
    for(int i = 1; i <= count; i++) {
        y[i] = num3 % 10;
        num3 /= 10;
    }

    int c[9999] = {0};
    int lenc{0};
    while(numb > 1) {
        int j, i, m;
        std::memset(c, 0, sizeof(c));

        for (i=1; i<=l; i++) {
            m=0;
            for (j=1; j<=count; j++) {
                c[i+j-1] = c[i+j-1] + m + x[i] * y[j];
                m = c[i+j-1] / 10;
                c[i+j-1] %= 10;
            }
            c[i+count] = m;
        }

        lenc = l + count;
        while (c[lenc] == 0 && lenc > 1) {
            lenc--;
        }

        memcpy((x), c, sizeof(c));
        l = lenc;
        numb = numb - 1;
        num2 = numb;
        num3 = numb;
        count = 1;
        while (num2 /= 10) {
            count++;
        }
        for (i = 1; i <= count; i++) {
            y[i] = num3 % 10;
            num3 /= 10;
        }
    }                                       //n! end


    int a[9999] = {0};
    int b[9999] = {0};
    int ans[9999] = {0};
    int la{0};
    la = lenc;
    memcpy((a), c, sizeof(c));                                      //a = n!


    num = num - 1;                                      //(n-1)!
    num2 = num;
    num3 = num;
    count = 1;
    while (num2 /= 10) {
        count++;
    }
    std::memset(x, 0, sizeof(x));
    l = count;
    for(int i = 1; i <= count; i++) {
        x[i] = num3 % 10;
        num3 /= 10;
    }

    numb = num - 1;
    num2 = numb;
    num3 = numb;
    count = 1;
    while (num2 /= 10) {
        count++;
    }
    std::memset(y, 0, sizeof(y));
    for(int i = 1; i <= count; i++) {
        y[i] = num3 % 10;
        num3 /= 10;
    }

    std::memset(c, 0, sizeof(c));
    lenc = 0;
    while(numb > 1) {
        int j, i, m;
        std::memset(c, 0, sizeof(c));

        for (i=1; i<=l; i++) {
            m=0;
            for (j=1; j<=count; j++) {
                c[i+j-1] = c[i+j-1] + m + x[i] * y[j];
                m = c[i+j-1] / 10;
                c[i+j-1] %= 10;
            }
            c[i+count] = m;
        }

        lenc = l + count;
        while (c[lenc] == 0 && lenc > 1) {
            lenc--;
        }

        memcpy((x), c, sizeof(c));
        l = lenc;
        numb = numb - 1;
        num2 = numb;
        num3 = numb;
        count = 1;
        while (num2 /= 10) {
            count++;
        }
        for (i = 1; i <= count; i++) {
            y[i] = num3 % 10;
            num3 /= 10;
        }
    }                                       //(n-1)! end


    int lb{0};
    lb = lenc;
    memcpy((b), c, sizeof(c));                                  //b = (n-1)!


    int lans{1};                                       //a + b
    std::memset(ans, 0, sizeof(ans));
    int e{0};
    while (lans <= la || lans <= lb) {
        ans[lans] = a[lans] + b[lans] + e;
        e = ans[lans] / 10;
        ans[lans] %= 10;
        lans++;
    }
    ans[lans] = e;
    if (ans[lans] == 0) {
        lans--;
    }


    memcpy((a), ans, sizeof(ans));                                      //a = n! + (n-1)!


    num = num -1;
    while (num >= 3) {                                      //sum (n >= 3)
        num2 = num;                                     //(n-i)!
        num3 = num;
        count = 1;
        while (num2 /= 10) {
            count++;
        }
        std::memset(x, 0, sizeof(x));
        l = count;
        for(int i = 1; i <= count; i++) {
            x[i] = num3 % 10;
            num3 /= 10;
        }

        numb = num - 1;
        num2 = numb;
        num3 = numb;
        count = 1;
        while (num2 /= 10) {
            count++;
        }
        std::memset(y, 0, sizeof(y));
        for(int i = 1; i <= count; i++) {
            y[i] = num3 % 10;
            num3 /= 10;
        }

        std::memset(c, 0, sizeof(c));
        lenc = 0;
        while(numb > 1) {
            int j, i, m;
            std::memset(c, 0, sizeof(c));

            for (i=1; i<=l; i++) {
                m=0;
                for (j=1; j<=count; j++) {
                    c[i+j-1] = c[i+j-1] + m + x[i] * y[j];
                    m = c[i+j-1] / 10;
                    c[i+j-1] %= 10;
                }
                c[i+count] = m;
            }

            lenc = l + count;
            while (c[lenc] == 0 && lenc > 1) {
                lenc--;
            }

            memcpy((x), c, sizeof(c));
            l = lenc;
            numb = numb - 1;
            num2 = numb;
            num3 = numb;
            count = 1;
            while (num2 /= 10) {
                count++;
            }
            for (i = 1; i <= count; i++) {
                y[i] = num3 % 10;
                num3 /= 10;
            }
        }                                       //(n-i)! end


        memcpy((b), c, sizeof(c));                                      //b = (n-i)!


        lans = 1;                                       //a + b
        std::memset(ans, 0, sizeof(ans));
        e = 0;
        while (lans <= la || lans <= lb) {
            ans[lans] = a[lans] + b[lans] + e;
            e = ans[lans] / 10;
            ans[lans] %= 10;
            lans++;
        }
        ans[lans] = e;
        if (ans[lans] == 0) {
            lans--;
        }


        memcpy((a), ans, sizeof(ans));                                      //a = ans


        num = num - 1;
    }


    int add{3};                                     //revise the term '2!+1!', add = 2! + 1!
    int add2 = add;
    int times = 1;
    while (add2 /= 10) {
        times++;
    }
    int addition[9999] = {0};
    //int l = count;
    for(int i = 1; i <= times; i++) {
        addition[i] = add % 10;
        add /= 10;
    }


    memcpy((b), addition, sizeof(addition));                                      //b = add


    lans = 1;                                       //ans + add
    std::memset(ans, 0, sizeof(ans));
    e = 0;
    while (lans <= la || lans <= lb) {
        ans[lans] = a[lans] + b[lans] + e;
        e = ans[lans] / 10;
        ans[lans] %= 10;
        lans++;
    }
    ans[lans] = e;
    if (ans[lans] == 0) {
        lans--;
    }


    int k{0};                                       //output
    for(k=lans; k>=1; k--) {
        std::cout << ans[k];
    }

    return 0;
}