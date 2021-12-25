
/*


You have information about n different recipes. You are given a string array recipes and a 2D string array ingredients. The ith recipe has the name recipes[i], and you can create it if you have all the needed ingredients from ingredients[i]. Ingredients to a recipe may need to be created from other recipes, i.e., ingredients[i] may contain a string that is in recipes.

You are also given a string array supplies containing all the ingredients that you initially have, and you have an infinite supply of all of them.

Return a list of all the recipes that you can create. You may return the answer in any order.

Note that two recipes may contain each other in their ingredients.

SO LONG B
*/



class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        int n_recipes = recipes.size();
        vector<int> indegree(n_recipes,0);
        unordered_map<string,int> pos;
        vector<string> ans;
        set<string> currSupplies;
        queue<int> q;
        vector<vector<int>> mat(n_recipes,vector<int>(n_recipes,0));
        for(int i = 0;i<supplies.size();i++){
            currSupplies.insert(supplies[i]);
        }
        for(int i = 0;i<n_recipes;i++){
            pos[recipes[i]] = i;
        }
        for(int i =0;i<n_recipes;i++){
            string curr_recipe = recipes[i];
            vector<string> req = ingredients[i];
            for(int j = 0;j<req.size();j++){
                string curr_req = req[j];
                if(pos.find(curr_req)!=pos.end()){
                    int target = pos[curr_req];
                    indegree[i]++;
                    mat[target][i] = 1;
                }
            }
        }
       
        for(int i = 0;i<n_recipes;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            bool flag = true;
             
            for(int i = 0;i<ingredients[curr].size();i++){
                string curr_ingredient = ingredients[curr][i];
                if(currSupplies.find(curr_ingredient)==currSupplies.end()){
                    flag = false;
                    break;
                }
            }
           
            
            if(!flag) continue;
            ans.push_back(recipes[curr]);
            
            currSupplies.insert(recipes[curr]);
            
            for(int i = 0;i<mat[curr].size();i++){
                if(mat[curr][i]==1){
                    indegree[i]--;
                    if(indegree[i]==0) q.push(i);
                }
            }
            
        }
        
        
        return ans;
    }
};
