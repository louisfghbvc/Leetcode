class Solution {
public:
    int countCollisions(string directions) {
        // use stack
        // if stack is S or R and cur is L, collision happened
        // if stack is R and cur is S
        
        stack<char> stack;
        int points = 0;
        
        for (char c: directions) {
            if (c == 'L') {
                if (stack.size()) {
                    char c = stack.top(); stack.pop();
                    if (c == 'S') {
                        points++;
                        stack.push('S');
                    }
                    else {
                        points += 2;
                        while (stack.size() && stack.top() == 'R') {
                            points += 1;
                            stack.pop();
                        } 
                        stack.push('S');
                    }
                }
            }
            else if (c == 'S') {
                while (stack.size() && stack.top() == 'R') {
                    points++;
                    stack.pop();
                }
                stack.push('S');
            }
            else {
                stack.push(c);
            }
        }
        
        return points;
    }
};
