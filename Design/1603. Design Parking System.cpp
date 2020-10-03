// Simple use 3 param.

class ParkingSystem {
public:
    int a = 0, b = 0, c = 0;
    int as, bs, cs;
    ParkingSystem(int big, int medium, int small) {
        as = big;
        bs = medium;
        cs = small;
    }
    
    bool addCar(int carType) {
        if(carType == 1){
            if(++a > as) return false;
        }
        else if(carType == 2){
            if(++b > bs) return false;
        }
        else{
            if(++c > cs) return false;
        }
        return true;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */
