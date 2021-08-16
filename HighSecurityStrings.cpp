int getStrength(string password, int weight_a) {
    // Complete the function
    int strength =0;
    for(int i=0;i<password.size();i++){
        int ch = (int)password.at(i);
        int weight = ((ch-97)+weight_a)%26;
        strength+=weight;
    }
    return strength;
}
