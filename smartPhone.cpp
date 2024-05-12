#include <bits/stdc++.h> 
using namespace std;


class Battery {
    public :
    double full_capacity;
    double current_charge;
    int paced_count;

    Battery(double fc)
    {
        full_capacity=fc;
        current_charge=fc;
        paced_count=0;
    }
    void discharge(double x){
        if(x>current_charge)
           {
            cout<<"discharge more than it already has???";
            return;
           }
        current_charge-=x;
    }
    void pace_increment()
    {
        paced_count++;
        cout<<paced_count<<" ";
    }
    
};

class SuperCapacitor{
    public:
    double full_capacity;
    double current_charge;
    double rate_of_charge;
    SuperCapacitor(double fc,double rc) // rc: rate of charge
    {
        full_capacity=fc;
        current_charge=fc;
        rate_of_charge=rc;
    }
    void charge(Battery &battery)
    {
        if(current_charge<full_capacity){
           battery.discharge(min(rate_of_charge,full_capacity-current_charge));
           current_charge=current_charge+ min(rate_of_charge,full_capacity-current_charge);
        }
    }
    void discharge(double x){
        if(x>current_charge)
           {
            cout<<"discharge more than it already has???";
            return;
           }
        current_charge-=x;
    }    
};

 vector<char> applications = {'I', 'G', 'V', 'A', 'P', 'S', 'W', 'C', 'E'};
 map <char,pair<int,int>> appRequirements={
    {'I', {805, 50}},
    {'G', {1516, 90}},
    {'V', {2614, 20}},
    {'A', {226, 50}},
    {'C', {2256, 20}},
    {'S', {1140, 45}},
    {'W', {1479, 180}},
    {'E', {1543, 140}},
    {'P', {843, 50}}
 };

bool isSuperCapacitorChargeEnough(SuperCapacitor &sp,char app)
{
    return sp.current_charge>= appRequirements[app].first;

}
void application(char app,Battery &battery, SuperCapacitor &sp,ifstream &file)
{
   if(isSuperCapacitorChargeEnough(sp,app)){
    for (int i = 0; i < appRequirements[app].second; i++)
    {
       sp.discharge(appRequirements[app].first/(appRequirements[app].second*3.8));
       file.get();
    }
   }
   else{
    battery.pace_increment();
    for (int i = 0; i < appRequirements[app].second; i++)
    {
       battery.discharge(appRequirements[app].first/(appRequirements[app].second*3.8));
       sp.charge(battery);
       file.get();
    }    
   }
}

int main(){ 
    Battery battery(30000);
    SuperCapacitor sp(1000,10);
    ifstream file("traceFile.txt"); // Open the file
    if (!file.is_open()) {
        std::cerr << "Failed to open the file." << std::endl;
        return 1;
    }
    char c;
    int appCount=0;
    while (file.get(c)) { 
        if(c=='-'){
            sp.charge(battery);
        }else{
           application(c,battery,sp,file);
           appCount++;
        }
    }
    cout<<endl;
    cout<<"Total Paces: "<<battery.paced_count<<endl;
    cout<<"battery charge remaining: "<<battery.current_charge<<endl;
    cout<<"Total app count: "<<appCount<<endl;
  return 0;
 } 