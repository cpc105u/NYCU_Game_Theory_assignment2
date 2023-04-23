#include <cmath>
#include <iomanip>
#include <iostream>
#include <list>
#include <math.h>
#include <random>
#include <string>
#include <time.h>
#include <vector>

using namespace std;


void Q(int u_r1c1_l, int u_r1c1_r, int u_r1c2_l, int u_r1c2_r, int u_r2c1_l, int u_r2c1_r, int u_r2c2_l, int u_r2c2_r)
{

    float belief1_l, belief1_r, belief2_l, belief2_r;
    float payoff1_l, payoff1_r, payoff2_l, payoff2_r;
    int choose;

    belief1_l = rand() % 101;
    belief1_r = 100 - belief1_l;
    belief2_l = rand() % 101;
    belief2_r = 100 - belief2_l;

    payoff1_l = belief1_l * u_r1c1_l + belief1_r * u_r1c2_l;
    payoff1_r = belief1_l * u_r2c1_l + belief1_r * u_r2c2_l;
    payoff2_l = belief2_l * u_r1c1_r + belief2_r * u_r2c1_r;
    payoff2_r = belief2_l * u_r1c2_r + belief2_r * u_r2c2_r;

    vector <int> record1;
    vector <int> record2;


    // 10000 rounds
    for(int i = 0; i < 10000; i++)
    {
        if(payoff1_l > payoff1_r)
        {
            belief2_l++;
            record1.push_back(0);
        }
        else if(payoff1_r > payoff1_l)
        {
            belief2_r++;
            record1.push_back(1);
        }
        else if(payoff1_l == payoff1_r)
        {
            choose = rand() % 2;
            if(choose == 0)
            {
                belief2_l++;
                record1.push_back(0);
            }
            else
            {
                belief2_r++;
                record1.push_back(1);
            }
        }

        if(payoff2_l > payoff2_r)
        {
            belief1_l++;
            record2.push_back(0);
        }
        else if(payoff2_r > payoff2_l)
        {    
            belief1_r++;
            record2.push_back(1);
        }
        else if (payoff2_l == payoff2_r)
        {
            choose = rand() % 2;
            if(choose == 0)
            {    
                belief1_l++;
                record2.push_back(0);
            }
            else
            {    
                belief1_r++;
                record2.push_back(1);
            }
        }

        // update
        payoff1_l = belief1_l * u_r1c1_l + belief1_r * u_r1c2_l;
        payoff1_r = belief1_l * u_r2c1_l + belief1_r * u_r2c2_l;
        payoff2_l = belief2_l * u_r1c1_r + belief2_r * u_r2c1_r;
        payoff2_r = belief2_l * u_r1c2_r + belief2_r * u_r2c2_r;
        
        if(i == 9999)
        {
            cout << "1's belief : (" << belief1_l << "," << belief1_r << ")" << endl;
            cout << "2's belief : (" << belief2_l << "," << belief2_r << ")" << endl;
        }
    }

    record1.clear();
    record2.clear();

}

void Q6_9(int u_r1c1_l, int u_r1c1_r, int u_r1c2_l, int u_r1c2_r, int u_r2c1_l, int u_r2c1_r, int u_r2c2_l, int u_r2c2_r, float r1, float r2, float c1, float c2)
{

    float belief1_l, belief1_r, belief2_l, belief2_r;
    float payoff1_l, payoff1_r, payoff2_l, payoff2_r;
    int choose;

    belief1_l = r1;
    belief1_r = r2;
    belief2_l = c1;
    belief2_r = c2;

    payoff1_l = belief1_l * u_r1c1_l + belief1_r * u_r1c2_l;
    payoff1_r = belief1_l * u_r2c1_l + belief1_r * u_r2c2_l;
    payoff2_l = belief2_l * u_r1c1_r + belief2_r * u_r2c1_r;
    payoff2_r = belief2_l * u_r1c2_r + belief2_r * u_r2c2_r;

    vector <int> record1;
    vector <int> record2;

    int flag1,flag2;
    // 10 rounds
    for(int i = 0; i < 10; i++)
    {
        if(payoff1_l > payoff1_r)
        {
            belief2_l++;
            record1.push_back(0);
            flag1 = 1;
        }
        else if(payoff1_r > payoff1_l)
        {
            belief2_r++;
            record1.push_back(1);
            flag1 =2;
        }
        else if(payoff1_l == payoff1_r)
        {
            choose = rand() % 2;
            if(choose == 0)
            {
                belief2_l++;
                record1.push_back(0);
                flag1 = 1;
            }
            else
            {
                belief2_r++;
                record1.push_back(1);
                flag1 =2;
            }
        }

        if(payoff2_l > payoff2_r)
        {
            belief1_l++;
            record2.push_back(0);
            flag2 = 1;
        }
        else if(payoff2_r > payoff2_l)
        {    
            belief1_r++;
            record2.push_back(1);
            flag2 = 2;
        }
        else if (payoff2_l == payoff2_r)
        {
            choose = rand() % 2;
            if(choose == 0)
            {    
                belief1_l++;
                record2.push_back(0);
                flag2 = 1;
            }
            else
            {    
                belief1_r++;
                record2.push_back(1);
                flag2 = 2;
            }
        }

        // update
        payoff1_l = belief1_l * u_r1c1_l + belief1_r * u_r1c2_l;
        payoff1_r = belief1_l * u_r2c1_l + belief1_r * u_r2c2_l;
        payoff2_l = belief2_l * u_r1c1_r + belief2_r * u_r2c1_r;
        payoff2_r = belief2_l * u_r1c2_r + belief2_r * u_r2c2_r;
        
    /*    if(i == 9990)
        {
            cout << "1's belief : (" << belief1_l << "," << belief1_r << ")" << endl;
            cout << "2's belief : (" << belief2_l << "," << belief2_r << ")" << endl;
        }
    */
     //   cout << "1's belief : (" << belief1_l << "," << belief1_r << ")" << endl;
     //   cout << "2's belief : (" << belief2_l << "," << belief2_r << ")" << endl;
       cout << "This rounds select (r" << flag1 << "," <<  "c" << flag2 << ")" << endl;
    }

    record1.clear();
    record2.clear();

}


void Q1()
{
    int u_r1c1_l = -1;
    int u_r1c1_r = -1;
    int u_r1c2_l = 1;
    int u_r1c2_r = 0;
    int u_r2c1_l = 0;
    int u_r2c1_r = 1;
    int u_r2c2_l = 3;
    int u_r2c2_r = 3;

    Q(u_r1c1_l, u_r1c1_r, u_r1c2_l, u_r1c2_r, u_r2c1_l, u_r2c1_r, u_r2c2_l, u_r2c2_r);
}

void Q2()
{
    int u_r1c1_l = 2;
    int u_r1c1_r = 2;
    int u_r1c2_l = 1;
    int u_r1c2_r = 0;
    int u_r2c1_l = 0;
    int u_r2c1_r = 1;
    int u_r2c2_l = 3;
    int u_r2c2_r = 3;

    Q(u_r1c1_l, u_r1c1_r, u_r1c2_l, u_r1c2_r, u_r2c1_l, u_r2c1_r, u_r2c2_l, u_r2c2_r);

    cout << "--------------------" << endl;

    //init
    float belief1_l, belief1_r, belief2_l, belief2_r;
    belief1_l = 0.5;
    belief1_r = 1;
    belief2_l = 1;
    belief2_r = 0.5;

    cout << "When i change the inital belief" << endl;
    cout << "The next 10 data" << endl;
    Q6_9(u_r1c1_l, u_r1c1_r, u_r1c2_l, u_r1c2_r, u_r2c1_l, u_r2c1_r, u_r2c2_l, u_r2c2_r, belief1_l, belief1_r, belief2_l, belief2_r);
}

void Q3()
{
    int u_r1c1_l = 1;
    int u_r1c1_r = 1;
    int u_r1c2_l = 0;
    int u_r1c2_r = 0;
    int u_r2c1_l = 0;
    int u_r2c1_r = 0;
    int u_r2c2_l = 0;
    int u_r2c2_r = 0;

    Q(u_r1c1_l, u_r1c1_r, u_r1c2_l, u_r1c2_r, u_r2c1_l, u_r2c1_r, u_r2c2_l, u_r2c2_r);
}

void Q4()
{
    int u_r1c1_l = 0;
    int u_r1c1_r = 1;
    int u_r1c2_l = 2;
    int u_r1c2_r = 0;
    int u_r2c1_l = 2;
    int u_r2c1_r = 0;
    int u_r2c2_l = 0;
    int u_r2c2_r = 4;

    Q(u_r1c1_l, u_r1c1_r, u_r1c2_l, u_r1c2_r, u_r2c1_l, u_r2c1_r, u_r2c2_l, u_r2c2_r);
}

void Q5()
{
    int u_r1c1_l = 0;
    int u_r1c1_r = 1;
    int u_r1c2_l = 1;
    int u_r1c2_r = 0;
    int u_r2c1_l = 1;
    int u_r2c1_r = 0;
    int u_r2c2_l = 0;
    int u_r2c2_r = 1;

    Q(u_r1c1_l, u_r1c1_r, u_r1c2_l, u_r1c2_r, u_r2c1_l, u_r2c1_r, u_r2c2_l, u_r2c2_r);
}

void Q6()
{
    int u_r1c1_l = 10;
    int u_r1c1_r = 10;
    int u_r1c2_l = 0;
    int u_r1c2_r = 0;
    int u_r2c1_l = 0;
    int u_r2c1_r = 0;
    int u_r2c2_l = 10;
    int u_r2c2_r = 10;

    cout << "If use the random inital belief" << endl;
    Q(u_r1c1_l, u_r1c1_r, u_r1c2_l, u_r1c2_r, u_r2c1_l, u_r2c1_r, u_r2c2_l, u_r2c2_r);

    cout << "--------------------" << endl;

    //init
    float belief1_l, belief1_r, belief2_l, belief2_r;
    belief1_l = 0.05;
    belief1_r = 1;
    belief2_l = 1;
    belief2_r = 0.05;

    cout << "When i change the inital belief" << endl;
    cout << "The next 10 data" << endl;
    Q6_9(u_r1c1_l, u_r1c1_r, u_r1c2_l, u_r1c2_r, u_r2c1_l, u_r2c1_r, u_r2c2_l, u_r2c2_r, belief1_l, belief1_r, belief2_l, belief2_r);
}

void Q7()
{
    int u_r1c1_l = 0;
    int u_r1c1_r = 0;
    int u_r1c2_l = 1;
    int u_r1c2_r = 1;
    int u_r2c1_l = 1;
    int u_r2c1_r = 1;
    int u_r2c2_l = 0;
    int u_r2c2_r = 0;

    cout << "If use the random inital belief" << endl;
    Q(u_r1c1_l, u_r1c1_r, u_r1c2_l, u_r1c2_r, u_r2c1_l, u_r2c1_r, u_r2c2_l, u_r2c2_r);

    cout << "--------------------" << endl;

    //init
    float belief1_l, belief1_r, belief2_l, belief2_r;
    belief1_l = 1;
    belief1_r = 0.5;
    belief2_l = 1;
    belief2_r = 0.5;

    cout << "When i change the inital belief" << endl;
    cout << "The next 10 data" << endl;

    Q6_9(u_r1c1_l, u_r1c1_r, u_r1c2_l, u_r1c2_r, u_r2c1_l, u_r2c1_r, u_r2c2_l, u_r2c2_r, belief1_l, belief1_r, belief2_l, belief2_r);
}

void Q8()
{
    int u_r1c1_l = 3;
    int u_r1c1_r = 2;
    int u_r1c2_l = 0;
    int u_r1c2_r = 0;
    int u_r2c1_l = 0;
    int u_r2c1_r = 0;
    int u_r2c2_l = 2;
    int u_r2c2_r = 3;

    cout << "If use the random inital belief" << endl;
    Q(u_r1c1_l, u_r1c1_r, u_r1c2_l, u_r1c2_r, u_r2c1_l, u_r2c1_r, u_r2c2_l, u_r2c2_r);

    cout << "--------------------" << endl;

    //init
    float belief1_l, belief1_r, belief2_l, belief2_r;
    belief1_l = 0.5;
    belief1_r = 1;
    belief2_l = 1;
    belief2_r = 0.5;

    cout << "When i change the inital belief" << endl;
    cout << "The next 10 data" << endl;

    Q6_9(u_r1c1_l, u_r1c1_r, u_r1c2_l, u_r1c2_r, u_r2c1_l, u_r2c1_r, u_r2c2_l, u_r2c2_r, belief1_l, belief1_r, belief2_l, belief2_r);
}

void Q9()
{
    int u_r1c1_l = 3;
    int u_r1c1_r = 3;
    int u_r1c2_l = 0;
    int u_r1c2_r = 2;
    int u_r2c1_l = 2;
    int u_r2c1_r = 0;
    int u_r2c2_l = 1;
    int u_r2c2_r = 1;

    cout << "If use the random inital belief" << endl;
    Q(u_r1c1_l, u_r1c1_r, u_r1c2_l, u_r1c2_r, u_r2c1_l, u_r2c1_r, u_r2c2_l, u_r2c2_r);

    cout << "--------------------" << endl;

    //init
    float belief1_l, belief1_r, belief2_l, belief2_r;
    belief1_l = 0.5;
    belief1_r = 1;
    belief2_l = 1;
    belief2_r = 0.5;

    cout << "When i change the inital belief" << endl;
    cout << "The next 10 data" << endl;

    Q6_9(u_r1c1_l, u_r1c1_r, u_r1c2_l, u_r1c2_r, u_r2c1_l, u_r2c1_r, u_r2c2_l, u_r2c2_r, belief1_l, belief1_r, belief2_l, belief2_r);
}

void Q10()
{
    int u_r1c1_l = 1;
    int u_r1c1_r = 0;
    int u_r1c2_l = 1;
    int u_r1c2_r = 0;
    int u_r2c1_l = 0;
    int u_r2c1_r = 0;
    int u_r2c2_l = 0;
    int u_r2c2_r = 0;

    Q(u_r1c1_l, u_r1c1_r, u_r1c2_l, u_r1c2_r, u_r2c1_l, u_r2c1_r, u_r2c2_l, u_r2c2_r);

}

int main()
{
    srand(time(NULL));
    cout << "--------------------" << endl;
    cout << "This is Q1's result." << endl;
    Q1();

    cout << "--------------------" << endl;
    cout << "This is Q2's result." << endl;
    Q2(); 

    cout << "--------------------" << endl;
    cout << "This is Q3's result." << endl;
    Q3(); 

    cout << "--------------------" << endl;
    cout << "This is Q4's result." << endl;
    Q4(); 

    cout << "--------------------" << endl;
    cout << "This is Q5's result." << endl;
    Q5();

    cout << "--------------------" << endl;
    cout << "This is Q6's result." << endl;
    Q6();

    cout << "--------------------" << endl;
    cout << "This is Q7's result." << endl;
    Q7(); 

    cout << "--------------------" << endl;
    cout << "This is Q8's result." << endl;
    Q8();

    cout << "--------------------" << endl;
    cout << "This is Q9's result." << endl;
    Q9();

    cout << "--------------------" << endl;
    cout << "This is Q10's result." << endl;
    Q10(); 

    return 0;
}