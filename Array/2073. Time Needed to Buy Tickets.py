# BF, O(N^2)

class Solution:
    def timeRequiredToBuy(self, tickets: List[int], k: int) -> int:
        time = 0
        while tickets[k]:
            for i in range(len(tickets)):
                if tickets[i]:
                    time += 1
                    tickets[i] -= 1
                if tickets[k] == 0:
                    return time
        return time

# O(N). if i > k, ticket[k] missing one
class Solution:
    def timeRequiredToBuy(self, tickets: List[int], k: int) -> int:
        time = 0
        for i in range(len(tickets)):
            time += min(tickets[k] - (i > k), tickets[i])
        return time
