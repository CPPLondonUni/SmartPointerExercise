#ifndef __EXERCISE_2_H__
#define __EXERCISE_2_H__

#include <random>
#include <cstdint>

class RandomDataProvider
{
public:
    RandomDataProvider(int cnt){
        randomDataArray = new uint64_t[cnt];
        FillArray();
    }
    
    ~RandomDataProvider()
    {
        delete randomDataArray;
    }
    
public:
    uint64_t* GetRandomData()
    {
        return randomDataArray;
    }
    
    uint64_t GetRandomDataAt(int idx)
    {
        if(!(randomDataArray + idx * 8))
            return 0;
        return randomDataArray[idx];
    }
    
public:
    void ResetData(int newSize)
    {
        randomDataArray = new uint64_t[newSize];
        FillArray();
    }
    
private:
    void FillArray()
    {
        for(uint64_t* curPos = randomDataArray; curPos && *curPos; curPos += 8)
            *curPos =  rng();
    }
    
private:
    std::mt19937_64 rng{std::random_device{}()};
    uint64_t* randomDataArray;
};

#endif //__EXERCISE_2_H__
