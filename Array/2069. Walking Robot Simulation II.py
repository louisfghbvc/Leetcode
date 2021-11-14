# handle the first time.
# generate all candidate, preprocessing.
# each is O(1).

class Robot:
    def __init__(self, width: int, height: int):
        # N, E, S, W = 0, 1, 2, 3
        self.ind = 0
        self.firstmove = 0
        self.w, self.h = width, height
        
        arr = []
        for x in range(width):
            arr.append((x, 0))
        for y in range(1, height):
            arr.append((width-1, y))
        for x in range(width-2, -1, -1):
            arr.append((x, height-1))
        for y in range(height-2, 0, -1):
            arr.append((0, y))

        self.movement = arr

    def move(self, num: int) -> None:
        self.firstmove = 1
        self.ind = (self.ind + num) % len(self.movement)

    def getPos(self) -> List[int]:
        return list(self.movement[self.ind])

    def getDir(self) -> str:
        if not self.firstmove: 
            return 'East'
        
        x, y = self.movement[self.ind]
        if y == 0 and 0 < x: return 'East'
        if y == self.h-1 and x < self.w-1: return 'West' 
        if x == 0 and y < self.h-1: return 'South' 
        if x == self.w-1 and 0 < y : return 'North' 
        return None


# Your Robot object will be instantiated and called as such:
# obj = Robot(width, height)
# obj.move(num)
# param_2 = obj.getPos()
# param_3 = obj.getDir()
