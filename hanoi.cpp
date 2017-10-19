#include <iostream>

using namespace std;

int main(int argc,char **argv)
{
    int m,counter=0;
    cin>>m;
    while(m--)
    {
        int n;
        unsigned long long int a,b,src=0,des=0;
        cin>>n>>a>>b;
        ++counter;
        cout<<"Case #"<<counter<<':'<<endl;
        if(n&1){
            for(unsigned long long int i=a;i<=b;i+=1)
            {
                src = (unsigned long long int)(i&i-1)%3+1,des = (unsigned long long int)((i|i-1)+1)%3+1;
                cout<<"Step "<<i<<": #"<<src<<" -> #"<<des<<endl;
            }
        }
        else{
            for(unsigned long long int i=a;i<=b;i+=1)
            {
                src = (unsigned long long int)(i&i-1)%3+1,des = (unsigned long long int)((i|i-1)+1)%3+1;
                switch(src){
                    case 2:
                        src=(unsigned long long int)3;
                        break;
                    case 3:
                        src=(unsigned long long int)2;
                        break;
                }
                switch(des){
                    case 2:
                        des=(unsigned long long int)3;
                        break;
                    case 3:
                        des=(unsigned long long int)2;
                        break;
                }
                cout<<"Step "<<i<<": #"<<src<<" -> #"<<des<<endl;
            }
        }
    }
    return 0;
}
