#include <bits/stdc++.h>

std::string intArrayTime(int *timeArray){
    std::string results = "";
    for(int i = 0; i < 4; i++){
        if(i == 2){
            results += ":";
        }
        results += 48 + timeArray[i];
    }
    return results;
}

std::string getMaxTime(int *timeArray){

    std::map<int, int> HashMap;

    for(int i = 0; i < 4; i++){
        HashMap[timeArray[i]]++;
    }

    int result[4] = {0};
    int i;
    bool flag = false;

    for(i = 2; i > -1; i--){
        if(HashMap[i]){
            result[0] = i;
            flag = true;
            HashMap[i]--;
            break;
        }
    }

    if(!flag){
        return "-1";
    }

    flag = false;

    if(result[0] == 2){

        for(i = 3; i > -1; i--){
            if(HashMap[i]){
                result[1] = i;
                flag = true;
                HashMap[i]--;
                break;
            }
        }

        if(!flag){
            return "-1";
        }

    }else{

        for(i = 9; i > -1; i--){
            if(HashMap[i]){
                result[1] = i;
                flag = true;
                HashMap[i]--;
                break;
            }
        }

        if(!flag){
            return "-1";
        }

    }

    flag = false;

    for(i = 5; i > -1; i--){
        if(HashMap[i]){
            result[2] = i;
            flag = true;
            HashMap[i]--;
            break;
        }
    }

    if(!flag){
        return "-1";
    }

    flag = false;

    for(i = 9; i > -1; i--){
        if(HashMap[i]){
            result[3] = i;
            flag = true;
            HashMap[i]--;
            break;
        }
    }

    if(!flag){
        return "-1";
    }

    return intArrayTime(result);

}


int main(){

    int timeArray[4];
    
    std::cout << "Enter time array : ";
    
    for(int i = 0; i < 4; i++){
        std::cin >> timeArray[i];
    }

    std::cout << getMaxTime(timeArray) << std::endl;

    return 0;
}