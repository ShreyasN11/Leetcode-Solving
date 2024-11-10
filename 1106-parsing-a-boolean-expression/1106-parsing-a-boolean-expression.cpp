class Solution {
public:
    char evaluate(vector<char>&arr,char ops){
        if(ops == '!'){
            if(arr[0] == 't') return 'f';
            else return 't';
        }
        else if(ops == '|'){
            for(auto it:arr){
                if(it == 't') return 't';
            }
            return 'f';
        }
        else{
            for(auto it:arr){
                if(it == 'f') return 'f';
            }
            return 't';
        }
    }
    bool parseBoolExpr(string expression) {
        stack<char>op;
        stack<char>exp;
        int n = expression.size();
        int i=0;
        while(i<n){
            char x = expression[i];
            if(x == '|' || x == '!' || x == '&'){
                op.push(x);
            }
            else if(x==')'){
                vector<char>temp;
                while(!exp.empty() && exp.top() != '('){
                    temp.push_back(exp.top());
                    exp.pop();
                }
                exp.pop();
                char ops = op.top(); op.pop();
                char z = evaluate(temp,ops);
                exp.push(z);
            }
            else{
                exp.push(x);
            }
            i++;
        }
        char res = exp.top();
        if(res == 't') return true;
        else return false;
    }
};