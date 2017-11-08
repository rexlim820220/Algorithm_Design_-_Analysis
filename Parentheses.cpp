#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <vector>
#include <new>

using namespace std;

struct Parent{
    int left_;
    int right;
};

int main(int argc,char **argv)
{
    std::string ss;
    while(std::cin>>ss)
    {
        unsigned long long int cost=0;
        int len=ss.length(),a=0;
        for(int i=0;i<len;i+=1)
        {
            if(ss[i]=='?'){a+=1;}
        }
        Parent *price=new Parent[a];
        for(int i=0;i<a;i+=1)
        {
            std::cin>>price[i].left_>>price[i].right;
            cost+=price[i].right;
        }
        bool balenced=true;
        long long int prefix=0,sth=0;
        std::priority_queue<long long int> left_right;
        std::vector<long long int> right_left;
        for(int i=0;i<len;i+=1)
        {
            if(ss[i]=='('){prefix+=1;}
            else if(ss[i]==')'){prefix-=1;}
            else{
                prefix-=1;
                right_left.push_back(price[sth].right-price[sth].left_);
                sth+=1;
            }
            if(prefix<0){
                if(!right_left.empty())
                {
                    auto it=max_element(right_left.begin(),right_left.end());
                    cost-=*it;
                    right_left.erase(it);
                    prefix+=2;
                }
                else
                {
                    balenced=false;
                    break;
                }
            }
        }
        if(prefix!=0){balenced=false;}
        if(balenced==true)
        {
            std::cout<<cost<<std::endl;
        }
        else
        {
            std::cout<<"Impossible"<<std::endl;
        }
        delete[]price;
    }
    return 0;
}
