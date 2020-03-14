#include <iostream>
#include <vector>
using namespace std;

//PROTOTYPES*********
int iquot(int a,int b);
int irem(int a,int b);
bool IsDivisor(int a,int b);
int gcd(int a,int b);
vector<int> ext_euc_alg(int a,int b);

//FUNCTIONS*********
int iquot(int a,int b){
    int c;
    c = a/b;
    return c;
}
int irem(int a,int b){
    return a%b;
}
bool IsDivisor(int a,int b){
    if (b%a==0) return true;
    else return false;
}
int gcd(int a,int b){
    int R {0};
    int A {a};
    int B {b};
    while(B!=0){
        R = irem(A,B);
        A = B;
        B = R;
    }
    if(A<0)A*=-1;
    return A;
}
vector<int> ext_euc_alg(int a,int b){
    int A {a};
    int B {b};
    int R {0};
    int Q{0};
    int temp_mp{0};
    int temp_np{0};
    int mpp {1};
    int mp {0};
    int npp {0};
    int np {1};
    vector<int> final {0,0,0};
    while (B!=0){
        R = irem(A,B);
        Q = iquot(A,B);
        A=B;
        B=R;
        temp_mp = mp;
        temp_np = np;
        mp = mpp - Q*mp;
        mpp = temp_mp;
        np = npp - Q*np;
        npp = temp_np;        
    }
    if(A<0){
        a*=-1;
        mpp*=-1;
        npp*=-1;
    }
    final[0] = A;
    final[1] = mpp;
    final[2] = npp;
    return final;
    
}


//MAIN**************
int main(){
  int t {0};//User input
  while(true){//Main Loop
      cout<<endl<<endl;
      cout<<"------MAIN MENU------\n";
      cout<<"Enter the number in the [  ], to select an option.\n";
      cout<<"[0]Quit.\n";
      cout<<"[1]Two integer operations.\n";
      cout<<"Enter an option: ";
      
      cin>>t;
      cout<<endl;
      if(t==0)break;
      else if(t==1){
          while(true){//Loop to fall back to in order to change a and b
              long a{0};
              long b{0};
              cout<<endl<<endl;
              cout<<"Enter first integer: ";
              cin>>a;
              cout<<"Enter second integer: ";
              cin>>b;
              while(true){//Loop for main option 2
                cout<<endl<<endl;
                cout<<"------Two integer operations------\n";
                cout<<"Enter the number in the [  ], to select an option.\n\n";
                cout<<"[0]Back.\n";
                cout<<"[1]Choose new integers.\n";
                cout<<"[2]Give quotient and remainder of " <<a<<" / "<<b<<".\n";
                cout<<"[3]Is "<<b<<" a divisor of "<<a<<"?\n";
                cout<<"[4]Show greatest common divisor of "<< a<<" and "<<b<<".\n";
                cout<<"[5]Simplify: "<<a<<" / "<<b<<".\n";
                cout<<"[6]Express the greatest common divisor of "<< a <<" and "<< b<< " as their linear combination.\n";
                cout<<"Enter an option: ";
                
                cin>>t;
                cout<<endl<<"+++++++++++++++++++++++++++++++++++++++++\n";
                if(t==0||t==1)break;
                else if(t==2){
                    int q{iquot(a,b)};
                    int r{irem(a,b)};
                    cout<<"For "<<a<<"/"<<b<<":\n";
                    cout<<"Quotient is: "<<q<<endl;
                    cout<<"Remainder is: "<<r<<endl;
                    cout<<"So we can say that: "<<a<<" = "<<q<<"*"<<b<<" + "<<r<<" \n";
                }
                else if(t==3){
                    int q {iquot(a,b)};
                    int r {irem(a,b)};
                    if(IsDivisor(b,a)){
                        cout<<"Yes, "<<b<<" is a divisor of "<<a<<".\n";
                        cout<<"In fact: "<< a<<" = "<< q <<"*"<<b<<endl;
                    }
                    else{
                        cout<<"No, "<<b<<" is not a divisor of "<<a<<".\n";
                        cout<<"In fact: "<< a<<" = "<< q <<"*"<<b<<" + "<<r<<" \n";
                    }
                }
                else if(t==4){
                    cout<<"The greatest common divisor of "<< a<<" and "<<b<<" is, "<<gcd(a,b)<<endl;
                }
                else if(t==5){
                    int c {gcd(a,b)};
                    int new_a{a/c};
                    int new_b{b/c};
                    if(c == 1){
                        cout<<"The greatest common divisor of "<< a<<" and "<<b<<" is 1, so no simplification is possible.\n";
                    }
                    else cout<<"Simplification: "<<a<<" / "<<b<<"   =   "<<new_a<<" / "<<new_b<<endl;
                }
                else if(t==6){
                    vector<int> temp {ext_euc_alg(a,b)};
                    cout<<"The greatest common divisor of "<< a <<" and "<< b<< " is "<< temp[0]<<".\n";
                    cout<< "We can now say that: \n"<<temp[0]<<"  =  " <<temp[1]<<" * "<<a<<"  +  "<<temp[2]<<" * "<<b<<endl;
                }
                 cout<<"+++++++++++++++++++++++++++++++++++++++++\n";
           }
            if(t!=1)break;
          }

          
      }
      else break;
  }
  return 0;
}