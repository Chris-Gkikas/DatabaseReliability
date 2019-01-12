#include <iostream>
#include<fstream>
#include<iomanip>


using namespace std;

int main(int argc, char *argv[]){
    
    if(argc != 2){
        cout << "\nusage: "<< argv[0] <<" <filename>" <<endl;
        return 0;
    }
    
    ifstream infile (argv[1]);
    
    if(!infile.is_open()){
        cout << "\nError: Could not open file or file may not even exist." <<endl;
        return 0;
    }
    
    string state,prev_state="";
    float time,total_time=0;
    int ups,downs,up_TO_down,last_down,lines=0;
    
    while(!infile.eof()){
        prev_state=state;
        infile >> state;
        lines++;
        
        if(state=="up"){
                infile>>time;
                ups++;
                total_time+=time;
        }
        else{   time=0;
                downs++;
                last_down=lines;
                if(prev_state=="up") up_TO_down++;
        }
    }
    infile.close();
    
    if(state=="up"){
        total_time-=time; 
        ups--;
    }
    else downs--;
    lines--;
    cout <<"**************************************************"<<endl;
    cout<<"\n1)Mean Time To Failure(MTTF):  "<<setprecision(3)<<setw(10)<<left<<(ups-(lines-last_down))/(float)up_TO_down<<setw(10)<<left<<"msec"<<endl;
    cout<<"\n2)Mean Time To Repair(MTTR):   "<<setprecision(3)<<setw(10)<<left<<downs/(float)up_TO_down<< setw(5)<<left <<"msec"<<endl;
    cout<<"\n3)Mean Response Time(MRT):     "<<setprecision(3)<<setw(10)<<left<<total_time/ups<<setw(5)<<left<<"msec"<<endl;
    cout<<"\n4)Availability(AV):            " <<setprecision(3)<<setw(10)<<left<<(ups/(float)(ups+downs))*100<<setw(5)<<left<<"%"<<endl;
    cout<<"\n**************************************************"<<endl;
    return 0;
}





