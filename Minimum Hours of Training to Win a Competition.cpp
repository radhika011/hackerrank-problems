



/*

You are entering a competition, and are given two positive integers initialEnergy and initialExperience denoting your initial energy and initial experience respectively.

You are also given two 0-indexed integer arrays energy and experience, both of length n.

You will face n opponents in order. The energy and experience of the ith opponent is denoted by energy[i] and experience[i] respectively. When you face an opponent, you need to have both strictly greater experience and energy to defeat them and move to the next opponent if available.

Defeating the ith opponent increases your experience by experience[i], but decreases your energy by energy[i].

Before starting the competition, you can train for some number of hours. After each hour of training, you can either choose to increase your initial experience by one, or increase your initial energy by one.

Return the minimum number of training hours required to defeat all n opponents.

MEANT TO BE LC EASY?




*/



class Solution {
public:
    
    
    
    int minNumberOfHours(int initialEnergy, int initialExperience, vector<int>& energy, vector<int>& experience) {
        int n = energy.size();
        int energyReq = 0;
        for(int i = 0;i<n;i++){
            energyReq+=energy[i];
        }
        int a1 = 0;
        if((energyReq+1)>initialEnergy)  a1 = (energyReq+1)-initialEnergy;
        int a2 = 0;
        int currexp = initialExperience;
        for(int i =0;i<n;i++){
            if(experience[i]<currexp){
                currexp+=experience[i];
                continue;
            }
            a2+=((experience[i]+1)-currexp);
            currexp+=((experience[i]+1)-currexp);
            currexp += (experience[i]);
        }
        
        return a1+a2;
    }
};
