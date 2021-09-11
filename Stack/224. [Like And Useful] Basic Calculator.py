# General solution. infix to postfix, and just simple.
# O(N).
class Solution:
    
    def rank(self, c: str):
        if c == '+' or c == '-': return 1
        elif c == '*' or c == '/': return 1
        return 0
    
    def infixToPostfix(self, s: str):
        ret, ops = [], []
        num = 0
        num_going = False
        unary = True # use to check need to unary or not
        neg = False
        
        for c in s:
            if unary:
                unary = False
                if c == '-': ret.append(0)
            if c.isdigit():
                num = num * 10 + ord(c)-ord('0')
                num_going = True
            else:
                if num_going:
                    ret.append(num)
                num, num_going = 0, False
                
                if c == ' ': continue
                elif c == '(':
                    unary = True
                    ops.append(c)
                elif c == ')':
                    while ops and ops[-1] != '(':
                        ret.append(ops.pop())
                    ops.pop() # pop '('
                else: # operator
                    # stack ops want to out
                    while ops and self.rank(ops[-1]) >= self.rank(c):
                        ret.append(ops.pop())
                    ops.append(c)
                    
        if num_going: ret.append(num)
        while ops: ret.append(ops.pop())
        return ret
    
    def calculate(self, s: str) -> int:
        # do postfix
        stack = []
        for c in self.infixToPostfix(s):
            if c != '-' and c != '+':
                stack.append(c)
            else:
                if c == '+':
                    b, a = stack.pop(), stack.pop()
                    stack.append(a + b)
                else:
                    b, a = stack.pop(), stack.pop()
                    stack.append(a - b)
        return stack[-1]
      
      
      
# Simple use stack.
