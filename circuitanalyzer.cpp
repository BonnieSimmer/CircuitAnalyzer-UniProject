#include <iostream>
#include <string>

#define size 12

using namespace std;
int main_type,type,type_pos=0,which=1,n;
float r[size],r2[size],R=0,R2=0,Rop=0;
string x[size],x2[size];
int space_placement=2,old_space_placement=1;

float calculate_series_resistors();
float calculate_parallel_resistors();

void get_type(string s) {
    if (s[type_pos]=='S' || s[type_pos]=='s') {
        type=1;
    }
    else if (s[type_pos]=='P' || s[type_pos]=='p') {
        type=2;
    } else {
    cout << "Wrong Description";
    exit(0);
    }
}
void get_resistors(string s, float r[],string x[] ){
    if (s[old_space_placement]!=' ') {
        cout << "Incorrect Input";
        exit(0);
    }
    if (s[space_placement]=='e') {
                    cout << "Incorrect Input";
                    exit(0);
                }
    for (int i=0;i<12;i++) {
        for ( ;space_placement< n; space_placement++) {
        if (s[space_placement]==' ') {
                x[i]=s.substr(old_space_placement+1,space_placement-old_space_placement-1);

                r[i] = stof(x[i]);
                if (r[i]<=0) {
                    exit(0);
                }
                old_space_placement=space_placement;
                space_placement++;
                break;
        }
        else if (s[space_placement]>64 && s[space_placement]!='e') {
            type_pos=space_placement;
            old_space_placement=space_placement+1;
            get_type(s);
            if (main_type==type) {
                cout << "Incorrect Input";
                exit(0);
            } else {
                space_placement=space_placement+2;
                get_resistors(s,r2,x2);

                space_placement=space_placement+2;

                old_space_placement=old_space_placement+1;

                which=2;
                if (type==1) {
        R2=calculate_series_resistors();
        }
        else {
        R2=calculate_parallel_resistors();
        }
        r[i]=R2;
        break;
            }

        }
    }
    if (s[space_placement]=='e') {
        return;
    }
    else if (space_placement==n){
        cout << "Incorrect Input";
        exit(0);
    }
}
}

float calculate_series_resistors(){
    if (which==1)
    {
     for (int j=0;j<12;j++){
        R+=r[j];
    }
    return R;
    }
    else {
        which=1;
        R2=0;
        for (int j=0;j<12;j++){
        R2+=r2[j];
    }
    return R2;
    }

}

float calculate_parallel_resistors(){
    if (which==1) {
            if (r[1]==0) {
        cout << "Incorrect Input";
        exit(0);
            }
     else {
        for (int i=0;i<12;i++) {
        if (r[i]>0) {
            Rop+=1/r[i];
        }
    }
    return (1/Rop);
    }
    }
    else {
    which=1;
                   if (r2[1]==0) {
        cout << "Incorrect Input";
        exit(0);
            }
     else {
        for (int i=0;i<12;i++) {
        if (r2[i]>0) {

            Rop+=1/r2[i];
        }
    }
    return (1/Rop);
    }
    }
}
int main() {
    string user;

    getline(cin, user);
    n= user.length();
    get_type(user);
    main_type=type;

    get_resistors(user,r,x);
    if (main_type==1) {
        R=calculate_series_resistors();
    }
    else {
        R=calculate_parallel_resistors();
    }
    cout << "The total resistance = " << R;
    cin.ignore();
}
