# greedy, sort and add

class Solution:
    def asteroidsDestroyed(self, mass: int, asteroids: List[int]) -> bool:
        # sort from small to big
        asteroids.sort()
        
        for x in asteroids:
            if mass >= x:
                mass += x
            else: return False
        
        return True
